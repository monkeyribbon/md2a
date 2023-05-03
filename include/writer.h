#ifndef WRITER_H
#define WRITER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

void ast_to_html(const ast_node *root, char **output_buffer);

void write_html_to_file(const char *filename, const char *output_buffer);

#endif //WRITER_H 
