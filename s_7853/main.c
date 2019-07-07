#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    
    for (int z = 1; z <= T; ++z) {
        char c[1001];
        scanf("%s", c);
        long long ans = 1;
        for (int i = 0; c[i] != 0; ++i) {
            int temp = 1;
            
            char d = 0, e = c[i + 1];
            if(i > 0) {
                d = c[i-1];
            }
            if(d && c[i] != d) {
                temp++;
            }
            if(e && c[i] != e) {
                temp++;
            }
            if(temp > 1 && d == e) {
                temp--;
            }
            ans *= temp;
            ans %= 1000000007;
        }
        printf("#%d %lld\n", z, ans);
    }
    return 0;
}

