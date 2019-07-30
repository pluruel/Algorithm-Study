#include <iostream>
#include <set>
#include <queue>

// 1시간 20분

using namespace std;

int hextoint(char c) {
    if(c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return (c - 'A') + 10;
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, K;
    cin >> T;
    
    char input[29];
    for (int z = 1; z <= T; ++z) {
        cin >> N >> K;
        cin >> input;
        priority_queue<int> pq;
        set<int> s;
        int a = N / 4;
        for (int i = 0; i < N; i++) {
            for (int j = 0, p = 0, temp2 = 1 << (4 * (a-1)), sum = 0; j < N; j++) {
                int temp = (N - i + j) % N;
                sum += hextoint(input[temp]) * temp2;
                temp2 >>= 4;
                p++;
                if(p % a == 0) {
                    s.insert(sum);
                    p = 0; temp2 = 1 << (4 * (a-1)); sum = 0;
                }
            }
        }

        for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
            pq.push(*i);
        }
    
        for (int i = 0; i < K-1; ++i) {
            pq.pop();
        }
        
        
        cout << "#" << z << " " << pq.top() << "\n";
    }
    return 0;
}
