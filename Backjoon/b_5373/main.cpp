#include <iostream>
#include <queue>
#define OUTSIDE dy + wy[w] >= 3 || dx + wx[w] >= 3 || dy + + wy[w] < 0 || dx + wx[w] < 0

using namespace std;

int cube[3][3][3];
int wy[] = {0, 1, 0, -1};
int wx[] = {1, 0, -1, 0};
char a[6][3][3];
char cs[] = {'w','g','r','b','o','y'};

void init() {
    int aaaa = 1;
    for (int i = 0; i < 6; ++i)  {
        for (int j = 0; j< 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                a[i][j][k] = cs[i];
            }
        }
    }
    // print();
}

void turnu(int n) {
    char temp[3];
    for (int i = 0; i < 3 && n == 1; ++i) {
        temp[i] = a[1][0][i];
        a[1][0][i] = a[2][0][i];
        a[2][0][i] = a[3][0][i];
        a[3][0][i] = a[4][0][i];
        a[4][0][i] = temp[i];
    }
    
    for (int i = 0; i < 3 && n == -1; ++i) {
        temp[i] = a[1][0][i];
        a[1][0][i] = a[4][0][i];
        a[4][0][i] = a[3][0][i];
        a[3][0][i] = a[2][0][i];
        a[2][0][i] = temp[i];
    }

    int dy = 0, dx = 0, w = n == 1 ? 0 : 1;
    queue<char> q;
    for (int i = 0; i < 11; ++i) {
        if((OUTSIDE)) {
            w+= n; w += 4; w %= 4;
        }
        if(i <= 8) q.push(a[0][dy][dx]);
        if(i > 1) {
            a[0][dy][dx] = q.front(); q.pop();
        }
        dy += wy[w]; dx += wx[w];
    }
}

void turnd(int n) {
    char temp[3];
    for (int i = 0; i < 3 && n == -1; ++i) {
        temp[i] = a[1][2][i];
        a[1][2][i] = a[2][2][i];
        a[2][2][i] = a[3][2][i];
        a[3][2][i] = a[4][2][i];
        a[4][2][i] = temp[i];
    }
    
    for (int i = 0; i < 3 && n == 1; ++i) {
        temp[i] = a[1][2][i];
        a[1][2][i] = a[4][2][i];
        a[4][2][i] = a[3][2][i];
        a[3][2][i] = a[2][2][i];
        a[2][2][i] = temp[i];
        
    }
   int dy = 0, dx = 0, w = n == 1 ? 0 : 1;
    queue<char> q;
    for (int i = 0; i < 11; ++i) {
        if((OUTSIDE)) {
            w+= n; w += 4; w %= 4;
        }
        if(i <= 8) q.push(a[5][dy][dx]);
        if(i > 1) {
            a[5][dy][dx] = q.front(); q.pop();
        }
        dy += wy[w]; dx += wx[w];
    }
}


void turnf(int n) {
    char temp[3];
    temp[2] = a[1][2][2];
    for (int i = 0; i < 3 && n == -1; ++i) {
        temp[i] = a[1][i][2];
        a[1][2-i][2] = a[0][2][i];
        a[0][2][i] = a[3][i][0];
        a[3][i][0] = a[5][0][2-i];
        a[5][0][2-i] = temp[2-i];
    }
    temp[2] = a[0][2][2];
    for (int i = 0; i < 3 && n == 1; ++i) {
        temp[i] = a[0][2][i];
        a[0][2][2-i] = a[1][i][2];
        a[1][i][2] = a[5][0][i];
        a[5][0][i] = a[3][2-i][0];
        a[3][2-i][0] = temp[2-i];
    }

    int dy = 0, dx = 0, w = n == 1 ? 0 : 1;
    queue<char> q;
    for (int i = 0; i < 11; ++i) {
        if((OUTSIDE)) {
            w+= n; w += 4; w %= 4;
        }
        if(i <= 8) q.push(a[2][dy][dx]);
        if(i > 1) {
            a[2][dy][dx] = q.front(); q.pop();
        }
        dy += wy[w]; dx += wx[w];
    }
}

