#include <iostream>
#include <vector>
#define MIN 1 << 31
using namespace std;

int maximumSum(const vector<int>& v) {
    int N = v.size(); int ans = MIN; int psum= 0;
    for (int i = 0; i < N; ++i) {
        psum = max(psum, 0) + v[i];
        ans = max(psum, ans);
    }
    return ans;
}   

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    vector<int> t = {1,2,3,-2,-3,4,-5,1,9,2,-8,4,7};

    cout << maximumSum(t) << endl;
    
}