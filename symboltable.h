// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the SymbolTable class. The symbol table is represented
// with a vector (list) of type Symbol which is a pair consisting of a variable and its associated value.
// The body of its functions are defined in symboltable.cpp.

#include <string>
#include <unordered_map>
#include <stdexcept>
class SymbolTable
{
public:
    void insert(std::string variable, double value);
    double lookUp(std::string variable) const;
    void init(); // Add this method to initialize (clear) the symbol table
private:
    std::unordered_map<std::string, double> symbols;
};
