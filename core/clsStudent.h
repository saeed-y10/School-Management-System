#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "librarys/clsDate.h"
#include "librarys/clsString.h"
#include "clsPerson.h"
#include "core/clsSubject.h"
#include "Global.h"

using namespace std;

class clsStudent : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	struct stSubjects
	{
		short TotalSubjects = 8;
		clsSubject Quran = clsSubject("Quran");
		clsSubject Arabic = clsSubject("Arabic");
		clsSubject English = clsSubject("English");
		clsSubject Computer = clsSubject("Computer");
		clsSubject Math = clsSubject("Math");
		clsSubject Physics = clsSubject("Physics");
		clsSubject Chemistry = clsSubject("Chemistry");
		clsSubject Biology = clsSubject("Biology");
	};

	enMode _Mode;
	short _ID;
	clsDate _DateOfBirth;
	bool _MrakForDelete;

	static clsStudent _GetEmptyStudentObject()
	{
		return clsStudent(enMode::EmptyMode, 0, "", "", "", "", "");
	}

	static string _ConvrtStudentObjectToLine(clsStudent Student, string Seperator = "#//#")
	{
		string Line = "";

		Line += to_string(Student.ID()) + Seperator;
		Line += Student.FirstName + Seperator;
		Line += Student.LastName + Seperator;
		Line += (Student.DateOfBirth.ToString()) + Seperator;
		Line += Student.Email + Seperator;
		Line += Student.Phone + Seperator;

		Line += to_string(Student.Subjects.TotalSubjects) + Seperator;

		Line += to_string(Student.Subjects.Quran.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Quran.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Quran.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.Arabic.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Arabic.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Arabic.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.English.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.English.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.English.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.Computer.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Computer.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Computer.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.Math.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Math.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Math.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.Physics.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Physics.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Physics.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.Chemistry.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Chemistry.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Chemistry.GetThirdMark()) + Seperator;

		Line += to_string(Student.Subjects.Biology.GetFirstMark()) + Seperator;
		Line += to_string(Student.Subjects.Biology.GetSecondMark()) + Seperator;
		Line += to_string(Student.Subjects.Biology.GetThirdMark());

		return Line;
	}

	static clsStudent _ConvrtLineToStudentObject(string Line, string Seperator = "#//#")
	{
		vector<string> vLine = clsString::Split(Line, Seperator);

		clsStudent Student(enMode::UpdateMode, stoi(vLine[0]), vLine[1], vLine[2], vLine[3], vLine[4], vLine[5]);

		Student.Subjects.TotalSubjects = stoi(vLine[6]);
		Student.Subjects.Quran.FirstMark = stof(vLine[7]);
		Student.Subjects.Quran.SecondMark = stof(vLine[8]);
		Student.Subjects.Quran.ThirdMark = stof(vLine[9]);

		Student.Subjects.Arabic.FirstMark = stof(vLine[10]);
		Student.Subjects.Arabic.SecondMark = stof(vLine[11]);
		Student.Subjects.Arabic.ThirdMark = stof(vLine[12]);


		Student.Subjects.English.FirstMark = stof(vLine[13]);
		Student.Subjects.English.SecondMark = stof(vLine[14]);
		Student.Subjects.English.ThirdMark = stof(vLine[15]);

		Student.Subjects.Computer.FirstMark = stof(vLine[16]);
		Student.Subjects.Computer.SecondMark = stof(vLine[17]);
		Student.Subjects.Computer.ThirdMark = stof(vLine[18]);

		Student.Subjects.Math.FirstMark = stof(vLine[19]);
		Student.Subjects.Math.SecondMark = stof(vLine[20]);
		Student.Subjects.Math.ThirdMark = stof(vLine[21]);

		Student.Subjects.Physics.FirstMark = stof(vLine[22]);
		Student.Subjects.Physics.SecondMark = stof(vLine[23]);
		Student.Subjects.Physics.ThirdMark = stof(vLine[24]);

		Student.Subjects.Chemistry.FirstMark = stof(vLine[25]);
		Student.Subjects.Chemistry.SecondMark = stof(vLine[26]);
		Student.Subjects.Chemistry.ThirdMark = stof(vLine[27]);

		Student.Subjects.Biology.FirstMark = stof(vLine[28]);
		Student.Subjects.Biology.SecondMark = stof(vLine[29]);
		Student.Subjects.Biology.ThirdMark = stof(vLine[30]);

		return Student;
	}

	static vector<clsStudent> _LoadStudentsDataFromFile()
	{
		vector<clsStudent> vStudents;

		fstream File;

		File.open("Students.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsStudent Student = _ConvrtLineToStudentObject(Line);

				vStudents.push_back(Student);
			}

			File.close();
		}

		return vStudents;
	}

	static void _SaveStudentsDataToFile(vector<clsStudent> vStudents, string Seperator = "#//#")
	{
		fstream File;

		File.open("Students.txt", ios::out);

		if (File.is_open())
		{
			string Line;

			for (clsStudent Student : vStudents)
			{
				if (Student._MrakForDelete == false)
				{
					Line = _ConvrtStudentObjectToLine(Student, Seperator);
					File << Line << endl;
				}

			}

			File.close();
		}

	}

	static void _AddDataLineToFile(string FileName, string DataLine)
	{
		fstream File;

		File.open(FileName, ios::out | ios::app);

		if (File.is_open())
		{
			File << DataLine << endl;

			File.close();
		}
	}

	void _Update()
	{
		vector<clsStudent> vStudents = _LoadStudentsDataFromFile();

		for (clsStudent& Student : vStudents)
		{
			if (Student.ID() == _ID)
			{
				Student = *this;
				break;
			}
		}

		_SaveStudentsDataToFile(vStudents);
	}

	void _AddNew()
	{
		_AddDataLineToFile("Students.txt", _ConvrtStudentObjectToLine(*this));
	}

