#include <cstdio>

int main () {

    // freopen ("test.txt", "r", stdin);

    char c;
    int lines = 0;
    
    while (scanf ("%c", &c) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    
    printf ("%d\n", lines);
    
    return 0;
}
