#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int w[2][4] = {-1, 0, 1, 0, 0, 1, 0 , -1};
int bm[50][50];
int amount = 0;
int ans = (1 << 31)-1;

struct po{
    int x, y;
    po(int _y, int _x) : x(_x), y(_y) {}
};

vector<po> v;
int viruses;
int map[50][50];

bool check(int y, int x) {
    if(y > N-1 || x > N-1 || x < 0 || y < 0 || map[y][x] == -1 || bm[y][x] == -2|| map[y][x] > 1) return false;
    else return true;
}
int list[12];
int bfs() {
    queue<po> q;
    
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            map[i][j] = bm[i][j];   
        }
    }
    int ju = amount;
    for (int i = 0; i < M; i++) {
        po p = v.at(list[i]);
        q.push(p);
        bm[p.y][p.x] = -2;
    }
    int thistime = 1;
    while(!q.empty() && ju != 0) {
        po p = q.front();
        q.pop();
        int px = p.x; int py =  p.y;
        for (int i = 0; i < 4; ++i) {
            int nx = px + w[1][i]; int ny = py + w[0][i];
            if(check(ny, nx)) {
                map[ny][nx] = map[py][px] + 1;
                
                thistime = map[ny][nx];
                q.push(po(ny, nx));
                if(!bm[ny][nx]) ju--;
            }
        }
            
        
    }


    if(ju != 0) 
    thistime = (1 << 31)-1;
    for (int i = 0; i < M; i++) {
        po p = v.at(list[i]);
        bm[p.y][p.x] = 1;
    }
    return thistime;
}

void combination(int depth, int p) {
    if(depth == M) {
        int temp = bfs();
        ans = min(temp, ans);
        return;
    }
    for (int i = p; i < viruses - M+depth + 1; ++i ) {
        list[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int temp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> temp;
            if(temp == 1) {
                bm[i][j] = -1;
                continue;
            }
            else if (temp == 2) {
                bm[i][j] = 1;
                viruses++;
                v.push_back(po(i, j));
            } 
            else {
                amount++;
            }
        }
    }

    combination(0,0);

    if(ans == (1 << 31)-1) {
        ans = 0;
    } 
    cout << --ans << "\n";

    
    
}