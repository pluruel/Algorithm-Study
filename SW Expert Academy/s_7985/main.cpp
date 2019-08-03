#include <iostream>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    short T;
    cin >> T;
     
    int nos[1024] = {0,};
    int temp, level, no;
    for (int z = 1; z <= T; ++z) {
        
        
        cin >> level;
        no = (1 << level) - 1;
        for (int i = 0; i < no; ++i) {
            cin >>nos[i];
        }
         
        temp = 1 << level;
         
         cout << "#" << z << " ";
        while(temp != 1) {
            string s;
            for (int j = temp / 2 -1; j < no; j+= temp) {
                s += nos[j] + " ";

                nos[j] = 0;
            }
            s.append("\n");
            temp /= 2;
            cout << s;
        }
    }
    return 0;
}