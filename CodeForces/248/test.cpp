#include <cstdio>

int main () {

    freopen ("test.txt", "w", stdout);

    printf ("10000\n");

    for (int i = 0; i < 10000; i++) {
        printf ("1000000000 ");
    }
    
    printf ("\n10000\n");
    
    for (int i = 0; i < 10000; i++) {
        printf ("1 1 10000\n");
    }
    
    return 0;
}
