#include <iostream>
#include <vector>
using namespace std;

struct pos{
    int x, y, dust;
    pos(int _y, int _x, int _dust) {
        x = _x; y = _y; dust = _dust;
    }
};

int air[2][2];
int R, C, T;
int map[2][52][52];
int way_x[4] = {1, 0, -1, 0};
int way_y[2][4] = {0, -1, 0, 1
                ,0, 1, 0, -1};


int wwx[4] = {0, 1, 0, -1};
int wwy[4] = {-1, 0, 1, 0};

void print(int a) {
    cout << "\n";
    for (int i = 1; i <= R; ++i ) {
        for (int j = 1; j <= C; ++j) {
            
                cout << map[a][i][j] << " ";
            
        }
        cout << "\n";
    }  
    cout << "\n";
}

bool judge (int y, int x) {
    if(y > R || x > C || y < 1 || x < 1) {
        return false;
    } else if (air[0][0] == y && air[0][1] == x) {
        return false;
    } else if (air[1][0] == y && air[1][1] == x) {
        return false;
    }
    return true;
}


void clear2(int a) {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            map[a][i][j] = 0;       
        }
    }

}

void whacksan(int y, int x, int b) {
    int nx, ny;
    int dust = map[!b][y][x];
    int dustsize = 0;
    
    for(int i = 0; i < 4; ++i)  {
        ny = y + wwy[i]; nx = x + wwx[i];
        if(judge(ny, nx)) {
            dustsize++;
            map[b][ny][nx] += dust/5;
        } 
    }
    map[b][y][x] += dust - dust / 5 * dustsize;

}

void clear(int a) {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            map[a][i][j] = 0;       
        }
    }
}

void airclear(int b) {
    int a = !b;
    int prex; int prey;
    bool checked[52][52] = {0};
    checked[air[0][1]][air[0][1]] = 1;
    checked[air[1][1]][air[1][1]] = 1;
    for(int airm = 0; airm < 2; airm++){
        int x = air[airm][1]; int y = air[airm][0];
        int ny = y;
        int nx = x;
        prey = y;
        prex = x;
        
        for (int i = 0; i < 4; ++i) {
            while(1){
                prey = ny;
                prex = nx;
                ny += way_y[airm][i];
                nx += way_x[i];
                if(!judge(ny, nx)) {
                    ny -= way_y[airm][i];
                    nx -= way_x[i];
                    break;
                }
                else if(map[b][prey][prex] != -1){
                    map[a][ny][nx] = map[b][prey][prex];
                    checked[ny][nx] |= 1;
                    checked[prey][prex] |= 1;
                }
                
                int aaa= 333;
            } 

        }
        // print(a);
    }

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if(!checked[i][j]) {
                map[a][i][j] = map[b][i][j];
            }
        }
    }
  
    
    
    int asdfasdfa =333;


}
int t = 0;
void simulation() {
    int a = t%2;
    int b = !a;
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            whacksan(i, j, b);
        }
    } 
   t++;
    // print(b);
    clear(a);
    t++;
    airclear(b);
    clear(b);
  
    

    int c= 333;

}

int finalcheck (int t) {
    int dusts = 0; int a = (t + 1) %2;
    for (int i = 1; i <= R; ++i ) {
        for (int j = 1; j <= C; ++j) {
            if(map[a][i][j] != -1)
             dusts += map[a][i][j];
            
        }
    }  
    return dusts;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> T;
    int dust;
    int ad = 0; int ari = 0;
    clear(1);
    clear(0);
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> map[0][i][j];
            if( map[0][i][j] == -1) {
                air[ari][0] = i;
                air[ari++][1] = j;
            } 
        }
    }
    int i;
    for (i = 0; i < T; ++i) {
        simulation();
    }
    // print((t+1)%2);
    cout << finalcheck((t+1)%2)<< "\n";

    return 0;
}
