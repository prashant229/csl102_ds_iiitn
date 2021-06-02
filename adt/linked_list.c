#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    LL_TRUE = 1,
    LL_FALSE = 0,
} status_t;
typedef struct nodeQ
{
    int data;
    struct nodeQ *next;
} nodeQ_t;

nodeQ_t *create_node(int val)
{
    nodeQ_t *ptr = (nodeQ_t *)malloc(sizeof(nodeQ_t));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}
status_t appendNode(nodeQ_t *tail, nodeQ_t *new_Node)
{
    if (NULL == tail || NULL == new_Node)
        return LL_FALSE;

    tail->next = new_Node;
    return LL_TRUE;
}
status_t prependNode(nodeQ_t *head, nodeQ_t *new_Node)
{
    if (NULL == head || NULL == new_Node)
        return LL_FALSE;

    new_Node->next = head;
    return LL_TRUE;
}
nodeQ_t *retrivenode(nodeQ_t *head, int index)
{
    nodeQ_t *ptr = head;
    for (int i = 0; i < index; i++)
    {
        if (NULL != ptr->next)
            ptr = ptr->next;
        else
        {
            printf("Error:Node[%d]is null\n", i + 1);
            return NULL;
        }
    }
    return ptr;
}
void printh2t(nodeQ_t *head)
{
    if (NULL == head)
        return;
    nodeQ_t *nodeptr = head;
    while (nodeptr)
    {
        printf("%d-->", nodeptr->data);
        nodeptr = nodeptr->next;
    }
    printf("EMPTYNODE\n");
}

void destroylist(nodeQ_t *ptr)
{
    if (NULL == ptr)
        return;

    while (ptr)
    {
        nodeQ_t *current = ptr;
        printh2t(ptr);
        ptr = ptr->next;
        free(current);
    }

    printf("EMPTYNODE\n");
}

int main()
{
    nodeQ_t *head = create_node(20);
    nodeQ_t *tail = head;

    printf("head:\t%d\t\t%p\t\t%p\n", head->data, head, head->next);
    printf("tail:\t%d\t\t%p\t\t%p\n", tail->data, tail, tail->next);
    for (int i = 0; i < 10; i++)
    {
        nodeQ_t *newNode = create_node(i * 2);
        if (LL_TRUE == appendNode(tail, newNode))
        {
            tail = newNode; //this moves the tail to point to the newly appended node at the end of the linked list
            printf("New Node is appended succesfully\n");
        }
        else
            printf("Not enough memory\n");
    }
    // prints all the nodes from head to tail
    printh2t(head);

    destroylist(head);
    head=NULL;

    return 0;
}