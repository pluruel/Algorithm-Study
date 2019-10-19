#include <stdio.h>
#define INSIDE ty < N && tx < N && ty >= 0 && tx >= 0


int A[10][10];
int grnd[10][10];
int t[10][10][100000];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int nt[10][10], ot[10][10];
int N, M, K, year;

int max(const int &a, const int &b) {
    if (a > b) return a;
    else return b;
}

void time() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j< N; ++j) {
            int pos = ot[i][j];
            for (int k = nt[i][j]-1; k > pos; --k) {
                if(nt[i][j] == pos) continue;
                if(grnd[i][j] - t[i][j][k] >= 0) {
                    grnd[i][j] -= t[i][j][k];
                    t[i][j][k]++;
                }
                else {
                    ot[i][j] = max(k, ot[i][j]);
                    grnd[i][j] += t[i][j][k] / 2;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j< N; ++j) {

            for (int k = nt[i][j]-1; k > ot[i][j]; --k) {
                if(nt[i][j] == ot[i][j]) continue;
                if(t[i][j][k] > 0 && t[i][j][k] % 5 == 0) {
                    int nnn = 3;
                    for (int l = 0; l< 8; ++l) {
                        int ty = i+dy[l], tx = j + dx[l];
                        if((INSIDE)) 
                        t[ty][tx][nt[ty][tx]++] = 1;
                    }
                }
                
            }
            grnd[i][j] += A[i][j];
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i< N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &A[i][j]);
            grnd[i][j] = 5;
            ot[i][j] = -1;
            nt[i][j] = 0;
        }
    }
    int temp1, temp2, temp3;
    for (int i = 0; i< M;++i) {
        scanf("%d %d %d", &temp1, &temp2, &temp3);
        t[temp2-1][temp1-1][nt[temp2-1][temp1-1]++] = temp3; 
    }

    for (year = 0; year < K; ++year) {
        time();
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans += nt[i][j]- ot[i][j];
        }
    }
    
    printf("%d\n", ans);

    return 0;
}