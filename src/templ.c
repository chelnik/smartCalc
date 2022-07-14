#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "underfile.h"

void tester(leksem **head);
int main() {
    leksem *head = NULL;
    head = create(4);
    tester(&head);
    // push(5, head); push(5, head); push(5, head); push(5, head); 
    print_list(head);
    return 0;
}

void tester(leksem **head) {
    head = push(50, *head);
//    head = push(5, head);
//    head = push(5, head);
//    head = push(5, head);
}