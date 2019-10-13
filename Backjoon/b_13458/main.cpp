#include <iostream>

using namespace std;
int N, a[1000001], B, C;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i< N; ++i) {
        cin >> a[i];
    }
    cin >> B >> C;
    long ans = 0;
    for(int i = 0; i < N; ++i) {
        int temp = a[i] - B;
        ans++;
        if(temp > 0) {
            ans += temp / C;
            if(temp % C) ans++;
        }
    }

    cout << ans << "\n";
}