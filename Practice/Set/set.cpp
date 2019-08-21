#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> s;
    string ss = "d";
    s.find(ss);
    if(s.find(ss) != s.end()) {
        // s의 원소로 존재한다는 이야기.
    }
}