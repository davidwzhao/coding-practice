#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string t[3];
bool r[3][105];

bool check(int c) {
    for (int i = 0; i < 3; i++) {
        if (r[i][c]) return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 105; j++) {
            r[i][j] = false;
        }
    }
    
    int n, k, s;
    
    cin >> n >> k;
    
    if (n == 1) {
        cout << "YES" << endl;
        return 0;
    }
    
    for (int i = 0; i < 3; i++) {
        getline(cin, t[i]);
        if (t[i][0] == 's') s = i;
    }
    
    if (t[max(s-1, 0)][1] == '.') r[max(s-1, 0)][1] = true;
    if (t[s][1] == '.') r[s][1] = true;
    if (t[min(s+1, 0)][1] == '.') r[min(s+1, 0)][1] = true;
    
    int i = 1;
    while (i < n) {
        if (!check(i)) {
            cout << "NO" << endl;
            return 0;
        }
        
        for (int j = 0; j < 3; j++) {
            if (r[j][i])