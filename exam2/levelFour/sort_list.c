/*

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

int ascending(int a, int b)
{
	return (a <= b);
}*/

//#include "list.h" I commented this as I will make a main to test the function 
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
    int data;
    t_list *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *head = lst;
    while (lst->next)
    {
        if (((cmp)(lst->data, lst->next->data)) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = head;
        }
        else
            lst = lst->next;
        
    }
    lst = head;
    return lst;
}

int ascending(int a, int b)
{
	return (a <= b);
}

int main()
{
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));
    t_list *node4 = (t_list *)malloc(sizeof(t_list));
    t_list *node5 = (t_list *)malloc(sizeof(t_list));
    t_list *node6 = (t_list *)malloc(sizeof(t_list));


    node1->data = 2;
    node2->data = -5;
    node3->data = 12;
    node4->data = -98;
    node5->data = 0;
    node6->data = 9;

    node1->next = node2;
    node2 ->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    t_list *sorted = sort_list(node1, ascending);
    printf("HEAD->");
    while (sorted != NULL)
    {
        printf("%d->", sorted->data);
        sorted = sorted->next;
    }
    printf("NULL\n");
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

    return 0;
        


}
