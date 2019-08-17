#include <iostream>
#include <vector>

using namespace std;

int m[2][4] = { 1, -1, 0, 0,
                0, 0, -1, 1 };

class atom {
public:
    int x, y, e, w; 
    atom(int _x, int _y, int _e, int _w) : x{_x}, y{_y}, e{_e}, w{_w} {}

    void move() {
        x += m[1][w]; y += m[0][w];
    }
    bool judge() {
        return !(x > 4002 || y > 4002 || x < 0 || y < 0); 
    }
};

int T, N;

int atomapcnt[2][4005][4005];
int ti, ans;
atom* v[2][1001];
int vs[2];

void init() {
    vs[0]= 0;
    vs[1]= 0;
    ti = 0;
    ans = 0;
}

vector<atom*> temp;

void simulation() {
    int aa = 0, bb = 1;


    for(int p = 0 ;p < 4003;++p){
        
        for (int i = 0; i < vs[aa]; ++i) {
            atom* a = v[aa][i];
             atomapcnt[aa][a->y][a->x]--;
            a->move();
            if (a->judge()) {
                atomapcnt[bb][a->y][a->x]++;
            }
        }
        for (int i = 0; i < vs[aa]; ++i) {
            atom* a = v[aa][i];
            if(!a->judge()) {
                continue;
            }
            if(atomapcnt[bb][a->y][a->x] > 1) {
                ans += a->e;           
                temp.push_back(a);    
            } else {
                if (a->judge()) {
                    v[bb][vs[bb]++] = a;
                }
            }
        }
        for (int i = 0; i < temp.size(); ++i) {
            atom* a = temp.at(i);
            atomapcnt[bb][a->y][a->x] = 0;
        }
        vs[aa] = 0;
        temp.clear();
        ti++;
        aa = ti %2;
        bb = !aa;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, y, e, w;
    cin >> T;

    for (int z = 1; z <= T; ++z) {
        init();
        cin >> N;

        for (int i = 0; i < N; ++i) {
            cin >> x >> y >> w >> e;
            x = (x + 1001) * 2; y = (y + 1001) * 2;
            v[0][vs[0]++] = new atom(x,y,e,w);
            atomapcnt[0][y][x]++;
        }
        simulation();
        cout << "#" << z << " " << ans << "\n";
    }


    return 0;
}