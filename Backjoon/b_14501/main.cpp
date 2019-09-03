#include <iostream>

using namespace std;

int coun[15][2], N;
int dp[15] = {0,};
int day[15] = {0,};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    int ans = 0;
    for (int i =0; i < N; ++i) {
        cin >> coun[i][0] >> coun[i][1];
        day[i] = coun[i][0];
    }

    for (int i = 0; i < N; ++i) {
        int maxi = coun[i][1];
        for (int j = 0; j < i; ++j) {
            day[j]--;
            if(day[j] <= 0) {
                int temp = coun[i][1] + dp[j];
                maxi = max(temp, maxi);
            }
        }
        if(N < i + coun[i][0]) {
            dp[i] = 0;
        } else {
            dp[i] = maxi;
        }
        ans = max(dp[i], ans);
    }

    cout << ans << "\n";
    return 0;
}