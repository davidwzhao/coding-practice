#include <iostream>

using namespace std;

int main () {

    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int rows[5];
        int fams[5];
        
        for (int j = 1; j < 5; j++) {
            cin >> rows[j];
        }
        
        for (int j = 1; j < 5; j++) {
            cin >> fams[j];
        }
        
        int totalFams = 0;
        bool refund = false;
        
        for (int j = 1; j < 5; j++) totalFams += fams[j];
        
        while (totalFams > 0) {
            for (int j = 1; j < 5; j++) {
                if (rows[j] != 0 && fams[j] != 0) {
                    if (rows[j] > fams[j]) {
                        rows[j] -= fams[j];
                        fams[j] = 0;
                    } else {
                        fams[j] -= rows[j];
                        rows[j] = 0;
                    }
                }
            }
            
            if (fams[4] > 0) {
                refund = true;
                break;
            }
            
            if (fams[3] > 0) {
                if (rows[4] > 0) {
                    rows[4]--;
                    rows[1]++;
                    fams[3]--;
                    continue;
                } else {
                    refund = true;
                    break;
                }
            }
            
            if (fams[2] > 0) {
                if (rows[4] == 0 && rows[3] == 0) {
                    refund = true;
                    break;
                } else if (rows[4] == 0) {
                    rows[3]--;
                    rows[1]++;
                    fams[2]--;
                    continue;
                } else {
                    rows[4]--;
                    rows[2]++;
                    fams[2]--;
                    continue;
                }
            }
            
            if (fams[1] > 0) break;
            
            totalFams = 0;
            for (int j = 1; j < 5; j++) totalFams += fams[j];
        }
        
        if (refund) {
            cout << "Refunds" << endl;
        } else {
            cout << "No Refunds!" << endl;
        }
    }
    
    return 0;
}
