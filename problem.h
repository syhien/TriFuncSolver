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
	bool error;
	double answer;
	Problem()
	{
		error = 0;
		answer = 0;
	}
	friend ostream& operator<<(ostream& out, const Problem& x)
	{
		out << x.problem_string;
		out << "=" << fixed << setprecision(8) << x.answer, out << defaultfloat;;
		return out;
	}
};

void CheckProblem(Problem& problem);
void SolveProblem(Problem& problem);
void ProblemPrintWithError(Problem problem);