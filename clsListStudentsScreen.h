#pragma once

#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsStudent.h"

class clsListStudentsScreen : protected clsScreen
{

private:

	static string _GetPassOrFail(bool Result)
	{
		return (Result ? "Pass" : "Fail");
	}

	static void PrintStudentRecord(clsStudent Student)
	{
		cout << " |" << left << setw(5) << Student.ID() << "|";
		cout << left << setw(20) << Student.FirstName << "|";
		cout << left << setw(20) << Student.LastName << "|";
		cout << left << setw(13) << Student.DateOfBirth.ToString() << "|";
		cout << left << setw(21) << Student.Email << "|";
		cout << left << setw(17) << Student.Phone << "|"; 
		cout << left << fixed << setprecision(2) << setw(7) << Student.Average() << "|";
		cout << left << setw(6) << _GetPassOrFail(Student.IsPass()) << "|";
	}

public:

	static void ShowListStudentsScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListStudents))
			return;

		clsUtil::ResetScreen();

		vector<clsStudent> vStudents = clsStudent::GetListStudents();

		string Title = "\t\t  Students List Screen";
		string SubTitle = "\t\t     (" + to_string(vStudents.size()) + ") Student(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n ______________________________________________________________________________________________________________________\n\n";
		cout << " |" << left << setw(5) << "ID";
		cout << "|" << left << setw(20) << "First Name";
		cout << "|" << left << setw(20) << "Last Name";
		cout << "|" << left << setw(13) << "Date of Birth";
		cout << "|" << left << setw(21) << "Email";
		cout << "|" << left << setw(17) << "Phone";
		cout << "|" << left << setw(7) << "Average";
		cout << "|" << left << setw(6) << "Status" << "|";
		cout << " \n ______________________________________________________________________________________________________________________\n\n";

		if (vStudents.size() == 0)
		{
			cout << " | " << left << setw(115) << "Sorry There Are No Students in The System!" << "|\n";
		}

		else
		{
			for (clsStudent Student : vStudents)
			{
				PrintStudentRecord(Student);

				cout << endl;
			}
		}

		cout << " ______________________________________________________________________________________________________________________\n";
	}

};

