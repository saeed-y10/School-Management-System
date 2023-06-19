#include <iostream>
#include "clsLoginScreen.h"

using namespace std;



int main()
{

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			exit(1);
	}

	return 0;
}