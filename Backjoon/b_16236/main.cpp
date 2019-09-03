#include <iostream>
#include <queue>

using namespace std;

int wy[4] = { -1, 0, 0, 1};
int wx[4] = { 0, -1, 1, 0};

struct pos{
    int x, y;
    pos(int _x, int _y) {
        x = _x; y = _y;
    }
    bool operator < (const pos& p1) const {
        if(y == p1.y) return x > p1.x;
        return y > p1.y;
    }
    
};

int map[20][20], N, sx, sy, ss = 2, sg = 0, ans;
int bfsm[20][20];
int visited[20][20];
int judge(int x, int y) {
    if (y >= N || x >= N || y < 0 || x < 0) {
        return 0;
    }
    else if (visited[y][x] || map[y][x] > ss) {
        return 0;
    }
    else {
        return 1;
    }
}

bool bfs() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bfsm[i][j] = 0;
            visited[i][j] = false;
        }
    }
    priority_queue<pos> q;
    vector<pos> vv;
    vv.push_back(pos(sx, sy));   
    int n = 0;
    visited[sy][sx] = true;
    
    // 
    while(!vv.empty()) {
        for(pos pp : vv) {
            q.push(pp);
        }
        vv.clear();
        while(!q.empty()){
            pos p = q.top();
            q.pop();
            int py = p.y, px = p.x;
            if (map[py][px] > 0 && map[py][px] < ss)  {
                
                ans += bfsm[py][px];
                map[py][px] = 0;
                sy = py; sx = px;
                
                sg++;
                if(sg == ss) {
                    sg = 0; 
                    ss++;
                }
                return true;
            } 
            for(int i = 0; i < 4;++i) {
                int ny = py + wy[i]; int nx = px + wx[i];
                int res = judge(nx, ny);
                if(res == 1) {
                    vv.push_back(pos(nx, ny));
                    visited[ny][nx] = true;
                    bfsm[ny][nx] = bfsm[py][px] + 1;
                } 
            }
        }
        
        // print();
        
    }
    
    return false;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                sy = i; sx = j;
            }
        }
    }
    map[sy][sx] = 0;
    while(bfs());

    cout << ans << '\n';
    return 0;
}