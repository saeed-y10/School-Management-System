#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsSubject
{

private:
	
	string _Name;
	float _FirstMark;
	float _SecondMark;
	float _ThirdMark;

public:

	/*clsSubject()
	{
		_Name = "";
		_FirstMark = 0;
		_SecondMark = 0;
		_ThirdMark = 0;
	}*/

	clsSubject(string Name, float FirstMark = 0, float SecondMark = 0, float ThirdMark = 0)
	{
		_Name = Name;
		_FirstMark = FirstMark;
		_SecondMark = SecondMark;
		_ThirdMark = ThirdMark;
	}

	void SetName(string Name)
	{
		_Name = Name;
	}

	string GetName()
	{
		return _Name;
	}
	__declspec(property(get = GetName, put = SetName)) string Name;

	void SetFirstMark(float FirstMark)
	{
		_FirstMark = FirstMark;
	}

	float GetFirstMark()
	{
		return _FirstMark;
	}
	__declspec(property(get = GetFirstMark, put = SetFirstMark)) float FirstMark;

	void SetSecondMark(float SecondMark)
	{
		_SecondMark = SecondMark;
	}

	float GetSecondMark()
	{
		return _SecondMark;
	}
	__declspec(property(get = GetSecondMark, put = SetSecondMark)) float SecondMark;

	void SetThirdMark(float ThirdMark)
	{
		_ThirdMark = ThirdMark;
	}

	float GetThirdMark()
	{
		return _ThirdMark;
	}
	__declspec(property(get = GetThirdMark, put = SetThirdMark)) float ThirdMark;

	float Sum()
	{
		return (float)(_FirstMark + _SecondMark + _ThirdMark);
	}

	float Average()
	{
		return (float)(Sum() / 3);
	}
	
	bool IsPassFirstMark()
	{
		return (_FirstMark >= 50);
	}

	bool IsPassSecondMark()
	{
		return (_SecondMark >= 50);
	}

	bool IsPassThirdMark()
	{
		return (_ThirdMark >= 50);
	}

	bool IsPass()
	{
		return (Average() >= 50);
	}

};

