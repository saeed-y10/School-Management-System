#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsListStudentsMarksScreen.h"
#include "clsStudentMarksScreen.h"
#include "clsChangeStudentMarks.h"

class clsManageStudentsScreen : protected clsScreen
{

private:

	enum enManageStudentsMenuOptions
	{
		eAllStudentsMarks = 1,
		eShowStudentMarks = 2,
		eChangeStudentMarks = 3,
		eGoBackToMainMenu = 4,
	};

	static void _ShowAllStudentsMarksScreen()
	{
		clsListStudentsMarksScreen::ShowListStudentsMarks();
	}

	static void _ShowStudentMarksScreen()
	{
		clsStudentMarksScreen::ShowStudentMarksScreen();
	}

	static void _ShowChangeStudentMarksScreen()
	{
		clsChangeStudentMarks::ShowChangeStudentMarks();
	}

	static enManageStudentsMenuOptions _ReadManageStudentsMenuOption()
	{
		short Option;

		cout << "\t\t\t\t     Choose What Do You Want To Do? [1 To 4]? ";

		Option = clsInputValidate::ReadShortNumberBetween(1, 4, "\t\t\t\t     Choose What Do You Want To Do? [1 To 4]? ");

		return (enManageStudentsMenuOptions)Option;
	}

	static void _GoBackToManageStudentsMenu()
	{
		cout << "\nPress Any Key To Go Back To Manage Students Menu...\n";

		system("pause>0");

		ShowManageStudentsMenu();
	}

	static void _PerformManageStudentsMenuOption(enManageStudentsMenuOptions Option)
	{
		switch (Option)
		{

		case clsManageStudentsScreen::eAllStudentsMarks:

			_ShowAllStudentsMarksScreen();

			_GoBackToManageStudentsMenu();

			break;
		
		case clsManageStudentsScreen::eShowStudentMarks:

			_ShowStudentMarksScreen();

			_GoBackToManageStudentsMenu();

			break;
		
		case clsManageStudentsScreen::eChangeStudentMarks:

			_ShowChangeStudentMarksScreen();

			_GoBackToManageStudentsMenu();

			break;
		
		case clsManageStudentsScreen::eGoBackToMainMenu:
			
			return;
			break;
		
		default:
			return;
			break;

		}
	}

public:

	static void ShowManageStudentsMenu()
	{
		if (!CheckAccessRights(clsUser::pManageStudents))
			return;

		clsUtil::ResetScreen();

		_DrawScreenHeader("\t\t Manage Students Menu");

		cout << endl;

		cout << left << setw(37) << " " << "==============================================\n";
		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "         Manage Students Menu" << "|\n";
		cout << left << setw(37) << " " << "==============================================\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[1] List Students Marks." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[2] Show Student Marks." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[3] Change Student Marks." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[4] Go Back To Main Menu." << "|\n";

		cout << left << setw(37) << " " << "==============================================\n\n";

		_PerformManageStudentsMenuOption(_ReadManageStudentsMenuOption());
	}

};

