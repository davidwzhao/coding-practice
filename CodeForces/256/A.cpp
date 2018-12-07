#include <cstdio>

int main () {

    int nCups, nMedals, nShelves;
    
    int c1, c2, c3;
    scanf ("%d %d %d", &c1, &c2, &c3);
    nCups = c1 + c2 + c3;
    
    int m1, m2, m3;
    scanf ("%d %d %d", &m1, &m2, &m3);
    nMedals = m1 + m2 + m3;
    
    scanf ("%d", &nShelves);
    
    int nNeeded = 0;
    
    if (nCups > 0) {
        if (nCups % 5 == 0) {
            nNeeded += nCups / 5;
        } else {
            nNeeded += (nCups / 5) + 1;
        }
    }
    
    if (nMedals > 0) {
        if (nMedals % 10 == 0) {
            nNeeded += nMedals / 10;
        } else {
            nNeeded += (nMedals / 10) + 1;
        }
    }
    
    if (nNeeded <= nShelves) {
        printf ("YES\n");
    } else {
        printf ("NO\n");
    }
    
    return 0;
}
