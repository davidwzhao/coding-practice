#include <iostream>
#include <algorithm>

using namespace std;

bool sortF (int a, int b) {
    return (a > b);
}

int main () {

    int darcy[10];
    int josh[10];
    
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> darcy[j];
        }
        for (int j = 0; j < 10; j++) {
            cin >> josh[j];
        }
        
        sort (darcy, darcy+10, sortF);
        sort (josh, josh+10, sortF);
        
        // for (int j = 0; j < 10; j++) cout << josh[j] << endl;
        
        int numWins = 0;
        int currentJosh = 0;
        
        for (int j = 0; j < 10; j++) {
            if (josh[currentJosh] > darcy[j]) {
                numWins++;
                currentJosh++;
            }
        }
        
        cout << numWins << endl;
    }
    
    return 0;
}
