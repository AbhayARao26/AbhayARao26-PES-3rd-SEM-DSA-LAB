/*
 Infix to postfix
 
 Design and implement an algorithm to convert infix mathematical expressions to postfix notation using a stack data structure. The algorithm should be capable of handling expressions containing operators such as addition (+), subtraction (-), multiplication (*), division (/), and parentheses. The goal is to develop a program that can efficiently and accurately convert infix expressions to postfix notation while respecting operator precedence and parentheses.

 Key Requirements:
     1. Accept infix mathematical expressions as input from the user or a file.
     2. Handle the following operators with correct precedence: + (addition), - (subtraction), * (multiplication), / (division).
     3. Properly handle parentheses to ensure correct order of operations.
     4. Output the corresponding postfix notation of the input expression.
     5. Implement the algorithm using a stack data structure to track operators and operands.
 
 Input Format:
    Infix Expression

 Constraints:
    None

 Output Format:
    Postfix Expression

 Sample Input:
    (3+4)*2/(5-2)
 
 Sample Output:
    34+2*52-/
 */

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct OpearatorList{
    char currOperator;
    struct OperatorList* link;
}OL;

OL* makeOperator(char myChar) {
    OL* myValue = (OL*) malloc (sizeof(OL));
    myValue->link = NULL;
    myValue->currOperator = myChar;
    return myValue;
}

OL* pushOperator(OL* myValue, char myChar){
    OL* LinkedList = makeOperator(myChar);
    if(myValue == NULL){
        return LinkedList;
    }
    else{
        LinkedList->link = myValue;
        return LinkedList;
    }
}

int whatPrecendence(char symbol)
{
    switch (symbol)
    {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '$':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}

bool isOperator(char symbol)
{
    if ((symbol=='(') || (symbol==')') || (symbol=='/') || (symbol=='*') || (symbol=='+') || (symbol=='-') || (symbol=='$'))
        return true;
    else
        return false;
}

OL* myPopper(OL* myOL){
    OL* tempVal = myOL;
    myOL = myOL->link;
    free(tempVal);
    return myOL;
}

bool isHigherPrecedence(OL* myOL, char currChar){
    if(currChar=='$'){
        if((whatPrecendence(myOL->currOperator)>whatPrecendence(currChar)))
            return true;
        else
            return false;
    }
    else{
        if((whatPrecendence(myOL->currOperator)>=whatPrecendence(currChar)))
            return true;
        else
            return false;
    }
}

void displayOL(OL* myRemainingOperator){
    while ((myRemainingOperator != NULL) && (myRemainingOperator->currOperator !='(')) {
        printf("%c", myRemainingOperator->currOperator);
        myRemainingOperator = myRemainingOperator->link;
    }
}

void charReader(char myArr[], OL* myOL){
    unsigned long mySize = strlen(myArr);
    
    for (int i=0; i<mySize; i++) {
        if((myArr[i] == '\t') || (myArr[i] == ' '))
            continue;
        
        else if (!isOperator(myArr[i]))
            printf("%c", myArr[i]);
        
        // Case of Detecting Operators
        else {
            if(myArr[i] == '(')
                myOL = pushOperator(myOL, '(');
            
            else if (myArr[i] == ')'){
                while((myOL->currOperator) != '('){
                    printf("%c", myOL->currOperator);
                    myOL = myPopper(myOL);
                }
                myOL = myPopper(myOL);
            }
            
            else if (isHigherPrecedence(myOL, myArr[i])) {
                while(isHigherPrecedence(myOL, myArr[i])) {
                    printf("%c", myOL->currOperator);
                    myOL = myPopper(myOL);
                }
                myOL = pushOperator(myOL, myArr[i]);
            }
            
            else
                myOL = pushOperator(myOL, myArr[i]);
        }
    }
    displayOL(myOL);
    printf("\n");
}

int main()
{
    char myArr[50];
    scanf("%[^\n]s", myArr);
    OL* myOL = makeOperator(' ');
    charReader(myArr, myOL);
    return 0;
}
