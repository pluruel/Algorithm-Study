#include <iostream>
#include <map>

using namespace std;


bool isavaliable(int a[][2]) {
    int bigone, bigcnt, sone, scnt;
    if(a[0][0] > a[1][0]) {
        bigone = a[0][0];
        bigcnt = a[0][1];
        sone = a[1][0];
        scnt = a[1][1];
    } else {
        bigone = a[1][0];
        bigcnt = a[1][1];
        sone = a[0][0];
        scnt = a[0][1];
    }

    if(bigone - sone == 1 && scnt == 1) {
        return true;
    } else {
        return false;
    }

    // int c;
    // int bigone;
    // if(a>b) {   
    //     c = a - b;
    //     bigone = a;
    // } 
    // else{ 
    //     c = b-a;
    //     bigone = b;
    // }
    // if(c == 1) {
    //     return bigone;
    // } else {
    //     return -1;
    // }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, cardwid = 0;
    string input;
    
    map<string, int> strmap;
    map<int, int> cntmap;
    

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> input;    
        auto a = strmap.find(input);
        if(a == strmap.end()) {
            strmap.insert({input, 1});
        } else{
            a->second++;
        }
    }
 
    for (auto a : strmap) {
        cardwid++;
        int cnt = a.second;
        auto a2 = cntmap.find(cnt);
        if(a2 == cntmap.end()) {
            cntmap.insert({cnt, 1});
        } else{
            a2->second++;
        }
    }
    string ans = "";
    if(cntmap.size() > 2) {
        ans += "N";
    } else {
        if(cntmap.size() == 1) {
            ans += "Y";
        } else {
            int i = 0;
            int anses[2][2];
            for (auto a : cntmap) {
                anses[i][0] = a.first;
                anses[i++][1] = a.second;
                
            }
            
            if(isavaliable(anses)) {
                ans += "Y";
                N++;
            } else {
                ans += "N";
            }
        }
    }

    cout << ans << "\n" << N << "\n" << cardwid << "\n";
	return 0;
}