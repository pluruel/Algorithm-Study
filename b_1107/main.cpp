#include <iostream>

using namespace std;


bool ans[2000001];

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    bool a[10] = {0,};
    int target = 100;
    cin >> N >> M;
    int wrong;
    for (int i = 0; i < M; ++i) {
        cin >> wrong;
        a[wrong] = 1;
    }
    int ans1 = N- 100;
    if(ans1 < 0) ans1 = -ans1;
    int radix;
    if(a[0]) {
        ans[0] = 1;
    }
    for (int i = 0; i <= 2000000; i++ ) {
        int temp =  i;
        radix = 1;
        while(temp) {
            if(a[temp%10]) {
                ans[i] = 1;
            }
            temp /= 10;
        }
    }
    int upper = N;
    int downer = N-1;
    while(1){
        if(!ans[upper] || upper >= 2000000){
            break;
        }
        upper++;
    }
    bool judge = 0;
    while(1){
        if(!ans[downer]) {
            judge = true;
            break;
        }
        if(0 < downer){
            downer--;
        } else {
            break;
        }
    }
    int upper2 = upper - N;;
    int downer2 = N - downer;
    if(downer < 0 || !judge) {
        downer2 = 999999999;
    }
    int ans2 = upper2 < downer2 ? upper2 : downer2;
    int temp3 = ans2 == downer2 ? downer : upper;
    if(!temp3) ans2++;
    while(temp3) {
        temp3 /= 10;
        ans2++;
    }
    
    int ans = ans1 > ans2 ? ans2: ans1;
    cout << ans << "\n";
    
    return 0;
}

