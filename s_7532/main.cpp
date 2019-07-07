
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; z++) {
        int S, E, M;
        cin >>  S >> E >> M;
        --S;--E; --M;
        for  (int i  = 0; ; i+= 365) {
            int temp =  S+ i;
            if(temp % 24 == E && temp %  29 == M){
                cout << "#" << z <<" " <<++temp << "\n";
                break;
            }
        }
    }
    return 0;
}

