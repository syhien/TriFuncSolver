#pragma once
#include <vector>
#include <iomanip>
#include <Windows.h>
using namespace std;
struct Item
{
	char c;
	double n;
	bool error;
	int error_type;
};

struct Problem
{
	string problem_string;
	vector <Item> problem;
	double answer;
	friend ostream& operator<<(ostream& out, const Problem& x)
	{
		for (auto& i : x.problem)
			switch (i.c)
			{
			case 'n':
				if (i.n == 3.1415926)
					out << "pi";
				else
					out << i.n;
				break;
			case 's':
				out << "sin";
				break;
			case 'c':
				out << "cos";
				break;
			case 't':
				out << "tan";
				break;
			default:
				out << i.c;
				break;
			}
		out << "=" << fixed << setprecision(8) << x.answer;
		return out;
	}
	bool error;
};

bool CheckProblem(Problem& problem);
double SolveProblem(Problem problem);
void ViewProblem(Problem problem);
void ProblemPrintWithError(Problem problem);