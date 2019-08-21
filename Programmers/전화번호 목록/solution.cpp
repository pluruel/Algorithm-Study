#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    map<string, int> s;
    int cc = 0;
    for (string se: phone_book) {
        s.insert({se,cc++});
    }
    int dd = 0;
    for(string se : phone_book) {
        string temp = "";
        for (int i = 0; i < se.size(); ++i){
            char c = se.at(i);
            temp += c;
            if(s.find(temp) != s.end()&& s.find(temp)->second != dd) {
                return false;
            }
            
        }
        dd++;
        
    }
    
    return answer;
}