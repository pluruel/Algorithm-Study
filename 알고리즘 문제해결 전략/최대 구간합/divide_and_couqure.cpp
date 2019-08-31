#include <iostream>
#include <vector>
#define MIN 1 << 31
using namespace std;


int maximumSum(const vector<int>& v, int lo, int high) {
    if(lo == high) {
        return v[lo];
    }
    int mid = (lo+high)/2;
    int left = MIN; int right = MIN; int sum = 0;

    for (int i = mid; i >= lo; --i) {
        sum += v[i];
        left = max(sum, left);
    }
    sum = 0;
    for (int i = mid+1; i <= high; ++i) {
        sum += v[i];
        right = max(sum, right);
    }

    int single = max(maximumSum(v, lo, mid), maximumSum(v, mid +1, high));

    return max(left + right, single);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    vector<int> t = {1,2,3,-2,-3,4,-5,1,9,2,-8,4,7};

    cout << maximumSum(t, 0, t.size()-1) << endl;
    
}