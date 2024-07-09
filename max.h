class Max : public SubExpression
{
public:
    Max(Expression *left, Expression *right) : SubExpression(left, right) {}
    double evaluate()
    {
        return std::max(left->evaluate(), right->evaluate());
    }
};