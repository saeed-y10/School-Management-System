#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsString.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsStudent.h"

class clsUpdateStudentScreen : private clsScreen
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

	static void _UpdateStudentInfo(clsStudent &Student)
	{
		cout << "Update Student Data:\n";
		cout << "__________________________________\n\n";

		cout << "First Name           : ";
		Student.FirstName = clsInputValidate::ReadString();

		cout << "Last Name            : ";
		Student.LastName = clsInputValidate::ReadString();

		cout << "Birth Date \'1/1/2022\': ";
		Student.DateOfBirth = clsInputValidate::ReadString();

		cout << "Email Address        : ";
		Student.Email = clsInputValidate::ReadString();

		cout << "Phone Number         : ";
		Student.Phone = clsInputValidate::ReadString();
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

	static void ShowUpdataStudentScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateStudent))
			return;

		string Title = "\t\t Update Student Screen";

		_DrawScreenHeader(Title);

		short ID = _ReadIDNumber();

		clsStudent Student = clsStudent::FindByID(ID);

		_PrintStudentCard(Student);

		char Answer = 'N';

		cout << "Are You Sure To Update This Student? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			_UpdateStudentInfo(Student);

			clsStudent::enSaveResult SaveResult = Student.Save();

			switch (SaveResult)
			{

			case clsStudent::eFaildEmpty:

				cout << "\nUpdate Failed.\n";
				break;

			case clsStudent::eFaildIDNotExist:

				cout << "\nUpdate Failed.\n";
				break;

			case clsStudent::eSuccessful:

				cout << "\nUpdated Successfuly.\n";
				break;
			
			default:
				cout << "\nUpdate Failed.\n";

				break;
			}
		}

		else
		{
			cout << "\nUpdated Canceled.\n";
		}

	}

};

