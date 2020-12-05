#include "problem.h"
#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

inline bool isoperater(char c)
{
	if (c == '+' or c == '-' or c == '*' or c == '/')
		return 1;
	return 0;
}

void CheckProblem(Problem& problem)
{
	//Ԥ����������ĸ���
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
	//ɾ�����ʽ��ͷ�Ķ���ո�
	while (problem.problem[0].c == ' ')
		problem.problem.erase(problem.problem.begin());
	while (problem.problem[problem.problem.size() - 1].c == ' ')
		problem.problem.pop_back();
	//1�����ʽ��ͷ
	auto problem_begin = problem.problem.begin();
	if (problem_begin->c == 'n' or problem_begin->c == 's' or problem_begin->c == 'c' or problem_begin->c == 't' or problem_begin->c == '(')
	{
		//OK
	}
	else
	{
		problem.problem[0].error = 1, problem.problem[0].error_type = 1;
		problem.error = 1;
	}
	//2�����ʽ��β
	auto problem_back = problem.problem.end() - 1;
	if (problem_back->c == 'n' or problem_back->c == ')')
	{
		//OK
	}
	else
	{
		problem.problem[problem.problem.size() - 1].error = 1, problem.problem[problem.problem.size() - 1].error_type = 2;
		problem.error = 1;
	}
	//3��������������������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (isoperater(i->c))
		{
			if (i + 1 != problem.problem.end())
			{
				if ((i + 1)->c == ')')
				{
					i->error = 1, i->error_type = 3;
					problem.error = 1;
				}
			}
		}
	}
	//4�������������ǲ�����
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (isoperater(i->c))
		{
			if (i + 1 != problem.problem.end())
			{
				if (isoperater((i + 1)->c))
				{
					i->error = 1, i->error_type = 4;
					problem.error = 1;
				}
			}
		}
	}
	//5�����Ǻ���������������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == 's' or i->c == 'c' or i->c == 't')
		{
			if (i + 1 != problem.problem.end())
			{
				if ((i + 1)->c == ')')
				{
					i->error = 1, i->error_type = 5;
					problem.error = 1;
				}
			}
		}
	}
	//6�������г��ֿո�
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
						problem.error = 1;
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
	//7�����ֺ�����������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == 'n')
		{
			if ((i + 1) != problem.problem.end() and (i + 1)->c == '(')
			{
				i->error = 1, i->error_type = 7;
				problem.error = 1;
			}
		}
	}
	//8�����ֺ��������Ǻ���
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == 'n')
		{
			if ((i + 1) != problem.problem.end() and ((i + 1)->c == 's' or (i + 1)->c == 'c' or (i + 1)->c == 't'))
			{
				i->error = 1, i->error_type = 8;
				problem.error = 1;
			}
		}
	}
	//9�������ź�����������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == '(')
		{
			if ((i + 1) != problem.problem.end() and (i + 1)->c == ')')
			{
				i->error = 1, i->error_type = 9;
				problem.error = 1;
			}
		}
	}
	//10�������ź����������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == '(')
		{
			if ((i + 1) != problem.problem.end() and isoperater((i + 1)->c))
			{
				i->error = 1, i->error_type = 10;
				problem.error = 1;
			}
		}
	}
	//11�������ź�����������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == ')')
		{
			if ((i + 1) != problem.problem.end() and (i + 1)->c == '(')
			{
				i->error = 1, i->error_type = 11;
				problem.error = 1;
			}
		}
	}
	//12�������ź�����������
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == ')')
		{
			if ((i + 1) != problem.problem.end() and (i + 1)->c == 'n')
			{
				i->error = 1, i->error_type = 12;
				problem.error = 1;
			}
		}
	}
	//13�������ź��������Ǻ���
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c == ')')
		{
			if ((i + 1) != problem.problem.end() and ((i + 1)->c == 's' or (i + 1)->c == 'c' or (i + 1)->c == 't'))
			{
				i->error = 1, i->error_type = 13;
				problem.error = 1;
			}
		}
	}
	//14����������ƥ��
	stack < vector<Item>::iterator > bracket;
	for (auto i = problem.problem.begin(); i != problem.problem.end(); i++)
	{
		if (i->c != '(' and i->c != ')')
			continue;
		if (i->c == '(')
		{
			bracket.push(i);
		}
		if (i->c == ')')
		{
			if (bracket.empty())
			{
				i->error = 1, i->error_type = 14;
				problem.error = 1;
			}
			else
				bracket.pop();
		}
	}
	while (!bracket.empty())
	{
		auto i = bracket.top();
		bracket.pop();
		i->error = 1, i->error_type = 14;
		problem.error = 1;
	}
}

