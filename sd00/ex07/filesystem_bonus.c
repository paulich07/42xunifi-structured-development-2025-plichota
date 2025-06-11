#include "filesystem.h"

// Recursively compute the total size of any given folder
// includes all files and nested contents
// int compute_total_size(FSNode *node)
// {

// }

void print_structure(const FSNode *node, int indent)
{
    if (!node)
        return ;
    printf("|%*s", indent, "-");

    if (node->size == 0)
        printf("📁 %s [%d]\n", node->name, node->size);
    else
        printf("📄 %s [%d]\n", node->name, node->size);
   
    // printf("sibiling: %p child %p\n", node->sibiling, node->child);
    print_structure(get_children(node), indent + 2);
    print_structure(get_sibling(node), indent);
}

void free_filesystem(FSNode *node);