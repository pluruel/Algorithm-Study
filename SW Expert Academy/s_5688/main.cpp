#include <iostream>
 
using namespace std;
 
long long binsearch(long long start, long long end, long long target) {
    long long check = (start + end)/2;
    long long temp = check * check * check;
     
    if(temp == target) {
        return check;
    } else if (start == end) {
        return -1;
    } else if(temp > target) {
        return binsearch(start, check, target);
    } else {
        return binsearch(check+1, end, target);
    }
}
 
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    short T;
    cin >> T;
     
    for (int z = 1; z <= T; ++z) {
        long long N;
        cin >> N;
        cout << "#" << z << " " << binsearch(1, 1000000, N) << "\n";
    }
     
     
    return 0;
}