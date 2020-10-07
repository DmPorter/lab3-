#include"tablef.h"
#include"menu.h"
#include"util.h"
#include <iostream>

double f(double x) {
	return x * x;
}

int main() {
	//double a[20] = { -4,-3,-2,-1, 0 ,1,2,3,4,5,6,7,8,9,10, -5 ,-6,-7,-8,-9 };
	//function table1(a, &f);
	function table;
	//table.add(table1);
	dialog(table);
	return 0;
}