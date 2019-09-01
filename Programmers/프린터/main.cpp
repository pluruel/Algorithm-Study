#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    int arr[10] = {0,};
    for (int p : priorities) {
        q.push(p);
        arr[p]++;
    } 
    while(1) {
        int t = q.front();
        q.pop();
        bool judge = false;
        for (int i = t +1; i <= 9; ++i) {
            if(arr[i] > 0) {
                judge = true;
                break;
            }
        }
        if(judge) {
            q.push(t);
        } else {
            answer++;
            arr[t]--;
            if(location == 0) {
                break;
            }
        }
        location--;
        if(location < 0) {
            location = q.size()-1;
        }
    }
    return answer;
}
int main() {
    vector<int> v;
    v.push_back(1);

    v.push_back(1);
    v.push_back(9);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    cout << solution(v, 0) <<"\n";
}