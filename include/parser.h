#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

ast_node *parse_markdown(const char *markdown_text);

ast_node *parse_header(const char *markdown, int *current_position);

ast_node *parse_paragraph(const char *markdown, int *current_position);

ast_node *parse_list(const char *markdown, int *current_position);

ast_node *parse_quote(const char *markdown, int *current_position);

ast_node *parse_code_block(const char *markdown, int *current_position);

ast_node *parse_inline_code(const char *markdown, int *current_position);

node_type determine_node_type(const char *markdown, int current_position);

void free_ast(ast_node *root);

#endif //PARSER_H 
