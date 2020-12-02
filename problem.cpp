#include "problem.h"
#include <iostream>
#include <cmath>
using namespace std;

inline bool isoperater(char c)
{
	if (c == '+' or c == '-' or c == '*' or c == '/')
		return 1;
	return 0;
}

bool CheckProblem(Problem& problem)
{
	bool error_exist = 0;
	//1：表达式开头
	auto problem_begin = problem.problem.begin();
	if (problem_begin->c == 'n' or problem_begin->c == 's' or problem_begin->c == 'c' or problem_begin->c == 't' or problem_begin->c == '(')
	{
		//OK
	}
	else
	{
		problem.problem[0].error = 1, problem.problem[0].error_type = 1;
		error_exist = 1;
	}
	//2：表达式结尾
	auto problem_back = problem.problem.end() - 1;
	if (problem_back->c == 'n' or problem_back->c == ')')
	{
		//OK
	}
	else
	{
		problem.problem[problem.problem.size() - 1].error = 1, problem.problem[problem.problem.size() - 1].error_type = 2;
		error_exist = 1;
	}
	//3：操作符后不能是右括号和操作符
	
	return !error_exist;
}

inline void PrintErrorInfo(int error_type)
{
	switch (error_type)
	{
	case 1:
		cout << "表达式开头非法\n";
		break;
	case 2:
		cout << "表达式结尾非法\n";
		break;
	default:
		break;
	}
}

void ProblemPrintWithError(Problem problem)
{
	for (auto i : problem.problem)
	{
		if (i.error)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		switch (i.c)
		{
		case 'n':
			if (i.n == 3.1415926)
				cout << "pi";
			else
				cout << i.n;
			break;
		case 's':
			cout << "sin";
			break;
		case 'c':
			cout << "cos";
			break;
		case 't':
			cout << "tan";
			break;
		default:
			cout << i.c;
			break;
		}
		if (i.error)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	cout << endl;
	for (auto i : problem.problem)
	{
		if (i.error)
		{
			switch (i.c)
			{
			case 'n':
				if (i.n == 3.1415926)
					cout << "pi";
				else
					cout << i.n;
				break;
			case 's':
				cout << "sin";
				break;
			case 'c':
				cout << "cos";
				break;
			case 't':
				cout << "tan";
				break;
			default:
				cout << i.c;
				break;
			}
			PrintErrorInfo(i.error_type);
		}
	}
}
