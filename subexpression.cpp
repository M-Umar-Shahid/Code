// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "modulus.h"
#include "power.h"
#include "min.h"
#include "max.h"
#include "avg.h"
#include "negate.h"
#include "ternary.h"
#include "quaternary.h"
#include <sstream>

SubExpression::SubExpression(Expression *left, Expression *right)
{
    this->left = left;
    this->right = right;
}

Expression *SubExpression::parse(std::stringstream &in)
{
    Expression *left;
    Expression *right;
    char operation, paren;

    left = Operand::parse(in);
    in >> operation;

    if (operation == '~')
    {
        in >> paren;
        return new Negate(left);
    }
    else if (operation == '?')
    {
        Expression *middle = Operand::parse(in);
        right = Operand::parse(in);
        in >> paren;
        return new Ternary(left, middle, right);
    }
    else if (operation == '#')
    {
        Expression *middle1 = Operand::parse(in);
        Expression *middle2 = Operand::parse(in);
        right = Operand::parse(in);
        in >> paren;
        return new Quaternary(left, middle1, middle2, right);
    }
    else
    {
        right = Operand::parse(in);
        in >> paren;
        switch (operation)
        {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Multiply(left, right);
        case '/':
            return new Divide(left, right);
        case '%':
            return new Modulus(left, right);
        case '^':
            return new Power(left, right);
        case '<':
            return new Min(left, right);
        case '>':
            return new Max(left, right);
        case '&':
            return new Avg(left, right);
        }
    }
    return 0;
}
