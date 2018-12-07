#include <cstdio>

int main () {

    int numHamsters;
    int standing = 0;
    int needToStand = 0;
    char hamsters[205];
    
    scanf ("%d", &numHamsters);
    
    for (int i = 0; i < numHamsters + 1; i++) {
        scanf ("%c", &hamsters[i]);
        if (hamsters[i] == 'X') {
            standing++;
        }
    }
    
    needToStand = (numHamsters / 2) - standing;
    
    int i = 1;
    int j = 1;
    if (needToStand > 0) {
        while (i <= needToStand) {
            if (hamsters[j] == 'x') {
                hamsters[j] = 'X';
                i++;
            }
            j++;
        }
    } else if (needToStand < 0) {
        while (i <= needToStand * -1) {
            if (hamsters[j] == 'X') {
                hamsters[j] = 'x';
                i++;
            }
            j++;
        }
    }
    
    if (needToStand < 0) {
        printf ("%d\n", needToStand * -1);
    } else {
        printf ("%d\n", needToStand);
    }
    
    for (int i = 1; i < numHamsters + 1; i++) {
        printf ("%c", hamsters[i]);
    }
    
    printf ("\n");
    
    return 0;
}
