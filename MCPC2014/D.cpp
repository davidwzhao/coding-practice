#include <cstdio>
#include <queue>

using namespace std;

int main () {

    // freopen ("test.txt", "r", stdin);

    int t, n;
    
    scanf ("%d", &t);
    
    for (int i = 0; i < t; i++) {
        
        queue <int> q;
        int w = 0;
        int g = 0;
        int prevm = 0;
        scanf ("%d", &n);
        
        for (int j = 0; j < n; j++) {
            int m, p;
            char s;
            
            scanf (" %d ", &m);
            scanf ("%c", &s);
            
            if (s == 'S') {
                p = 3;
            } else if (s == 'M') {
                p = 4;
            } else if (s == 'L') {
                p = 5;
            } else if (s == 'X') {
                scanf ("%c", &s);
                if (s == 'S') {
                    p = 2;
                } else if (s == 'L') {
                    p = 6;
                }
            }
            
            g += 2 * (m - prevm);
            
            q.push(p);
            while (!q.empty() && q.front() <= g) {
                g -= q.front();
                q.pop();
            }
            
            if (!q.empty()) {
                w++;
            }
            
            prevm = m;
        }
        
        printf ("%d\n", w);
    }
    
    return 0;
}
