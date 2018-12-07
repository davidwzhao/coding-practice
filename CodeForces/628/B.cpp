#include <cstdio>

using namespace std;

int main() {
    int s[300005];
    int i = 0;
    int num = 0;

    long long** m = new long long*[300005];

    for (int j = 0; j < 300005; j++) s[j] = 0;

    char c;
    while (scanf("%c", &c) > 0) {
        if (c >= '0' && c <= '9') num++;
        s[i] = c - '0';
        i++;
    }

    for (int j = 0; j < 300005; j++) {
        m[j] = new long long[3];
        m[j][0] = 0;
        m[j][1] = 0;
        m[j][2] = 0;
    }

    for (i = num - 1; i >= 0; i--) {
        if (s[i] % 4 == 1 || s[i] % 4 == 3) {
            m[i][1] += m[i+1][2];
            m[i][1] += m[i+1][1];
        } else {
            m[i][1] += m[i+1][1];
            m[i][1] += m[i+1][0];
        }

        if (s[i] % 4 == 0) m[i][0]++;
        else if (s[i] % 4 == 2) m[i][2]++;
    }

    long long t = 0;
    for (int j = 0; j < num; j++) {
        t += m[j][0] + m[j][1];
    }

    printf("%I64d\n", t);

    for (int j = 0; j < 300005; j++) {
        delete[] m[j];
    }

    delete[] m;

    return 0;
}
