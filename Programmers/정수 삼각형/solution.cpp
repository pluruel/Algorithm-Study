#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    // DP의 가장 쉬운 예제
    // 각 라인별로 가장 큰 값을 선택적으로 취하여 최종으로 보냄.
    // 뒤에서 앞을 당겨오는 방식

    for(int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j){
            int temp = 0;
            if(j > 0) {
                temp = max(triangle[i-1][j-1], temp);
            }
            if(j < triangle[i].size()-1) {
                temp = max(triangle[i-1][j], temp);
            }
            triangle[i][j] += temp;
            answer = max(answer, triangle[i][j]);
        }
    }
    
    
    return answer;
}