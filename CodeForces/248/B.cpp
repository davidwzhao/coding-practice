#include <iostream>
#include <algorithm>

using namespace std;

int main () {

    int numStones;
    int numQuestions;
    
    long long stones[100005];
    long long sortedStones[100005];
    
    int temp;
    
    cin >> numStones;
    // scanf ("%d", &numStones);
    
    for (int i = 0; i < numStones; i++) {
        cin >> temp;
        // scanf ("%d", &temp);
        stones[i] = temp;
        sortedStones[i] = temp;
    }
    
    sort (sortedStones, sortedStones + numStones);
    
    for (int i = 1; i < numStones; i++) {
        stones[i] += stones[i - 1];
        sortedStones[i] += sortedStones[i - 1];
    }
    
    cin >> numQuestions;
    // scanf ("%d", &numQuestions);
    
    int q, l, r;
    for (int i = 0; i < numQuestions; i++) {
        cin >> q >> l >> r;
        // scanf ("%d %d %d", &q, &l, &r);
        
        if (q == 1) {
            if (l == 1) {
                cout << stones[r - 1] << endl;
                // printf ("%I64d\n", stones[r - 1]);
            } else {
                cout << stones[r - 1] - stones[l - 2] << endl;
                // printf ("%I64d\n", stones[r - 1] - stones[l - 2]);
            }
        } else {
            if (l == 1) {
                cout << sortedStones[r - 1] << endl;
                // printf ("%I64d\n", sortedStones[r - 1]);
            } else {
                cout << sortedStones[r - 1] - sortedStones[l - 2] << endl;
                // printf ("%I64d\n", sortedStones[r - 1] - sortedStones[l - 2]);
            }
        }
    }
    
    return 0;
}
