#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int widr, widc;

int map[102][102];


class no{
public:
    int n, cnt, diff;
    no(int _n, int _cnt) {
        n = _n; cnt = _cnt;
    }
    bool operator< (const no& a) const{
        if(this->cnt == a.cnt) {
            return this->n < a.n;
        } else {
            return this->cnt < a.cnt;
        }
    }
};

void FuncR() {
    
    
    for (int i = 1; i <= widr; ++i) {
        vector<no> arr;
        int arrsize = 0;
        int temp[101] = {0};
        int maxi = -1;
        for (int j = 1; j <= widc; ++j) {
            if(map[i][j] == 0) continue;
            temp[map[i][j]]++;
            maxi = max(map[i][j], maxi);
        }

        for (int j = 1; j <= maxi; j++) {
            if(temp[j] != 0){
                arr.push_back(no(j, temp[j]));
            }
        }
        sort(arr.begin(), arr.end());
        int subtemp[101] = {0};
        int sti= 1;
        for (vector<no>::iterator it = arr.begin(); it != arr.end(); it++) {
            no noo = *it; int nn = noo.n; int nnn = noo.cnt;
            subtemp[sti++] = nn; subtemp[sti++]= nnn; 
            if(sti >= 100) break;
            widc = max(sti, widc);
        }
        for (int j = 1; j <= widc; j++) {
            map[i][j] = subtemp[j];
        }
    }
}

void FuncC() {
    for (int i = 1; i <= widc; ++i) {
        vector<no> arr;
        int arrsize = 0;
        int temp[101] = {0};
        int maxi = -1;
        for (int j = 1; j <= widr; ++j) {
            if(map[j][i] == 0) continue;
            temp[map[j][i]]++;
            maxi = max(map[j][i], maxi);
        }
        for (int j = 1; j <= maxi; j++) {
            if(temp[j] != 0){
                arr.push_back(no(j, temp[j]));
            }
        }
        sort(arr.begin(), arr.end());
        int subtemp[101] = {0};
        int sti= 1;
        for (vector<no>::iterator it = arr.begin(); it != arr.end(); it++) {
            no noo = *it; int nn = noo.n; int nnn = noo.cnt;
            subtemp[sti++] = nn; subtemp[sti++]= nnn; 
            if(sti >= 100) break;
            widr = max(sti, widr);
        }
        for (int j = 1; j <= widr; j++) {
            map[j][i] = subtemp[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>> r >> c >> k;
    for (int i = 1; i <=3 ; ++i) {
        for (int j =1 ; j <=3; ++j) {
            cin >> map[i][j];
        }
    }
    widr = 3; widc = 3;
    int ans = 0;
    while(map[r][c] != k) {
        
        if (ans > 100) {
            ans = -1;
            break;
        }
        if(widr >= widc) {
            FuncR();
        } else {
            FuncC();
        }
        ans++;
    }
    
    cout << ans << "\n";

    return 0;
}