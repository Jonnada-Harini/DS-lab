#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expression) {
    int i = 0;
    char ch;
    int val;

    while ((ch = expression[i]) != '\0') {
        // If whitespace, skip
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        // If digit, convert to integer and push
        if (isdigit(ch)) {
            val = 0;
            while (isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            push(val);
        } else {
            // Operator encountered, pop two operands
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
            i++;
        }
    }

    return pop();
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression (space separated):\n");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePostfix(expression);
    printf("Result = %d\n", result);

    return 0;
}
