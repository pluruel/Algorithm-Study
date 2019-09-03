#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool b[10000001] = {0,};
bool cc[10000001] = {0,};

void era() {
    b[0] = true;
    b[1] = true;
    for (int i =3; i <= 10000; i+=2) {
        if(b[i]) continue;
        for (int j = i * 2; j < 10000001; j+= i) {
            b[j] = true;
        }
    }
}

void swap(char& a, char& b) {
    char c = a;
    a = b;
    b = c;
}
int ans = 0;
void permutation(char* c, int depth, int n, int k) {
    if(depth == k) {
        int temp = 0;
        for (int i = 0; i < k; ++i) {
            temp *= 10;
            temp += (c[i] - '0');
        }
        if(temp%2 == 0) return; 
        if(cc[temp]== false) {
            if(b[temp] == false) ans++;
            cc[temp] = true;
        } 
        return;
    }
    for (int i = depth; i < n; i++) {
        swap(c[depth], c[i]);
        permutation(c, depth+1, n, k);
        swap(c[depth], c[i]);
    }
    
}

int solution(string numbers) {
    char c[10] = {0};
    era();
    for (int i = 0; i < numbers.size(); ++i) {
        c[i] = numbers[i];
    }
    for (int i = 1; i <= numbers.size(); ++i) {
        permutation(c, 0, numbers.size(), i);
    }
    return ans;
}
int main() {
    int c[10] = {1,7};
    solution("011");

    cout << ans;
}