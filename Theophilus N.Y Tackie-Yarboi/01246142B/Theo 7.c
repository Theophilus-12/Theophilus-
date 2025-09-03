#include <stdio.h>

// Function declaration
char calculateGrade(int marks);

int main() {
    int marks;
    char grade;

    printf("Enter student marks (0 to 100): ");
    scanf("%d", &marks);   // <--- missing in your screenshot

    // Validate marks
    if (marks < 0 || marks > 100) {
        printf("Invalid input! Marks must be between 0 and 100.\n");
    } else {
        // Function call
        grade = calculateGrade(marks);
        printf("Grade: %c\n", grade);
    }

    return 0;
}

// Function definition
char calculateGrade(int marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}
