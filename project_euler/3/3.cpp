#include <cstdio>

int main () {

    long long number = 600851475143;

    long long i = 2;
    for (i = 2; i < number; i++) {
        while (number % i == 0) {
            number = number / i;
        }
    }

    printf ("%lld\n", number);

    return 0;
}
