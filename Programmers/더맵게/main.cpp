#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a> b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, cmp> a;
    for (int t : scoville) {
        a.push(t);
    }
    
    while(a.size() > 1 && a.top() < K) {
        int m1 = a.top(); a.pop();
        int m2 = a.top(); a.pop();
        a.push(m1 + m2 *2);
        answer++;
    }
    
    if(a.top() < K ) {
        answer = -1;
    }
    
    return answer;
}