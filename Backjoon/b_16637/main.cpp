#include <iostream>
#include <stack>
#include <vector>

using namespace std;

char in[23];
char sym[10];
deque<char> gen;
char no[11];
int arr[10] = {0,1,2,3,4,5,6,7,8,9}, RL, L;

void swap(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
}

int ans = INT32_MIN;

int simulation() {
    int i = 0;
    int j = 0;
    gen.clear();
    int z = 0;
    vector<int> ivv;
    stack<int> svv;
    int vv = 0; int vvm =0;
    for (int i = 0; i <= L; ++i){ 
        for (;j <= arr[i] && j < L; j++) {
            svv.push(sym[j]);
        }
        for (; z <= arr[i] + 1 && z < L + 1; z++) {
            gen.push_back(no[z]);
        }
        while(!svv.empty()) {
                gen.push_back(svv.top());
                svv.pop();
                vv++;
                vvm++;
            }
      
    }
    stack<int> t;


    for (int i = 0; i < RL; ++i) {
        if(gen[i] >= '0' && gen[i] <= '9') {

            t.push(gen[i] - '0');
        } else {
            int bb = t.top(); t.pop();
            int aa = t.top(); t.pop();
            switch(gen[i]) {
            case '+':
                t.push(aa + bb);
                break;
            case '-':
                t.push(aa - bb);
                break;
            case '*':
                t.push(aa * bb);
                break;
            }
        }
    }
    ans = max(t.top(),  ans);
    t.pop();

}

void makearr(int pos) {
    swap(arr+pos, arr+pos+1);
    simulation();
    for (int j = 2 + pos; j + 1 < L; j++) {
        makearr(j);
    }
    swap(arr+pos, arr+pos+1);    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> RL >> in;
    L = RL/2;
    int sympos = 0;
    int npos = 0;
    for (int i = 0; in[i]; ++i) {
        if(i % 2) {
            sym[sympos++] = in[i];
        } else {
            no[npos++] = in[i];
        }
    }
    if (RL == 1) {
        cout << in[0]-'0' << "\n";
        return 0;
    }
    simulation();
    for (int i = 0; i < L-1; ++i) {
        makearr(i);
    }

    cout << ans << "\n";
    return 0;
}