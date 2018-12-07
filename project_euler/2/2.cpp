#include <cstdio>

int fibCache[100];
int sumEvenFib = 0;

int fibonacci (int nFibonacci) {

    int fibonacciNumber = 0;

    if (nFibonacci == 1) {
        fibonacciNumber = 1;
    } else if (nFibonacci == 2) {
        fibonacciNumber = 2;
    } else if (fibCache[nFibonacci] != -1) {
        fibonacciNumber = fibCache[nFibonacci];
    } else {
        fibonacciNumber = fibonacci (nFibonacci - 1) + fibonacci (nFibonacci - 2);
    }

    if (fibCache[nFibonacci] == -1) {
        fibCache[nFibonacci] = fibonacciNumber;
    }

//    if (fibonacciNumber % 2 == 0) {
//        sumEvenFib += fibonacciNumber;
//    }

    return fibonacciNumber;
}

int findFib () {

    int i = 35;

    for (i = 35; i > 20; i--) {
        if (fibonacci(i) < 4000000) {
            break;
        }
    }

//    sumEvenFib = 0;

//    int fibonacciNumber = fibonacci(i);

    return i;
}

int main () {

    for (int i = 0; i < 100; i++) {
        fibCache[i] = -1;
    }

    int fibonacciNumber = findFib();

    int i = 0;
    for (i = 0; i <= fibonacciNumber; i++) {
        if (fibonacci(i) % 2 == 0) {
            sumEvenFib += fibonacci(i);
        }
    }

    printf ("%d %d\n", fibonacci(i), sumEvenFib);

    return 0;
}

    
