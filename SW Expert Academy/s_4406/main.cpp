#include <iostream>

using namespace std;

void print(char c) {
    switch(c) {
        case 'a': 
        break;
        case 'e': 
        break;
        case 'i': 
        break;
        case 'o': 
        break;
        case 'u': 
        break;
        default :
        cout << c;
        break;
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    char input[52];
    
    for (int z = 1; z <= T; ++z) {
        cin >> input;
        cout << "#" << z << " " ;
        for (int i = 0; input[i]; ++i) {
            print(input[i]);
        }
        cout << "\n";
    }
    return 0;
}

