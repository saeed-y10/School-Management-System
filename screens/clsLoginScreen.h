#pragma once

#include <iostream>
#include "librarys/clsUtil.h"
#include "librarys/clsInputValidate.h"
#include "screens/clsScreen.h"
#include "core/clsUser.h"
#include "Global.h"
#include "screens/clsMainScreen.h";

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{
		string Username;
		string Password;

		short FaildLoginCount = 0;
		bool LoginFailed = false;

		do
		{
			

			if (LoginFailed)
			{
				FaildLoginCount++;

				if (FaildLoginCount == 5)
				{
					cout << "\nYou Are Locked After 5 Faild Trail(s).\n";

					return false;
				}

				else
				{
					cout << "\nInvalid Username/Password!";
					cout << "\nYou Have " << 5 - FaildLoginCount << " Trail(s) To Login." << "\n";
				}
			}

			cout << "\nUsername : ";
			Username = clsInputValidate::ReadString();

			cout << "Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::FindByID(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();

		clsMainMenuScreen::ShowMainMenu();
		
		return true;
	}

public:
	 
	static bool ShowLoginScreen()
	{
		clsUtil::ResetScreen();

		_DrawScreenHeader("\t\t     Login Screen");

		return _Login();
	}

};

