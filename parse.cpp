// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the function parseName. That function consumes all alphanumeric
// characters until the next whitespace and returns the name that those characters form.

#include <cctype>
#include <sstream>
#include <string>
using namespace std;

#include "parse.h"

string parseName(std::stringstream &in)
{
    char ch;
    std::string name = "";

    in >> std::ws;
    if (isalpha(in.peek()))
    {
        in >> ch;
        name += ch;
    }
    while (isalnum(in.peek()) || in.peek() == '_')
    {
        in >> ch;
        name += ch;
    }
    return name;
}