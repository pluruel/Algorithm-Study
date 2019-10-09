#include <iostream>
#include <queue>

using namespace std;

int ans = -1, N;

void simulation(int map[][20], int depth, int w) {
    
    if(depth == 5) {
        for (int i =0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = max(ans, map[i][j]);
            }
        }
        return;
    }
    
    bool c = w%2;
    bool jud = false;

    int tm[20][20];
    for (int i =0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tm[i][j] = map[i][j];
        }
    }
    
    for (int i = 0; i < N; ++i) {
        int p = 0;
        int pre = -1;
        int q[20] = {0};
        bool flag = false;
        switch(w) {
        case 0:
            for (int j = N-1; j >= 0; --j) {
                int temp = tm[i][j];
                tm[i][j] = 0;
                if (temp == 0) continue;
                if (p > 0 && temp == q[p-1] && !flag) {
                    q[p-1] *= 2;
                    flag = true;
                } else {
                    q[p++] = temp;
                    flag = false;
                }
            }
            p = 0;
            for (int j = N-1; j >= 0; --j) {
                tm[i][j] = q[p++];
            }
            break;
        case 1:
            for (int j = N-1; j >= 0; --j) {
                int temp = tm[j][i];
                tm[j][i] = 0;
                if (temp == 0) continue;
                if (p > 0 && temp == q[p-1] && !flag) {
                    q[p-1] *= 2;
                    flag = true;
                } else {
                    q[p++] = temp;
                    flag = false;
                }
            }
            p = 0;
            for (int j = N-1; j >= 0; --j) {
                tm[j][i] = q[p++];
            }
            break;
        case 2:
           for (int j = 0; j < N; ++j) {
                int temp = tm[i][j];
                tm[i][j] = 0;
                if (temp == 0) continue;
                if (p > 0 && temp == q[p-1] && !flag) {
                    q[p-1] *= 2;
                    flag = true;
                } else {
                    q[p++] = temp;
                    flag = false;
                }
            }
            p = 0;
            for (int j = 0; j < N; ++j)  {
                tm[i][j] = q[p++];
            }
            break;
        case 3:
            for (int j = 0; j < N; ++j)  {
                int temp = tm[j][i];
                tm[j][i] = 0;
                if (temp == 0) continue;
                if (p > 0 && temp == q[p-1] && !flag) {
                    q[p-1] *= 2;
                    flag = true;
                } else {
                    q[p++] = temp;
                    flag = false;
                }
            }
            p = 0;
            for (int j = 0; j < N; ++j)  {
                tm[j][i] = q[p++];
            }
            break;
        }
    }

    if(depth == 1)
        depth = 1;
    for (int i = 0; i < 4; ++i) {
        simulation(tm, depth + 1, i);
    }
}

int main() {
    int map[20][20];
    cin >> N;
    for (int i = 0; i < N;++i) 
        for(int j = 0; j < N; ++j)
            cin >> map[i][j];

    for (int i = 0; i < 4; ++i) 
        simulation(map, 0, i);

    cout << ans << "\n";
    return 0; 
}