#include <iostream>

using namespace std;
int in[9], gy[9];
int winningin, winninggy;

void perm(int* arr, int depth, int ins, int gys) {
    if(ins >= 86) {
        int add = 1;
        for (int i = 2; i < 10-depth ; i++) {
            add *= i;
        }
        winningin += add;
        return;
    }else if (gys >= 86) {
        int add = 1;
        for (int i = 2; i < 10-depth ; i++) {
            add *= i;
        }
        winninggy += add;
        return;
    }
    
    for (int i = depth; i < 9; i++) {
        swap(arr[i], arr[depth]);
        if(gy[depth] > arr[depth]) {
            perm(arr, depth + 1, ins, gys + (arr[depth] + gy[depth]));
        } else {
            perm(arr, depth + 1, ins + (arr[depth] + gy[depth]), gys);
        }
        
        swap(arr[i], arr[depth]);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        winningin = 0;
        winninggy = 0;
        bool ch[19] = {0,};
        for(int i = 0; i < 9 ; ++i) {
            cin >> gy[i];
            ch[gy[i]] = true;
        }
        int i = 0;
        for(int j = 1; j <=18 ; ++j) {
            if(!ch[j]) {
                in[i++] =j;
            }
        }
        
        perm(in,0, 0, 0);
        cout << "#" << z << " " << winninggy << " " << winningin <<  "\n";
        
    }
    return 0;
}
