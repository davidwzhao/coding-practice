#include <cstdio>

int main () {

    int n, nl;
    int i;
    int min = 1000000;
    int max = -1000000;
    
    scanf ("%d", &n);
    
    for (int k = 0; k < n; k++) {
        scanf ("%d", &nl);
        for (int j = 0; j < nl; j++) {
            scanf ("%d", &i);
            
            if (i < min) {
                min = i;
            }
            
            if (i > max) {
                max = i;
            }
        }
        
        printf ("Case %d: %d %d %d\n", k + 1, min, max, max - min);
        
        min = 1000000;
        max = -1000000;
    }
    
    return 0;
}
