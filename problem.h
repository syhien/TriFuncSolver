#pragma once
#include <vector>
#include <iomanip>
using namespace std;
struct Item
{
	char c;
	double n;
};

struct ErrorInfo
{
	int error_position;
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
			if (i.c != 'n')
				out << i.c;
			else
			{
				if (i.n == 3.1415926)
					out << "pi";
				else
					out << i.n;
			}
		out << "=" << fixed << setprecision(8) << x.answer;
		return out;
	}
	vector <ErrorInfo> error;
};

bool CheckProblem(Problem problem);
ErrorInfo FindError(Problem problem);
double SolveProblem(Problem problem);
void ViewProblem(Problem problem);