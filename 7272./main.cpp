
#include <iostream>

using namespace std;

int judge(char c) {
    switch(c){
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'D':
            return 1;
        case 'O':
            return 1;
        case 'P':
            return 1;
        case 'Q':
            return 1;
        case 'R':
            return 1;
        default:
            return 0;
            
    }
    return 0;
}

bool check(const char *a, const char *b) {
    int ahash = 1, bhash = 1,i,j;
    for (i = 0; a[i] != 0; i++) {
        ahash <<= 2;
        ahash += judge(a[i]);
        
    }
    for (j = 0; b[j] != 0; j++) {
        bhash <<= 2;
        bhash += judge(b[j]);
    }
    return ahash == bhash;
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    const char ANS[2][5] = {"DIFF", "SAME"};
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; z++) {
        char a[13] = {0,}, b[13] = {0,};
        cin >> a >> b;
        cout << "#" << z <<" " << ANS[check(a,b)] << "\n";
    }
    
    return 0;
}

