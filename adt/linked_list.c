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

status_t isdataPresent(nodeQ_t *ptr,int  data)
{
    if(NULL==ptr)return;
    
    while(ptr)
    {
        if(ptr->data==data)
        {
            printf("number found successfully\n");
            return;
        }
        ptr=ptr->next;
    }
    printf("data not present\n");
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
            tail = newNode; //this moves the tail to point to the newly appended node at the end of the linked list
        else
            printf("Not enough memory\n");
    }
    // prints all the nodes from head to tail
    printh2t(head);
       isdataPresent(head,23);
       isdataPresent(head,12);
    destroylist(head);
    head = NULL;

    return 0;
}
// =======

// #define EMPTYNODE 0

// struct nodeQ{
//     short data;
//     struct nodeQ* next;
// };

// typedef struct nodeQ nodeQ_t;

// typedef enum{
//     LIST_FALSE = 0,
//     LIST_TRUE = 1,
// } status_t;

// nodeQ_t* createNode(short val){
//     nodeQ_t* ptr = (nodeQ_t*)malloc(sizeof(nodeQ_t));
//     ptr->data = val;
//     ptr->next = EMPTYNODE; // NULL
//     return ptr;
// }

// status_t appendNode(nodeQ_t* tail, nodeQ_t* newNode){

//     if(EMPTYNODE == tail || EMPTYNODE == newNode) return LIST_FALSE;

//     tail->next = newNode;
//     return LIST_TRUE;
// }

// status_t prependNode(nodeQ_t* head, nodeQ_t* newNode){

//     if(EMPTYNODE == head || EMPTYNODE == newNode) return LIST_FALSE;

//     newNode->next = head;
//     return LIST_TRUE;
// }

// void printList(nodeQ_t* head){
//     if(EMPTYNODE == head) return;

//     nodeQ_t* node = head;
//     while(node){
//         printf("%d --> ", node->data);
//         node = node->next;
//     }
//     printf("EMPTYNODE\n");
// }

// void destroyList(nodeQ_t* ptr){
//     if(EMPTYNODE == ptr) return;

//     while(ptr){
//         nodeQ_t* current = ptr;
//         printList(current);
//         ptr = ptr->next;
//         free(current);    
//     }

//     printf("EMPTYNODE\n");
// }

// status_t isDataPresent(nodeQ_t* ptr, short data){
//     if(EMPTYNODE == ptr) return LIST_FALSE;

//     while(ptr){
//         if(data == ptr->data) return LIST_TRUE;
//         ptr = ptr->next;
//     }

//     return LIST_FALSE;
// }

// status_t insertNode(nodeQ_t* head, nodeQ_t* newNode, unsigned short index){
//     if(EMPTYNODE == head || EMPTYNODE == newNode) return LIST_FALSE;

//     if(0 == index) return prependNode(head, newNode);  

//     nodeQ_t* curr = head;

//     unsigned short counter = 0;
//     while(curr){
//         counter++;
//         if(index == counter){
//             // 56
//             // 14 -> 16 -> 17
//             newNode->next = curr->next;
//             // 56 ->16
//             curr->next = newNode;
//             // 14->56->16>17
//             return LIST_TRUE;
//         }
//         curr = curr->next;
//     }

//     return LIST_FALSE;
// }

// status_t removeNode(nodeQ_t* head, nodeQ_t** newHead, unsigned short index){
//     if(EMPTYNODE == head) return LIST_FALSE;

//     if(0 == index){
//         *newHead = head->next;
//         free(head);
//         return LIST_TRUE;
//     }

//     nodeQ_t* prev = head;
//     nodeQ_t* curr = head->next;

//     // 15 -> EMPTYNODE
//     unsigned short counter = 0;
//     while(curr){
//         counter++;
//         if(index == counter){
            
//             // 15 = prev
//             // 16 = curr
//             // 17 = curr->next
//             prev->next = curr->next;
//             free(curr);
//             return LIST_TRUE;
//         }

//         // 15->16->17->18
//         // 16 = prev
//         // curr = 17
//         prev = curr;
//         curr = curr->next;
//     }
//     return LIST_FALSE;
// }

// nodeQ_t* reverseList(nodeQ_t* head){
//     if(EMPTYNODE == head) return EMPTYNODE;

//     nodeQ_t* prev = head;
//     nodeQ_t* tmp = EMPTYNODE;
//     nodeQ_t* curr = head->next;
//     head->next = EMPTYNODE;

//     while(curr){
//         // 15 -> 16 -> 17 -> 18 -> 19
//         // store curr->next into a tmp variable
//         tmp = curr->next;
//         // tmp = 17

//         // update next for the curr node
//         curr->next = prev;
//         // curr = 16
//         // curr->next = 15
//          // 15 <- 16 <- 17 ??? 18 -> 19
         
//         prev = curr;
//         // prev = 16
//         curr = tmp;
//         // curr = 17
//     }

//     return prev;
// }


// int main(){
    
//     nodeQ_t* head = EMPTYNODE;
//     nodeQ_t* tail = EMPTYNODE;
    
//     head = createNode(20);
//     printf("%p\n", head);

//     tail = head;

//     for(short i=1; i < 6; i++){
//         nodeQ_t* newNode = createNode(20+i);
//         if(appendNode(tail, newNode))
//             tail = newNode;
//     }

//     for(short i=1; i < 6; i++){
//         nodeQ_t* newNode = createNode(20-i);
//         if(prependNode(head, newNode))
//             head = newNode;
//     }

//     #if 0
//     printf("%d\t\t%p\t\t%p\n", head->data, head, head->next);
//     printf("%d\t\t%p\t\t%p\n", head->next->data, head->next, head->next->next);
//     printf("%d\t\t%p\t\t%p\n", head->next->next->data, head->next->next, head->next->next->next);
//     printf("%d\t\t%p\t\t%p\n", tail->data, tail, tail->next);
//     #endif

//     printList(head);

//     if(LIST_TRUE == insertNode(head, createNode(100), 5)){
//         printList(head);
//     }

//     if(LIST_TRUE == insertNode(head, createNode(101), 10)){
//         printList(head);
//     }

//     if(LIST_TRUE == insertNode(head, createNode(450),20)){
//         printList(head);
//     }

//     if(LIST_TRUE == removeNode(head, &head, 8)){
//         printList(head);
//     }

//     if(LIST_TRUE == removeNode(head, &head, 0)){
//         printList(head);
//     }

//     if(LIST_TRUE == removeNode(head, &head, 800)){
//         printList(head);
//     }

//     head = reverseList(head);
//     printList(head);

//     //printf("dataPresent = %d \n", isDataPresent(head, 225));

//     //destroyList(head);
//     //head = EMPTYNODE;

//     //printf("%d\n", head->data);

//     return 0;
// }
// >>>>>>> 8a95b38d10b5302b2dc561713576f6c0e9e2a7bf
