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
		cout << "\n��������ʽ���м��㣨�ո��س��������ʽ���룩���ϡ��·�����鿴�����¼\n��ESC�˳�����\n";
		fflush(stdin);
		char ch = _getch();
		if (ch == 38 or ch == 40)//38up 40down
		{

		}
		else if (ch == 27)//esc
		{
			exit = 1;
			cout << "�˳�����\n";
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
				if (c == 's')//sin
				{
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������sin��\n";
						break;
					}
					if (c != 'i')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������sin��\n";
					}
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������sin��\n";
						break;
					}
					if (c != 'n')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������sin��\n";
					}
					if (!unknown_char)
						new_problem.problem.push_back({ 's',0 });
				}
				else if (c == 'c')//cos
				{
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������cos��\n";
						break;
					}
					if (c != 'o')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������cos��\n";
					}
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������cos��\n";
						break;
					}
					if (c != 's')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������cos��\n";
					}
					if (!unknown_char)
						new_problem.problem.push_back({ 'c',0 });
				}
				else if (c == 't')//tan
				{
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������tan��\n";
						break;
					}
					if (c != 'a')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������tan��\n";
					}
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������tan��\n";
						break;
					}
					if (c != 'n')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������tan��\n";
					}
					if (!unknown_char)
						new_problem.problem.push_back({ 't',0 });
				}
				else if (c == 'p')//pi
				{
					c = problem_string[++i];
					if (i == problem_string.length())
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������pi��\n";
						break;
					}
					if (c != 'i')
					{
						unknown_char = 1;
						cout << "�������󣬻�����Ҫ�������pi��\n";
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
				cout << "����ȷ�����룬������������ʽ\n";
				continue;
			}
			//DEBUG
			cout << new_problem << endl;
		}

	}
	return 0;
}