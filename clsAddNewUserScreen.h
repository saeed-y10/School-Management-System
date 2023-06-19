#pragma once

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{
private:

	static int _ReadPermissions()
	{
		int Permissions = 0;

		char Answer = 'N';

		cout << "\nDo You Want To Give Full Access? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return clsUser::enPermissions::pAll;
		}

		cout << "\nDo You Want To Give Access To:\n";

		cout << "\nShow Students List? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions = clsUser::enPermissions::pListStudents;
		}

		cout << "\nAdd New Students? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewStudent;
		}

		cout << "\nDelete Students? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteStudent;
		}

		cout << "\nUpdate Students? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateStudent;
		}

		cout << "\nFind Students? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindStudent;
		}

		cout << "\nManage Students? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageStudents;
		}

		cout << "\nManage Users? Y/N? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name   : ";
		User.FirstName = clsInputValidate::ReadString();
		
		cout << "Enter Last Name    : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email        : ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone Number : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password     : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nRead Permissions:\n";
		User.Permissions = _ReadPermissions();
	}

	static void _PrintUser(clsUser User)
	{
	cout << "\nUser Card:\n";
	cout << "________________________________________\n";
	cout << "\nFirst Name  : " << User.FirstName;
	cout << "\nLast Name   : " << User.LastName;
	cout << "\nFull Name   : " << User.FullName();
	cout << "\nEmail       : " << User.Email;
	cout << "\nPhone       : " << User.Phone;
	cout << "\nUsername    : " << User.Username;
	cout << "\nPassword    : " << User.Password;
	cout << "\nPermissions : " << User.Permissions;
	cout << "\n________________________________________\n\n";
    }

	static void _ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::pManageUsers))
		{
			return;
		}

		string Title = "\t\t Add New User Screen";

		_DrawScreenHeader(Title);

		string Username;

		cout << "\nEnter Username? ";
		Username = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(Username))
		{
			cout << "\nUsername is Already Used, Enter Another One: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetNewUserObject(Username);

		cout << "\nAdding New User:\n";
		cout << "________________________________________\n";

		_ReadUserInfo(NewUser);

		cout << "________________________________________\n";

		clsUser::enSaveResult SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSucceeded:
		{
			cout << "\nUser Added, Successfully.\n";
			_PrintUser(NewUser);
			break;
		}

		case clsUser::enSaveResult::svEmptyFaild:
		{
			cout << "\nError User was not Added Because it's Empty.\n";
			break;
		}

		case clsUser::enSaveResult::svFaildUsernameExist:
		{
			cout << "\nError User was not Added Because Username is Already Exist.\n";
			break;
		}

		}
	}

public:

	static void ShowAddNewClientScreen()
	{
		_ShowAddNewClientScreen();
	}

};

