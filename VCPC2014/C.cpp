#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct profit {
    int amount;
    int radius;
    int start;
};

int restaurants[10000005];
vector <profit> profits;

int main () {

    int q;
    cin >> q;

    for (int i = 0; i < 10000005; i++) {
        restaurants[i] = 0;
    }

    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        
        int n, g, r;
        if (s.compare ("good") == 0) {
            cin >> n >> g >> r;
            
            restaurants[n] += 1000 * g;
            
            profit p;
            p.amount = 100 * g;
            p.radius = r;
            p.start = n;
            
            profits.push_back(p);
        }
        
        if (s.compare ("bad") == 0) {
            cin >> n;
            
            restaurants[n] -= 1000;
        }
        
        if (s.compare ("profit") == 0) {
            cin >> n;
            
            int addProfit = 0;
            
            for (int j = 0; j < profits.size(); j++) {
                // cout << profits[j].start << " " << profits[j].radius << " " << profits[j].amount << endl;
            
                if (profits[j].start != n) {
                    if (profits[j].start - profits[j].radius <= n && profits[j].start + profits[j].radius >= n) {
                        addProfit += profits[j].amount;
                    }
                }
            }
            
            cout << restaurants[n] + addProfit << endl;
        }
    }
    
    return 0;
}
