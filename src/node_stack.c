#include <stdlib.h>
#include "ast.h"
#include "node_stack.h"

node_stack *create_node_stack(int initial_capacity) {
    node_stack *new_stack = (node_stack *)malloc(sizeof(node_stack));
    new_stack->size = 0;
    new_stack->nodes = (ast_node **)malloc(sizeof(ast_node *) * initial_capacity);
    new_stack->capacity = initial_capacity;

    return new_stack;
}

void resize_list(node_stack *stack) {
    int new_capacity = stack->capacity * 2;
    ast_node **new_node_list = (ast_node **)malloc(sizeof(ast_node *) * new_capacity);
    for (int i = 0; i < stack->size; i++) {
        new_node_list[i] = stack->nodes[i];
    }
    free(stack->nodes);
    stack->nodes = new_node_list;
}

void push_node(node_stack *stack, ast_node *node) {
    if (node == NULL || stack == NULL) {
        return;
    }
    if (stack->size == stack->capacity) {
        resize_list(stack);
    }
    stack->nodes[stack->size] = node;
    stack->size++;
}

ast_node *pop_node(node_stack *stack) {
    if (stack == NULL || stack->size == 0) {
        return NULL;
    }
    ast_node *value = stack->nodes[stack->size - 1];
    stack->nodes[stack->size - 1] = NULL;
    stack->size--;
    return value;
}

ast_node *peek_node(node_stack *stack) {
    if (stack == NULL || stack->size == 0) {
        return NULL;
    }
    ast_node *value = stack->nodes[stack->size - 1];
    return value;
}

int is_empty_node_stack(node_stack *stack) {
    if (stack->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

void free_node_stack(node_stack *stack) {
    free(stack->nodes);
    free(stack);
}
