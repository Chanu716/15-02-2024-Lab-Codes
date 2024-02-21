#include <stdio.h>
#include <stdlib.h>

double evaluateExpression(char expression[]) {
    char operators[100];
    double operands[100];
    int opCount = 0;
    int numCount = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operators[opCount++] = expression[i];
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            double num = expression[i] - '0';

            while (expression[i + 1] >= '0' && expression[i + 1] <= '9') {
                num = num * 10 + (expression[i + 1] - '0');
                i++;
            }

            operands[numCount++] = num;
        }
    }

    double result = operands[0];

    for (int i = 0; i < opCount; i++) {
        switch (operators[i]) {
            case '+':
                result += operands[i + 1];
                break;
            case '-':
                result -= operands[i + 1];
                break;
            case '*':
                result *= operands[i + 1];
                break;
            case '/':
                if (operands[i + 1] != 0) {
                    result /= operands[i + 1];
                } else {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                printf("Error: Invalid operator\n");
                exit(EXIT_FAILURE);
        }
    }

    return result;
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '\n') {
            expression[i] = '\0';
            break;
        }
    }

    double result = evaluateExpression(expression);

    printf("Result: %lf\n", result);

    return 0;
}
