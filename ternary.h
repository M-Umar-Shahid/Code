class Ternary : public SubExpression
{
public:
    Ternary(Expression *left, Expression *middle, Expression *right) : SubExpression(left, right), middle(middle) {}
    double evaluate()
    {
        return left->evaluate() ? middle->evaluate() : right->evaluate();
    }

private:
    Expression *middle;
};