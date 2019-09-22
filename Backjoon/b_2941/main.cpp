#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;
    int ans = 0;

    for(int i = 0; i < input.size(); ++i) {
        switch(input[i]) {
        case 'c' :
            if(input[i+1] == '=')  {
                i++;
                ans++;
            } else if (input[i+1] == '-') {
                i++;
                ans++;
            } else {
                ans++;
            }
            break;
        case 'd' :
            if(input[i+1] == 'z' && input[i+2] == '=')  {
                i+=2;
                ans++;
            } else if (input[i+1] == '-') {
                i++;
                ans++;
            } else {
                ans++;
            }
            break;
        case 'l' :
            if(input[i+1] == 'j')  {
                i++;
                ans++;
            } else {
                ans++;
            }
            break;
        case 'n' :
             if(input[i+1] == 'j')  {
                i++;
                ans++;
            } else {
                ans++;
            }
            break;
        case 's' :
            if (input[i+1] == '=') {
                i++;
                ans++;
            } else {
                ans++;
            }
            break;
        case 'z' :
            if (input[i+1] == '=') {
                i++;
                ans++;
            } else {
                ans++;
            }
            break;
        default:
            ans++;
            break;
        }
    }
    cout << ans << "\n";
    return 0;

}