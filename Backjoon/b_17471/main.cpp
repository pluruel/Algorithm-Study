#include <iostream>
#include <queue>
#define INT_MAX 1 << 31 - 1 

using namespace std;

int p[12], N;
int c[12][20]; 
int com[12];
bool bb[12];
int ans = INT_MAX;

int abs(const int &a, const int &b) {
    if(a > b) return a-b;
    else return b - a;
}

bool isCon2(int* comm, int len, bool* v) {
    bool b[12] = {false};
    queue<int> q;
    q.push(comm[0]);
    while(!q.empty()) {
        b[q.front()] = true;
        for(int i = 1; i < c[q.front()][0]; ++i) {
            if(!b[c[q.front()][i]] && v[c[q.front()][i]])
                q.push(c[q.front()][i]);
        }
        q.pop();
    }
    for (int i =0 ; i < len; ++i) {
        if(!b[comm[i]]) {
            return false;
        }
    }
    
    return true;
}

void isCon(int len) {
    bool v[11] = {false};
    bool v2[11];
    for (int i = 0; i < 10; ++i) v2[i] = true;
    int a[10] = {0,}, alen = 0;
    int b[10] = {0,}, blen = 0;
    for (int i = 0; i < len;++i) {
        v2[com[i]] =false;
        v[com[i]] = true;
    }
    for (int i = 1; i <= N;++i) {
        if(v[i]) a[alen++]= i;
        else b[blen++]= i;
    }
    if( isCon2(a, alen, v) && isCon2(b, blen, v2)) {
        int suma = 0, sumb = 0;
        for(int i = 0; i < alen; ++i) 
            suma += p[a[i]];
        for(int i = 0; i < blen; ++i) 
            sumb += p[b[i]];
        ans = min(ans, abs(suma, sumb));
    }
}

void comb(int depth, int n, int cur) {
   
    if(depth == n) {
       isCon(n);
       return;
    }

    for (int i = cur; i <= N- n + depth ;i++) {
        com[depth] = i + 1;
        comb(depth + 1, n, i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N;++i) {
        cin >> p[i];
    }

    for (int i =1; i <= N; ++i) {
        cin >> c[i][0];
        for (int j = 1; j <= c[i][0]; ++j) {
            cin >> c[i][j];
        } 
        c[i][0]++;
    }

    for (int i = 1; i < N; ++i) {
        comb(0, i, 0);
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}