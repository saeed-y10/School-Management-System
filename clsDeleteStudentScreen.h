#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsStudent.h"

class clsDeleteStudentScreen : protected clsScreen
{

private:

	static short _ReadIDNumber()
	{
		cout << "Enter Student ID Number: ";
		short ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Enter Student ID Number: ");

		while (!clsStudent::IsStudentExist(ID))
		{
			cout << "\nStudent With ID[" << ID << "] is not Found Enter Another ID:";

			ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Invalid ID Try Again : ");
		}

		return ID;
	}

	static void _PrintStudentCard(clsStudent Studenet)
	{
		cout << "\nStudent Card:\n";
		cout << "__________________________________\n";
		cout << "\nID Number    : " << Studenet.ID();
		cout << "\nFirst Name   : " << Studenet.FirstName;
		cout << "\nLast Name    : " << Studenet.LastName;
		cout << "\nDate of Birth: " << Studenet.DateOfBirth.ToString();
		cout << "\nEmail        : " << Studenet.Email;
		cout << "\nPhone        : " << Studenet.Phone;
		cout << "\n__________________________________\n\n";
	}

public:

	static void ShowDeleteStudentScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteStudent))
			return;

		string Title = "\t\t Delete Student Screen";

		_DrawScreenHeader(Title);

		short ID = _ReadIDNumber();

		clsStudent Student = clsStudent::FindByID(ID);

		_PrintStudentCard(Student);

		char Answer = 'N';

		cout << "Are You Sure To Delete This Student? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Student.Delete())
			{
				cout << "\nDeleted Successfuly.\n";
			}

			else
			{
				cout << "\nDelete Failed.\n";
			}

		}

		else
		{
			cout << "\nDelete Canceled.\n";
		}

	}

};

