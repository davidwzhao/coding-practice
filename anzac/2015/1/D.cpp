#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct p {
    int num;
    vector <int> indeces;
};

void doCase () {

    int h, v, k;
    bool poss = false;
    
    int len[1005];
    
    cin >> h;
    cin >> v;
    cin >> k;
    
    for (int i = 0; i < k; i++) cin >> len[i];
    
    sort (len, len+k);
    
    vector <p> possible;
    
    for (int i = 0; i < k; i++) {
        p asdfg;
        asdfg.num = len[i];
        asdfg.indeces.push_back(i);
        
        possible.push_back(asdfg);
        
        int asdfasdf = possible.size();
        for (int a = 0; a < asdfasdf; a++) {
            bool add = true;
            for (int b = 0; b < possible[a].indeces.size(); b++) {
                if (i == possible[a].indeces[b]) {
                    add = false;
                    break;
                }
            }
            if (add) {
                p asdfgh;
                asdfgh.num = len[i] + possible[a].num - v;
                asdfgh.indeces.insert (asdfgh.indeces.begin(), possible[a].indeces.begin(), possible[a].indeces.end());
                asdfgh.indeces.push_back (i);
                possible.push_back(asdfgh);
            }
        }
    }
    
    for (int i = 0; i < possible.size(); i++) {
        if (possible[i].num == h) {
            poss = true;
            break;
        }
    }
    
    if (poss) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main () {

    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) doCase();
    
    return 0;
}
