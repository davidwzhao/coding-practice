#include <cstdio>

// int qCache[1000005];
int nums[100];


int q (int i, int num) {

    if (num == 0 || num == 1) {
        // qCache[num] = 0;
        return 0;
    // } else if (num == 2) {
    //     return i % 2;
    // } else if (qCache[num] != -1) {
    //     return qCache[num];
    } else {
        // qCache[num] = (i % num) ^ q(i, num - 1);
        // printf ("i = %d, num = %d, i mod num = %d\n", i, num, i % num);
        nums[i % num]++;
        return (i % num) ^ q(i, num - 1);
    } 
}

int main () {

    int num;
    int qValues[1000005];
    int answer = 0;
    int max;
    
    /* for (int i = 0; i < 1000005; i++) {
        qCache[i] = -1;
    } */
    
    for (int i = 0; i < 100; i++) {
        nums[i] = 0;
    }
    
    scanf ("%d", &num);
    
    for (int i = 1; i <= num; i++) {
        // scanf ("%d", &qValues[i]);
        // max = i + num;
        /* for (int j = max; j > i; j--) {
            if (j == i || j == i + 1) {
                qCache[j] = 0;
                qValues[i] = 0;
            } else if (j == i + 2) {
                qValues[i] = qValues[i] ^ (i % 2);
            } else if (qCache[j] != -1) {
                qValues[i] = qCache[j];
            } else {
                qCache[j] = (j % num) ^ qCache[j + 1];
                qValues[i] = qCache[j];
            }
        } */ 
        // qValues[i] = qValues[i] ^ (q (i, num));
        q(i, num);
    }
    
    for (int i = 1; i <= num; i++) {
        printf ("%d ", nums[i]);
    }
    
    /* for (int i = 1; i <= num; i++) {
        printf ("q = %d\n", qValues[i]);
        answer = answer ^ qValues[i];
    } */
    
    // printf ("%d\n", answer);
    
    printf ("\n");
    
    return 0;
}
