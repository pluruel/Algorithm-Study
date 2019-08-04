#include <stdio.h>
  
int map[100][100], N, ans = 0;
int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};
int hall[5][2][2];
int hallcnt[5];
  
// 4시간 반

int block[6][4] = {
    0,1,2,3,
    1,3,0,2,
    2,3,1,0,
    2,0,3,1,
    3,2,0,1,
    2,3,0,1  
};
  
int simulation(int w, int y, int x) {
     
    int score = 0;
    int next_y = y, next_x = x, next_w = w,  sth = -2;
    do {
        next_y += my[next_w];
        next_x += mx[next_w];
        sth = map[next_y][next_x];

        if(next_y == N || next_x == N || next_x == -1 || next_y == -1) {
            next_w = (next_w + 2) % 4;
            score = score * 2 + 1;
            break;
        } else if(sth < 6) {
            next_w = block[sth][next_w];
            if(sth > 0) {
                score++;
            }
        } else if (sth>= 6 && sth <= 10){
            int no = sth-6;
            if(hall[no][0][0] == next_y && hall[no][0][1] == next_x) {
                next_y = hall[no][1][0];
                next_x = hall[no][1][1];
            } else {
                next_y = hall[no][0][0];
                next_x = hall[no][0][1];
            }
        } 
       
    } while((next_y != y || next_x != x ) && sth != -1);

    return score;
}
  
void bruteforce() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(!map[i][j]) {
                for (int k = 0; k < 4; ++k) {
                    int score = simulation(k, i, j);     
                    if(score > ans) ans = score;
                }
            }
        }
    }
}
  
void init() {
    ans = 0;
    for (int i = 0; i < 5; ++i) {
        hallcnt[i] = 0;
    }
}
int main() {
    int T;
    scanf("%d", &T);
  
    for (int z = 1; z <= T; ++z) {
        ans = 0;
          
        scanf("%d", &N);
        init();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                 scanf("%d", &map[i][j]);
                if(map[i][j] >= 6) {
                    hall[map[i][j]-6][hallcnt[map[i][j]-6]][0] = i;
                    hall[map[i][j]-6][hallcnt[map[i][j]-6]++][1] = j;
                }
            }
        }
        bruteforce();
        printf("#%d %d\n", z, ans);
    }
  
}