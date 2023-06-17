#pragma once

#include <iostream>
#include <iomanip>
#include "librarys/clsUtil.h"
#include "screens/clsScreen.h"
#include "core/clsStudent.h"

class clsListStudentsMarksScreen : protected clsScreen
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
		cout << "|" << left << setw(51) << " " << "|\n";
	}

	static void PrintStudentSubjectLine(clsSubject Subject)
	{
		cout << " |" << left << setw(20) << Subject.Name;
		cout << "|" << left << setw(18) << fixed << setprecision(2) << Subject.FirstMark;
		cout << "|" << left << setw(18) << fixed << setprecision(2) << Subject.SecondMark;
		cout << "|" << left << setw(18) << fixed << setprecision(2) << Subject.ThirdMark;
		cout << "|" << left << setw(18) << fixed << setprecision(2) << Subject.Average();
		cout << "|" << left << setw(18) << _GetPassOrFail(Subject.IsPass()) << "|\n";
	}

	static void _PrintStudentDetails(clsStudent Student)
	{
		cout << endl;

		cout << left << setw(33) << " " << "==================================================\n";

		cout << left << setw(33) << " " << "| Name: ";
		cout << left << setw(31) << Student.FullName();
		cout << left << "ID: " << setw(6) << Student.ID() << "|\n";

		cout << " =====================================================================================================================\n";

		cout << " |" << left << setw(20) << "Subject Name";
		cout << "|" << left << setw(18) << "First Mark";
		cout << "|" << left << setw(18) << "Second Mark";
		cout << "|" << left << setw(18) << "Third Mark";
		cout << "|" << left << setw(18) << "Average";
		cout << "|" << left << setw(18) << "Result" << "|\n";

		cout << " =====================================================================================================================\n";

		PrintStudentSubjectLine(Student.Subjects.Quran);
		PrintStudentSubjectLine(Student.Subjects.Arabic);
		PrintStudentSubjectLine(Student.Subjects.English);
		PrintStudentSubjectLine(Student.Subjects.Computer);
		PrintStudentSubjectLine(Student.Subjects.Math);
		PrintStudentSubjectLine(Student.Subjects.Physics);
		PrintStudentSubjectLine(Student.Subjects.Chemistry);
		PrintStudentSubjectLine(Student.Subjects.Biology);

		cout << " =====================================================================================================================\n";

		cout << " |" << left << setw(14) << "Total Subjects";
		cout << "|" << left << setw(15) << "      Sum";
		cout << "|" << left << setw(15) << "    Average";
		cout << "|" << left << setw(16) << "  Final Result";
		cout << "|" << left << setw(51) << "                       Note" << "|\n";

		cout << " =====================================================================================================================\n";

		_PrintStudentFinalResultLine(Student);

		cout << " =====================================================================================================================\n";
	}

public:

	static void ShowListStudentsMarks()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageStudents))
			return;

		vector<clsStudent> vStudents = clsStudent::GetListStudents();

		string Title = "\t\t Students Marks List Screen";
		string SubTitle = "\t\t     (" + to_string(vStudents.size()) + ") Student(s).";

		_DrawScreenHeader(Title, SubTitle);

		if (vStudents.size() == 0)
		{
			cout << " ______________________________________________________________________________________________________________________\n\n";
			cout << " | " << left << setw(115) << "Sorry There Are No Students in The System!" << "|\n";
			cout << " ______________________________________________________________________________________________________________________\n";
		}

		else
		{
			for (clsStudent Student : vStudents)
			{
				_PrintStudentDetails(Student);
			}
		}
	}

};

