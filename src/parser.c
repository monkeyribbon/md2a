#include <string.h>

#include "parser.h"
#include "ast.h"
#include "node_stack.h"

ast_node *parse_markdown(const char *markdown_text) {
    ast_node *root = create_node(ROOT);
    int curr_position = 0;
    int text_length = strlen(markdown_text);
    node_stack *stack = create_node_stack(10);

    while (curr_position < text_length) {
        node_type type = determine_node_type(markdown_text, curr_position);

        ast_node *node = NULL;
        switch (type) {
            case HEADER:
                node = parse_header(markdown_text, &curr_position);
                break;
            case PARAGRAPH:
                node = parse_paragraph(markdown_text, &curr_position);
                break;
            case LIST:
                node = parse_list(markdown_text, &curr_position);
                break;
            case QUOTE:
                node = parse_quote(markdown_text, &curr_position);
                break;
            case CODE_BLOCK:
                node = parse_code_block(markdown_text, &curr_position);
                break;
            case INLINE_CODE:
                node = parse_inline_code(markdown_text, &curr_position);
                break;
            default:
                curr_position++;
                continue;
        }

        if (is_empty_node_stack(stack)) {
            add_child(root, node);
        } else {
            ast_node *parent_node = peek_node(stack);
            add_child(parent_node, node);
        }

        if (is_container_node(node)) {
            push_node(stack, node);
        }

        while (
            !is_empty_node_stack(stack) 
            && !is_position_inside(stack, curr_position, text_length)
        ) {
            pop_node(stack);
        }
    }

    free_node_stack(stack);
    return root;
}

ast_node *parse_header(const char *markdown, int *current_position){

}

ast_node *parse_paragraph(const char *markdown, int *current_position){

}

ast_node *parse_list(const char *markdown, int *current_position){

}

ast_node *parse_quote(const char *markdown, int *current_position){

}

ast_node *parse_code_block(const char *markdown, int *current_position){

}

ast_node *parse_inline_code(const char *markdown, int *current_position){

}

node_type determine_node_type(const char *markdown, int current_position){

}

