#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "librarys/clsInputValidate.h"
#include "librarys/clsUtil.h"
#include "screens/clsScreen.h"
#include "core/clsStudent.h"
#include "core/clsSubject.h"

class clsStudentMarksScreen : protected clsScreen
{

private:

	static string _GetPassOrFail(bool Result)
	{
		return (Result ? "Pass" : "Fail");
	}

	static void _PrintStudentFinalResultLine(clsStudent Student)
	{
		cout << " |" << left << setw(14) << Student.Subjects.TotalSubjects;
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Student.Sum();
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Student.Average();
		cout << "|" << left << setw(16) << _GetPassOrFail(Student.IsPass());
		cout << "|" << left << setw(52) << " " << "|\n";
	}

	static void PrintStudentSubjectLine(clsSubject Subject)
	{
		cout << " |" << left << setw(20) << Subject.Name;
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Subject.FirstMark;
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Subject.SecondMark;
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Subject.ThirdMark;
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Subject.Sum();
		cout << "|" << left << setw(15) << fixed << setprecision(2) << Subject.Average();
		cout << "|" << left << setw(15) << _GetPassOrFail(Subject.IsPass()) << "|\n";
	}

	static void _PrintStudentDetails(clsStudent Student)
	{
		cout << endl;

		cout << left << setw(33) << " " << "==================================================\n";

		cout << left << setw(33) << " " << "| Name: ";
		cout << left << setw(31) << Student.FullName();
		cout << left << "ID: " << setw(6) << Student.ID() << "|\n";

		cout << " ======================================================================================================================\n";

		cout << " |" << left << setw(20) << "Subject Name";
		cout << "|" << left << setw(15) << "First Mark";
		cout << "|" << left << setw(15) << "Second Mark";
		cout << "|" << left << setw(15) << "Third Mark";
		cout << "|" << left << setw(15) << "Sum";
		cout << "|" << left << setw(15) << "Average";
		cout << "|" << left << setw(15) << "Result" << "|\n";

		cout << " ======================================================================================================================\n";

		PrintStudentSubjectLine(Student.Subjects.Quran);
		PrintStudentSubjectLine(Student.Subjects.Arabic);
		PrintStudentSubjectLine(Student.Subjects.English);
		PrintStudentSubjectLine(Student.Subjects.Computer);
		PrintStudentSubjectLine(Student.Subjects.Math);
		PrintStudentSubjectLine(Student.Subjects.Physics);
		PrintStudentSubjectLine(Student.Subjects.Chemistry);
		PrintStudentSubjectLine(Student.Subjects.Biology);

		cout << " ======================================================================================================================\n";

		cout << " |" << left << setw(14) << "Total Subjects";
		cout << "|" << left << setw(15) << "      Sum";
		cout << "|" << left << setw(15) << "    Average";
		cout << "|" << left << setw(16) << "  Final Result";
		cout << "|" << left << setw(52) << "                       Note" << "|\n";

		cout << " ======================================================================================================================\n";

		_PrintStudentFinalResultLine(Student);

		cout << " ======================================================================================================================\n\n";
	}

	enum enSearchOption
	{
		eByID = 1,
		eByName = 2,
		eGoBack = 3,
	};

	static short _ReadIDNumber()
	{
		cout << "\nEnter Student ID: ";
		short ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Enter Student ID Number: ");

		/*while (!clsStudent::IsStudentExist(ID))
		{
			cout << "\nStudent With ID[" << ID << "] is not Found Enter Another ID:";

			ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Invalid ID Try Again : ");
		}*/

		return ID;
	}

	static string _ReadName()
	{
		cout << "\nEnter Student Name: ";

		return clsInputValidate::ReadString();
	}

	static enSearchOption _ReadSearchOption()
	{
		cout << "\n [1] Find By ID";
		cout << "\n [2] Find By Name";
		cout << "\n [3] Go Back\n";

		cout << "\n Enter What To Do? ";

		return (enSearchOption)clsInputValidate::ReadNumberbetween<short>(1, 3, " Enter What To Do? ");
	}

	static void _FindAndPrintStudentDetails(enSearchOption Option)
	{
		if (Option == enSearchOption::eByID)
		{
			short ID = _ReadIDNumber();

			clsStudent Student = clsStudent::FindByID(ID);

			if (Student.IsEmpty())
			{
				cout << "\nStudent With ID Number [" << ID << "] is not Found.\n\n";
			}

			else
			{
				_PrintStudentDetails(Student);
			}

		}

		else if (Option == enSearchOption::eByName)
		{
			string Name = _ReadName();

			vector<clsStudent> vStudents = clsStudent::FindByName(Name);

			if (vStudents.size() == 0)
			{
				cout << "\nStudent With Name [" << Name << "] is not Found.\n\n";
			}

			else
			{
				for (clsStudent Student : vStudents)
					_PrintStudentDetails(Student);
			}

		}

		return;
	}

public:

	static void ShowStudentMarksScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageStudents))
			return;
		
		char Answer = 'N';

		string Title = "\t\t Show Student Marks Screen";

		do
		{

			_DrawScreenHeader(Title);

			enSearchOption Option = _ReadSearchOption();

			if (Option == enSearchOption::eGoBack)
				return;

			_FindAndPrintStudentDetails(Option);

			cout << "Do You Want To Show Another Student Marks? Y/N? ";

			Answer = 'N';

			cin >> Answer;

		} while (toupper(Answer) == 'Y');
	}

};

