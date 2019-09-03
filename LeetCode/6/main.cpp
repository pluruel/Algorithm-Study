#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int aa[10];
        int i = 0;
        int ans = true;
        while(x) {
            aa[i++] = x %10;
            x/= 10;
        }
        int a = i /2, b = i / 2;
        if (0 == i % 2) {
            a--;
        }
        for (int j = 0; j <= i /2; j++)  {
            if(aa[a + j] != aa[b - j]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
   Solution s;
   cout << s.isPalindrome(100) << endl;
}