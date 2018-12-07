#include <iostream>
#include <stack>

#define DIG 1
#define DRILL 2

using namespace std;

int main () {

    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        stack <int> l;
        
        int k;
        
        cin >> k;
        
        while (k > 1) {
            if (k % 2 == 1) {
                l.push(DIG);
                k--;
            } else {
                k /= 2;
                l.push(DRILL);
            }
        }
        
        if (k == 1) l.push(DIG);
        
        while (!l.empty()) {
            if (l.top() == DIG) cout << "dig ";
            if (l.top() == DRILL) cout << "drill ";
            l.pop();
        }
        
        cout << endl;
    }
    
    return 0;
}
