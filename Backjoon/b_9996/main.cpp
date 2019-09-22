#include <iostream>
#include <vector>

using namespace std;

bool judge(string& st, string& et, string& cmp) {
    int pos = 0;
    int ss = st.size();
    for (int i= 0; i < st.size(); i++) {

        if(st[i]!= cmp[i]) return false;
    }
    int es = et.size()-1;
    int cms = cmp.size()-1;
    for (int i= 0; i < et.size(); i++) {
        if(ss > (cms-i) || et[es-i] != cmp[cms-i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    string t;
    vector<string> ans = {"NE", "DA"};
    cin >> n >> t;
    string st, et;
    int i = 0;
    for (; t[i] != '*'; ++i) {
        st += t[i];
    }
    for (++i; i < t.size(); ++i) {
        et += t[i];
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << ans[judge(st, et, s)] << "\n";
    }

    return 0;
}