void turnb(int n) {
    char temp[3];
    for (int i = 0; i < 3 && n == 1; ++i) {
        temp[i] = a[1][2-i][0];
        a[1][2-i][0] = a[0][0][i];
        a[0][0][i] = a[3][i][2];
        a[3][i][2] = a[5][2][2-i];
        a[5][2][2-i] = temp[i];
    }
    
    for (int i = 0; i < 3 && n == -1; ++i) {
        temp[i] = a[0][0][2-i];
        a[0][0][2-i] = a[1][i][0];
        a[1][i][0] = a[5][2][i];
        a[5][2][i] = a[3][2-i][2];
        a[3][2-i][2] = temp[i];
    }
    int dy = 0, dx = 0, w = n == 1 ? 0 : 1;
    queue<char> q;
    for (int i = 0; i < 11; ++i) {
        if((OUTSIDE)) {
            w+= n; w += 4; w %= 4;
        }
        if(i <= 8) q.push(a[4][dy][dx]);
        if(i > 1) {
            a[4][dy][dx] = q.front(); q.pop();
        }
        dy += wy[w]; dx += wx[w];
    }
}

void turnl(int n) {
    char temp[3];
    for (int i = 0; i < 3 && n == 1; ++i) {
        temp[i] = a[0][i][0];
        a[0][i][0] = a[4][2-i][2];
        a[4][2-i][2] = a[5][i][0];
        a[5][i][0] = a[2][i][0];
        a[2][i][0] = temp[i];
    }
    
    for (int i = 0; i < 3 && n == -1; ++i) {
        temp[i] = a[0][i][0];
        a[0][i][0] = a[2][i][0];
        a[2][i][0] = a[5][i][0];
        a[5][i][0] = a[4][2-i][2];
        a[4][2-i][2] = temp[i];
    }
    int dy = 0, dx = 0, w = n == 1 ? 0 : 1;
    queue<char> q;
    for (int i = 0; i < 11; ++i) {
        if((OUTSIDE)) {
            w+= n; w += 4; w %= 4;
        }
        if(i <= 8) q.push(a[1][dy][dx]);
        if(i > 1) {
            a[1][dy][dx] = q.front(); q.pop();
        }
        dy += wy[w]; dx += wx[w];
    }
}
void turnr(int n) {
    char temp[3];
    for (int i = 0; i < 3 && n == -1; ++i) {
        temp[i] = a[0][i][2];
        a[0][i][2] = a[4][2-i][0];
        a[4][2-i][0] = a[5][i][2];
        a[5][i][2] = a[2][i][2];
        a[2][i][2] = temp[i];
    }
    
    for (int i = 0; i < 3 && n == 1; ++i) {
        temp[i] = a[0][i][2];
        a[0][i][2] = a[2][i][2];
        a[2][i][2] = a[5][i][2];
        a[5][i][2] = a[4][2-i][0];
        a[4][2-i][0] = temp[i];
    }
    int dy = 0, dx = 0, w = n == 1 ? 0 : 1;
    queue<char> q;
    for (int i = 0; i < 11; ++i) {
        if((OUTSIDE)) {
            w+= n; w += 4; w %= 4;
        }
        if(i <= 8) q.push(a[3][dy][dx]);
        if(i > 1) {
            a[3][dy][dx] = q.front(); q.pop();
        }
        dy += wy[w]; dx += wx[w];
    }
}


int main() {
    int N, M;
    char input[3];
    
    cin >> M;
    
    while(M--){
        init();
        cin >> N;
        for (int i = 0; i< N; ++i){
            cin >> input;
            int n = input[1] == '-' ? -1 : 1;
            // cout << input[0] << "\n";
            switch(input[0]) {
            case 'U' :
                turnu(n);
                break;
            case 'D' :
                turnd(n);
                break;
            case 'F' :
                turnf(n);
                break;
            case 'B' :
                turnb(n);
                break;
            case 'L' :
                turnl(n);
                break;
            case 'R' :
                turnr(n);
                break;
            }
        // print();
        }
        

        

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << a[0][i][j];
            }
            cout << "\n";
        }
    }
    
    return 0;

}