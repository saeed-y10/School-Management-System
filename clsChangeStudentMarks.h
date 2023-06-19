#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsStudent.h"
#include "clsSubject.h"

class clsChangeStudentMarks : protected clsScreen
{

private:

	enum enWhatMarkToChangeOption
	{
		eFirstMark = 1,
		eSecondMark = 2,
		eThirdMark = 3,
		eAllMarks = 4,
		emGoBack = 5,
	};

	enum enWhatSubjectToChangeOption
	{
		eQuran = 1,
		eArabic = 2,
		eEnglish = 3,
		eComputer = 4,
		eMath = 5,
		ePhysics = 6,
		eChemistry = 7,
		eBiology = 8,
		eAll = 9,
		esGoBack = 10,
	};

	static enWhatMarkToChangeOption _ReadWhatMarkToChangeOption()
	{
		short Option;

		cout << "\n1 - First Mark.\n";
		cout << "2 - Second Mark.\n";
		cout << "3 - Third Mark.\n";
		cout << "4 - All Marks.\n";
		cout << "5 - Go Back.\n";

		cout << "\nEnter What Mark Do You Want To Change? ";

		Option = clsInputValidate::ReadShortNumberBetween(1, 5, "\nEnter What Mark Do You Want To Change? ");

		return (enWhatMarkToChangeOption)Option;
	}

	static enWhatSubjectToChangeOption _ReadWhatSubjectToChangeOption()
	{
		short Option;

		cout << "\n1 - Quran\n";
		cout << "2 - Arabic\n";
		cout << "3 - English\n";
		cout << "4 - Computer\n";
		cout << "5 - Math\n";
		cout << "6 - Physics\n";
		cout << "7 - Chemistry\n";
		cout << "8 - Biology\n";
		cout << "9 - All\n";
		cout << "10- Go Back\n";

		cout << "\nEnter What Subject Do You Want To Change? ";

		Option = clsInputValidate::ReadShortNumberBetween(1, 10, "\nEnter What Subject Do You Want To Change? ");

		return (enWhatSubjectToChangeOption)Option;
	}

	static short _ReadIDNumber()
	{
		cout << "Enter Student ID Number: ";
		short ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Enter Student ID Number: ");

		/*while (!clsStudent::IsStudentExist(ID))
		{
			cout << "\nStudent With ID[" << ID << "] is not Found Enter Another ID:";

			ID = clsInputValidate::ReadNumberbetween<short>(1, SHRT_MAX, "Invalid ID Try Again : ");
		}*/

		return ID;
	}

	static string _GetPassOrFail(bool Result)
	{
		return (Result ? "Pass" : "Fail");
	}

	static float _ReadMark(string Message)
	{
		cout << Message;

		return clsInputValidate::ReadFloatNumberBetween(0, 100, Message);
	}

	static void _ChangeMarks(clsSubject& Subject, enWhatMarkToChangeOption Option)
	{
		clsUtil::ResetScreen();

		cout << "\nChange " << Subject.Name << " Marks:\n";
		cout << "_________________________________________\n\n";

		switch (Option)
		{

		case enWhatMarkToChangeOption::eAllMarks:

			Subject.FirstMark = _ReadMark("Enter First Mark : ");
			Subject.SecondMark = _ReadMark("Enter Second Mark: ");
			Subject.ThirdMark = _ReadMark ("Enter Third Mrak : ");
			break;

		case enWhatMarkToChangeOption::eFirstMark:

			Subject.FirstMark = _ReadMark("Enter First Mark: ");
			break;

		case enWhatMarkToChangeOption::eSecondMark:

			Subject.SecondMark = _ReadMark("Enter Second Mark: ");
			break;

		case enWhatMarkToChangeOption::eThirdMark:

			Subject.ThirdMark = _ReadMark("Enter Third Mark: ");
			break;

		default:
			break;
		}
	}

	static void _ChangeSubject(clsStudent& Student, enWhatSubjectToChangeOption SubjectsOption, enWhatMarkToChangeOption MarksOption)
	{
		switch (SubjectsOption)
		{
		case enWhatSubjectToChangeOption::eAll:

			_ChangeMarks(Student.Subjects.Arabic, MarksOption);
			_ChangeMarks(Student.Subjects.Biology, MarksOption);
			_ChangeMarks(Student.Subjects.Chemistry, MarksOption);
			_ChangeMarks(Student.Subjects.Computer, MarksOption);
			_ChangeMarks(Student.Subjects.English, MarksOption);
			_ChangeMarks(Student.Subjects.Math, MarksOption);
			_ChangeMarks(Student.Subjects.Physics, MarksOption);
			_ChangeMarks(Student.Subjects.Quran, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eArabic:

			_ChangeMarks(Student.Subjects.Arabic, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eBiology:

			_ChangeMarks(Student.Subjects.Biology, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eChemistry:

			_ChangeMarks(Student.Subjects.Chemistry, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eComputer:

			_ChangeMarks(Student.Subjects.Computer, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eEnglish:

			_ChangeMarks(Student.Subjects.English, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eMath:

			_ChangeMarks(Student.Subjects.Math, MarksOption);
			break;

		case enWhatSubjectToChangeOption::ePhysics:

			_ChangeMarks(Student.Subjects.Physics, MarksOption);
			break;

		case enWhatSubjectToChangeOption::eQuran:

			_ChangeMarks(Student.Subjects.Quran, MarksOption);
			break;

		default:
			break;
		}
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

	static void ShowChangeStudentMarks()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateStudent))
			return;

		string Title = "\t\t Change Student Marks Screen";

		_DrawScreenHeader(Title);

		short ID = _ReadIDNumber();

		clsStudent Student = clsStudent::FindByID(ID);


		if (!Student.IsEmpty())
		{
			_PrintStudentCard(Student);

			char Answer = 'N';

			cout << "Are You Sure To Update This Student? Y/N? ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{

				enWhatSubjectToChangeOption SubjectToChangeOption = _ReadWhatSubjectToChangeOption();

				if (SubjectToChangeOption == enWhatSubjectToChangeOption::esGoBack)
					return;

				enWhatMarkToChangeOption MarksToChangeOption = _ReadWhatMarkToChangeOption();

				if (MarksToChangeOption == enWhatMarkToChangeOption::emGoBack)
					return;

				_ChangeSubject(Student, SubjectToChangeOption, MarksToChangeOption);

				clsStudent::enSaveResult SaveResult = Student.Save();

				switch (SaveResult)
				{

				case clsStudent::eFaildEmpty:

					cout << "\nUpdate Failed.\n";
					break;

				case clsStudent::eFaildIDNotExist:

					cout << "\nChange Failed.\n";
					break;

				case clsStudent::eSuccessful:

					cout << "\nChanged Successfuly.\n";
					break;

				default:
					cout << "\nChange Failed.\n";

					break;
				}
			}
		}

		else
		{
			cout << "\nStudent With ID Number [" << ID << "] is not Found.\n";
		}

	}

};

