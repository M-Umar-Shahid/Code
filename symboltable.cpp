// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SymbolTable class. The insert function
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name.

// symboltable.cpp
#include "symboltable.h"

void SymbolTable::insert(std::string variable, double value)
{
    symbols[variable] = value;
}

double SymbolTable::lookUp(std::string variable) const
{
    auto it = symbols.find(variable);
    if (it == symbols.end())
    {
        throw std::runtime_error("Variable '" + variable + "' is uninitialized.");
    }
    return it->second;
}

void SymbolTable::init()
{
    symbols.clear(); // Clear all entries in the symbol table
}
