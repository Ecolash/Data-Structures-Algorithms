#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned int capacity;
    char *array;
};

struct Stack *createStack(unsigned int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

int isFull(struct Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

char peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int getPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *infix, char *postfix)
{
    struct Stack *stack = createStack(strlen(infix));
    int i, j;
    i = j = 0;

    while (infix[i])
    {
        char currentChar = infix[i];

        if (isOperand(currentChar))
        {
            postfix[j++] = currentChar;
        }
        else if (currentChar == '(')
        {
            push(stack, currentChar);
        }
        else if (currentChar == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && getPrecedence(currentChar) <= getPrecedence(peek(stack)))
            {
                postfix[j++] = pop(stack);
            }
            push(stack, currentChar);
        }
        i++;
    }

    while (!isEmpty(stack))
    {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    if (strlen(infix) > 0 && infix[strlen(infix) - 1] == '\n')
    {
        infix[strlen(infix) - 1] = '\0';
    }

    char postfix[100];
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
