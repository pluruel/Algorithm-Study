#include <iostream>
#include <queue>
#define INSIDE ty <= N && ty > 0

using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = {1, 0, -1, 0};

int N, M, T;

int p[51][51];


bool search(int y, int x) {
    int n = p[y][x];
    if (!n) return false;
    queue<pair<int, int> > q;
    queue<pair<int, int> > q2;
    q.push({y, x});
    bool checked[51][51] = {0,};
    while(q.size()) {
        auto a = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ty = a.first + dy[i], tx = (a.second + dx[i] + M) % M;
            if((INSIDE) && !checked[ty][tx] && p[ty][tx] == n) {
                q.push({ty,tx});
                q2.push({ty, tx});
                checked[ty][tx] = 1;
            }
        }
    }
    if(q2.size()) {
        q2.push({y,x});
        while(q2.size()) {
            auto a = q2.front();
            q2.pop();
            p[a.first][a.second] = 0;
        }
    }else {
        return false;
    }
    return true;
}
 
void turn(int x, int d, int k) {
    if(d) k = -k;
    k %= M;
    k = (M + k)% M;
    queue<int> q;
    for (int pp = x; pp <= N; pp+= x) {
        for (int i = 0; i < M + k; ++i) {
            if(i < M) {
                q.push(p[pp][i]);
            }
            if(i >= k) {
                p[pp][i%M] = q.front();
                q.pop();
            }
        }
    }
    int judge = 0;
    for (int i = 1; i <= N; ++i) {
       for (int j = 0; j < M; ++j) {
           judge += search(i,j);
       }
   }
    if(!judge){
        int sum = 0, n = 0;;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < M; ++j) {
                if(p[i][j]){
                    sum += p[i][j]; n++;
                }
            }
        }
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < M; ++j) {
                if(p[i][j]) {
                    if(p[i][j] * n > sum)
                        p[i][j]--;
                    else if(p[i][j] * n < sum)
                        p[i][j]++;
                }
            }
        }
    }
    

    return;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> T;
    
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i< T; ++i) {
        int x,d,k;
        cin >> x >> d >> k;
        turn(x,d,k);
    }
    
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            sum += p[i][j];
        }
    }
    
    cout << sum << '\n';
    
    return 0;
}
