#include <iostream>
#include <queue>

using namespace std;

// 2시간 20분

int map[651][651], N, M, K;
int way_x[4] = {0, 1, 0 , -1};
int way_y[4] = {-1, 0, 1, 0};

int idx[2], runningTime;

class cell {
public:
    int x, y, live, time;

    cell(int _y, int _x, int _live) {
        y = _y; x = _x; live = _live; time = _live;
    }

    void wait() {
        if(time > 0) time--;
        else live--;

    }

    bool isAvaliable() {
        return !time;
    }

    bool isalive() {
        return live;
    }

};
struct cmp{
    bool operator()(cell* a, cell*b) {
        return a->live < b ->live;
    }
};

cell* q[2][2501];

void swap(int a, int b, int time) {
    cell* temp = q[time][a];
    q[time][a] = q[time][b];
    q[time][b] = temp;
}

void sort(int left, int right, int time) {
    int j = right, i = left;
    int pivot = q[time][(j+i)/2]->live;
    
    while(i <= j) {
        while(q[time][i]->live > pivot) i++;
        while(q[time][j]->live < pivot) j--;
        if(i <= j) {
            swap(i, j, time);
            i++; j--;
        }
    }
    if(j > left) sort(left, j, time);
    if(i < right) sort(i, right, time);
}

bool checkPos(int y, int x) {
    return y < 0 || y >= N || x >= M || x < 0;
}   

void findNewCell(int time, cell* c) {
    int y = c->y, x = c->x;

    for (int i = 0; i < 4; ++i) {
        int newy = y + way_y[i];
        int newx = x + way_x[i];
        if(!map[newy][newx]) {
            q[time][idx[time]++] = new cell(newy, newx, c->live);
            map[newy][newx] = q[time][idx[time]-1]->live;
        }
        
    }
}

void print() {
    cout << "\n";
    for (int i = 300; i < 330; ++i) {
        for (int j = 300; j < 330; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void takeHour() {
    int time1 = !(runningTime%2);
    int time2 = runningTime%2;
    idx[time1] = 0;
    // print();
    sort(0, idx[time2]-1, time2);
    for (int i = 0; i < idx[time2]; ++i) {
        cell *t = q[time2][i];
        if(t->isAvaliable()){
            findNewCell(time1, t);
        }
        t->wait();
        if(t->isalive()) q[time1][idx[time1]++] = t;
    }
}

void init() {
    for(int i = 0; i < 651; ++i) {
        for(int j = 0; j < 651; ++j) {
            map[i][j] = 0;
        }
    }
}

void input() {

    idx[0] = 0;
    cin >> N >> M >> K;
    for (int i= 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int temp;
            cin >> temp;
            if(temp) {
                map[i+300][j+300] = temp;
                q[0][idx[0]++] = new cell(i+300,j+300, temp);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        init();
        input();
        for(runningTime = 0; runningTime < K; ++runningTime) {
            takeHour();
        }
        cout << "#" << z << " " << idx[runningTime%2] << "\n";
    }
}