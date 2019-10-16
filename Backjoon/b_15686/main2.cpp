#include <iostream>
#include <vector>
//9 05
#define INTMAX (1 << 31) - 1
using namespace std;

struct pos {
    int y, x;
    pos(int _y, int _x): y(_y), x(_x){}
};

vector<pos> c;
vector<pos> h;
int N, M;

int dist[13][100];
int per[13];
int temp[13];

int getdist(pos p1, pos p2) {
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

int ans = INTMAX;

void perm(int depth, int p) {
    if (depth == M) {
        int sum = 0;
        for (int i = 0; i < h.size(); ++i) {
            int dis = INTMAX;
            for (int j = 0; j< M; ++j) {
                dis = min(dist[temp[j]][i], dis);
            }
            sum += dis;
        }
        ans = min(ans, sum);
        return;
    }

    for (int i = p; i< c.size(); ++i)  {
        temp[depth] = per[i];
        perm(depth +1, i +1 );
    }

}

int main() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i< N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> temp;
            if(temp == 1) {
                h.push_back(pos(i, j));
            } 
            else if(temp == 2) {
                c.push_back(pos(i, j));
            }
        }
    }
    
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < h.size(); ++j) {
            dist[i][j] = INTMAX;
        }
    }

    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < h.size(); ++j) {
            dist[i][j] = min(dist[i][j], getdist(c[i], h[j]));
        }
    }
    for (int i =0; i < 13; ++i) per[i] = i;

    perm(0, 0);

    cout << ans << '\n';

    return 0;
}