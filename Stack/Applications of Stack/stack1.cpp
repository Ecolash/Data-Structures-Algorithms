#include <iostream>
#include <stack>

using namespace std;

int calculate(string s)
{
    int n = s.size();
    stack<int> st;

    int sign = 1;
    int current = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            current = s[i] - '0';
            while (i + 1 < n && isdigit(s[i + 1]))
            {
                current = (current * 10) + (s[i + 1] - '0');
                i++;
            }

            current = current * sign;
            ans += current;
            current = 0;
        }
        else if (s[i] == '+')
            sign = 1;
        else if (s[i] == '-')
            sign = -1;

        else if (s[i] == '(')
        {
            st.push(ans);
            st.push(sign);

            sign = 1;
            current = 0;
            ans = 0;
        }

        else if (s[i] == ')')
        {
            int prevSign = st.top();
            ans = ans * prevSign;
            st.pop();

            int prevAns = st.top();
            ans += prevAns;
            st.pop();
        }
    }
    return ans;
}

int main()
{
    cout << "Enter expression to evaluate (+ AND -) :";
    string s;
    cin >> s;

    int ans = calculate(s);
    cout << "ANS : " << ans << endl;
    return 0;
}