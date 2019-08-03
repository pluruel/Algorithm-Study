#include <iostream>
#include <queue>

using namespace std;

int map[302][302];
int map2[302][302];
int N, ans;

class type {
public: 
    int i, j;
    type(int _i, int _j) {
        i = _i;
        j = _j;
    }
};

void bfs(int i, int j) {
    queue<type> q;
    q.push(type(i, j));
    map[i][j] = 10;
    while(!q.empty()) {
        type t = q.front();
        int y = t.i;
        int x = t.j;
        for(int i = -1; i <= 1; ++i) {
            int temp_y = y + i;
            if (temp_y > N || temp_y < 1) continue;
            for (int j = -1; j <= 1; ++j) {
                int temp_x = x + j;
                if (temp_x > N || temp_x < 1) continue;
                if(i || j) {
                    if(map[temp_y][temp_x] == 0) {
                        q.push(type(temp_y, temp_x));
                    }
                    map[temp_y][temp_x] = 10;
                }
            }
        }
        q.pop();
    }
}

void checkBomb(int y, int x) {
    for(int i = -1; i <= 1; ++i) {
        int temp_y = y + i;
        if (temp_y > N || temp_y < 1) continue;
        for (int j = -1; j <= 1; ++j) {
            int temp_x = x + j;
            if (temp_x > N || temp_x < 1) continue;
            if((i || j) && map[temp_y][temp_x] != -1 ) {
                map[temp_y][temp_x]++;
            }
        }
    }
}

void input() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            char c;
            cin >> c;
            if(c == '*') {
                map[i][j] = -1;
                checkBomb(i, j);
            }
        }
    }
}

void init() {
    ans = 0;
    for (int i = 0; i <= N+1; ++i) {
        for (int j = 0; j<= N+1; ++j) {
            map[i][j] = 0;
            map2[i][j] = 0;
        }
    }
}
void search() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j<= N; ++j) {
            if(map[i][j] == 0 ){
                bfs(i, j);
                ans++;
            } 
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j<= N; ++j) {
            if(map[i][j] > 0 && map[i][j] <10) {
                ans++;
            }
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
        cin >> N;
        init();
        input();
        search();
        
        cout << "#" << z << " " << ans << "\n";
    }
    return 0;
}
