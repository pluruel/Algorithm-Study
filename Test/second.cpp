#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class LL {
public:
    int n;
    LL* next;
    LL(int _n) : n(_n){}
};

class Data{
public:
    set<int> s;
    int cnt;
    Data(int _cnt, set<int> _s) {
        cnt = _cnt;
        s = _s;
    }
    bool operator < (Data b) const{
        return this->cnt > b.cnt;
    }
};

LL *init = new LL(-1);
LL *endnode = new LL(-1);
map<int, int> iv;

vector<int> answers;

void dequeue() {
    map<int, set<int>> cv;
    for(auto a : iv) {
        auto b = cv.find(a.second);
        if(b == cv.end()) {
            cv.insert({a.second, set<int>()});
            b = cv.find(a.second);
        } 
        b->second.insert(a.first);
    }
    vector<Data> v;
    for(auto a : cv) {
        v.push_back(Data(a.first, a.second));
    }
    sort(v.begin(), v.end());

    LL* p = init;
    
    auto sets = v[0].s;
    int target;
    while(true){
        if(sets.find(p->next->n) == sets.end()) {
            p = p->next;
        } else {
            target = p->next->n;
            p->next = p->next->next;
            answers.push_back(target);
            break;
        }
    }
    
    iv.find(target)->second--;
}

int main() {
    init->next = endnode;
    
    int N;

    cin >> N;

    for (int i =0; i < N; ++i) {
        string inputstr;
        cin >> inputstr;
        if(inputstr.compare("enqueue") == 0) {
            int inputint;
            cin >> inputint;
            auto found = iv.find(inputint);
            if(found == iv.end()) {
                iv.insert({inputint, 1});
            } else {
                found->second++;
            }
            LL *p = init;
            while(p->next != endnode) 
                p = p->next;
            p->next = new LL(inputint);
            p->next->next = endnode;
        } else if (inputstr.compare("dequeue") == 0) {
            dequeue();
        }

    }

    for(int answer : answers) {
        cout << answer << " ";    
    }

    cout << "\n";
	return 0;
}