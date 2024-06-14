// STACK
// INFIX EXPRESSION
// <operand> <operator> <operand>

// PRECEDENCE ORDER

// 1 -----> (),{},[]
// 2 -----> ^ (R -> L)
// 3 -----> * , / (L -> R)
// 4 -----> + , - (L -> R)

#include <stdio.h>
#include <stdlib.h>

struct operatorNode
{
    char data;
    struct operatorNode *next;
};

struct operatorStack
{
    int size;
    struct operatorNode *top;
};

struct operatorStack *createStack()
{
    struct operatorStack *new_stack = (struct operatorStack *)malloc(sizeof(struct operatorStack));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

int isEmpty(struct operatorStack *stack)
{
    return (stack->size == 0);
}

char peek(struct operatorStack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return '\0';
    }
    return ((stack->top)->data);
}

char pop(struct operatorStack *stack)
{
    struct operatorNode *temp;
    char temp_data;
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return '\0';
    }
    temp = stack->top;
    temp_data = temp->data;
    stack->size -= 1;
    stack->top = temp->next;
    free(temp);
    return temp_data;
}

void push(struct operatorStack *stack, char op)
{
    struct operatorNode *new_top = (struct operatorNode *)malloc(sizeof(struct operatorNode));

    new_top->data = op;
    new_top->next = stack->top;
    stack->top = new_top;
    stack->size += 1;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

int evaluate(char *s)
{
    
}

int main()
{
    printf("%d \n", evaluate("10 + 2 * 6"));
    printf("%d \n", evaluate("100 * 2 + 12"));
    printf("%d \n", evaluate("100 * ( 2 + 12 )"));
    printf("%d \n", evaluate("100 * ( 2 + 12 ) / 14"));
    return 0;
}