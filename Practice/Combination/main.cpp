#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    int t = a; a= b; b = t;
}

int no = 0;
class noee {
public:
    int x, y;
    noee(int _x, int _y) {
        x = _x; y = _y;
    }
    bool operator<(const noee& a) const {
        if(x == a.x) {
            return y < a.y;
        } else {
            return x < a.x;
        }
    }
};

struct noe {
    int x, y;
    noe(int _x, int _y) {
        x = _x; y = _y;
    }
};
void print2(vector<noee> n) {
    for (auto i : n) {
        cout << i.x << " " << i.y << "\n";
    }
}
bool operator< (noe a, noe b) {
    if(a.x == b.x) {
        return a.y < b.y;
    } else {
        return a.x < b.x;
    }
}



void print(int* arr) {
    for (int i = 0 ; i < 3; ++i) {
            cout << arr[i] << " ";
        }
    cout << "\n";
    no++;
}



int temp[3];

void com(int* arr, int depth, int p) {
    if (depth == 3){
        print(temp);
        return;
    }
    for (int i = p; i < 3 + depth; ++i) {
        temp[depth] = arr[i];
        com(arr, depth+1, p+ 1 );
    }
}
// int temp[4];

int main() {
    ios_base::sync_with_stdio(false) ;  cin.tie(NULL); cout.tie(NULL);
    int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 } ;
    // (arr, 0);
    // com(arr,0, 0);

    // vector<noee> v;
    // v.push_back(noee(1,2));
    // v.push_back(noee(3,2));
    // v.push_back(noee(4,5));
    // v.push_back(noee(1,3));
    // v.push_back(noee(1,5));
    // v.push_back(noee(1,7));
    // v.push_back(noee(1,7));
    // sort(v.begin(), v.end());
    // print(arr);
    cout << no << "\n";

    return 0;


}