#include <stdio.h>

// Function declarations
void checkBalance(float balance);
float deposit(float balance, float amount);
float withdraw(float balance, float amount);

int main() {
    float balance = 1000.00, amount;
    int choice;

    do {
        // Display ATM menu
        printf("\n==== ATM MENU ====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance = deposit(balance, amount);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                balance = withdraw(balance, amount);
                break;

            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to check balance
void checkBalance(float balance) {
    printf("Your current balance is: %.2f\n", balance);
}

// Function to deposit money
float deposit(float balance, float amount) {
    if (amount > 0) {
        balance += amount;
        printf("Deposit successful! New balance: %.2f\n", balance);
    } else {
        printf("Invalid deposit amount!\n");
    }
    return balance;
}

// Function to withdraw money
float withdraw(float balance, float amount) {
    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
    } else if (amount > balance) {
        printf("Insufficient balance! Withdrawal failed.\n");
    } else {
        balance -= amount;
        printf("Withdrawal successful! New balance: %.2f\n", balance);
    }
    return balance;
}
