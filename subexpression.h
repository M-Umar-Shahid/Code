// subexpression.h
#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

#include "expression.h"
#include <sstream>

class SubExpression : public Expression
{
public:
    SubExpression(Expression *left, Expression *right);
    static Expression *parse(std::stringstream &in);

protected:
    Expression *left;
    Expression *right;
};

#endif
