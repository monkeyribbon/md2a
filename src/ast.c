#include <stdlib.h>
#include "ast.h"

ast_node *create_node(node_type type) {
    ast_node *new_node = (ast_node *)malloc(sizeof(ast_node));
    new_node->type = type;
    new_node->child_count = 0;
    new_node->children = NULL;
    new_node->content = NULL;
    return new_node;
}

void add_child(ast_node *parent, ast_node *child) {
    if (parent == NULL || child == NULL) {
        return;
    }

    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (ast_node **)realloc(parent->children, sizeof(ast_node *) * parent->child_capacity);
    }

    parent->children[parent->child_count] = child;
    parent->child_count++;
}

int is_container_node(ast_node *node) {
    if (node->type == LIST || node->type == QUOTE) {
        return 1;
    } else {
        return 0;
    }
}
