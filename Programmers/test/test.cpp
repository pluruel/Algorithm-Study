#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string& p) {
    stack<int> s;
    if(p.size() == 0) {
        return true;
    }
    s.push(p[0]);
    for(int i = 1; i < p.size(); i++) {
        if(!s.empty() && s.top() == '(' && p[i] == ')') {
            s.pop();
        } else {
            s.push(p[i]);
        }
    }
    return s.empty();
}

string reconstruct(string &s) {
    string u;
    string v;
    int b = 0;
    if(s.size() == 0) {
        return "";
    }

    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '(') {
            b++;
        } else {
            b--;
        }
        if(b == 0){
            for (int j = 0; j <= i; ++j) {
                u += s[j];
            }
            for (int j = i+1; j < s.size(); ++j) {
                v += s[j];
            }
            break;
        }
    }
    if(check(u)) {
        u += reconstruct(v);
    } else {
        string n;
        n += '(';
        n += reconstruct(v);
        n += ')';
        for (int j = u.size()-2; j > 0; --j) {
            n += u[j];
        }
        u.clear();
        for (int j = 0; j < n.size(); ++j) {
            u += n[j];
        }
    }
    return u;
}

string solution(string p) {
    string answer = "";
    if (p.size() == 0) {
        return answer;
    }

    if(check(p)) {
        return p;
    }
    
    return reconstruct(p);
}
int main() {
    cout << solution("()()())(") << endl;

}