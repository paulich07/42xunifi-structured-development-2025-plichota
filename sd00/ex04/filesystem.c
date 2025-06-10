#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
    FSNode *node;
    char *s;

    if (!name)
        return (NULL);
    node = malloc(sizeof(FSNode));
    // if (!node)
        // return (NULL);
    s = strdup(name);
    // if (!s)
        // return (free(node), NULL);
    node->name = s;
    node->size = size;
    node->sibiling = NULL;
    node->child = NULL;
    return (node);
}

FSNode *create_folder(const char *name)
{
    return (create_file(name, 0));
}

void add_child(FSNode *parent, FSNode *child)
{
    FSNode *curr;

    if (!parent || !child)
        return ;
    if (parent->size > 0)
        return ;
    if (parent->child != NULL)
    {
        curr = parent->child;
        while (curr->sibiling != NULL)
            curr = curr->sibiling;
        curr->sibiling = child;
    }
    parent->child = child;
}

FSNode *get_children(const FSNode *parent)
{
    if (!parent)    
        return (NULL);
    return (parent->child);
}

FSNode *get_sibling(const FSNode *node)
{
    if (!node)
        return (NULL);
    return (node->sibiling);
}

// #include <stdio.h>

// int main(void)
// {
//     FSNode *root = create_folder("root");
//     FSNode *file = create_file("file.txt", 998);
//     FSNode *file2 = create_file("file.txt", 10024);

//     add_child(root, file);
//     add_child(file, file2);
//     add_child(root, file2);

//     // printf("name: %s, size: %d, sibiling:%s, child:%s\n", root->name, root->size, (root->sibiling)->name, (root->child)->name);
//     // printf("name: %s, size: %d, sibiling:%s, child:%s\n", root->name, root->size, (root->sibiling)->name, (root->child)->name);
//     printf("name: %s, size: %d, sibiling: %p, child:%p, child name:%s \n", root->name, root->size, root->sibiling, root->child, (root->child)->name);
//     printf("name: %s, size: %d, sibiling: %p, child:%p \n", file->name, file->size, file->sibiling, file->child);
//     file = file->sibiling;
//     printf("name: %s, size: %d, sibiling: %p, child:%p \n", file->name, file->size, file->sibiling, file->child);
// }