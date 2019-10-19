#include <stdio.h>

struct shark {
    int s,d,z;
} map[101][101], tm[101][101];
int dy[] = {0, -1, 1, 0,0};
int dx[] = {0, 0, 0, 1,-1};
int R, C, M, ans = 0;;
int main() {
    scanf("%d %d %d", &R, &C, &M);
    while(M--) {
        int r,c,s,d,z;
        scanf("%d %d %d %d %d", &r,&c,&s,&d,&z);
        if (d < 3) s = s%(R * 2 -2);
        else s = s%(C * 2 -2);

        map[r][c] = {s,d,z};
    }

    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= R; ++j) {
            if(map[j][i].z) {
                ans += map[j][i].z;
                map[j][i] = {0,0,0};
                break;
            }
           
        }
        for (int k = 1; k <= R; ++k) {
            for (int l = 1; l <= C; ++l) {
                if(map[k][l].z) {
                    auto[s,d,z] = map[k][l];
                    int ny = k + dy[d] * s;
                    int nx = l + dx[d] * s;
                    if(ny <= 0 || ny > R) {
                        if(ny <= 0) d = 2, ny = 2 - ny;
                        if(ny > R) d = 1, ny = 2 * R - ny;
                    }
                    if(nx <= 0 || nx > C) {
                        if(nx <= 0) d = 3, nx = 2 - nx;
                        if(nx > C) d = 4, nx = 2 * C - nx;
                    }
                    
                    if(tm[ny][nx].z < z) {
                        tm[ny][nx] = {s,d,z};
                    } 
        
                    map[k][l] = {0,0,0};
                    
                }
            }
        }
        for (int k = 1; k <= R; ++k) {
            for(int l = 1; l <= C; ++l) {
                map[k][l] = tm[k][l];
                tm[k][l] = {0,0,0};
            }
        }
    }
    printf("%d\n", ans);
    return 0;

}