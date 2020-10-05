#pragma once
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

struct Point {
	double x, y; 
	Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
};

class function
{
public:

	function(double x = 0, double y = 0, int i = 0);
	int SetPoint(double x, double y);
	int findPoint(double key, int a);
	void GetTable();
	void GetMinMax(double* a, double* b);
	int GetType();
	double GetInterpolation(double x);

private:

	static const int SZ = 20;
	Point P[SZ];
	int i;

};

