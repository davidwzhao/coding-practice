#include <cstdio>

int main () {

    int customers[105][105];
    int numCashiers[105];
    int times[105];
    
    int numLines = 0;
    
    scanf ("%d", &numLines);
    
    for (int i = 0; i < numLines; i++) {
        scanf ("%d", &numCashiers[i]);
    }
    
    for (int j = 0; j < numLines; j++) {
        for (int k = 0; k < numCashiers[j]; k++) {
            scanf ("%d", &customers[j][k]);
        }
    }
    
    for (int l = 0; l < numLines; l++) {
        for (int m = 0; m < numCashiers[l]; m++) {
            times[l] += 5*(customers[l][m]);
            times[l] += 15;
        }
    }
    
    int minimumTime = times[0];
    for (int n = 0; n < numLines; n++) {
        if (times[n] < minimumTime) {
            minimumTime = times[n];
        }
    }
    
    printf ("%d\n", minimumTime);
    
    return 0;
}
