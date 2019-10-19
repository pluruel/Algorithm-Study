#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;

struct pp{
    int p, len;
    bool operator < (const pp &o) const {
        return len > o.len;
    }
};

vector<vector<int> > vv; 
int dist[1001][1001];
bool visited[1001];

int mst() {
    priority_queue<pp> q;
    visited[1] = 1;
    for (int i: vv[1]) {
        q.push({i, dist[1][i]});
    }
    int ans = 0;
    int nnn = 1;
    while(q.size() && nnn < N) {
        pp p = q.top();
        q.pop();
        if(visited[p.p]) continue;
        ans += p.len;
        visited[p.p] = 1;
        for (int i : vv[p.p]) {
            if(!visited[i]) 
                q.push({i, dist[p.p][i]});
        }
        nnn++;
        
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) vv.push_back(vector<int>()); 
    for (int i = 0; i < M; ++i) {
        int p1, p2, len;
        cin >> p1 >> p2 >> len;
        vv[p1].push_back(p2);
        vv[p2].push_back(p1);
        dist[p1][p2] = len;
        dist[p2][p1] = len;
    }

    cout << mst() << '\n';

    return 0;
}