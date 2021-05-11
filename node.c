//
// Created by 김재훈 on 2021/04/01.
//

#include "node.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct node {
    double value;
    int type;
    node *next;
} node;

enum expression {NUMBER, OPERATOR};

node* createNode(double value, int type) {
    newNode = NULL;
    newNode = (struct node*) malloc(sizeof(node));
    if (newNode) {
        newNode->value = value;
        if (type == NUMBER) {
            newNode->type = NUMBER;
        }
        else if (type == OPERATOR) {
            newNode->type = OPERATOR;
        }
        else {
            newNode->type = NULL;
        }
        newNode->next = NULL;
    }
    else {
        puts("unable to allocate memory for a node. \n");
    }
    return newNode;
}