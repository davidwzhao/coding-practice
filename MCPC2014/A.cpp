#include <cstdio>

int main () {

    int n;
    int s[26];
    char c;
    int num = 0;
    
    scanf (" %d ", &n);
    
    for (int i = 0; i < 26; i++) {
        s[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        scanf ("%c", &c);
        while (c != '\n') {
            s[c - 'a']++;
            scanf ("%c", &c);
        }
        
        for (int j = 0; j < 26; j++) {
            num += s[j] % 2;
        }
        
        printf ("%d\n", num);
        
        for (int j = 0; j < 26; j++) {
            s[j] = 0;
        }
        num = 0;
    }
    
    return 0;
}
