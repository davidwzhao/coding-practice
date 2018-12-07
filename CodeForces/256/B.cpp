#include <cstdio>
#include <cstring>

using namespace std;

int main () {

    char w1[105];
    char w2[105];
    
    scanf ("%s", w1);
    scanf ("%s", w2);
    
    bool automation = true;
    bool array = false;
    bool tree = false;
    
    if (strlen (w1) == strlen (w2)) {
        automation = false;
    } else if (strlen (w1) < strlen (w2)) {
        tree = true;
    }
    
    /*
    if (strstr (w1, w2) != 0) {
        array = false;
    }
    */
    
    char *temp;
    char *w1temp = w1;    
    for (int i = 0; i < strlen (w2); i++) {
        if (strchr (w1temp, w2[i]) == 0) {
            array = true;
        }
        
        if (strchr (w1, w2[i]) == 0) {
            tree = true;
        } else {
            if (strchr (w1temp, w2[i]) != 0) {
                w1temp = strchr(w1temp, w2[i]);
            }
            printf ("%s\n", w1temp);
            temp = strchr(w1, w2[i]);
            *temp = '%';
        }
    }
    
    /*
    for (int i = 0; i < strlen(w2) - 1; i++) {
        if (mem[i + 1] < mem[i]) {
            array = true;
        }
    }
    */
    
    if (tree) {
        printf ("need tree\n");
    } else {
        if (automation && array) {
            printf ("both\n");
        } else if (automation) {
            printf ("automaton\n");
        } else if (array) {
            printf ("array\n");
        }
    }
    
    return 0;
}
