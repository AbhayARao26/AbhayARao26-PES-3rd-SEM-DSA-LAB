/*
 Evaluation of prefix expressions
 
 Design and implement an algorithm to evaluate prefix expressions using stacks. Given a prefix expression as input, the goal is to develop a program that can efficiently parse and evaluate the expression to produce the correct result. The program should support various arithmetic operators (+, -, *, /) and handle both positive and negative integers. Ensure that the solution adheres to the following requirements:

 1. Input Parsing: The program should take a valid prefix expression as input, where operators and operands are separated by spaces. For example, "+ 5 3" represents the infix expression "5 + 3".

 2. Stack Implementation: Utilize a stack data structure to parse and evaluate the expression. Implement the stack using an appropriate data structure (e.g., an array or linked list) and define the necessary stack operations (push, pop, peek, etc.).

 3. Operator Precedence: Ensure correct operator precedence and associativity in the evaluation of expressions. For example, "* 2 + 3 4" should be evaluated as "(2 * (3 + 4))".

 4. Error Handling: Handle invalid expressions gracefully, providing informative error messages in case of syntax errors or division by zero.

 5. Output: Output the result of the evaluation, which should be the final value of the prefix expression.

 6. Efficiency: Strive for efficient evaluation by minimizing unnecessary operations and optimizing stack usage.

 7. User-Friendly Interface: Provide a user-friendly interface for entering prefix expressions and displaying the results.
 
 Input Format:
    Prefix Expression

 Constraints:
    None

 Output Format:
    Evaluated value

 Sample Input:
    +53
 
 Sample Output:
    8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    int top;
    int numOfItems;
    int* items;
} STACK;

STACK* createStack(int num){
    STACK* myStack = (STACK*) malloc (sizeof(STACK));
    myStack->numOfItems = num;
    myStack->items = (int*) malloc ((sizeof(int) * num));
    myStack->top = -1;
    return myStack;
}

int isEmpty(STACK* myStack){
    int result = (myStack->top == -1);
    return result;
}

void push(STACK* myStack, int val){
    myStack->items[++myStack->top] = val;
}

int pop(STACK* myStack){
    return myStack->items[myStack->top--];
}

int isDigit(char c){
    int result = (c >= '0' && c <= '9');
    return result;
}

int evalPrefixExp(char* exp){
    STACK* myStack = createStack(strlen(exp));
    
    int length = strlen(exp);
    for(int i = length-1; i>=0; i--){
        
        if(isDigit(exp[i]))
            push(myStack, exp[i] - '0');
        
        else if(exp[i] == ' ')
            continue;
        
        else{
            
            if(isEmpty(myStack)){
                printf("Error : Invalid expression\n");
                exit(1);
            }
            int op1 = pop(myStack);
            
            if (isEmpty(myStack)){
                printf("Error : Invalid expression\n");
                exit(1);
            }
            int op2 = pop(myStack);
            
            switch(exp[i])
            {
                case '+':
                    push(myStack, op1 + op2);
                    break;
                    
                case '-':
                    push(myStack, op1 - op2);
                    break;
                    
                case '*':
                    push(myStack, op1 * op2);
                    break;
                    
                case '/':
                    if(op2 == 0){
                        printf("Error : Division by zero\n");
                        exit(1);
                    }
                    push(myStack, op1 / op2);
                    break;
                    
                case '$':
                    if(op2 == 0){
                        push(myStack, 1);
                        exit(1);
                    }
                    push(myStack, op1^op2);
                    break;
                    
                default:
                    printf("Error : Invalid operator\n");
                    break;
            }
        }
    }
    
    
    if(isEmpty(myStack)){
        printf("Error : Invalid expression\n");
        exit(1);
    }
    
    int result = pop(myStack);
    
    if(!isEmpty(myStack)){
        printf("Error : Invalid expression\n");
        exit(1);
    }
    
    
    return result;
}

int main(){
    char exp[100];
    fgets(exp, sizeof(exp), stdin);
    
    int length = strlen(exp);
    exp[length] = '\0';
    
    int result = evalPrefixExp(exp);
    printf("%d\n", result);
    
    return 0;
}


