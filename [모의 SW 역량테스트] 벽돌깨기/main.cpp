#include <iostream>
#include <queue>

// 5시간정도
using namespace std;

int N, W, H;
int way_x[4] = {0, 1, 0, -1};
int way_y[4] = {-1, 0, 1, 0};
int ans = 999999;

class pos {
public: 
    int x, y;
    pos(int _x, int _y) {
        x = _x;
        y = _y;
    } 
};

void input(int board[][12], int* target) {
    cin >> N >> W >> H;
    for (int i = 0; i < W; ++i) target[i] = -1;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j)  {
            cin >> board[i][j];
            if(board[i][j] && target[j] == -1) {
                target[j] = i;
            }
        }
    }
    ans = 999999;
}

queue<pos> q;

void bombing(pos p, int arr[][12]) {
    int x = p.x;
    int y = p.y;
    int len = arr[y][x];
    

    for (int i = 0; i < 4; ++i) {
        for(int j = 1; j <= len-1; ++j) {
            int movex = x + way_x[i] * j;
            int movey = y + way_y[i] * j;
            if(movex < 0 || movex > W - 1 || movey < 0 || movey > H - 1) continue;
            if(arr[movey][movex]) {
                q.push(pos(movex, movey));
            }
        }
    }
    arr[y][x] = 0;
}

void cpy(int board_temp[][12], int board[][12]) {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            board_temp[i][j] = board[i][j];
        }
    }
}

void sorting(int b[][12], int* target) {
    for (int i = 0; i < W; ++i) {
        int pos= H-1;
        target[i] = -1;
        int arr[16] = {0,};
        for (int j = H-1; j >= 0; --j) {
            if(b[j][i]) {
                arr[pos--] = b[j][i];
            }
        }
        for (int j = H-1; j >= 0; --j) {
            b[j][i] = arr[j];
        }
    }
}

int calculate(int arr[][12]) {
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if(arr[i][j]) {
                ans++;
            }
        }
    }
    return ans;
}

void setTarget(int b[][12], int* t) {
    
    for (int i = 0; i < W; ++i){
        t[i] = -1;
        for (int j = 0; j < H ; ++j) {
            if(b[j][i]) {
                t[i] = j;
                break;
            } 
        }
    }
}

void bruteForce(int depth, int map[][12], int* target) {
    int len = 0;
    for (int i = 0; i < W; ++i) if(target[i] != -1) len++;
    if (depth == N || !len) {
        int temp = calculate(map);
        if(ans > temp) {
            ans = temp;
        }
        return;
    }

    for(int j = 0; j < W; ++j) {
        if(target[j] != -1) {
            q.push(pos(j, target[j]));
            int thismap[15][12] = {0};
            int thisTarget[12];
            cpy(thismap, map);
            
            while(!q.empty()) {
                pos p = q.front();
                q.pop();
                bombing(p, thismap);   
            }
            
            sorting(thismap, thisTarget);
            setTarget(thismap, thisTarget);
            bruteForce(depth +1, thismap, thisTarget);
        } else {
            continue;
        }
        
    }

}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int board[15][12] = {0,};
    int target[12] = {0};
    
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        input(board, target);
        bruteForce(0, board, target);
        cout << "#" << z << " " << ans << "\n";
    }
    return 0;
}
