#include <iostream>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    short T;
    cin >> T;
     
    for (int z = 1; z <= T; ++z) {
        int N, D, input;
        cin >> N >> D;
        int c = 0;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            cin >> input;
            if(input) {
                c = 0;
            } else {
                c++;
                if(c >= D) {
                    c = 0;
                    ans++;
                }
            }
             
        }
        cout << "#" << z << " " << ans << "\n";
    }
     
     
    return 0;
}