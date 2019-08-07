#include <iostream>
#include <vector>

using namespace std;


struct shark{
    int r,c,s,d,z;
    shark(int _r,int _c,int _s,int _d,int _z) {
        r = _r; c = _c; s = _s; d = _d; z = _z;
    }
};

vector<shark*> v;
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, -1, 1, 0, 0 };

shark* map[101][101];

int R, C, M;

int ans;
int oe;
void init() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if(map[i][j] != NULL) {
                v.push_back(map[i][j]);
            }
            map[i][j] = NULL;
        }
    }
}

void fishing(int fk) {
    for (int i = 1; i <= R; ++i) {
        if(map[i][fk] != NULL) {
            shark* s = map[i][fk];
            ans += s->z;
            map[i][fk] = NULL;
            break;
        }
    }
    v.clear();
}

void moveshark(shark* s) {
    int y = s->r; int x = s->c; int d = s->d; int spd = s->s;
    if(d == 1) {
        int pos = R - y;
        int a = pos + spd;
        // 방향
        int dd = a / (R-1);
        // 위치
        int wa = a % (R-1);

        if(dd % 2) {
            s->r= 1 + wa;
            s->d = 2;
        } else {
            s->r= R - wa;
        }
        oe = 0;
    }
    else if(d == 2) {
        int pos = y - 1;
        int a = pos + spd;
        // 방향
        int dd = a / (R-1);
        // 위치
        int wa = a % (R-1);

        if(dd % 2) {
            s->r= R - wa;
            s->d = 1;
            
        } else {
            s->r= 1 + wa;
        }
        oe = 0;
    }
    else if(d == 3) {
        int pos = x - 1;
        int a = pos + spd;
        // 방향
        int dd = a / (C-1);
        // 위치
        int wa = a % (C-1);

        if(dd % 2) {
            s->c= C - wa;
            s->d = 4;
        } else {
            s->c= 1 + wa;
        }
        int temp = 0;
    }
    else if(d == 4) {
        int pos = C - x;
        int a = pos + spd;
        // 방향
        int dd = a / (C-1);
        // 위치
        int wa = a % (C-1);

        if(dd % 2) {
            s->c= 1 + wa;
            s->d = 3;
        } else {
            s->c= C - wa;
        }
        oe= 0;
    }
    
}

void moving() {
    init();
    
    for (int i = 0; i < v.size(); ++i) {
        shark* s = v.at(i);
        int y = s->r; int x = s->c;
        int d = s->z;
        
        moveshark(s);
        
        y = s->r; x = s->c;
        d = s->z;

        if(map[y][x] != NULL && map[y][x]->z > s->z) {
            continue; 
        } else {
            map[y][x] = s;
        }
    }
    v.clear();
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if(map[i][j] != NULL) {
                v.push_back(map[i][j]);
            }
        }
    }

}

shark* ssE = NULL;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> M;

    for (int i = 0; i < M; ++i) {
        int r,c,s,d,z;
        cin >> r >> c >> s >> d>> z;
        shark* sk = new shark(r,c,s,d,z);
        ssE = sk;
        v.push_back(sk);
        map[r][c] = sk;
    }
    for (int i = 1; i <= C; ++i) {
        fishing(i);
        
        moving();
    }

    cout << ans << "\n";

    return 0;

}