#include <stdio.h>

bool input[750][750];

int R, C;
int maxize;
int ny[] = {1, 1, -1, -1};
int nx[] = {-1, 1, 1, -1};
char inp[751];
// 8시 시작

bool test(int y, int x, int size) {
   int dy = y, dx = x;
   if(!input[dy][dx]) {
       return false;
   }
   for (int i = 0; i < 4; ++i) {
       for (int j = 0; j < size-1; ++j) {
            dy += ny[i]; dx += nx[i];
            if(!input[dy][dx]) {
                return false;
            }
       }
   }
   return true;
}

int min(int &r, int &c) {
    if (r > c) return c;
    else return r;
}

int main() {
    scanf("%d %d", &R, &C);
    maxize = min(R, C) / 2 + 1;

    bool isAvaliable = false;
    int ans = maxize;
    
    for(int i = 0; i < R;++i) {
        scanf("%s", inp);
        for (int j = 0; j < C; ++j) {
            input[i][j] = inp[j] - '0';
        }
    }

    for (ans = maxize; ans > 0; ans--) {
        for(int j = 0; j < R - (2 * (ans - 1)); j++) {
            for(int k = ans - 1; k < C - ans + 1; k++) {
                if(test(j, k, ans)) {
                    isAvaliable = true;
                    printf("%d\n", ans);
                    return 0;
                }
            }
        }
    }
    

    printf("%d\n", ans);
    return 0;
}