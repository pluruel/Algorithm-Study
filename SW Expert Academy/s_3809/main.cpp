#include <iostream>
#include <charconv>

using namespace std;

int arr[1001] = {0,};

int test(int N) {
    int t = 1, ans = -1;
    
    for (int t = 0; ; ++t) {
        bool judge = false;
        int temp = t;
        int a = 0;
        if(!t) {
            a++;
        }
        while (temp) {
            temp /= 10;
            a++;
        }
        for (int i = a; i <= N; ++i) {
            int radix = 1;
            int sum = 0;
            for (int j = 1; j <= a; ++j) {
                sum += radix * arr[i - j]; 
                radix *= 10;
            }
            if(sum == t) {
                judge = true;
                break;
            }
        }

        if(!judge) {
            return t;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;
    cin >> T;
    for (int z = 1; z <= T; ++z) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
       
        
        cout << "#" << z << " " << test(N) << "\n";
    }
    return 0;
}
