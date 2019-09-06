#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

bool moved[20001];
int anslist[20001];
int ma = -1;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    map<int, vector<int> > g;
    queue<pair<int, int> > q;
    
    for(auto v : edge) {
        int a1 = v[0]; int a2 = v[1];
        if(g.find(a1) == g.end()) {
            g.insert({a1, vector<int>()});
        }
        if(g.find(a2) == g.end) {
            g.insert({a2, vector<int>()});
        }
        g.find(a1)->second.push_back(a2);
        g.find(a2)->second.push_back(a1);
    }
    
    q.push({1, 0});
    moved[1] = true;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int t = p.first;
        int pp = p.second + 1;
        if(g.find(t) == g.end()) continue;
        auto aaa = g.find(t)->second;
        for(int b : aaa) {
            if(!moved[b]) {
                moved[b] = true;
                q.push({b, pp});
                if(pp == ma) {
                    answer++;
                } else if(pp > ma)  {
                    answer = 1;
                    ma = pp;
                }
                
            }
        }
    }
    
    return answer;
}
int main() {
    vector<vector<int> > vb;
    
    vb.push_back({3,6});      
    vb.push_back({4,3});
    vb.push_back({3,2});
    vb.push_back({1,3});
    vb.push_back({1,2});
    vb.push_back({2,4});
    vb.push_back({5,2});


    solution(6, vb);


    return 0;
}