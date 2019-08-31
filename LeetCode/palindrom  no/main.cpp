#include <iostream>
#include <string>
using namespace std;

 class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int n = (numRows -1) * 2;
        int si = s.size();
        if(si == 1 || numRows == 1) {
            return s;
        }
        
        for (int i = 0; i < numRows; ++i) {
            int pos = i;
            for(int j = 0; pos < s.size(); j++) {
                ans += s[pos];
                if(i >= 0 && i < numRows && (pos - i) * 2 < s.size()) {
                    ans += s[(pos - i) * 2];
                }
                pos += n;
            }
        }
        return ans;
    }
};

int main() {
   Solution s;
   cout << s.convert("PAYPALISHIRING", 4) << endl;
}