#ifndef ___COMMON_H_
#define ___COMMON_H_


#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
using namespace std;

class _Common
{
public:
	_Common();
	~_Common();
	static void fixConsoleWindow();
	static void gotoXY(int, int);
};
#endif // !___COMMON_H_

