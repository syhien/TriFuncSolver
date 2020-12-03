#include <iostream>
#include <cmath>
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "problem.h"
#include <string>
using namespace std;

int main()
{
	bool exit = 0;
	int view_problem;
	vector <Problem> problem;
	while (!exit)
	{
		cout << "\n请输入表达式进行计算（空格或回车结束表达式输入）或按上、下方向键查看计算记录\n按ESC退出程序\n";
		fflush(stdin);
		char ch = _getch();
		if (ch == 38 or ch == 40)//38up 40down
		{

		}
		else if (ch == 27)//esc
		{
			exit = 1;
			cout << "退出程序\n";
			continue;
		}
		else//input
		{
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
					bool found_point = 0;
					while (i + 1 < new_problem.problem_string.length() and (new_problem.problem_string[i + 1] == '.' or isdigit(new_problem.problem_string[i + 1])))
					{
						i++;
						if (new_problem.problem_string[i] == '.')
						{
							found_point = 1;
						}
						else if (!found_point)
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
			bool legel_problem = CheckProblem(new_problem);
			if (!legel_problem)
			{
				cout << "表达式有误\n";
				ProblemPrintWithError(new_problem);
			}
			else
				cout << new_problem << endl;
		}
	}
	return 0;
}