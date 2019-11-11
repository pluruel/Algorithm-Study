#include <iostream>
#include <queue>
#include <vector>

#define INF (1 << 31) -1
using namespace std;

int vdd[20002];

int V, E, st;

struct dist{
    int v, w;
    bool operator < (const dist &o ) const {
        return w > o.w;
    }
};


vector< vector<dist>> con;
priority_queue<dist> q;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> st;
    for (int i = 0; i <= V; ++i) {
        con.push_back(vector<dist>());
        vdd[i] = INF;
    }
    for (int i = 0; i < E; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        con[u].push_back({v, w});
    }
    vdd[st] = 0;
    q.push({st, 0});
    while(q.size()) {
        dist d = q.top(); q.pop();
        int p = d.v, ww = d.w;
        if(ww > vdd[p]) continue;
        for (dist nd : con[p]) {
            int ndd = nd.w + ww;
            if(vdd[nd.v] > ndd){ 
                q.push({nd.v, ndd});
                vdd[nd.v] = ndd;
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if(vdd[i] == INF) cout << "INF\n"; 
        else cout << vdd[i] << '\n';
    }
    return 0;
}