#include <iostream>

using namespace std;
int map[21][21] = {
    0,
};
int T, N;

void movedown()
{
    for (int i = 0; i < N; ++i)
    {
        int s[20] = {
            0,
        },
            pos = -1, t = N - 1, pre = 0;
        for (int j = t; j >= 0; --j)
        {
            if(!map[j][i]) {
                continue;
            }
            else if (pre != map[j][i] )
            {
                pos++;
                s[pos] = map[j][i];
                pre = map[j][i];
            }
            else
            {
                s[pos] <<= 1;
                pre = -1;
            }
        }
        for (int j = t; j >= 0; --j)
        {
            map[j][i] = s[t - j];
        }
    }
}

void moveup()
{
    for (int i = 0; i < N; ++i)
    {
        int s[20] = {
            0,
        },
            pos = -1, t = N - 1, pre = 0;
        for (int j = 0; j < N; ++j)
        {
            if(!map[j][i]) {
                continue;
            }
            else if (pre != map[j][i])
            {
                pos++;
                s[pos] = map[j][i];
                pre = map[j][i];
            }
            else
            {
                s[pos] <<= 1;
                pre = -1;
            }
        }
        for (int j = 0; j < N; ++j)
        {
            map[j][i] = s[j];
        }
    }
}
void moveright()
{
    for (int i = 0; i < N; ++i)
    {
        int s[20] = {0, }, pos =-1, t = N - 1, pre = 0;
    
        for (int j = t; j >= 0; --j)
        {
            if(!map[i][j]) {
                
                continue;
            }
            else if (pre != map[i][j])
            {
                pos++;
                s[pos] = map[i][j];
                pre = map[i][j];
            }
            else
            {
                s[pos] <<= 1;
                pre = -1;
            }
        }

        for (int j = t; j >= 0; --j)
        {
            map[i][j] = s[t - j];
        }
    }
}

void moveleft()
{
    for (int i = 0; i < N; ++i)
    {
        int s[20] = {
            0,
        },
            pos = -1, pre = 0;
        for (int j = 0; j < N; ++j)
        {
            if(!map[i][j]) {
                continue;
            }
            else if (pre!= map[i][j])
            {
                pos++;
                s[pos] = map[i][j];
                pre = map[i][j];
            }
            else
            {
                s[pos] <<= 1;
                pre = -1;
            }
        }

        for (int j = 0; j < N; ++j)
        {
            map[i][j] = s[j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char way[10];
    cin >> T;

    for (int z = 1; z <= T; ++z)
    {
        cin >> N >> way;
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> map[i][j];
            }
        }
        if (way[0] == 'u')
        {
            moveup();
        }
        else if (way[0] == 'd')
        {
            movedown();
        }
        else if (way[0] == 'r')
        {
            moveright();
        }
        else if (way[0] == 'l')
        {
            moveleft();
        }
        cout << "#" << z << "\n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
    }
}