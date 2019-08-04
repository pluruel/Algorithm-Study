#include <iostream>

using namespace std;
 
int input[51][9], N, ans;

int hitting(int* status, int n, int pos) {
    int score = 0;
    status[pos] += n;
    if(status[pos]>= 4){ 
        status[pos] = 0;
        score++;
    }
    int a = 0;
    for (int i = 0; i < 9; ++i ) {
        if(status[i] && i != pos) {
            if(status[i] + n >= 4) {
                score++;
                status[i] = 0;
            } else {
                status[i] += n;
            }
        }
    }
    return score;
}

int simulation(int* arr3) {
    int cnt = 0, score = 0;
    int status[9] = {0};

    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < 9; ++j) status[j] = 0;
        int out = 3;
        while(out) {
            if(!input[i][arr3[cnt]]) {
                out--;
            } else {
                score += hitting(status, input[i][arr3[cnt]], cnt);
            }
            cnt++;
            cnt %= 9;
        }
    }
    ans = max(ans, score);
}

int* createarr(int* a, int* b) {
    
    for (int i = 0, j = 0; j < 9; j++) {
        b[j] = a[i]; 
        if(j != 3) i++;
    }

    b[3] = 0;
    return b;
}

void swap(int* arr, int a, int b) {
    int temp= arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void permu(int *arr, int depth){
    if(depth == 8) {
        int arr2[9];
        simulation(createarr(arr, arr2));
    }
    for (int i = depth; i < 8; ++i) {
        swap(arr, depth, i);
        permu(arr, depth + 1);
        swap(arr, depth, i);
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int barr[8];
    for (int i = 1; i <=8; ++i) barr[i-1] = i;

    cin >> N; 
    ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 9; ++j){
        cin >> input[i][j];
        }
    }
    permu(barr, 0);
    cout << ans <<"\n";
    return 0;
}
