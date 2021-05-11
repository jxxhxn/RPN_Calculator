//
// Created by 김재훈 on 2021/04/01.
//

#include "stack.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    double value;
    int type;
    node *next;
} node;


void push(node some_node) {
    node *temp;
    temp = (struct node*) malloc(sizeof(node));
    if (!temp) {
        puts("Heap overflow\n");
    }
    else {
        temp->value = some_node.value;
        temp->type = some_node.type;
        temp->next = HEAD;
        HEAD = temp;
    }
}

node* pop( ) {
    node *temp;
    if (HEAD == NULL) {
        temp = NULL;
        return temp;
    }
    else {
        temp = HEAD;
        HEAD = HEAD->next;
        temp->next = NULL;
    }
    return temp;
}

int stackEmpty(node* HEAD) {
    return (HEAD == NULL);
}

node* peek( ) {
    if (!stackEmpty(HEAD)) {
        return HEAD;
    }
}

void clearStack (node* HEAD) {
    if (HEAD) {
        clearStack(HEAD->next);
        free(HEAD);
    }
}