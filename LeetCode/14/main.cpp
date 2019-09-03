#include <iostream>
#include <map>
#include <vector>

using namespace std;


class trie {
public:
    char c;
    map<char, trie> nexts;
    trie(char _c) : c(_c){}
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        trie* root = new trie(NULL);
        for(string s : strs) {
            map<char, trie> *tr = &root->nexts;
            for(int i = 0; i < s.size(); ++i) {
                char c = s[i];
                if (c < 'a' || c > 'z') continue;
                if(tr->find(c) == tr->end()) {
                    tr->insert({c, trie(c)});  
                } 
                tr = &(tr->find(c)->second.nexts);
            }
            tr->insert({0, trie(0)});
        }
        
        if(root->nexts.size() == 1) {
            map<char, trie> *tr = &(root->nexts);
            while(tr->size() == 1) {
                ans += tr->begin()->first;
                tr = &(tr->begin()->second.nexts);
            }
        }
        
        return ans;
    }
};

int main() {
    vector<string> strs = {"a","aaa","aa"};

    Solution s;
    cout << s.longestCommonPrefix(strs) << "\n";
    return 0;
}