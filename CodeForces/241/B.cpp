#include <cstdio>

/*
struct painting {
    int startTime[5];
    int endTime[5];
};
*/

int main () {

    int numPaintings, numPainters;
    int startTimes[6][50005];
    int temp;
    
    scanf ("%d %d", &numPaintings, &numPainters);
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 50000; j++) {
            startTimes[i][j] = 0;
        }
    }
    for (int j = 1; j < numPaintings + 1; j++) {
        for (int i = 1; i < numPainters + 1; i++) {
            scanf ("%d", &temp);
            if (j == 0) {
                startTimes[i][j] = startTimes[i - 1][j] + temp;
            } else {
                if (startTimes[i][j - 1] > startTimes[i - 1][j]) {
                    startTimes[i][j] = startTimes[i][j - 1] + temp;
                } else {
                    startTimes[i][j] = startTimes[i - 1][j] + temp;
                }
            }
        }
    }
    
    for (int i = 1; i < numPaintings + 1; i++) {
        printf ("%d ", startTimes[numPainters][i]);
    }
    
    printf ("\n");
    
    return 0;
}