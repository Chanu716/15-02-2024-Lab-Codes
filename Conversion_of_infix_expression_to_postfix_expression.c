#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return -1;
}

// Check if the character is an operand
int is_operand(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return 1;
    if (ch >= 'A' && ch <= 'Z')
        return 1;
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

// Convert infix to postfix expression
void infix_to_postfix(char *infix_expression) {
    int i, j = 0;
    char postfix_expression[100];
    char stack[100];
    int top = -1;

    // Traverse through each character in the infix expression
    for (i = 0; infix_expression[i]; i++) {
        // If the character is an operand, add it to the postfix expression
        if (is_operand(infix_expression[i])) {
            postfix_expression[j++] = infix_expression[i];
            postfix_expression[j++] = ' ';
        }
        // If the character is an open parenthesis, push it to the stack
        else if (infix_expression[i] == '(') {
            stack[++top] = infix_expression[i];
        }
        // If the character is a close parenthesis, pop and add operators to the postfix expression until an open parenthesis is encountered
        else if (infix_expression[i] == ')') {
            while (stack[top] != '(') {
                postfix_expression[j++] = stack[top--];
                postfix_expression[j++] = ' ';
            }
            top--;  // Remove the open parenthesis from the stack
        }
        // If the character is an operator
        else {
            // While the stack is not empty and the top operator has higher or equal precedence, pop operators and add them to the postfix expression
            while (top >= 0 && precedence(infix_expression[i]) <= precedence(stack[top])) {
                postfix_expression[j++] = stack[top--];
                postfix_expression[j++] = ' ';
            }
            stack[++top] = infix_expression[i];  // Push the current operator to the stack
        }
    }

    // Pop and add remaining operators to the postfix expression
    while (top >= 0) {
        postfix_expression[j++] = stack[top--];
        postfix_expression[j++] = ' ';
    }

    // Print postfix expression
    printf("Postfix expression: %s\n", postfix_expression);
}

int main() {
    char infix_expression[100];

    // Get infix expression from user
    printf("Enter infix expression: ");
    fgets(infix_expression, sizeof(infix_expression), stdin);

    // Remove newline character from the input
    infix_expression[strcspn(infix_expression, "\n")] = 0;

    // Convert infix to postfix expression
    infix_to_postfix(infix_expression);

    return 0;
}