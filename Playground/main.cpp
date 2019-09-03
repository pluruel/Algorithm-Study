#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

struct node{
    int x; int y; int weight;
    node(int _x, int _y, int _weight) {
        x = _x; y = _y; weight = _weight;
    }
};

int a[5] = {1,3,2,-1,5};

vector<node> n;

void print() {
    cout << "\n";
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

    for (vector<node>::iterator it = n.begin(); it != n.end(); it++) {
        cout << it->weight << " ";
    }

    cout << "\n";

}

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};



bool operator<(node a, node b) {
    return a.weight < b.weight;
}

int main() {
    sort(a, a + 5, less<int>());
    sort(a, a + 5, greater<int>());
    sort(a, a + 5, cmp());

    n.push_back(node(1,2,6));
    n.push_back(node(1,2,7));
    n.push_back(node(1,2,8));
    n.push_back(node(1,2,4));
    n.push_back(node(1,2,3));
    n.push_back(node(1,2,5));
    n.push_back(node(1,2,9));

    print();

}