#include <iostream>

 
using namespace std;
int N, M, ans;
 
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    short T;
    cin >> T;
     
    for (int z = 1; z <= T; ++z) {
        ans = 0;
        cin >> N >> M;
        bool map[51][51] = {0,};
         
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
            map[y][x] = 1;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i+1; j <= N; ++j) {
                if(map[i][j]){
                    for (int k = j + 1; k <= N; ++k) {
                        if(map[j][k] && map[k][i]){
                            ans++;
                        }
                    }
                }
            }
        }
         
        cout << "#" << z << " " << ans << "\n";
    }
     
     
    return 0;
}