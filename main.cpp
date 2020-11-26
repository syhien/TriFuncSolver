#include <iostream>
#include <cmath>
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
#include "problem.h"
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
			string problem_string;
			cin >> problem_string;
			problem_string = ch + problem_string;
			for (int i = 0; i < problem_string.length(); i++)
			{
				char c = problem_string[i];
				if (c == 's' or c == 'S')//sin
				{
					c = problem_string[++i];
					if (i == problem_string.length())
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
					c = problem_string[++i];
					if (i == problem_string.length())
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
						new_problem.problem.push_back({ 's',0 });
				}
				else if (c == 'c' or c == 'C')//cos
				{
					c = problem_string[++i];
					if (i == problem_string.length())
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
					c = problem_string[++i];
					if (i == problem_string.length())
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
						new_problem.problem.push_back({ 'c',0 });
				}
				else if (c == 't' or c == 'T')//tan
				{
					c = problem_string[++i];
					if (i == problem_string.length())
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
					c = problem_string[++i];
					if (i == problem_string.length())
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
						new_problem.problem.push_back({ 't',0 });
				}
				else if (c == 'p' or c == 'P')//pi
				{
					c = problem_string[++i];
					if (i == problem_string.length())
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
						new_problem.problem.push_back({ 'n',3.1415926 });
				}
				else if (isdigit(c))
				{
					double number = c - '0';
					double decimal = 1.0;
					bool found_point = 0;
					while (i + 1 < problem_string.length() and (problem_string[i + 1] == '.' or isdigit(problem_string[i + 1])))
					{
						i++;
						if (problem_string[i] == '.')
						{
							found_point = 1;
						}
						else if (!found_point)
						{
							number = number * 10 + (problem_string[i] - '0');
						}
						else
						{
							decimal *= 0.1;
							number += (problem_string[i] - '0') * decimal;
						}
					}
					new_problem.problem.push_back({ 'n',number });
				}
				else if (c == '+' or c == '-' or c == '*' or c == '/' or c == '(' or c == ')')
				{
					new_problem.problem.push_back({ c,0 });
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
			//DEBUG
			cout << new_problem << endl;
		}
	}
	return 0;
}