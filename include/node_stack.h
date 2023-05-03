#ifndef NODE_STACK_H
#define NODE_STACK_H

#include "ast.h"

typedef struct {
    ast_node **nodes;
    int size;
    int capacity;
} node_stack;

node_stack *create_node_stack(int initial_capacity);

void resize_list(node_stack *stack);

void push_node(node_stack *stack, ast_node *node);

ast_node *pop_node(node_stack *stack);

ast_node *peek_node(node_stack *stack);

int is_empty_node_stack(node_stack *stack);

void free_node_stack(node_stack *stack);

#endif //NODE_STACK_H
