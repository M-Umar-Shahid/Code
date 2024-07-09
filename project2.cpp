// project2.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>
using namespace std;

// #include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream &in);

int main()
{
	const int SIZE = 256;
	Expression *expression;
	char paren, comma, line[SIZE];

	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open()))
	{
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}
	while (true)
	{
		fin.getline(line, SIZE);
		if (!fin)
			break;
		stringstream in(line, ios_base::in);
		in >> paren;
		cout << line << " ";
		try
		{
			// symbolTable.init(); // Initialize (clear) the symbol table
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			cout << "Value = " << result << endl;
		}
		catch (const std::exception &e)
		{
			cout << "Error: " << e.what() << endl;
		}
	}
	system("pause");
	return 0;
}

void parseAssignments(stringstream &in)
{
	char assignop, delimiter;
	string variable;
	double value;
	unordered_set<string> assignedVariables;
	do
	{
		variable = parseName(in);
		if (assignedVariables.find(variable) != assignedVariables.end())
		{
			throw std::runtime_error("Variable '" + variable + "' is assigned more than once.");
		}
		assignedVariables.insert(variable);
		in >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}
