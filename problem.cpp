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
	//预处理操作数的负号
	bool problem_read_finish = 0;
	while (!problem_read_finish)
	{
		for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
		{
			if (i + 1 == problem.problem.end())
				problem_read_finish = 1;
			if (i->c == '-')
			{
				if ((i == problem.problem.begin() or i - 1 >= problem.problem.begin()) and i + 1 != problem.problem.end())
				{
					if (i == problem.problem.begin() and (i + 1)->c == 'n')
					{
						i++;
						i->n *= -1;
						problem.problem.erase(i - 1);
						break;
					}
					else if (((i - 1)->c == '(' or (i - 1)->c == 's' or (i - 1)->c == 'c' or (i - 1)->c == 't') and (i + 1)->c == 'n')
					{
						i++;
						i->n *= -1;
						problem.problem.erase(i - 1);
						break;
					}
				}
			}
		}
	}
	//删除表达式开头的多余空格
	while (problem.problem[0].c == ' ')
		problem.problem.erase(problem.problem.begin());
	while (problem.problem[problem.problem.size() - 1].c == ' ')
		problem.problem.pop_back();
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
	//3：操作符后不能是右括号
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (isoperater(i->c))
		{
			if (i + 1 != problem.problem.end())
			{
				if ((i + 1)->c == ')')
				{
					i->error = 1, i->error_type = 3;
					error_exist = 1;
				}
			}
		}
	}
	//4：操作符后不能是操作符
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (isoperater(i->c))
		{
			if (i + 1 != problem.problem.end())
			{
				if (isoperater((i + 1)->c))
				{
					i->error = 1, i->error_type = 4;
					error_exist = 1;
				}
			}
		}
	}
	//5：三角函数后不能是右括号
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == 's' or i->c == 'c' or i->c == 't')
		{
			if (i + 1 != problem.problem.end())
			{
				if ((i + 1)->c == ')')
				{
					i->error = 1, i->error_type = 5;
					error_exist = 1;
				}
			}
		}
	}
	//6：数字中出现空格
	problem_read_finish = 0;
	while (!problem_read_finish)
	{
		for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
		{
			if (i + 1 == problem.problem.end())
			{
				problem_read_finish = 1;
			}
			if (i->c == ' ')
			{
				if (i - 1 >= problem.problem.begin() and i + 1 != problem.problem.end())
				{
					if ((i - 1)->c == 'n' and (i + 1)->c == 'n')
					{
						(i - 1)->error = (i + 1)->error = 1;
						(i - 1)->error_type = (i + 1)->error_type = 6;
						error_exist = 1;
					}
					else
					{
						problem.problem.erase(i);
						break;
					}
				}
			}
		}
	}
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
	case 3:
		cout << "操作符后不能接右括号\n";
		break;
	case 4:
		cout << "操作符后不能接操作符\n";
		break;
	case 5:
		cout << "三角函数后不能是右括号\n";
		break;
	case 6:
		cout << "有空格的运算数是非法的\n";
		break;
	default:
		cout << "不是合法的输入\n";
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
