#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
    FSNode *node;
    char *s;

    if (!name)
        return (NULL);
    node = (FSNode *) malloc(sizeof(FSNode));
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
        return ;
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

#include <stdio.h>

int main(void)
{
    FSNode *root = create_folder("root");
    FSNode *file = create_file("file.txt", 998);
    FSNode *file2 = create_file("file2.txt", 10024);
    FSNode *file3 = create_file("file5.txt", 124);
    FSNode *folder2 = create_folder("rand_folder");

    add_child(root, file);
    add_child(root, file2);
    add_child(root, folder2);
    add_child(folder2, file3);

    // FSNode *curr = root;
    // printf("name: %s, size: %d, sibiling: %p, child:%p %s \n", curr->name, curr->size, curr->sibiling, curr->child, (curr->child)->name);
    // curr = curr->child;
    // printf("name: %s, size: %d, sibiling: %p, child:%p \n", curr->name, curr->size, curr->sibiling, curr->child);
    // curr = curr->sibiling;
    // printf("name: %s, size: %d, sibiling: %p, child:%p \n", curr->name, curr->size, curr->sibiling, curr->child);
    print_structure(root, 0);
}