inline void PrintErrorInfo(int error_type)
{
	switch (error_type)
	{
	case 1:
		cout << "���ʽ��ͷ�Ƿ�\n";
		break;
	case 2:
		cout << "���ʽ��β�Ƿ�\n";
		break;
	case 3:
		cout << "��������ܽ�������\n";
		break;
	case 4:
		cout << "����������������\n";
		break;
	case 5:
		cout << "���Ǻ���������������\n";
		break;
	case 6:
		cout << "�пո���������ǷǷ���\n";
		break;
	case 7:
		cout << "������������������\n";
		break;
	case 8:
		cout << "���������������Ǻ���\n";
		break;
	case 9:
		cout << "�����ڵ����ݲ���Ϊ��\n";
		break;
	case 10:
		cout << "�����ź����������\n";
		break;
	case 11:
		cout << "�����ź�����������\n";
		break;
	case 12:
		cout << "�����ź�����������\n";
		break;
	case 13:
		cout << "�����ź��������Ǻ���\n";
		break;
	case 14:
		cout << "�������Ų�ƥ��\n";
		break;
	default:
		cout << "���ǺϷ�������\n";
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

void SolveProblem(Problem& problem)
{
	int in_priority[150], out_priority[150];
	fill(in_priority, in_priority + 150, 0);
	fill(out_priority, out_priority + 150, 0);
	in_priority['('] = 1, in_priority['s'] = in_priority['c'] = in_priority['t'] = 7, in_priority['*'] = in_priority['/'] = 5, in_priority['+'] = in_priority['-'] = 3;
	out_priority['('] = 9, out_priority['s'] = out_priority['c'] = out_priority['t'] = 8, out_priority['*'] = out_priority['/'] = 6, out_priority['+'] = out_priority['-'] = 4, out_priority[')'] = 1;
	stack<char> mid_to_back;
	queue<Item> back;
	stack<double> solve_number;
	for (auto i : problem.problem)
	{
		if (i.c == 'n')
			back.push(i);
		else
		{
			if (i.c == ')')
			{
				while (mid_to_back.top() != '(')
					back.push({ mid_to_back.top(),0,0,0 }), mid_to_back.pop();
				mid_to_back.pop();
			}
			else
			{
				while (!mid_to_back.empty() and in_priority[mid_to_back.top()] >= out_priority[i.c])
					back.push({ mid_to_back.top(),0,0,0 }), mid_to_back.pop();
				mid_to_back.push(i.c);
			}
		}
	}
	while (!mid_to_back.empty())
		back.push({ mid_to_back.top(),0,0,0 }), mid_to_back.pop();
	while (!back.empty())
	{
		double x, y;
		switch (back.front().c)
		{
		case 'n':
			solve_number.push(back.front().n);
			break;
		case '+':
			y = solve_number.top(), solve_number.pop();
			x = solve_number.top(), solve_number.pop();
			solve_number.push(x + y);
			break;
		case '-':
			y = solve_number.top(), solve_number.pop();
			x = solve_number.top(), solve_number.pop();
			solve_number.push(x - y);
			break;
		case '*':
			y = solve_number.top(), solve_number.pop();
			x = solve_number.top(), solve_number.pop();
			solve_number.push(x * y);
			break;
		case '/':
			y = solve_number.top(), solve_number.pop();
			x = solve_number.top(), solve_number.pop();
			if (y == 0)
			{
				problem.error = 1;
				return;
			}
			else
				solve_number.push(x / y);
			break;
		case 's':
			y = solve_number.top(), solve_number.pop();
			solve_number.push(sin(y));
			break;
		case 'c':
			y = solve_number.top(), solve_number.pop();
			solve_number.push(cos(y));
			break;
		case 't':
			y = solve_number.top(), solve_number.pop();
			solve_number.push(tan(y));
			break;
		default:
			break;
		}
		back.pop();
	}
	problem.answer = solve_number.top();
}
