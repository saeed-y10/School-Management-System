#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsString.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsStudent.h"

class clsFindStudentScreen : protected clsScreen
{

private:

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
		cout << "\n__________________________________\n";
	}

	static void _FindByID()
	{

		short ID = _ReadIDNumber();

		clsStudent Student = clsStudent::FindByID(ID);

		if (Student.IsEmpty())
		{
			cout << "\nStudent With ID Number [" << ID << "] is not Found.\n";
		}

		else
		{
			_PrintStudentCard(Student);
		}

	}

	static void _FindByName()
	{

		string Name = _ReadName();

		vector<clsStudent> vStudents = clsStudent::FindByName(Name);

		if (vStudents.size() != 0)
		{
			for (clsStudent Student : vStudents)
			{
				_PrintStudentCard(Student);
			}
		}

		else
		{
			cout << "\nStudent With Name [" << Name << "] is not Found.\n";
		}

	}

public:

	static void ShowFindStudentScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindStudent))
			return;

		char Answer = 'N';

		string Title = "\t\t  Find Student Screen";
		
		do
		{
			_DrawScreenHeader(Title);

			enSearchOption Option = _ReadSearchOption();

			if (Option == enSearchOption::eByID)
			{
				_FindByID();
			}

			else if (Option == enSearchOption::eByName)
			{
				_FindByName();
			}

			else
			{
				return;
			}

			cout << "\nDo You Want To Find Another Student? Y/N? ";
			
			Answer = 'N';

			cin >> Answer;

		} while (toupper(Answer) == 'Y');

	}

};

