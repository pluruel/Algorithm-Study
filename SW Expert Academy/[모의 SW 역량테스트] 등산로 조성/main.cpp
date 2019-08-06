#include <iostream>
#include <vector>

using namespace std;

int wx[4] = {0, 1, 0, -1};
int wy[4] = {1, 0, -1 , 0};

int map[8][8];
bool map2[8][8];

int T, N, K, maxi, ans;

struct pos{
    int x, y;
    pos(const int _x, const int _y) : x(_x), y(_y){}
};

vector<pos> v;

void init() {
    v.clear();
    maxi = 0;
    ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            map[i][j] = 0;
            map2[i][j] = 0; 
        }
    }
}

void dfs(int x, int y, bool card, int depth) {
    map2[y][x] = 1;
    ans = max(depth, ans);
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + wx[i]; int ny = y + wy[i];
        if(map2[ny][nx] || nx >= N || ny >= N || ny < 0 || nx < 0) continue;
        else if(map[ny][nx] < map[y][x]){
            dfs(x + wx[i], y + wy[i], card, depth + 1);
        } else if(map[ny][nx] - K < map[y][x] && card){
            int pre = map[ny][nx];
            map[ny][nx] = map[y][x] - 1;
            dfs(x + wx[i], y + wy[i], 0, depth + 1);
            map[ny][nx] = pre;
        }
    }
    map2[y][x] = 0;
}


void simulation() {

    for (int i = 0; i < v.size(); ++i) {
        pos p = v.at(i);
        dfs(p.x, p.y, true, 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int z = 1; z <= T; ++z) {
        init();
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> map[i][j];
                if(maxi < map[i][j]) {
                    v.clear();
                    maxi = map[i][j];
                    v.push_back(pos(j, i));
                } else if (maxi == map[i][j]) {
                    v.push_back(pos(j, i));
                }
            }
        }
        simulation();

        cout << "#" << z << " " << ans << "\n";
    }


    return 0;
}