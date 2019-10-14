#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H, n;
bool checked[31][11];
int nn[11];
int ans = 4;

void simulation(int d, int nnn) {
    if(d == H+1) {
        for (int i = 1; i <= N; ++i) {
            if(nn[i] != i) return;
        }
        ans = min(ans, n);
        
        return;
    }
    
    if(nnn > 0){      
        for (int i = 1; i <= N-1; ++i) {
            if(i > 1 && !checked[d][i-1] && !checked[d][i] && !checked[d][i + 1]) {
                checked[d][i] = 1;  
                simulation(d, nnn-1);
                checked[d][i] = 0;
            }
            else if(i == 1 && !checked[d][i] && !checked[d][i + 1] ) {
                checked[d][i] = 1;
                simulation(d, nnn-1);
                checked[d][i] = 0;
            }
            
        }
    }

    for (int i = 1; i <= N-1; ++i) {
        if(checked[d][i]) {
            swap(nn[i], nn[i + 1]);
        }
    }

    simulation(d + 1, nnn);

     for (int i = 1; i <= N-1; ++i) {
        if(checked[d][i]) {
            swap(nn[i], nn[i + 1]);
        }
    }

    
}

int main() {
    cin >> N >> M >> H;
    int t1, t2;
    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2;
        checked[t1][t2] = 1;
    }

    for (n = 0; n <= 3; ++n) {
        for (int i = 1; i <= N; ++i) nn[i] = i;
        simulation(1, n);
    }
    if(ans == 4) ans = -1;
    cout << ans << "\n";
    return 0;
  
}