//
// Created by s-gheldd on 4/27/16.
//

#include <zconf.h>
#include <stdlib.h>
#include "msg_linked_set.h"

int msg_linked_set_add(struct list_node **root, pid_t pid) {
    struct list_node **list = root;
    while (*list != NULL) {
        if ((*list)->pid == pid) {
            return 0;
        }
        list = &(*list)->next;
    }
    *list = malloc(sizeof(struct list_node));
    if (*list == NULL) {
        return -1;
    }
    (*list)->pid = pid;
    (*list)->next = NULL;
    return 1;
}

int msg_linked_set_remove(struct list_node **root, pid_t pid) {
    struct list_node **list = root;
    while (*list != NULL) {
        if ((*list)->pid == pid) {
            struct list_node *freeable = *list;
            *list = (*list)->next;
            free(freeable);
            return 1;
        } else {
            list = &(*list)->next;
        }
    }
    return 0;
}

int msg_linked_set_size(struct list_node *list) {
    int i = 0;
    while (list != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

int msg_linked_set_contains(struct list_node *list, pid_t pid){
    while (list != NULL){
        if (list->pid == pid){
            return 1;
        }
        list = list->next;
    }
    return 0;
}

int msg_linked_set_free(struct list_node **root) {
    if (*root != NULL) {
        int result = msg_linked_set_free(&(*root)->next);
        free(*root);
        *root = NULL;
        return result + 1;
    }
    return 0;
}