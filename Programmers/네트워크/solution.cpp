#include <string>
#include <vector>
#include <queue>

using namespace std;

// 섬 개수 구하기 문제의 경우, 방문한 노드만 체크, 간선을 지울 필요는 없다.

bool visited[201] ={0,};

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if(visited[i]) continue;
        q.push(i);
        visited[i] = 1;
        answer++;
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            for (int j = 0; j < computers[a].size(); ++j) {
                if(!computers[a][j] || visited[j]) continue;
                q.push(j);
                visited[j] = 1;
            }
        }
    }
    
    
    return answer;
}