#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int input[300][2] = {
        0,
    },
        N;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &input[i][0]);
        if (i == 0)
        {
            input[i][1] = input[i][0];
        }
        if (i > 0)
        {
            input[i][1] = input[i - 1][0] + input[i][0];
        }
        if (i > 1)
        {
            input[i][0] = max(input[i - 2][1], input[i - 2][0]) + input[i][0];
        }
    }

    printf("%d\n", max(input[N - 1][0], input[N - 1][1]));

    return 0;
}