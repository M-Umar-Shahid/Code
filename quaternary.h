class Quaternary : public SubExpression
{
public:
    Quaternary(Expression *left, Expression *middle1, Expression *middle2, Expression *right)
        : SubExpression(left, right), middle1(middle1), middle2(middle2) {}
    double evaluate()
    {
        if (left->evaluate() < 0)
        {
            return middle1->evaluate();
        }
        else if (left->evaluate() == 0)
        {
            return middle2->evaluate();
        }
        else
        {
            return right->evaluate();
        }
    }

private:
    Expression *middle1;
    Expression *middle2;
};