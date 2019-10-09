#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[11][11];

int N, M;
int xw[] = {0,1,0,-1}, yw[] = {-1,0,1,0};
bool ck[11][11][11][11];

int by, bx, ry, rx;

int bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push({{by, bx}, {ry, rx}});
    ck[by][bx][ry][rx] = 1;

    int ans = 0;
    while(q.size()) {
        int size = q.size();
        while(size--){
            int oby = q.front().first.first;
            int obx = q.front().first.second;
            int ory = q.front().second.first;
            int orx = q.front().second.second;
            q.pop();
            if(map[ory][orx] == 'O' && map[obx][oby] != '0') {
                return ans;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nby = oby, nbx = obx, nry = ory, nrx = orx;
                while(map[nby][nbx] != 'O' && map[nby + yw[i]][nbx + xw[i]] != '#') {
                    nby += yw[i]; nbx += xw[i];
                }
                while(map[nry][nrx] != 'O' && map[nry + yw[i]][nrx + xw[i]] != '#') {
                    nry += yw[i]; nrx += xw[i];
                }
                
                if(nby == nry && nbx == nrx) {
                    if(map[nby][nbx] == 'O') continue;
                    if(i % 2) {
                        if(abs(obx - nbx) > abs(orx - nrx)) nbx -= xw[i];
                        else nrx -= xw[i];
                    } else {
                        if(abs(oby - nby) > abs(ory - nry)) nby -= yw[i];
                        else nry -= yw[i];
                    }
                }
                if(ck[nby][nbx][nry][nrx]) 
                    continue;
                ck[nby][nbx][nry][nrx] = 1;
                q.push({{nby, nbx}, {nry, nrx}});
            }
        }
        if(ans == 10) 
            return -1;
        ans++;
        
    }
    return -1;
 
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map[i][j] == 'R') {
                ry= i; rx = j;
                
            }
            else if(map[i][j] == 'B') {
                by= i; bx = j;
            }
        }
    }    
    
    cout << bfs() << "\n";
    return 0;
}