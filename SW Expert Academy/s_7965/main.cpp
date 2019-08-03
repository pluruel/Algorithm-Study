#include <iostream>

using namespace std;

long long anses[1000001];
long long temp[100];
bool check[100];

int getLen(int t) {
    int i = 0;
    while(t){  
        check[i] = t % 2; 
        temp[i+1] = temp[i] * temp[i];
        temp[++i] %= 1000000007;
        t  >>= 1;
    }
    
    return i;
}
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <=100000; ++i ) {
        anses[i] = 1;
        temp[0] = i;
        int t = 1;
        int size = getLen(i);
        for (int j = 0; j < size; ++j) {
            if(check[j]){
                anses[i] *= temp[j];
                anses[i] %= 1000000007;
            }
        }
        anses[i] += anses[i-1];
        anses[i] %= 1000000007;
    }

    int T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        int input;
        cin >> input;

        cout << "#" << z << " " <<  anses[input] << "\n";
    }
    return 0;
}
