/*Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;*/
#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next; // it imcrement the node and the i++ give your the number of incrementations
        i++;
    }
    return i;
}
// partie test
t_list *create_node(void *data)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int main(void)
{
    t_list *head = NULL;
    t_list *node1 = create_node("node1");
    t_list *node2 = create_node("node2");
    t_list *node3 = create_node("node3");
    head = node1;
    node1->next = node2;
    node2->next = node3;
    int size = ft_list_size(head);
    printf("La taille de la liste est : %d\n", size);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}