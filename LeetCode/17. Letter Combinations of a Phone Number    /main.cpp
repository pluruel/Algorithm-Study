#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Solution {
public:
    char c[10][5]  = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
            
    };
    
    int nn[10] = {0,0,3,3,3,3,3,4,3,4};
    int input[10];
    int N;
    
    void construct(vector<string> &a, string cre, int depth) {
        if (depth == N) {
            a.push_back(cre);
            return;
        }
        
        int pos = input[depth];
        
        for (int i = 0; i < nn[pos]; ++i) {
            if(i == 0) cre.push_back(c[pos][i]);
            else cre[depth] = c[pos][i];
            construct(a, cre, depth + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int i = 0;
        for (char c : digits) {
            input[i++] = c-'0';
        }
        N = digits.size();
        
        vector<string> a;
        string ss;
        construct(a, ss, 0);
        
        return a;
    }
};

int main() {
    Solution s;

    for (string ss :s.letterCombinations("23")) {
        cout << ss << ", ";
    }
    cout << endl;
}