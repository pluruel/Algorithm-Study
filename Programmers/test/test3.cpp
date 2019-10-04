#include <string>
#include <vector>
#include <map>

using namespace std;

class trie {
public:
    char c;
    map<char, trie*> nexts;
    trie(char _c) : c(_c){}
    
};

int sum = 0;

void finds(trie* t, int depth, string &str) {
    
    if(depth == str.length()) {
        if(t->nexts.find(0) != t->nexts.end()) {
            sum++;
        }
        return;
    }
    
    if(str[depth] == '?') {
        for(auto a: t->nexts) {
            finds(a.second, depth + 1, str);
        }
    } else {
        if(t->nexts.find(str[depth]) != t->nexts.end()) {
            finds(t->nexts.find(str[depth])->second, depth + 1, str);
        } else {
            return;
        }
    }

}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    trie* root[10001];
    for(int i =0; i < 10000; i++ ) new trie(NULL);
    for(string s : words) {
        map<char, trie*> *tr = &root[s.size()]->nexts;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(tr->find(c) == tr->end()) {
                tr->insert({c, new trie(c)});  
            } 
            tr = &(tr->find(c)->second->nexts);
        }
        tr->insert({0, new trie(0)});
    }

    for(string q : queries) {
        int temp = 0;
        sum = 0;
        trie* t = root[q.size()];
        finds(t, 0, q);
        answer.push_back(sum);
    }
    
    return answer;
}