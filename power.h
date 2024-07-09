#include <cmath>
class Power : public SubExpression
{
public:
    Power(Expression *left, Expression *right) : SubExpression(left, right) {}
    double evaluate()
    {
        return pow(left->evaluate(), right->evaluate());
    }
};
