class Solution {
public:
    string longestPalindrome(string s) {
        int max = -1;
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            for(int j = 0; j + i < s.size() && i - j >= 0; ++j) {
                if(s.at(i + j) == s.at(i-j)) {
                    if(max < j * 2 + 1){
                        ans = s.substr(i-j, j*2 + 1);
                        max = (j * 2) + 1;
                    }
                } else {
                    break;
                }
            }
            for(int j = 1; j + i -1< s.size() && i - j >= 0; ++j) {
                if(s.at(i + j -1) == s.at(i-j)) {
                   if(max < j * 2){
                        ans = s.substr(i-j, j*2);
                        max = (j * 2);
                    }
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};