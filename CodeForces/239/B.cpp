#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    char sheets[1005];
    char garland[1005];
    
    for (int k = 0; k < 1005; k++) {
        sheets[k] = '\0';
        garland[k] = '\0';
    }
    
    int i = 0;
    int j = 0;
    while (true) {
        scanf ("%c", &sheets[i]);
        if (sheets[i] == '\n') {
            sheets[i] = '\0';
            break;
        }
        i++;
    }
    
    while (true) {
        scanf ("%c", &garland[j]);
        if (garland[j] == '\n') {
            garland[j] = '\0';
            break;
        }
        j++;
    }
    
    sort (sheets, sheets+i);
    sort (garland, garland+j);
    
    int l = 0;
    int m = 0;
    int n = 0;
    int countsS[26];
    int countsG[26];
    int totalArea = 0;
    
    for (int p = 0; p < 26; p++) {
        countsS[p] = 0;
        countsG[p] = 0;
    }
    
    while (!(sheets[l] == '\0' || garland[m] == '\0')) {
        for (char c = 'a'; c <= 'z'; c++) {
            while (sheets[l] == c) {
                countsS[c - 97]++;
                l++;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            while (garland[m] == c) {
                countsG[c - 97]++;
                m++;
            }
        }
        l++;
        m++;
    }
    
    for (int o = 0; o < 26; o++) {
        if (countsS[o] == 0 && countsG[o] > 0) {
            totalArea = -1;
            break;
        }
        totalArea += min(countsS[o], countsG[o]);
    }
    
    if (totalArea == 0) {
        totalArea = -1;
    }
    printf ("%d\n", totalArea);
    
    return 0;
}
