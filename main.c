#include <stdio.h>

#include "rpn.h"
#include "errors.h"
#include "stack.h"
#include "string.h"
int main() {
    char expression[100];
    double result;
    int status = 0;

    printf("\nWelcome to my RPN calculator.\n");
    printf("Enter floats and + - / * ^ in RPN format: \n >");
    fgets(expression,100, stdin);

    result = evaluate(expression,&status);
    printf("result is %f\n",result);
    return 0;
}
