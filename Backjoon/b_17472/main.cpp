#include <iostream>
#include <algorithm>
#include <queue>

#define INSIDE ty < N && tx < M && ty >= 0 && tx >= 0 
#define OUTSIDE y >= N || x >= M || y < 0 || x < 0 
#define MIN 987654321

using namespace std;

int map[10][10], map2[10][10], N, M, n = 1;
int con[10][10];
int way[2][4] = {
    -1, 0, 1, 0,
    0, 1, 0, -1
};

struct pos {
    int x, y;
    pos(int _y, int _x) : x(_x), y(_y){}
};

struct bridge {
    int p1, p2, len;
    bridge(int _p1, int _p2, int _len) : p1(_p1), p2(_p2), len(_len){}

    bool operator < (const bridge& b) const {
        return len > b.len;
    }
};

vector<bridge> bs;



void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << map2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print2() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << con[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void bfs(int y, int x) {
    queue<pos> q;
    int ty, tx;
    q.push(pos(y, x));
    while(!q.empty()) {
        pos p = q.front();
        q.pop();
        map[p.y][p.x] = 0;
        map2[p.y][p.x] = n;
        for (int i = 0; i < 4; ++i) {
            ty = p.y + way[0][i];
            tx = p.x + way[1][i];
            if(INSIDE && map[ty][tx] == 1) {
                q.push(pos(ty, tx));
            }
        }
    }
}

void simulation(int y, int x, int w, int island) {
    int a = 1;

    while(map2[y][x] == 0) {
        y += way[0][w];
        x += way[1][w];
        if(OUTSIDE) return;
        a++;
    }
    a--;
    if(map2[y][x] > 0 && a > 1){
        if(con[island][map2[y][x]] == 0 || con[island][map2[y][x]] > a){
            con[island][map2[y][x]] = a;
        }
        if(con[map2[y][x]][island] == 0 || con[map2[y][x]][island] > a){
            con[map2[y][x]][island] = a;
        }
    }
}

void findShortest(int y, int x) {
   
    int ty, tx;

    for (int i = 0; i < 4; ++i) {
        ty = y + way[0][i];
        tx = x + way[1][i];
        if(INSIDE && map[ty][tx] == 0) {
            simulation(ty, tx, i, map2[y][x]);
        }
    }

}

int mst() {
    bool checked[10] = {0,};
    int rn = 1;
    int ans = 0;
    int nn = 1;
    priority_queue<bridge> s; 
    checked[1] = true;
    
    while(nn < n-1) {
        for(int i= 1; i < n; ++i) {
            if(con[rn][i] > 0 && !checked[i]) {
                s.push(bridge(rn, i, con[rn][i]));
            }
        }
        if(s.empty()) {
            ans = -1; 
            break;
        }
        while(!s.empty()){
            bridge b = s.top();
            s.pop();
            if(!checked[b.p2]) {
                rn = b.p2;
                nn++;
                ans += b.len;
                checked[b.p2] = true;
                break;
            }
        }
       
    }

    return ans;
}

int main() {

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map[i][j]) {
                bfs(i,j);
                n++;
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map2[i][j] > 0)
                findShortest(i, j);
        }
    }
    
    
    cout << mst() << "\n";

    return 0;
}