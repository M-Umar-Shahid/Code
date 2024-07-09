class Negate : public SubExpression
{
public:
    Negate(Expression *left) : SubExpression(left, nullptr) {}
    double evaluate()
    {
        return -left->evaluate();
    }
};