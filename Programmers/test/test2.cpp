#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;


class pos {
public:
    int x, y;
    pos(int _y, int _x) : x(_x), y(_y){}
    bool operator<(const pos &c) const {
        if(y == c.y) return x < c.x;  
        else return y < c.y;
    }
};

bool turnandrun(int key[][20], set<pos> lock) {
    int key2[20][20]= {0,};


}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int N = lock.size() * lock.size();
    
    pos *init = nullptr;
    set<pos> needkey;
    int hall = 0;
    for (int i = 0; i < lock.size(); ++i) {
        for (int j = 0; j < lock[i].size(); ++j) {
            if(lock[i][j] == 0) {
                if(init == nullptr) {
                    init = new pos(i, j);
                }
                needkey.insert(pos(i-init->y, j-init->y));
                hall++;
            }
        }
    } 
    
    // key1
    pos *ikey = nullptr;
    vector<pos> keys;
    for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            if(key[i][j]== 1) {
                if(ikey == nullptr) {
                    ikey = new pos(i, j);
                }
                keys.push_back(pos(i-ikey->y, j-ikey->y));
            }
        }   
    }
    int te = 0;
    for(pos p : keys) {
        if(needkey.find(p) != needkey.end()) te++;
        if(te == hall) {
            answer |= true;
            break;
        }
    }
    //key2
    int key2[20][20]= {0,};

    ikey = nullptr;
    keys.clear();
    int i2 = 0, j2 = 0;
    for (int i = 0; i < key.size(); ++i) {
        for (int j = key.size() -1 ; j >= 0; --j) {
            key2[i2][j2++] = key[j][i];
        }
        i2++;
        j2 = 0;
     }

     for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            if(key2[i][j]== 1) {
                if(ikey == nullptr) {
                    ikey = new pos(i, j);
                }
                keys.push_back(pos(i-ikey->y, j-ikey->y));
            }
        }   
    }
     te = 0;
    for(pos p : keys) {
        if(needkey.find(p) != needkey.end()) te++;
        if(te == hall) {
            answer |= true;
            break;
        }
    }
    

     //key3
    int key3[20][20]= {0,};

    ikey = nullptr;
    keys.clear();
    i2 = 0; j2 = 0;
    for (int i = 0; i < key.size(); ++i) {
        for (int j = key.size() -1 ; j >= 0; --j) {
            key3[i2][j2++] = key2[j][i];
        }
        i2++;
        j2 = 0;
     }

     for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            if(key3[i][j]== 1) {
                if(ikey == nullptr) {
                    ikey = new pos(i, j);
                }
                keys.push_back(pos(i-ikey->y, j-ikey->y));
            }
        }   
    }
     te = 0;
    for(pos p : keys) {
        if(needkey.find(p) != needkey.end()) te++;
        if(te == hall) {
            answer |= true;
            break;
        }
    }
    
    //key4
    int key4[20][20]= {0,};

    ikey = nullptr;
    keys.clear();
    i2 = 0; j2 = 0;
    for (int i = 0; i < key.size(); ++i) {
        for (int j = key.size() -1 ; j >= 0; --j) {
            key4[i2][j2++] = key3[j][i];
        }
        i2++;
        j2 = 0;
     }

     for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            if(key4[i][j]== 1) {
                if(ikey == nullptr) {
                    ikey = new pos(i, j);
                }
                keys.push_back(pos(i-ikey->y, j-ikey->y));
            }
        }   
    }
     te = 0;
    for(pos p : keys) {
        if(needkey.find(p) != needkey.end()) te++;
        if(te == hall) {
            answer |= true;
            break;
        }
    }
    
    
    
    
    return answer;
}

int main() {

    int key[20][20] = {0};
    int key2[20][20]= {0,};
     int key3[20][20]= {0,};

    int i2 = 0, j2 = 0;

    for (int i= 0; i < 3; ++i) {
        for (int j =0; j < 3; ++j) {
            cin >> key[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 2 ; j >= 0; --j) {
            key2[i2][j2++] = key[j][i];
        }
        i2++;
        j2 = 0;
     }
i2 = 0, j2 = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 2 ; j >= 0; --j) {
            key3[i2][j2++] = key2[j][i];
        }
        i2++;
        j2 = 0;
     }

    for (int i= 0; i < 3; ++i) {
        for (int j =0; j < 3; ++j) {
            cout << key3[i][j] <<" ";
        }
        cout << "\n";
    }
}