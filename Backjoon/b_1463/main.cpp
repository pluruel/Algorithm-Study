#include <stdio.h>

int dp(int N)
{
    if (N <= 1)
    {
        return 0;
    }
    int n1 = dp(N / 3) + N % 3 + 1;
    int n2 = dp(N / 2) + N % 2 + 1;

    return n1 < n2 ? n1 : n2;
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%d\n", dp(N));
    return 0;
}