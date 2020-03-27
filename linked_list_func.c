// author: karan singh kochar
// project name: FastFoodOrderManagement
// date: 27th march 2020

#include "main.h"

void _initNode(NODE** node, char * name, int numBurgers, int numSalads, boolean callAhead){

    // initiliazing the new node
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->name = name;
    newNode->numBurgers = numBurgers;
    newNode->numSalads = numSalads;
    newNode->isCallAhead = callAhead;
    newNode->next = NULL;

    // updating the node
    *node = newNode;
}

// just for debug purposes
// void _displayList(NODE* head, NODE* tail) {
//     if(head!= NULL) {
//         printf("\n**head at %s\n", head->name);
//         printf("List contains: ");
//         while(head != NULL) { 
//             printf("%s: %d, ", head->name, head->isCallAhead);
//             head = head->next;
//         }
//         printf("\n**tail at %s\n", tail->name);
//         printf("\n");
//     }   
// }

void _deleteNode(NODE** head, NODE** tail, NODE** prev, NODE** cur) {
    if(*prev == NULL) { //head of the list is to be deleted.
        *head = (*cur)->next;
        free(*cur);
    } else if ((*cur)-> next == NULL) { //tail of the list is to be deleted.
        (*prev)->next = NULL;
        free(*cur);
        *tail = *prev;
    } else { // node is someware in between.
        (*prev)->next = (*cur)->next;
        free(*cur);
    }
}


// This operation is to add a new node to the end of the linked list. This is to be
// used when the a and c commands are given as input.
void addToList(NODE** head, NODE** tail, char * name, int numBurgers, int numSalads, boolean isCallAhead){
    
    if (*head == NULL) { // if head is null, we will initialize null ans point tail to head.
        _initNode(head, name, numBurgers, numSalads, isCallAhead);
        *tail = *head;
        if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", (*head)->name, (*head)->numBurgers, (*head)->numSalads);
    }
    else { // just adding the node to the tail.
        NODE* temp = *tail;
        _initNode(tail, name, numBurgers, numSalads, isCallAhead);
        temp->next = *tail;  
         if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", (*tail)->name, (*tail)->numBurgers, (*tail)->numSalads);   
    }

    // for debug purposes.
    //_displayList(*head, *tail);
}

// This operation is to return a Boolean value indicating whether a name
// already exists in the linked list. This is to be used when the a, c, w, t and l commands are given
// as input.
boolean doesNameExist(NODE* head, char * name) {
    // printf("%d\n", strcmp("karan", "karan"));

    NODE* temp = head;
    while(temp != NULL) {
        if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", temp->name, temp->numBurgers, temp->numSalads);
        if( strcmp(temp->name, name) == 0) {
            return TRUE; // name exists
        }
        temp = temp->next;
    }

    // since temp is NULL at this point, we did not find the name in the list.
    return FALSE;
}

// This operation is to change the in-restaurant status when a call-ahead order
// arrives at the restaurant. This operation will return a FALSE value if that order is already
// marked as being in the restaurant. This is to be used when the w command is given as input.
boolean updateStatus(NODE* head, char* name){
    
    while(head != NULL) {
        if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", head->name, head->numBurgers, head->numSalads);
        if( strcmp(head->name, name) == 0){
            
            // once the matching name is found chech is if its call ahead.
            if(head->isCallAhead == TRUE){
                head->isCallAhead = FALSE;
                return TRUE;
            }
            // else the given name wasnt found
            else{ 
                printf("Error: \"%s's\" order is already waiting in the restaurant\n", head->name);
                return FALSE;
            }
        }
        head = head->next;
    }
    
    printf("Error: \"%s\" not found in the order que\n", name);
    return FALSE;
}

// This operation is to find the first in-restaurant order that matches the
// order prepared for pick up at the counter. This operation is to return the name of group. This
// group is to be removed from the linked list. This is to be used when the r command is given as
// input.
char * retrieveAndRemove(NODE** head, NODE** tail, int numBurgers, int numSalads){
    
    NODE* prev = NULL, * cur = *head;
    
    while(cur != NULL){
        if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", (cur)->name, (cur)->numBurgers, (cur)->numSalads);
        if( cur->numBurgers == numBurgers && cur->numSalads == numSalads){ // if group name is found
            char* name = cur->name;
            _deleteNode (head, tail, &prev, &cur);
            // for debug purposes.
            // _displayList(*head, *tail);
            return name;
        }
        prev = cur;
        cur = cur->next;
    }

    return "-1"; // if the group name is not found
}

// This operation is to return the number of orders waiting ahead of an
// order with a specific name. This is to be used when the l command is given as input
int countOrdersAhead(NODE * head, char * name){
    int count = 0;
    while(head != NULL){
        if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", head->name, head->numBurgers, head->numSalads);
        if(strcmp(head->name, name) == 0){
            return count;
        }
        count += 1;
        head = head->next;
    }
    return -1;
}

// This operation is to return the estimated waiting time for the specific
// name. The function will check the number of burgers and salads ordered ahead of the specified
// name and using known preparing time (10 minutes for burger and 5 minutes for salad) calculates
// the estimated wait time. This is to be used when t command is given as input.
int displayWaitingTime(NODE* head, char* name)
{
    int time = 0;
    while(head != NULL){
        if(getDebug()) printf("%s: %d burgers, %d salads, in-Restaurant\n", head->name, head->numBurgers, head->numSalads);
        if(head->numBurgers > 0) time += 10;
        if(head->numSalads > 0) time += 5;
        if(strcmp(head->name, name) == 0){
            return time;
        }
        head = head->next;
    } 
    // if we reach here then name wasnot found.
    return -1;
}

// This operation traverses down the list until a specific order name is
// encountered. As each node is traversed, print out that node’s orders. This command is to be
// used when the l command is given.
void displayOrdersAhead(NODE* head, char* name)
{
    NODE* temp = head;
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0){
            break;
        }
        temp = temp->next;
    }
    
    if(temp == NULL){ // if head is null then end of the list was reached hence name wasnt found.
        printf("%s not in the que\n", head->name);
    }

    else { // since name is found, we will print untill the order name is found.
        printf("Order for \"%s\" is behind the following orders:\n", name);
        while(head != NULL) {
            if(strcmp(head->name, name) == 0){
                return;
            }
            printf("%s: %d burgers, %d salads, in-Restaurant\n", head->name, head->numBurgers, head->numSalads);
            head = head->next;
        }
    }
    
}

// This operation to traverse down the entire list from beginning to
// end. As each node is traversed, print out that node’s name, order details and in-restaurant status.
// This command is to be used when the d command is given as input
void displayListInformation(NODE* head)
{
    while(head != NULL){ // simple display.
        printf("%s: %d burgers, %d salads, in-Restaurant\n", head->name, head->numBurgers, head->numSalads);
        head = head->next;
    }
}



