#include <iostream>

using namespace std;

int map[20][20];
int dice[7] = {0,0,0,0,0,0,0};
int movens[6] = {2, 1, 5, 6, 2, 1};
int movewe[6] = {4, 1, 3, 6, 4, 1};
int mc[5] = {0, 0, 0, -1, 1};
int mr[5] = {0, 1, -1, 0, 0};
int colour[7];
int N, M, x, y, K;

int north() {
    int temp[4];
    for(int i = 0; i < 4; ++i)  temp[i] = dice[movens[i+2]];
    for(int i = 0; i < 4; ++i) dice[movens[i+1]] = temp[i];
    return dice[1];
}

int south() {
    int temp[4];
    for(int i = 0; i < 4; ++i)  temp[i] = dice[movens[i+1]];
    for(int i = 0; i < 4; ++i) dice[movens[i+2]] = temp[i];
    return dice[1];
}

int west() {
    int temp[4];
    for(int i = 0; i < 4; ++i)  temp[i] = dice[movewe[i+2]];
    for(int i = 0; i < 4; ++i) dice[movewe[i+1]] = temp[i];

    return dice[1];
}

int east() {
    int temp[4];
    for(int i = 0; i < 4; ++i)  temp[i] = dice[movewe[i+1]];
    for(int i = 0; i < 4; ++i) dice[movewe[i+2]] = temp[i];
    return dice[1];
}

void move(int way) {
    x += mr[way]; y += mc[way];
    if(x >= M || y >= N || x < 0 || y < 0) {
        x -= mr[way]; y -= mc[way];
        return;
    }

    switch(way) {
        case 1:
            cout << east() << "\n";
            break;
        case 2:
            cout << west() << "\n";
            break;
        case 3:
            cout << north() << "\n";
            break;
        case 4:
            cout << south() << "\n";
            break;
    }
    if(map[y][x] != 0){
        dice[6] = map[y][x];
        map[y][x] = 0;
    }
    else {
        map[y][x] = dice[6];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    

    cin >> N >> M >> y >> x >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
    int way;    

    for (int i = 0; i < K; ++i) {
        cin >> way;
        move(way);
    }
}