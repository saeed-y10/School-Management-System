#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsListStudentsScreen.h"
#include "clsAddNewStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsDeleteStudentScreen.h"
#include "clsFindStudentScreen.h"
#include "clsManageStudentsScreen.h"
#include "clsManageUsersScreen.h"

using namespace std;

class clsMainMenuScreen : protected clsScreen
{

private:
	
	enum enMainMenuOptions
	{
		eListStudents = 1,
		eAddNewStudent = 2,
		eUpdateStudent = 3,
		eDeleteStudent = 4,
		eFindStudent = 5,
		eManageStudents = 6,
		eManageUsers = 7,
		eLogout = 8,
		eExit = 9,
	};

	static enMainMenuOptions _ReadMainMenuOption()
	{
		short Option;

		cout << "\t\t\t\t     Choose What Do You Want To Do? [1 To 9]? ";

		Option = clsInputValidate::ReadShortNumberBetween(1, 9, "\t\t\t\t     Choose What Do You Want To Do? [1 To 9]? ");

		return (enMainMenuOptions)Option;
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nPress Any Key To Go Back To Main Menu...\n";

		system("pause>0");

		ShowMainMenu();
	}

	static void _PerformMainMenuOption(enMainMenuOptions Option)
	{
		switch (Option)
		{
		case clsMainMenuScreen::eListStudents:
			
			_ShowListStudentScreen();
			_GoBackToMainMenu();
			break;
			
		case clsMainMenuScreen::eAddNewStudent:
			
			_ShowAddNewStudentScreen();
			_GoBackToMainMenu();
			break;

		case clsMainMenuScreen::eUpdateStudent:
			
			_ShowUpdateStudentScreen();
			_GoBackToMainMenu();
			break;

		case clsMainMenuScreen::eDeleteStudent:
			
			_ShowDeleteStudentScreen();
			_GoBackToMainMenu();
			break;

		case clsMainMenuScreen::eFindStudent:

			_ShowFindStudentScreen();
			_GoBackToMainMenu();
			break;

		case clsMainMenuScreen::eManageStudents:

			_ShowManageStudentsScreen();
			_GoBackToMainMenu();
			break;

		case clsMainMenuScreen::eManageUsers:

			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;

		case clsMainMenuScreen::eLogout:

			_Logout();
			break;

		case clsMainMenuScreen::eExit:
			
			exit(1);
			break;

		default:
			
			_Logout();
			break;
		}
	}

	static void _Logout()
	{
		CurrentUser = clsUser::FindByID("", "");
	}

	static void _ShowListStudentScreen()
	{
		clsListStudentsScreen::ShowListStudentsScreen();
	}

	static void _ShowAddNewStudentScreen()
	{
		clsAddNewStudentScreen::ShowAddNewStudentScreen();
	}

	static void _ShowUpdateStudentScreen()
	{
		clsUpdateStudentScreen::ShowUpdataStudentScreen();
	}

	static void _ShowDeleteStudentScreen()
	{
		clsDeleteStudentScreen::ShowDeleteStudentScreen();
	}

	static void _ShowFindStudentScreen()
	{
		clsFindStudentScreen::ShowFindStudentScreen();
	}

	static void _ShowManageStudentsScreen()
	{
		clsManageStudentsScreen::ShowManageStudentsMenu();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}

public:

	static void ShowMainMenu()
	{
		clsUtil::ResetScreen();

		_DrawScreenHeader("\t\t       Main Menu");

		cout << endl;

		cout << left << setw(37) << " " << "==============================================\n";
		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "                Main Menu" << "|\n";
		cout << left << setw(37) << " " << "==============================================\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[1] Show All Students." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[2] Add New Student." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[3] Update Student." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[4] Delete Student." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[5] Find Student." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[6] Manage Students." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[7] Manage Users." << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[8] Logout" << "|\n";

		cout << left << setw(37) << " " << "| ";
		cout << left << setw(43) << "[9] Exit." << "|\n";

		cout << left << setw(37) << " " << "==============================================\n\n";

		_PerformMainMenuOption(_ReadMainMenuOption());
	}

};

