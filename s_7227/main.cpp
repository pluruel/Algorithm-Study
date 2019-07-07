#include <iostream>
#include <vector>
 
using namespace std;
#define LONG_MAX 9223372036854775807
 
class Point {
public: Point(long long _x, long long _y) {
    x = _x;
    y = _y;
}
    long long x, y;
    Point operator + (const Point& a){
        x = x + a.x;
        y = y + a.y;
        return Point(x, y);
    }
    Point operator - (const Point& a){
        x = x - a.x;
        y = y - a.y;
        return Point(x, y);
    }
    long long getDistance() {
        return x * x + y * y;
    }
};
 
vector<Point> v;
int N, no_couple;
long long lowest;
 
void combination(bool* b, int depth, int pos) {
     
    if(depth == no_couple) {
        Point p = Point(0, 0);
        for (int i = 0; i < N ; ++i) {
            if(b[i]) {
                p = p + v.at(i);
            } else {
                p = p - v.at(i);
            }
        }
        long long distance = p.getDistance();
        if (lowest > distance) lowest = distance;
        return;
    }
    for (int i = pos; i < N; i++) {
        b[i] = true;
        combination(b, depth+ 1, i + 1);
        b[i] = false;
    }
}
 
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
     
    short T;
    cin >> T;
     
    for (int z = 1; z <= T; z++) {
        cin >> N;
        bool b[21] = {false, };
        no_couple = N/2;
        lowest = LONG_MAX;
        v.clear();
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            v.push_back(Point(x, y));
        }
         
        combination(b, 0, 0);
         
        cout << "#" << z << " " << lowest << "\n";
         
    }
    return 0;
}