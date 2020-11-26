#pragma once
#include <vector>
using namespace std;
struct Item
{
	char c;
	double n;
};

struct Problem
{
	vector <Item> problem;
	double answer;
};

struct ErrorInfo
{
	int error_position;
	int error_type;
};

bool CheckProblem(Problem problem);
ErrorInfo FindError(Problem problem);
double SolveProblem(Problem problem);
void ViewProblem(Problem problem);