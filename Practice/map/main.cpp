#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    for(string s : participant) {
        if(m.find(s) == m.end()) {
            m.insert({s, 1});
        } else {
            m.find(s)->second++;
        }
    }
    for(string s : completion) {
        if(m.find(s)->second > 1) {
            m.find(s)->second--;
        } else {
            m.erase(s);
        }
    }
    cout << m.empty() << " \n";
    string answer = "";
    return answer;
}

int main() {
    vector<string> v = {"leo", "kiki", "eden"};
    vector<string> v2 = {"eden", "kiki"};
    for(pair<string, int> p : m) {
        
    }
    solution(v,v2);

    return 0;
    
}