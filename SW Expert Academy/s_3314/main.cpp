#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        int ans = 0, temp;
        for (int i = 0; i < 5; ++i){
        cin >> temp;
        ans += temp > 40 ? temp : 40;}
        
        cout << "#" << z << " " << ans /5 << "\n";
    }
    return 0;
}
