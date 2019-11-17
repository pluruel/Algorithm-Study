#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int map[100][100];
int N, M, T;

struct pos
{
    int y, x, n, t;
    pos(int _y, int _x, int _n, int _t) : y(_y), x(_x), n(_n), t(_t) {}
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> T;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    queue<pos> q;
    map[0][0] = 1;
    q.push({0, 0, 1, 0});
    bool flag = true;
    int ans = -1;
    while (q.size() && flag)
    {
        pos p = q.front();
        q.pop();
        int y = p.y, x = p.x, n = p.n, t = p.t;
        if (t > T)
            continue;
        for (int i = 0; i < 4; ++i)
        {
            int ty = y + dy[i], tx = x + dx[i];
            if (ty < N && tx < M && ty >= 0 && tx >= 0)
            {
                if (ty == N - 1 && tx == M - 1)
                {
                    if (t + 1 <= T)
                    {
                        ans = t + 1;
                        flag = false;
                    }
                    break;
                }
                else if (map[ty][tx] == 2)
                {
                    q.push({ty, tx, 3, t + 1});
                    map[ty][tx] = 3;
                }
                else if (map[ty][tx] < n)
                {
                    q.push({ty, tx, n, t + 1});
                    map[ty][tx] = n;
                }
            }
        }
    }

    if (ans == -1)
    {
        cout << "fail\n";
    }
    else
    {
        cout << ans << "\n";
    }
    return 0;
}