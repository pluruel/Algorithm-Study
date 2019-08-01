#include <iostream>
#include <queue>
using namespace std;
int N, M, R, C, L;
int map[50][50], map2[50][50];

// 1시간 10분

int pipe[8][4] = { 
    0,0,0,0,
    1,1,1,1,
    1,0,1,0,
    0,1,0,1,
    1,1,0,0,
    0,1,1,0,
    0,0,1,1,
    1,0,0,1
};


class Pos {
public:
    int x, y;
    Pos(int _y, int _x) {
        x = _x;
        y = _y;
    }
};

queue<Pos> q;


int getmovex(int i) {
    if (i == 1) return 1;
    else if (i == 3) return -1;
    else return 0;
}

int getmovey(int i) {
    if (i == 0) return -1;
    else if (i == 2) return 1;
    else return 0;
}

int getans() { 
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map2[i][j] <= L && map2[i][j] > 0) ans++;
        }
    }
    return ans;
}


void bfs(Pos p) {
    q.push(p);
    map2[p.y][p.x] = 1;
    while(!q.empty()) {
        Pos cur = q.front();
        int x = cur.x, y = cur.y;
        int pre = map2[y][x];
        for (int i = 0; i < 4; ++i) {
            if(pipe[map[y][x]][i]) {    
                int m_x = x+getmovex(i);
                int m_y = y+getmovey(i);
                if(m_x >= M || m_y >= N || m_x < 0 || m_y < 0 ) {
                    continue;
                }
                else if (pipe[map[m_y][m_x]][(i+2)%4] && !map2[m_y][m_x]) {
                    map2[m_y][m_x] = map2[y][x] + 1;
                    q.push(Pos(m_y,m_x));
                }
            }
        }
        q.pop();
    }
    
}

void input() {
    cin >> N >> M >> R >> C >> L;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            map2[i][j] = 0;
            cin >> map[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        input();
        bfs(Pos(R, C));
        cout << "#" << z << " " << getans() << "\n";
    }
    return 0;
}
