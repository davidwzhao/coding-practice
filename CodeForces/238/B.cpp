#include <cstdio>

int main () {

    int numDominoes;
    char dominoes[3005];
/*     int fallen = 0;
    int isL = 0;
    int seenR = 0; */
    int count = 0;
    int standing = 0;
    int firstL = 0;
    
    scanf ("%d", &numDominoes);
    
    for (int i = 0; i <= numDominoes; i++) {
        scanf ("%c", &dominoes[i]);
    }
    
/*    for (int i = 1; i <= numDominoes; i++) {
        if (dominoes[i] == '.') {
            count++;
        } else if (dominoes[i] == 'R') {
            count = 0;
            fallen++;
            for (int j = i; j <= numDominoes; j++) {
                if (dominoes[j] == 'L') {
                    isL = 1;
                    break;
                }
            }
            if (isL == 0) {
                fallen += numDominoes - i;
            }
            isL = 0;
            seenR = 1;
        } else if (dominoes[i] == 'L') {
            fallen++;
            if (count > 0 && seenR == 1) {
                if (count % 2 == 0) {
                    fallen += count;
                } else {
                    fallen += count - 1;
                }
            } else {
                fallen += count;
            }
            count = 0;
        }
    } */
    
    int i = 1;
    while (dominoes[i] != 'R') {
        if (dominoes[i] == 'L') {
            firstL = i;
        }
        i++;
    }
    
    standing += i - firstL - 1;
    
    i++;
    while (i <= numDominoes) {
        while (dominoes[i] != 'L' && i <= numDominoes) {
            count++;
            i++;
        }
        i++;
        if (count % 2 == 1) {
            standing++;
        }
        
        count = 0;
        
        while (dominoes[i] != 'R' && i <= numDominoes) {
            standing++;
            i++;
        }
        i++;
    }
    
    printf ("%d\n", standing);
    
    return 0;
}
