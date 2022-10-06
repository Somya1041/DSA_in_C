# include <stdio.h>

int exp[100], top, data, n = 20;
void push(int data);
void pop();

void push(int data)
{
    top++;
    exp[top] = data;
}

 void pop()
{
    deleted = exp[top];
    top--;
}

int main()
{
    char exp[100];
    int op1, op2, result;

    printf("Enter the expression: ");
    gets(exp);
    printf("entered exp is: %s", exp);

    for(int i = n; i >= 0; i--)
    {
        if(typeof(exp[i]) == int)
        {
            push(exp[i]);
        }
        else
        {
            if(typeof(exp[i]) == char)
            {
                pop();
                op1 = exp[top];
                op2 = exp[top - 1];

                result = op1 char op2;
            }
        }
        result = push(exp[top]);
    }
    return exp[top];
} 