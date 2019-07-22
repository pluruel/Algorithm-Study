#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;    
    
    int board[10][10] = {0,};
    int tc_x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    int tc_y[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int N, M, X, Y, C;
    for (int z = 1; z <= T; ++z) {
        cin >> N >> M;
        for (int i = 0; i <= N+1; ++i) {
            for (int j = 0; j <= N+1; ++j) {
                board[i][j] = 0;
            }
        }
        int m = N/2;
        board[m][m] = 2; board[m+1][m] = 1; board[m][m + 1] = 1; board[m+1][m+1] = 2;   
        for (int i = 0; i < M; ++i) {
            cin >> X >> Y >> C;
            board[Y][X] = C;
            for (int j = 0; j < 8; ++j) {
                int cur_y = Y, cur_x = X, target_y = -1, target_x = -1;
                while(board[cur_y][cur_x]) {
                    cur_y += tc_y[j];
                    cur_x += tc_x[j];
                    if(board[cur_y][cur_x] == C ){
                        target_x = cur_x;
                        target_y = cur_y;
                        break;
                    }
                }
                cur_y = Y;
                cur_x = X;
                if(target_x != -1 && target_y != -1) {
                    while(cur_y != target_y || cur_x != target_x) {
                        cur_y += tc_y[j];
                        cur_x += tc_x[j];
                        board[cur_y][cur_x] = C;
                    }
                }
                
            }
        }
        int K = 0, W = 0;
        for (int j = 1 ; j <= N; ++j) {
            for (int k = 1; k <= N ; ++k) {
                if(board[j][k] == 1) K++;
                else if(board[j][k] == 2) W++;
            }
        }
        cout << "#" << z << " " << K << " " << W << "\n";
    }
    return 0;
}

