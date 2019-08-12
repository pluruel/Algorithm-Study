#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tree{
    int y; int x; int age;
    tree(int _y, int _x, int _age) {
        x = _x; y = _y; age = _age;
    }
};

int wy[9] = {-1, -1, -1, 0, 0, 1,1,1};
int wx[9] = {-1, 0, 1, -1, 1, -1,0,1};

int N, M, K, ans;
int map[12][12];
int map2[12][12];
deque<int> q[11][11];

bool isavailable(int x, int y) {
    if (x > N || y > N || x < 1 || y < 1) return false;
    return true;
}

bool cmp(int a, int b) {
    return a > b;
}

void print2() {
    cout << "\n";
    for (int i = 1; i <= N; ++i ) {
        for (int j = 1; j <= N; ++j) {
            cout << q[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


vector<tree> diedTree;

void growing(int s) {
    switch(s) {
        case 0:
        for (int i = 1; i <= N; ++i ) {
            for (int j = 1; j <= N; ++j) {
                vector<int> tv; 
                for (deque<int>::iterator k = q[i][j].end(); k != q[i][j].begin(); k--) {
                    int age = *k;
                    if(map[i][j] >= age) {
                        map[i][j] -= age;
                        age++;
                        tv.push_back(age);
                    } else {
                        diedTree.push_back(tree(i, j, age));
                    }
                }
                
                q[i][j].clear();
                for(vector<int>::iterator k = tv.end(); k != tv.begin(); --k) {
                    int temp = *k;
                    q[i][j].push_back(temp);
                } 
            tv.clear();
            }
        } 
        
        break;
        case 1: 
            for(vector<tree>::iterator i = diedTree.begin(); i != diedTree.end(); i++ ) {
                tree dt = diedTree.front();
                map[dt.y][dt.x] += (dt.age / 2);
            }
            diedTree.clear();
            break;
        case 2:
            for (int i = 1; i <= N; ++i ) {
                for (int j = 1; j <= N; ++j) {
                    for (deque<int>::iterator k = q[i][j].end(); k != q[i][j].begin(); k--) {
                    int age = *k;
                        if (age % 5 == 0){
                            // cout << "ddd eee " << age;
                            for (int l = 0; l < 8; ++l) {
                                int ny = i + wy[l]; int nx = j + wx[l];
                                if(isavailable(nx, ny)){    
                                    q[ny][nx].push_back(1);
                                }   
                            }   
                        }
                    }
                }
            }

            break;
        case 3:
            for (int i = 1; i <= N; ++i) {
                for (int j = 1 ; j <= N; ++j) {
                    map[i][j] += map2[i][j];
                }   
            }    
            break;
        }
    print2();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> map2[i][j];
            map[i][j] = 5;
        }
    }
    
    int x, y, age;
    for (int i = 0; i < M; ++i) {
        cin >> y >> x >> age;
        q[y][x].push_back(age);
    }

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 4; ++j) {
            growing(j);
        }
    }
    ans = 0;
    for (int i = 1; i <= N ; ++i) {
        for (int j = 1; j <= N; ++j) {
            ans += q[i][j].size();
        }
    }

    cout << ans << "\n";
    
    return 0;
}