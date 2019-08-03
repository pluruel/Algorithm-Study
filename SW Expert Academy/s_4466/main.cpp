#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {

        priority_queue<int> q;
        int N, K, input;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            cin >> input;
            q.push(input);
        }
        int sum = 0;
        for (int i = 0; i < K; ++i) {
            sum += q.top();
            q.pop();
        }
        cout << "#" << z << " " << sum << "\n";
    }
    return 0;
}

