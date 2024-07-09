#include <cmath>
class Modulus : public SubExpression
{
public:
    Modulus(Expression *left, Expression *right) : SubExpression(left, right) {}
    double evaluate()
    {
        return fmod(left->evaluate(), right->evaluate());
    }
};