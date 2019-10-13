#include <iostream>
#include <queue>
using namespace std;

bool w[4][8];
int N, pos[4];

struct p {
    int no, way;
    p(int _no, int _way): no(_no), way(_way){}
};

void simulation(int no, int way) {
    queue<p> q;
    queue<p> q2;
    q.push(p(no,way));
    bool checked[4] = {0,};
    checked[no] = true;
    while(q.size()) {
        p op = q.front();
        q2.push(op);
        q.pop();
        if(op.no > 0) {
            if(w[op.no][(pos[op.no]+ 8 - 2 )% 8] != w[op.no - 1][(pos[op.no-1] + 2 )% 8] && !checked[op.no-1]) {
                q.push(p(op.no -1, -op.way));
                checked[op.no-1] = true;
            }
        }
        if(op.no < 3) {
            if(w[op.no][(pos[op.no] + 2) % 8] != w[op.no + 1][(pos[op.no+1] + 8 - 2 )% 8]&& !checked[op.no+1]) {
                q.push(p(op.no +1, -op.way));
                checked[op.no +1] = true;
            }
        }

    }

    while(q2.size()) {
        p op = q2.front();
        q2.pop();
        pos[op.no] = (pos[op.no] + 8 - op.way) % 8;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    char input[9];
    
    for (int i = 0; i < 4; ++i) {
        cin >> input;
        for (int j =0; j < 8; ++j) {
            if(input[j] == '1') {
                w[i][j] = true;
            }
        }
    }
    int no, way;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin>> no >> way;
        simulation(no-1, way);
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += w[i][(pos[i] + 8)% 8] * (1 << i);
    }
    cout << ans << "\n";
    return 0;

}