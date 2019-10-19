#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

struct pp{
    int p1, p2, len;
    bool operator < (const pp &o) const {
        return len > o.len;
    }
};

int pa[1001];

int getp(int n ) {
    if(pa[n] == n) return n;
    else return pa[n] = getp(pa[n]);
}

priority_queue<pp> q;
int mst() {
    int con = 1, ans = 0, cnt = 0;
    while(cnt != N-1){
        pp p = q.top();
        q.pop();
        int p1 = getp(p.p1), p2 = getp(p.p2);
        if(p1 != p2) {
            pa[p1] = p2;
            cnt++;
            ans += p.len;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) pa[i] = i; 
    for (int i = 0; i < M; ++i) {
        int p1, p2, len;
        cin >> p1 >> p2 >> len;
        q.push({p1,p2,len});
    }

    cout << mst() << '\n';

    return 0;
}