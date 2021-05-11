//
// Created by 김재훈 on 2021/04/01.
//

#ifndef PS4_STACK_H
#define PS4_STACK_H

#include <stdbool.h>

typedef struct node node;
node* HEAD;
void push(node);
node* pop(void);
int stackEmpty(node*);
node* peek(void);
void clearStack(node*);
#endif //PS4_STACK_H
