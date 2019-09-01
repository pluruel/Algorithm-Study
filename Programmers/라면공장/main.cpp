#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class sup {
public:
    int d,s;
    sup(int _d, int _s) : d(_d), s(_s) {}
    
    bool operator < (const sup &p) const {
        return s < p.s;
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int N = dates.size();
    int curr =0;
    priority_queue<sup> pq;
    
    for (int i = 0; i < N; ++i) {
        pq.push(sup(dates[i], supplies[i]));
    }
    vector<sup> v;
    while(stock < k) {
        sup p = pq.top();
        if(p.d <= stock) {
            stock += p.s;
            curr = p.d;
            pq.pop();
            for (sup pp : v) {
              pq.push(pp);
            }
            answer++;
            v.clear();
            
        } else {
            v.push_back(p);
            pq.pop();
        }
        
    }
    
    return answer;
}
int main() {
    vector<int> d = {5,4,3};
    vector<int> s = {20,5,10};

    cout << solution(4,d,s,30) << endl;

    return 0;
}