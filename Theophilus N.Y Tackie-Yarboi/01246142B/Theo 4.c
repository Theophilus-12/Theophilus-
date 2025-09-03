#include <stdio.h>

// Function to display Fibonacci series
void fibonacci(int n) {
    int a = 0, b = 1, next, i;

    printf("Fibonacci series: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int terms;
    printf("Enter number of terms: ");
    scanf("%d", &terms);
    fibonacci(terms);
    return 0;
}
