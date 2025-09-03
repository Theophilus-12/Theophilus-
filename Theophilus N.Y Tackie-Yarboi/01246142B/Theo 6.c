	#include <stdio.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (op) {
        case '+':
            printf("Result: %.2lf\n", add(num1, num2));
            break;
        case '-':
            printf("Result: %.2lf\n", subtract(num1, num2));
            break;
        case '*':
            printf("Result: %.2lf\n", multiply(num1, num2));
            break;
        case '/':
            if (num2 != 0)
                printf("Result: %.2lf\n", divide(num1, num2));
            else
                printf("Error! Division by zero is not allowed.\n");
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}
