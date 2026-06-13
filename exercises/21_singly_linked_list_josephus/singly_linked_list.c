#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// 全局头指针
static link head = NULL;

// 创建新节点
link make_node(unsigned char item) {
    link p = (link)malloc(sizeof(struct node));
    p->item = item;
    p->next = NULL;
    return p;
}

// 释放节点
void free_node(link p) { free(p); }

// 查找节点
link search(unsigned char key) {
    link p;
    for (p = head; p; p = p->next) {
        if (p->item == key)
            return p;
    }
    return NULL;
}

// 在链表头部插入节点
void insert(link p) {
    p->next = head;
    head = p;
}

// 删除指定节点
void delete(link p) {
    if (head == NULL) return;
    if (p == head) {
        head = head->next;
        return;
    }
    link prev;
    for (prev = head; prev; prev = prev->next) {
        if (prev->next == p) {
            prev->next = p->next;
            return;
        }
    }
}

// 遍历链表
void traverse(void (*visit)(link)) {
    link p;
    for (p = head; p; p = p->next) {
        visit(p);
    }
}

// 销毁整个链表
void destroy(void) {
    link p;
    while (head) {
        p = head;
        head = head->next;
        free_node(p);
    }
}

// 在链表头部推入节点
void push(link p) {
    insert(p);
}

// 从链表头部弹出节点
link pop(void) {
    if (head == NULL) return NULL;
    link p = head;
    head = head->next;
    return p;
}

// 释放链表内存
void free_list(link list_head) {
    link p;
    while (list_head) {
        p = list_head;
        list_head = list_head->next;
        free(p);
    }
}
