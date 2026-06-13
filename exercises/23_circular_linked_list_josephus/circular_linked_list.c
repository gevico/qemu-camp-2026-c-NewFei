#include "circular_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Node* create_circular_list(int n) {
    if (n <= 0) return NULL;
    Node* head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    head->next = head;
    Node* prev = head;
    for (int i = 2; i <= n; ++i) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->id = i;
        node->next = head;
        prev->next = node;
        prev = node;
    }
    return head;
}

void free_list(Node* head) {
    if (head == NULL) return;
    Node* cur = head->next;
    while (cur != head) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(head);
}
