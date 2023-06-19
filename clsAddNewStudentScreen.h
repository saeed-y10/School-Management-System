#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsStudent.h"

class clsAddNewStudentScreen : protected clsScreen
{

private:

	static short _ReadIDNumber()
	{
		cout << "ID Number            : ";
		short ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "ID Number            : ");

		while (clsStudent::IsStudentExist(ID))
		{
			cout << "\nStudent With ID[" << ID << "] is Already Exist Enter Another ID:";

			ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Invalid ID Try Again : ");
		}

		return ID;
	}

	static clsStudent _ReadStudentInfo()
	{
		cout << "Enter Student Data:\n";
		cout << "__________________________________\n\n";

		clsStudent Student = clsStudent::GetNewStudentObject(_ReadIDNumber());

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

		return Student;
	}

	static void _AddNewStudent()
	{
		string Title = "\t\tAdd New Student Screen";
		
		_DrawScreenHeader(Title);

		clsStudent Student = _ReadStudentInfo();

		clsStudent::enSaveResult SaveResult = Student.Save();

		switch (SaveResult)
		{

		case clsStudent::enSaveResult::eFaildEmpty:
		{
			cout << "\nAdding was Failed Because The Object is Empty.\n";
			break;
		}

		case clsStudent::enSaveResult::eFaildIDExist:
		{
			cout << "\nAdding was Failed Because ID is Already Exists.\n";
			break;
		}

		case clsStudent::enSaveResult::eSuccessful:
		{
			cout << "\nStudent Added Successfuly.\n";
			break;
		}

		default:
		{
			cout << "\nAdding New Student was Failed Because it's Empty.\n";
			break;
		}

		}
	}

public:

	static void ShowAddNewStudentScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewStudent))
			return;

		char AddMore = 'N';

		do
		{
			AddMore = 'N';

			_AddNewStudent();

			cout << "\nTo Add More Students Enter Y/N? ";

			cin >> AddMore;

		} while (toupper(AddMore) == 'Y');
	
	}


};

