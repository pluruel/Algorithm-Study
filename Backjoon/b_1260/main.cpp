#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;

bool checkpointdfs[1003] = {0, };
bool checkpointbfs[1004] = {0, };
void dfs(vector<vector<int > > &vec, int start_point) {
    stack<int> stack;
    cout << start_point << ' ';
    checkpointdfs[start_point] = 1;
    for (auto i = vec[start_point].begin(); i != vec[start_point].end(); i++) {
        if (!checkpointdfs[*i]) {
            dfs(vec, *i);
        }
    }

}

void bfs(vector<vector<int> > &vec, int start_point) {
    deque<int> deque;
    deque.push_back(start_point);
    checkpointbfs[start_point] = 1;
    while (deque.size())
    {
        int point = deque.front();
        deque.pop_front();
        cout << point << ' ';
        for(vector<int>::iterator i = vec[point].begin(); i != vec[point].end() ; i++ ) {
            if(!checkpointbfs[*i]) {
                deque.push_back(*i);
                checkpointbfs[*i] = 1;
            }
        }
    }
}



int main() {
    int N, M, V;

    cin >> N >> M >> V;
    vector<vector<int> > vec;

    for (int i= 0; i < N; i++) {
        vec.push_back(vector<int>());
    }
    vec.push_back(vector<int>());

    int ts, tt;
    for (int i= 0; i< M; i++) {
        cin >> ts >> tt;
        vec[ts].push_back(tt);
        vec[tt].push_back(ts);
    }
    for (int i= 0; i <= N; i++) {
        sort(vec[i].begin(), vec[i].end(), less<int>());
    }
    dfs(vec, V);
    cout << endl;
    bfs(vec, V);
    cout << endl;

}