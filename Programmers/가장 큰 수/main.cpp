#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

 bool cmp (string a, string b) {
        
    return a > b;
}

string itoa(int n) {
    string s;
    stack<int> q;
    while(n) {
        q.push(n%10);
        n/=10;
    }
    while(!q.empty()) {
        s += q.top() + '0';
        q.pop();
    }
    return s;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sv;
    
    
    for (int n : numbers) {
        sv.push_back(itoa(n));
    }
    sort(sv.begin(), sv.end(), cmp);
    for(string s: sv) {
        answer += s;
    }
    return answer;
}


int main() {
    cout << solution({7,0,0,0}) << endl;
}