#include <iostream>

#include <stack>
using namespace std;

class Solution
{
public:
    stack<bool> n;
    bool isminus[2];
    int divide(int dividend, int divisor)
    {
        if (dividend < 0)
        {
            isminus[0] = 1;
            dividend = -dividend;
        }
        if (divisor < 0)
        {
            isminus[1] = 1;
            divisor = -divisor;
        }

        int temp = divisor;
        for (int i = 0; temp < dividend; i++)
        {
            temp += temp;
        }
        temp >>= 1;
        int temp2 = dividend;
        while (temp2)
        {
            if (temp2 - temp > 0)
            {
                temp2 -= temp;
                n.push(1);
            }
            else
            {
                n.push(0);
            }
        }
        int nn = 1;
        int ans = 0;
        while (n.size())
        {
            ans += n.top() * nn;
            n.pop();
            nn <<= 1;
        }

        bool a = isminus[0] + isminus[1];
        return a ? -ans : ans;
    }
};

int main()
{
    Solution s;
    cout << s.divide(10, 3) << "\n";
}