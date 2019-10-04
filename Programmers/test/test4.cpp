#include <string>
#include <vector>
#include <map>

using namespace std;

class trie {
public:
    char c;
    int n = 0;
    map<char, trie*> nexts;
    trie(char _c) : c(_c){}
    
};

int sum = 0;

void finds(trie* t, int depth, string &str, bool is) {
    
    if(depth == str.length()) {
        if(t->nexts.find(0) != t->nexts.end()) {
            sum++;
        }
        return;
    }
    
    if(str[depth] == '?') {
        if(depth != 0) {
            sum += t->n;
            return;
        } else {
            for(auto a: t->nexts) {
                finds(a.second, depth + 1, str, true);
            }
        }
    } else {
        if(t->nexts.find(str[depth]) != t->nexts.end()) {
            finds(t->nexts.find(str[depth])->second, depth + 1, str, false);
        } else {
            return;
        }
    }

}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    trie* root[10002];
    for(int i =0; i < 10002; i++ ) root[i] = new trie(NULL);
    for(string s : words) {
        map<char, trie*> *tr = &root[s.size()]->nexts;
        trie* ttt;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(tr->find(c) == tr->end()) {
                tr->insert({c, new trie(c)});  
            } 
            ttt = tr->find(c)->second;
            tr = &(tr->find(c)->second->nexts);
        }
        ttt->n++;
        tr->insert({0, new trie(0)});
    }

    for(string q : queries) {
        int temp = 0;
        sum = 0;
        trie* t = root[q.size()];
        finds(t, 0, q, false);
        answer.push_back(sum);
    }
    
    return answer;
}