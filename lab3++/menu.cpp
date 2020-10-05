#include "menu.h"

#define OPTS_NUM 5

typedef void (*opt_t)(function&);
	
static const opt_t OPTS[OPTS_NUM] =
{
	&SetPoint,
	&PrintTable,
	&MinMax,
	&TypeF,
	&Interpolation

};

void dialog(function& table)
{
	while (true) {
		menu();

		int choice = 0;
		choice = GetNumber<int>("Your choice: ");
		std::cout << std::endl;

		if (!choice)
			break;

		else if (choice < 0 || choice > OPTS_NUM)
			std::cout << "[WARNING] Wrong option" << std::endl << std::endl;

		else
			OPTS[choice - 1](table);
	}
}

void menu()
{
	std::cout <<
		"0. Exit" << std::endl <<
		"1. Set Table" << std::endl <<
		"2. Print Table" << std::endl <<
		"3. Min and Max" << std::endl <<
		"4. Type Function" << std::endl <<
		"5. Interpolation" << std::endl;
}

void SetPoint(function& table) {
	int i = 0;
	double x, y = 0;
	i = GetNumber<int>("How many element do you want add? ");
	for (int l = 0; l < i; l++) {
		x = GetNumber<double>("Enter x = ");
		y = GetNumber<double>("Enter y = ");
		int e = table.SetPoint(x, y);
		if(e == -1)
			std::cout << "Table is full" << std::endl << std::endl;
		else if ( e == -2)
			std::cout << "This item has been added" << std::endl << std::endl;
		else std::cout << "The addition was successful" << std::endl << std::endl;
	}
}

void PrintTable(function& table) {
	table.GetTable();
}

void MinMax(function& table) {
	double a, b;
	table.GetMinMax(&a, &b);
	std::cout << "Min: " << a << std::endl;
	std::cout << "Max: " << b << std::endl << std::endl;
}

void TypeF(function& table) {
	int i = table.GetType();
	if (i == -3)
		std::cout << "Table is free " << std::endl << std::endl;
	else if (i == -2)
		std::cout << "The function of the variable " << std::endl << std::endl;
	else if (i == -1)
		std::cout << "The function is decreasing " << std::endl << std::endl;
	else if (i == 0)
		std::cout << "The function is constant " << std::endl << std::endl;
	else if (i == 1)
		std::cout << "The function is increasing " << std::endl << std::endl;
}

void Interpolation(function& table) {
	double x = GetNumber<double>("Enter x = ");
	std::cout << "y = " << table.GetInterpolation(x) << std::endl << std::endl;
}