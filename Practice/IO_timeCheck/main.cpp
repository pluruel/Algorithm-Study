#include <iostream>
#include <time.h>

using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);
    clock_t s, e;
    s = clock();
    for (int i = 0; i < 10000000; ++i)
        cout << i << "\n";

    e = clock();
    cout << (double)e-s << endl;
    return 0;
}