public:

	clsStudent(enMode Mode, short ID, string FirstName, string LastName, string DateOfBirth, string Email, string Phone)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_ID = ID;
		_MrakForDelete = false;

		/*short DateLength = clsString::Split(DateOfBirth, "/").size();
		
		if (DateLength < 3)
		{
			DateOfBirth = "0/0/0";
		}*/

		_DateOfBirth = clsDate::ToDate(DateOfBirth);
	}

	stSubjects Subjects;

	static clsStudent GetNewStudentObject(short ID)
	{
		return clsStudent(enMode::AddNewMode, ID, "", "", "", "", "");
	}

	short ID()
	{
		return _ID;
	}

	void SetDateOfBirth(string DateOfBirth)
	{
		_DateOfBirth = clsDate::ToDate(DateOfBirth);
	}

	clsDate GetDateOfBirth()
	{
		return _DateOfBirth;
	}
	__declspec(property(get = GetDateOfBirth, put = SetDateOfBirth)) clsDate DateOfBirth;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	float Sum()
	{
		float Sum = Subjects.Arabic.Average() + Subjects.Biology.Average()
			+ Subjects.Chemistry.Average() + Subjects.Computer.Average()
			+ Subjects.English.Average() + Subjects.Math.Average()
			+ Subjects.Physics.Average() + Subjects.Quran.Average();

		return Sum;
	}

	float Average()
	{
		return (float)(Sum() / Subjects.TotalSubjects);
	}

	bool IsPass()
	{
		return (Average() >= 50);
	}

	static clsStudent FindByID(string FullName)
	{
		fstream File;

		File.open("Students.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsStudent Student = _ConvrtLineToStudentObject(Line);

				if (Student.FullName() == FullName)
				{
					File.close();
					return Student;
				}
			}

			File.close();
		}

		return _GetEmptyStudentObject();
	}

	static vector<clsStudent> FindByName(string Name)
	{
		vector<clsStudent> vStudents;

		fstream File;

		File.open("Students.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsStudent Student = _ConvrtLineToStudentObject(Line);

				if (Student.FullName() == Name)
				{
					vStudents.push_back(Student);
				}
			}

			File.close();
		}

		return vStudents;
	}

	static clsStudent FindByID(short ID)
	{
		fstream File;

		File.open("Students.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsStudent Student = _ConvrtLineToStudentObject(Line);

				if (Student.ID() == ID)
				{
					File.close();

					return Student;
				}
			}

			File.close();
		}

		return _GetEmptyStudentObject();
	}

	static bool IsStudentExist(short ID)
	{
		return (!FindByID(ID).IsEmpty());
	}

	enum enSaveResult
	{
		eFaildEmpty = 0,
		eFaildIDExist = 1,
		eFaildIDNotExist = 2,
		eSuccessful = 3,
	};

	enSaveResult Save()
	{
		switch (_Mode)
		{

		case enMode::EmptyMode:
		{
			if (IsEmpty())
				return enSaveResult::eFaildEmpty;
		}

		case enMode::UpdateMode:
		{
			if (IsStudentExist(ID()))
			{
				_Update();

				return enSaveResult::eSuccessful;
			}

			else
			{
				return enSaveResult::eFaildIDNotExist;
			}
		}

		case enMode::AddNewMode:
		{
			if (IsStudentExist(ID()))
			{
				return enSaveResult::eFaildIDExist;
			}
			
			else
			{
				_Mode = enMode::UpdateMode;
				
				_AddNew();

				return enSaveResult::eSuccessful;
			}

		}

		default:
			return enSaveResult::eFaildEmpty;
			break;
		}
	}

	bool Delete()
	{
		vector<clsStudent> vStudents = _LoadStudentsDataFromFile();

		for (clsStudent& Student : vStudents)
		{
			if (Student.ID() == _ID)
			{
				Student._MrakForDelete = true;
				
				*this = _GetEmptyStudentObject();

				_SaveStudentsDataToFile(vStudents);

				return true;
			}
		}

		return false;
	}

	static vector<clsStudent> GetListStudents()
	{
		return _LoadStudentsDataFromFile();
	}

};

