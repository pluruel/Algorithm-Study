#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    
    for(int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j){
            int temp = 0;
            if(j > 0) {
                temp = max(triangle[i-1][j-1], temp);
            }
            if(j < triangle.size()-1) {
                temp = max(triangle[i-1][j], temp);
            }
            triangle[i][j] += temp;
            answer = max(answer, triangle[i][j]);
        }
    }
    
    
    return answer;
}