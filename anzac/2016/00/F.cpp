#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > iii;

string grid[205];
bool seen[205][205];
int w, h;

int is(int y, int x, int check) {
    int i = 1;
    
    if (seen[y][x]) return 1;
    seen[y][x] = true;
    
    while (y + i < h && x + i < w && grid[y + i][x] == grid[y][x + i]) {
        // cout << grid[y + i][x] << " " << grid[y][x + i] << " " << i << endl;
        i++;
    }
    
    if (check && grid[y+i-1][x+i-1] != grid[y][x]) return 1;
    
    if (i <= 1) return i;
    else return min(i, is(y+1, x+1, 0) + 1);
}

int main() {
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++) seen[i][j] = false;
    }
    
    cin >> w >> h;
    
    vector<iii> out;
    
    string junk;
    getline(cin, junk);
    
    for (int i = 0; i < h; i++) {
        getline(cin, grid[i]);  
    }
    
    // for (int i = 0; i < h; i++) cout << grid[i] << endl;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int lol = is(i, j, 1);
            if (lol > 1) {
                out.push_back(make_pair(lol, make_pair(i, j)));
            }
        }
    }
    
    sort(out.begin(), out.end());
    
    for (int i = 0; i < out.size(); i++) {
        cout << out[i].first << " " << out[i].second.first << " " << out[i].second.second << endl;
    }
    
    return 0;
} 
    