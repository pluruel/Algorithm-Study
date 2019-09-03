#include <iostream>
#include <vector>

using namespace std;

int map[51][51];
int tmap[51][51];
int wx[4] = {0, 1, 0, -1};
int wy[4] = {1, 0, -1, 0};


int N, M, K;

class magic{
public:
    int y, x, w;
    magic(int _y, int _x, int _w) {
        y = _y; x = _x; w = _w;
    }


    int turn() {
       

        for(int i = 1; i <= w; ++i) {
            int pos[2];
            pos[0] = y - i; pos[1] = x-i; 
            int cy = i * 2;
            int tempp = tmap[y-i][x - i];
            for (int j = 0; j < 8 * i; ++j) {
                int ccy = pos[0]; int ccx = pos[1];
                 pos[0] += wy[j/cy]; pos[1] += wx[j/cy];
                 tmap[ccy][ccx] = tmap[pos[0]][pos[1]];
            }
            tmap[y-i][x-i+1] = tempp;
            
        }

        
       
    }
};

vector<magic> m;

int per[6] = {0,1,2,3,4,5};

void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}

int ans = 1 << 31 - 1;

void permu(int depth) {
    if(depth == K) {
         
        for (int i = 1; i <= N; ++i ) {
            for (int j = 1; j <= M; ++j) {
                tmap[i][j] = map[i][j];
            }
        }
        for (int i = 0; i < K; ++i) {
            ans, m.at(per[i]).turn();
        }
        int temp;

         for (int i = 1; i <= N; ++i ) {
            temp = 0;
            for (int j = 1; j <= M; ++j) {
                temp += tmap[i][j];
            }
            ans = min(temp, ans);
        }
    }

    for (int i = depth; i < K; i++) {
        swap(per[i], per[depth]);
        permu(depth + 1);
        swap(per[i], per[depth]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    int r, c, s;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[i][j];
        }
    }

     for (int i = 1; i <= K; ++i) {
        cin >> r >> c >> s;
        m.push_back(magic(r, c, s));
    }

    permu(0);

    cout << ans << "\n";    

    return 0;
}