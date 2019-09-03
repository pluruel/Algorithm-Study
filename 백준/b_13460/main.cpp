#include <iostream>
#include <vector>
using namespace std;

char map[10][10];
int N, M, ans;


void movement(char a[][10], int way) {

    if(way < 2) {
        vector<char> v;
        for (int i = 0; i < N; ++i) {
            int cur = 0;
            for (int j = 0; j < M; ++j) {
                char temp = a[i][j];
                if(temp == 'R' || temp == 'B'   ) {
                    v.push_back(temp);        
                }
                else if (temp == '#') {

                }
            }
        }
    }
}


void permu(char a[][10], int depth, int way) {
    if(depth == 10) {
        return;
    }

    int m[10][10];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            m[i][j] = map[i][j];
        }
    }

    


    for(int i = 0; i < 4; ++i) {

        permu(m, depth, i);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }    




    
    cout <<  << "\n";
    return 0;
}