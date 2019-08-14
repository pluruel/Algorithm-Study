#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[52][52];
int a[13];
int N, M, PER;
vector<pair<int, int>> v;
vector<pair<int, int>> houss;

int ans = (1 << 31) - 1;

int abs(int a, int b){
    if(a > b) return a-b;
    else return b-a;
}

void test() {
    queue<pair<int, int>> q;
    int subans = 0;
    for (vector<pair<int, int>>::iterator i =  houss.begin(); i != houss.end(); i++) {
            int hy = i->first; int hx = i->second;
            int temp = (1 << 31) - 1;
            for(int i = 0; i < M; ++i) {
                pair<int, int> pr = v.at(a[i]);
                temp = min(temp, abs(hy, pr.first) + abs(hx, pr.second));
            }
            subans += temp;
    }
    ans = min(ans, subans);   
}

void com(int depth, int p) {
    if(depth >= M) {
        test();    
        return;
    }

    int run = PER-M + depth + 1;
    for (int i = p; i < run; ++i) {
        a[depth] = i;
        com(depth + 1, i + 1);
    } 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 13; ++i) a[i] =i;
    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if(map[i][j]== 2) {
                v.push_back({i, j});
                PER++;
            } else if (map[i][j] == 1) {
                houss.push_back({i,j});
            }
        }
    }

    com(0, 0);

    cout << ans << "\n";
    return 0;
}