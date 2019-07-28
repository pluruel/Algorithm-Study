#include <iostream>

using namespace std;

long long cal(long long input) {
    long long ans = 0;
    long long temp = input;
    while(temp) {
        ans += temp % 10;
        temp /= 10;
    }

    if(ans == input) {
        return ans;
    } else {
        return cal(ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int z = 1; z <= T; ++z) {
        long long input;
        cin >> input;
        cout <<"#" << z << " " << cal(input) << "\n";
    }
}