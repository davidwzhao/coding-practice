#include <cstdio>

int main () {

    // freopen ("test.txt", "r", stdin);

    int t;
    scanf ("%d", &t);
    for (int z = 0; z < t; z++) {
    
        int a1, i1, j1, k1, a2, i2, j2, k2, a, i, j, k;
        char o;
        
        scanf (" %d %d %d %d ", &a1, &i1, &j1, &k1);
        scanf ("%c", &o);
        scanf (" %d %d %d %d ", &a2, &i2, &j2, &k2);
        
        if (o == '+') {
            printf ("%d %d %d %d\n", a1 + a2, i1 + i2, j1 + j2, k1 + k2);
        } else if (o == '-') {
            printf ("%d %d %d %d\n", a1 - a2, i1 - i2, j1 - j2, k1 - k2);
        } else if (o == '*') {
            a = (a1 * a2) - (i1 * i2) - (j1 * j2) - (k1 * k2);
            i = (a1 * i2) + (a2 * i1) - (k1 * j2) + (j1 * k2);
            j = (a2 * j1) + (a1 * j2) + (k1 * i2) - (i1 * k2);
            k = (a2 * k1) + (a1 * k2) - (j1 * i2) + (i1 * j2);
            
            printf ("%d %d %d %d\n", a, i, j, k);
        }
    }
    
    return 0;
}
