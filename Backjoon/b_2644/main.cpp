#include <iostream>
#include <queue>

using namespace std;

int fam[100][100];
int a[100];
int N, t1, t2, M, temp1, temp2;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> t1 >> t2 >> M;

    for (int i = 0; i < M; ++i) {
        cin >> temp1 >> temp2;
        fam[temp1][++fam[temp1][0]] = temp2;
        fam[temp2][++fam[temp2][0]] = temp1;
    }
    queue<int> q;
    q.push(t1);
    int ans = -1;
    a[t1] = 1;
    while(ans == -1 && q.size()) {
        int p = q.front();
        q.pop();
        for(int i = 1; i <= fam[p][0]; ++i) {
            if(fam[p][i] == t2) {
                ans = a[p];   
                break;
            }
            if(!a[fam[p][i]]){
                a[fam[p][i]] = a[p] + 1;
                q.push(fam[p][i]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}