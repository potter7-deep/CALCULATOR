#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float square_root(float a);

float memory = 0.0f;

/* Simple square root implementation for portability */
float square_root(float x) {
    if (x < 0) return 0.0f/0.0f; /* NaN */
    if (x == 0) return 0.0f;
    
    float guess = x;
    float precision = 0.00001f;
    
    while ((guess * guess - x) > precision || (x - guess * guess) > precision) {
        guess = (guess + x / guess) / 2.0f;
    }
    
    return guess;
}

int main() {
    int choice;
    float num1 = 0.0f, num2 = 0.0f, result = 0.0f;
    char cont = 'y', useMemory = 'n';

    do {
        printf("\n=== Calculator ===\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Square Root (√)\n");
        printf("6. Memory Recall (MR)\n");
        printf("7. Memory Clear (MC)\n");
        printf("8. Exit\n");
        printf("Choose operation (1-8): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); /* Clear input buffer */
            continue;
        }

        switch (choice) {
            case 1: case 2: case 3: case 4:
                printf("Use memory for first number? (y/n): ");
                scanf(" %c", &useMemory);
                if (useMemory == 'y' || useMemory == 'Y') {
                    num1 = memory;
                    printf("Using memory value: %.2f\n", num1);
                } else {
                    printf("Enter first number: ");
                    if (scanf("%f", &num1) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n'); /* Clear input buffer */
                        continue;
                    }
                }

                printf("Enter second number: ");
                if (scanf("%f", &num2) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); /* Clear input buffer */
                    continue;
                }

                switch (choice) {
                    case 1:
                        result = add(num1, num2);
                        printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                        break;
                    case 2:
                        result = subtract(num1, num2);
                        printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                        break;
                    case 3:
                        result = multiply(num1, num2);
                        printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                        break;
                    case 4:
                        if (num2 == 0) {
                            printf("Error: Division by zero!\n");
                            result = 0.0f/0.0f; /* NaN */
                        } else {
                            result = divide(num1, num2);
                            printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                        }
                        break;
                }

                printf("Save result to memory? (y/n): ");
                scanf(" %c", &useMemory);
                if (useMemory == 'y' || useMemory == 'Y') {
                    memory = result;
                    printf("Memory saved: %.2f\n", memory);
                }
                break;

            case 5:
                printf("Enter number to find square root: ");
                if (scanf("%f", &num1) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); /* Clear input buffer */
                    continue;
                }
                if (num1 < 0) {
                    printf("Error: Cannot calculate square root of negative number!\n");
                    result = 0.0f/0.0f; /* NaN */
                } else {
                    result = square_root(num1);
                    printf("Result: √%.2f = %.2f\n", num1, result);
                }

                printf("Save result to memory? (y/n): ");
                scanf(" %c", &useMemory);
                if (useMemory == 'y' || useMemory == 'Y') {
                    memory = result;
                    printf("Memory saved: %.2f\n", memory);
                }
                break;

            case 6:
                printf("Memory Recall: %.2f\n", memory);
                break;

            case 7:
                memory = 0.0f;
                printf("Memory cleared.\n");
                break;

            case 8:
                printf("Thanks for using the enhanced calculator!\n");
                return 0;

            default:
                printf("Invalid option! Please choose 1-8.\n");
        }

        printf("Continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}

/* Basic arithmetic functions */
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }