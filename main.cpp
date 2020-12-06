#include <iostream>
#include <cmath>
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "problem.h"
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	bool exit = 0;
	int view_problem;
	vector <Problem> problem;
	while (!exit)
	{
		cout << "\n请输入表达式进行计算（空格或回车结束表达式输入）或按上、下方向键进入查看计算记录界面\n按ESC退出程序\n";
		fflush(stdin);
		char ch = _getch();
		if (ch == -32)//72up 80down
		{
			cout << "按键查看成功计算的表达式，按上、下方向键切换，按ESC退出查看\n";
			if (problem.size() == 0)
			{
				cout << "没有成功计算的表达式\n";
				ch = _getch();
				continue;
			}
			bool exit_view = 0;
			int viewing;
			ch = _getch();
			if (ch == 72)
				viewing = problem.size() - 1;
			else if (ch == 80)
				viewing = 0;
			else
				continue;
			while (!exit_view)
			{
				cout << problem[viewing] << endl;
				ch = _getch();
				if (ch == 27)
				{
					exit_view = 1;
					cout << "退出查看表达式\n";
					continue;
				}
				else if (ch == -32)
				{
					ch = _getch();
					if (ch == 72)
					{
						viewing--;
						while (viewing < 0)
							viewing += problem.size();
					}
					else if (ch == 80)
					{
						viewing++;
						viewing %= problem.size();
					}
					else
						continue;
				}
			}
			continue;
		}
		else if (ch == 27)//esc
		{
			exit = 1;
			cout << "退出程序\n";
			continue;
		}
		else if (ch == 16)//shift
		{
			ch = _getch();
			if (ch == 57)//(
				ch = '(';
			else if (ch == 48)//)
				ch = ')';
		}
		cout << ch;
		Problem new_problem;
		bool unknown_char = 0;
		getline(cin, new_problem.problem_string);
		new_problem.problem_string = ch + new_problem.problem_string;
		for (int i = 0; i < new_problem.problem_string.length(); i++)
		{
			char c = new_problem.problem_string[i];
			if (c == 's' or c == 'S')//sin
			{
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是sin？\n";
					break;
				}
				if (c != 'i' and c != 'I')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是sin？\n";
				}
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是sin？\n";
					break;
				}
				if (c != 'n' and c != 'N')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是sin？\n";
				}
				if (!unknown_char)
					new_problem.problem.push_back({ 's',0,false,-1 });
			}
			else if (c == 'c' or c == 'C')//cos
			{
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是cos？\n";
					break;
				}
				if (c != 'o' and c != 'O')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是cos？\n";
				}
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是cos？\n";
					break;
				}
				if (c != 's' and c != 'S')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是cos？\n";
				}
				if (!unknown_char)
					new_problem.problem.push_back({ 'c',0,false,-1 });
			}
			else if (c == 't' or c == 'T')//tan
			{
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是tan？\n";
					break;
				}
				if (c != 'a' and c != 'A')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是tan？\n";
				}
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是tan？\n";
					break;
				}
				if (c != 'n' and c != 'N')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是tan？\n";
				}
				if (!unknown_char)
					new_problem.problem.push_back({ 't',0,false,-1 });
			}
			else if (c == 'p' or c == 'P')//pi
			{
				c = new_problem.problem_string[++i];
				if (i == new_problem.problem_string.length())
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是pi？\n";
					break;
				}
				if (c != 'i' and c != 'I')
				{
					unknown_char = 1;
					cout << "输入有误，或许想要输入的是pi？\n";
				}
				if (!unknown_char)
					new_problem.problem.push_back({ 'n',3.1415926,false,-1 });
			}
			else if (isdigit(c))
			{
				double number = c - '0';
				double decimal = 1.0;
				int count_point = 0;
				while (i + 1 < new_problem.problem_string.length() and (new_problem.problem_string[i + 1] == '.' or isdigit(new_problem.problem_string[i + 1])))
				{
					i++;
					if (new_problem.problem_string[i] == '.')
					{
						count_point++;
					}
					else if (!count_point)
					{
						number = number * 10 + (new_problem.problem_string[i] - '0');
					}
					else
					{
						decimal *= 0.1;
						number += (new_problem.problem_string[i] - '0') * decimal;
					}
				}
				new_problem.problem.push_back({ 'n',number,false,-1 });
				if (count_point > 1)
				{
					unknown_char = 1;
					cout << "输入了过多的小数点\n或许想要输入的是" << number << "?\n";
				}
			}
			else if (c == '+' or c == '-' or c == '*' or c == '/' or c == '(' or c == ')' or c == ' ')
			{
				new_problem.problem.push_back({ c,0,false,-1 });
			}
			else
			{
				unknown_char = 1;
			}
		}
		if (unknown_char)
		{
			cout << "不正确的输入，请重新输入表达式\n";
			continue;
		}
		CheckProblem(new_problem);
		if (new_problem.error)
		{
			cout << "表达式有误\n";
			ProblemPrintWithError(new_problem);
		}
		else
		{
			SolveProblem(new_problem);
			if (new_problem.error)
			{
				cout << "计算过程中出现了除以0！\n";
				continue;
			}
			cout << new_problem << endl;
			problem.push_back(new_problem);
		}
		while (problem.size() > 5)
			problem.erase(problem.begin());
	}
	return 0;
}