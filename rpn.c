//
// Created by 김재훈 on 2021/04/01.
//

#include "rpn.h"
#include "stack.h"
#include "node.h"
#include "errors.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node {
    double value;
    int type;
    node *next;
} node;


double power(double num1, double num2)
{
    double result = 1;
    while (num2 != 0) {
        result *= num1;     // result = result * num1
        --num2;              // Decrement first and then return num2
    }
    return result;
}

double evaluate (char* expression, int* status) {
    char *token;
    node *temp;
    node *result;
    node *first;
    node *second;
    int num_count = 0;
    int op_count = 0;
    token = strtok(expression, " ");
    while (token != NULL) {
        // printf(" %s", token);
        if (atof(token) != 0) {
            temp = createNode(atof(token), 1);
            push(*temp);
            num_count++;
        }
        else {
            char op = *token;
            //printf("char %c", *token);
            first = pop();
            second = pop();
            if  (second == NULL) {
                if (num_count != 0) {
                    print_error(TOOMANY);
                    return 0;
                }
                else {
                    print_error(onlyone);
                    return 0;
                }
            }
            switch (op) {
                case '+':
                    temp = createNode(second->value + first->value, 1);
                    //printf(" node %f\n", temp->value);
                    push(*temp);
                    op_count++;
                    break;
                case '-':
                    temp = createNode(second->value - first->value,1);
                    push(*temp);
                    op_count++;
                    break;
                case '/':
                    temp = createNode(second->value / first->value,1);
                    push(*temp);
                    op_count++;
                    break;
                case '*':
                    temp = createNode(second->value * first->value,1);
                    push(*temp);
                    op_count++;
                    break;
                case '^':
                    temp = createNode(power(second->value, first->value),1);
                    push(*temp);
                    op_count++;
                    break;
            }
        }
        token = strtok(NULL, " ");
    }
    if (op_count >= num_count && num_count != 0) {
        print_error(TOOMANY);
        return 0;
    }
    else if (num_count - op_count >= 2) {
        print_error(TOOFEW);
        return 0;
    }
    else if (num_count == 0) {
        print_error(NULLPTR);
        return 0;
    }
    else {
        result = pop();
        double res = result->value;
        clearStack(result);
        print_error(SUCCESS);
        return res;
    }
}