#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool re[31] = {0};
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int r : reserve) {
        re[r] = true;
    }

    vector<int> lost2;
    for(int l2 : lost) {
        if(!re[l2]) {
            lost2.push_back(l2);
        } else {
            re[l2] = false;
        }
     }
        answer = n - lost2.size();
    
    for (int i = 0; i <lost2.size(); ++i) {
        if (lost2[i] > 1 && re[lost2[i]-1]) {
            re[lost2[i] - 1] = false;
            answer++;
            continue;
        } 
        if (lost[i] < n && re[lost2[i] + 1]) {
            re[lost2[i] +1] = false;
            answer++;
            continue;
        }
    }
    
    return answer;
}