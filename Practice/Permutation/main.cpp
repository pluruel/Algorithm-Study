#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
void print(vector<int> arr) {
    for(int i = 0; i < n ; ++i) 
        cout << arr[i] << ' ';
    cout << "\n";
}

void per(vector<int> arr, int depth){
    if(depth == n) {
        print(arr);
        cnt++;
        return;
    }
    for (int i = depth; i < arr.size(); ++i) {
        swap(arr[i], arr[depth]);
        per(arr, depth + 1);
        swap(arr[i], arr[depth]);
    }
}

int main() {

    vector<int> v = {0,1,2,3,4,5,6,7};
    n = 5;
    per(v, 0);

    cout << cnt << endl;
    
}