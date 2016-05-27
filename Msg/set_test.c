//
// Created by s-gheldd on 4/27/16.
//


#include <zconf.h>
#include <stdio.h>
#include "msg_linked_set.h"

#define pretty_print_bool(x) x?"true":"false"

int main() {


    struct list_node *root = NULL;
    struct list_node **root_ptr = &root;
    int i;
    for (i = 0; i < 10; i++) {
        msg_linked_set_add(&root, i);
        printf("%d", msg_linked_set_size(root));
    }
    for (i = 0; i < 10; ++i) {
        msg_linked_set_remove(&root, i);
        printf("%d", msg_linked_set_size(root));
    }

    printf("\n%d, ", msg_linked_set_add(root_ptr, 1));
    printf("\n%s", pretty_print_bool(msg_linked_set_contains(root, 1)));
    printf("\n\n%d, %d", msg_linked_set_add(root_ptr, 1), msg_linked_set_add(root_ptr, 1));

    printf("\n\nFree: %d\n", msg_linked_set_free(root_ptr));

}
