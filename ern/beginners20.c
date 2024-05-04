#include <stdio.h>

void fibonacci(int limit) {
    int num1 = 0, num2 = 1, nextTerm;


    for (int i = 1; i <= limit; ++i) {
        printf("%d, ", num1);
        nextTerm = num1 + num2;
        num1 = num2;
        num2 = nextTerm;
    }
    printf("%d",num1);
}

int main() {
    int limit;

    scanf("%d", &limit);

    fibonacci(limit);

    return 0;
}
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765
