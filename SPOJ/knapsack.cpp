#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// first = value
// second = weight
typedef pair<int, int> ii;

int knapsack(vector<ii> items, int w) {
    int opt[items.size() + 1][w + 1];
    
    for (int i = 0; i <= items.size(); i++) opt[i][0] = 0;
    for (int i = 0; i <= w; i++) opt[0][i] = 0;
    
    // items start at index 0 instead of 1
    // so we must subtract 1 from i when checking items
    for (int i = 1; i <= items.size(); i++) {
        for (int j = 1; j <= w; j++) {
            if (items[i - 1].second > j) opt[i][j] = opt[i - 1][j];
            else {
                opt[i][j] = max(opt[i - 1][j],
                                opt[i - 1][j - items[i - 1].second] + items[i - 1].first);
            }
        }
    }
    
    return opt[items.size()][w];
}

int main() {
    int W, n;
    cin >> W >> n;
    
    vector<ii> items;
    while (n--) {
        int w, v;
        cin >> w >> v;
        
        items.push_back(make_pair(v, w));
    }
    
    cout << knapsack(items, W) << endl;
    
    return 0;
}