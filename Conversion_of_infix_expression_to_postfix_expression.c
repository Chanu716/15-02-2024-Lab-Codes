#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return -1;
}
int is_operand(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return 1;
    if (ch >= 'A' && ch <= 'Z')
        return 1;
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

void infix_to_postfix(char *infix_expression) {
    int i, j = 0;
    char postfix_expression[100];
    char stack[100];
    int top = -1;

    for (i = 0; infix_expression[i]; i++) {
        if (is_operand(infix_expression[i])) {
            postfix_expression[j++] = infix_expression[i];
            postfix_expression[j++] = ' ';
        }
        else if (infix_expression[i] == '(') {
            stack[++top] = infix_expression[i];
        }
        else if (infix_expression[i] == ')') {
            while (stack[top] != '(') {
                postfix_expression[j++] = stack[top--];
                postfix_expression[j++] = ' ';
            }
            top--;
        }
        else {
            while (top >= 0 && precedence(infix_expression[i]) <= precedence(stack[top])) {
                postfix_expression[j++] = stack[top--];
                postfix_expression[j++] = ' ';
            }
            stack[++top] = infix_expression[i];
        }
    }

    while (top >= 0) {
        postfix_expression[j++] = stack[top--];
        postfix_expression[j++] = ' ';
    }
   printf("Postfix expression: %s\n", postfix_expression);
}

int main() {
    char infix_expression[100];

    printf("Enter infix expression: ");
    fgets(infix_expression, sizeof(infix_expression), stdin);
    infix_expression[strcspn(infix_expression, "\n")] = 0;

    infix_to_postfix(infix_expression);

    return 0;
}
