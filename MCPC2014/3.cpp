#include <cstdio>

int main () {

    int n;
    char c[10];
    
    scanf ("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf ("%s", c);
        
        int j = 0;
        for (j = 0; j < 10; j++) {
            if (c[j] == '\0') {
                break;
            }
        }
        
        bool s0 = true;
        for (int k = j - 1; k >=0; k--) {
            if (c[k] != '0') {
                s0 = false;
            }
            
            if (!s0) {
                printf ("%c", c[k]);
            }
        }
        
        printf ("\n");
    }
    
    return 0;
}
