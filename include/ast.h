#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef enum {
    ROOT,
    HEADER,
    PARAGRAPH,
    LIST,
    CODE_BLOCK,
    INLINE_CODE,
    ITALICS,
    BOLD,
    QUOTE,
    LINK,
} node_type;

typedef struct ast_node {
    node_type type;
    char *content;
    int content_length;
    struct ast_node **children;
    int child_count;
    int child_capacity;
} ast_node;

ast_node *create_node(node_type type);

void add_child(ast_node *parent, ast_node *child);

int is_container_node(ast_node *node);

int is_position_inside(ast_node *node, const char *markdown_text, int current_position);


#endif //AST_H
