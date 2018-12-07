#include <iostream>
#include <algorithm>

using namespace std;

int values[80][80];
int dist[80][80];

int main () {

    int N;
    cin >> N;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> values[r][c];
        }
    }
    
    dist[0][0] = values[0][0];
    
    for (int r = 1; r < N; r++) dist[r][0] = values[r][0];
    
    /*
    for (int c = 1; c < N; c++) {
        dist[0][c] = dist[0][c-1] + values[0][c];
        cout << dist[0][c] << endl;
    }
    */
    
    for (int c = 1; c < N; c++) {
        for (int r = 0; r < N; r++) {
            if (r == 0) dist[r][c] = dist[r][c-1] + values[r][c];
            else {
                dist[r][c] = min (dist[r-1][c], dist[r][c-1]) + values[r][c];
                for (int j = r-1; j >= 0; j--) dist[j][c] = min (dist[j][c], dist[j+1][c] + values[j][c]);
            }
        }
    }
    
    int max = dist[0][N-1];
    for (int r = 0; r < N; r++) {
        if (dist[r][N-1] < max) max = dist[r][N-1];
    }
    
    cout << max << endl;
        
    return 0;
}
