#include <iostream>

using namespace std;

int map[10][10];
int ans = 999999, ad = 0;
int arlist[5] = {5, 5, 5, 5, 5};
int maxi[5] = {5,5,5,5,5};
int notanymore = 0;

bool isavailable(int y, int x, int size, int tmap[][10]) {
    for (int i= y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if(!tmap[i][j]) 
                return false;
        }
    }
    return true;
}

void cut(int y, int x, int size, int tmap[][10]) {
    for (int i = y; i < y +size; ++i) {
        for (int j = x; j < x + size ; ++j) {
            tmap[i][j] = 0;
        }
    }
}

void print(int map[][10]) {
    cout << "\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void simulation(int *papers, int tmap[][10], int n, int left, int temp) {
    if(left == 0) {
        
        ans = min(ans, temp);
        notanymore = n;
        return;
    } else if (n == 1) {
        if(left > maxi[0]) return;
        ans = min(ans, temp + left);
        return;
    }
    
    int now = maxi[n-1];
    for (int j = 0; j < 11 - n; ++j) {
        for (int k = 0; k < 11 - n; ++k) {
            if(isavailable(j,k,n, tmap) && papers[n-1]) {
                int map2[10][10];
                for (int l = 0; l < 10; ++l) {
                    for (int m = 0; m < 10; ++m) {
                        map2[l][m] = tmap[l][m];
                    }
                }
                int curpapers[5];

                for (int i = 0; i < 5; ++i) {
                    curpapers[i] = papers[i];
                }
                curpapers[n-1]--;
                now = curpapers[n-1];
                int judge;
                for (judge = 4; judge > n-1; --judge) {
                    if(curpapers[judge] > maxi[n-1]){
                        break;   
                    }
                }
                if(judge == n-1) {
                    maxi[n-1] = min(now, maxi[n-1]);
                }
                cut(j,k,n, map2);
                // print(map2);
                simulation(curpapers, map2, n, left - (n * n), temp + 1);
            }
        }
    }   
    if(n > 1 && papers[n-2] && papers[n-1] <= maxi[n-1]) {
        simulation(papers, tmap, n - 1, left, temp);
    } 
     
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> map[i][j];
            if(map[i][j]) ad++;
        }
    }
    simulation(arlist, map, 5, ad, 0);

    
    if(ans == 999999) ans = -1;

    cout << ans << "\n";
    return 0;
}