//
// Created by 김재훈 on 2021/04/03.
//

#include "errors.h"
#include "stdio.h"

char* errorMessages[] = {
        "Calculation successful",
        "Encountered null pointer",
        "Too many operands",
        "Too few operands",
        "Only One operand"
};
void print_error(int status) {
    puts(errorMessages[status]);
}