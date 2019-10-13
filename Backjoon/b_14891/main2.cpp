#include <iostream>
#include <queue>
#include <algorithm>
#define INSIDE ty < N && tx < M && ty >= 0 && tx >= 0

using namespace std;

int m[10][10], cm[10][10], N, M;
int wy[] = { -1,0,1,0 };
int wx[] = { 0,1,0,-1 };
int gmap[10][10];
int n = 0;

int *used[10];
int idx[10];
int tm[10][10];

struct s {
   int p1, p2, len;
   s(int _p1, int _p2, int _len) : p1(_p1), p2(_p2), len(_len){}
   
   bool operator < (const s& s) const {
      return len < s.len;
   }
};



void bfs(int y, int x) {
   queue<pair<int, int> > q;
   q.push({ y, x });
   while (q.size()) {
      int py = q.front().first;
      int px = q.front().second;
      m[py][px] = 0; cm[py][px] = n;
      q.pop();
      for (int i = 0; i < 4; ++i) {
         int ty = py + wy[i], tx = px + wx[i];
         if ((INSIDE) && m[ty][tx]) {
            q.push({ ty, tx });
         }
      }
   }

   return;
}

void checkisle() {
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         if (m[i][j] > 0) {
            n++;
            bfs(i, j);
         }
      }
   }
   int pre = 0, preis = 0, distance = 0;
   
   for (int i = 0; i < N; ++i) {
      preis = 0, distance = 0;
      for (int j = 0; j < M; ++j) {
         int temp = cm[i][j];
         if (temp > 0) {
            if (pre == 0 && preis > 0 && preis != temp && distance > 1) {
               if (!gmap[preis][temp]) {
                  gmap[preis][temp] = distance;
                  gmap[temp][preis] = distance;
               }
               gmap[preis][temp] = min(gmap[preis][temp], distance);
               gmap[temp][preis] = min(gmap[temp][preis], distance);
            }
            preis = temp;
            distance = 0;
         }
         else if (temp == 0) {
            distance++;
         }
      }
   }
   for (int i = 0; i < M; ++i) {
      preis = 0, distance = 0;
      for (int j = 0; j < N; ++j) {
         int temp = cm[j][i];
         if (temp > 0) {
            if (pre == 0 && preis > 0 && preis != temp && distance > 1) {
               if (!gmap[preis][temp]) {
                  gmap[preis][temp] = distance;
                  gmap[temp][preis] = distance;
               }
               gmap[preis][temp] = min(gmap[preis][temp], distance);
               gmap[temp][preis] = min(gmap[temp][preis], distance);
            }
            preis = temp;
            distance = 0;
         }
         else if (temp == 0) {
            distance++;
         }
      }
   }
}


int main() {
   cin >> N >> M;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         cin >> m[i][j];
      }
   }

   checkisle();

   vector<s> v;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         if (gmap[i][j]) {
            v.push_back(s(i, j, gmap[i][j]));
         }
      }
   }
   sort(v.begin(), v.end());
   int ans = 0;
   int unique= 1;
   
   for (int i = 1; i <= n; ++i) used[i] = &idx[i];
   for (s line : v) {
        int pr1 = line.p1, pr2 = line.p2;
        if(*used[pr1] == 0 && *used[pr2] == 0) {
            *used[pr1] = unique++;
            used[pr2] = used[pr1];
            ans += line.len;
        } else if(*used[pr1] == 0 || *used[pr2] == 0) { 
            if(*used[pr1]== 0) used[pr1] = used[pr2];
            else used[pr2] = used[pr1];
            ans += line.len;
        } else if(*used[pr1] != *used[pr2]){
            *used[pr2] = *used[pr1];
            ans += line.len;
        } 
        
   }
   int pre = *used[1];
   for (int i = 2; i <= n; ++i) {
      if (*used[i] != pre || *used[i] == 0) {
         cout << -1 << '\n';
         return 0;
      }
   }

   cout << ans << '\n';

   return 0;
}