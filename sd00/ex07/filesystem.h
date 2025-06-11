#ifndef FILESYSTEM_H
# define FILESYSTEM_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char *name;
    int size;
    struct node *child;
    struct node *sibiling;
} FSNode;

FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);

int compute_total_size(FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);

#endif
