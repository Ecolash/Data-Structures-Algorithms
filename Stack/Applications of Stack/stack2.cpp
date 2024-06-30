#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

int evaluate(string expression)
{
    int i;

    stack<int> operands;
    stack<char> operators;

    for (i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ')
            continue;

        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }

        else if (isdigit(expression[i]))
        {
            int val = 0;

            while (i < expression.length() && isdigit(expression[i]))
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }

            operands.push(val);
            i--;
        }

        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                int val2 = operands.top();
                operands.pop();

                int val1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                operands.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            if (!operators.empty())
                operators.pop();
        }

        // Current token is an operator.
        else
        {
            // While top of 'operators' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'operators' to top two elements in operands stack.
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i]))
            {
                int val2 = operands.top();
                operands.pop();

                int val1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                operands.push(applyOp(val1, val2, op));
            }

            // Push current token to 'operators'.
            operators.push(expression[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining operators to remaining
    // operands.
    while (!operators.empty())
    {
        int val2 = operands.top();
        operands.pop();

        int val1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        operands.push(applyOp(val1, val2, op));
    }

    // Top of 'operands' contains result, return it.
    return operands.top();
}

int main()
{
    string s;
    cin >> s;
    cout << evaluate(s) << "\n";
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}
