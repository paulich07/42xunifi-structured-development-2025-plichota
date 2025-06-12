#include "filesystem.h"

// Recursively compute the total size of any given folder
// including all files and nested contents
int compute_total_size(const FSNode *node)
{
    int size = 0;

    if (!node)
        return (0);
    size = node->size;
    size += compute_total_size(get_children(node));
    size += compute_total_size(get_sibling(node));
    return (size);
}

void print_structure(const FSNode *node, int indent)
{
    if (!node)
        return ;
    printf("|%*s", indent, "-");

    if (node->size == 0)
        printf("📁 %s [%d]\n", node->name, node->size);
    else
        printf("📄 %s [%d]\n", node->name, node->size);
   
    // printf("sibling: %p child %p\n", node->sibling, node->child);
    print_structure(get_children(node), indent + 2);
    print_structure(get_sibling(node), indent);
}

void free_node(FSNode *node)
{
    if (node->name)
        free(node->name);
    free(node);
}

void free_filesystem(FSNode *node)
{
    if (!node)
        return ;
    free_filesystem(get_children(node));
    free_filesystem(get_sibling(node));
    free_node(node);
}