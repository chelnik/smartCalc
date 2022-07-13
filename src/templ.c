#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "underfile.h"
void tester(leksem **head);
int main() {
    leksem *head = NULL;
    tester(head);
    print_list(&head);
    return 0;
}

void tester(leksem **head) { 
    push(5, *head); 
}