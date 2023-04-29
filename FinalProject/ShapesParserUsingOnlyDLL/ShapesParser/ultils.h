#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

LPCWSTR ConvertStringToLPCWSTR(const std::string& str)
{
	int num_chars = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wide_str = new wchar_t[num_chars];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide_str, num_chars);
	return wide_str;
}
