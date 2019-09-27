#include <iostream>

using namespace std;

struct trie {
    trie *node[10];
    bool isend;
    int n = 0;
};

trie* getNewNode() {
    trie* nn = new trie();
    nn->isend = false;
    return nn;
}

bool insert(trie* root, char* s) {
    trie* t = root;
    
    for (int i = 0; s[i] != 0; i++) {
        char c = s[i];
        int p = c- '0';
        if(t->node[p] == NULL) {
           t->node[p] = getNewNode(); 
           t->n++;
        } 
        if(t->isend) 
            return false;
        t = t->node[p];
    }

    if(t->n > 0) {
        return false;
    }
    t->isend = true;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K;

    cin >> K;

    string anss[2] = {"NO", "YES"};
    char s[10001];
    for (int i = 0; i < K; ++i) {
        int n;
        cin >>n;
        bool ans = true;

        trie* root = getNewNode();
        for (int j = 0; j < n;++j) {
            cin >> s;
            ans &= insert(root, s);
        }
        cout << anss[ans] << "\n";

    }


}