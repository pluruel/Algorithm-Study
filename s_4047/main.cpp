#include <iostream>

using namespace std;

int defineCardColour(char input) {
    switch (input)
    {
    case 'S':
        return 0; 
    case 'D':
        return 1;
    case 'H':
        return 2;
    case 'C':
        return 3;
    default:
        break;
    }
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        bool check[4][14] = {0,};
        char input[1001];
        cin >> input;
        int color = -1;
        int no = 0;
        bool iserror = false;
        for (int i = 0; !iserror && input[i]; ++i) {
            int pos = i % 3;
            
            switch (pos)
            {
            case 0:
                color = defineCardColour(input[i]);
                break;
            case 1:
                no += (input[i]-'0') * 10;
                break;
            case 2:
                no += input[i]-'0';
                if(check[color][no]) {
                    iserror = true;
                    break;
                }
                check[color][no] = 1;
                color = -1; no = 0;
                break;
            default:
                break;
            }
        }

        cout << "#" << z << " ";
        if(iserror) {
            cout << "ERROR\n";
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int sum = 0;;
            for (int j = 1; j <= 13; ++j) {
                if(!check[i][j]) {
                    sum++;
                }
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}
