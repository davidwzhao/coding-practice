#include <cstdio>

int grid[105][105];

void swap (int i1, int j1, int i2, int j2) {

    int temp = grid[i1][j1];
    grid[i1][j1] = grid[i2][j2];
    grid[i2][j2] = temp;
}

int main () {

    // freopen ("test.txt", "r", stdin);
    
    int t, m, n;
    
    scanf ("%d", &t);
    
    for (int i = 0; i < t; i++) {
    
        for (int j = 0; j < 105; j++) {
            for (int k = 0; k < 105; k++) {
                grid[j][k] = -1;
            }
        }
    
        scanf ("%d %d", &m, &n);
        
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf ("%d", &grid[j][k]);
            }
        }
        
        int j = 0;
        int k = 0;
        
        while (j < n || k < m) {
            // bubble rows
            if (j < n) {
                int l1 = 0;
                while (l1 < m) {
                    int l = 0;
                    while (l < n - 1) {
                        if (grid[l1][l] > grid[l1][l + 1]) {
                            swap (l1, l, l1, l + 1);
                            printf ("(%d,%d)<-->(%d,%d)\n", l1, l, l1, l + 1);
                        }
                        l++;
                    }
                    l1++;
                }
                j++;
            }
            // bubble columns
            if (k < m) {
                int p1 = 0;
                while (p1 < n) {
                    int p = 0;
                    while (p < m - 1) {
                        if (grid[p][p1] > grid[p + 1][p1]) {
                            swap (p, p1, p + 1, p1);
                            printf ("(%d,%d)<-->(%d,%d)\n", p, p1, p + 1, p1);
                        }
                        p++;
                    }
                    p1++;
                }
                k++;
            }
        }
        
        printf ("DONE\n");
    }
    
    return 0;
}
