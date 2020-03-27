#include "main.h"

void _initNode(NODE** node, char * name, int numBurgers, int numSalads, boolean callAhead){

    // debugging
    // printf("adding");

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

void _displayList(NODE* head, NODE* tail) {
    if(head!= NULL) {
        // printf("\n**head at %s\n", head->name);
        // printf("List contains: ");
        
        while(head != NULL) { 
            printf("%s: %d, ", head->name, head->isCallAhead);
            head = head->next;
        }

        // printf("\n**tail at %s\n", tail->name);
    }
    
}


// This operation is to add a new node to the end of the linked list. This is to be
// used when the a and c commands are given as input.
void addToList(NODE** head, NODE** tail, char * name, int numBurgers, int numSalads, boolean isCallAhead){
    
    if (*head == NULL) { // if head is null, we will initialize null ans point tail to head.
        _initNode(head, name, numBurgers, numSalads, isCallAhead);
        *tail = *head;
    }
    else { // just adding the node to the tail.
        NODE* temp = *tail;
        _initNode(tail, name, numBurgers, numSalads, isCallAhead);
        temp->next = *tail;     
    }

    // for debug purposes.
    _displayList(*head, *tail);
}

// This operation is to return a Boolean value indicating whether a name
// already exists in the linked list. This is to be used when the a, c, w, t and l commands are given
// as input.
boolean doesNameExist(NODE* head, char * name) {
    // printf("%d\n", strcmp("karan", "karan"));

    NODE* temp = head;
    while(temp != NULL) {
        // printf("\n %s", temp->name);
        if( strcmp(temp->name, name) == 0) {
            printf("Error: name-> %s exists in the list\n", name);
            return TRUE;
        }
        temp = temp->next;
    }

    // since temp is NULL at this point, we did not find the name in the list.
    return FALSE;
}

// This operation is to change the in-restaurant status when a call-ahead order
// arrives at the restaurant. This operation will return a FALSE value if that order is already
// marked as being in the restaurant. This is to be used when the w command is given as input.
void updateStatus()
{

}

// This operation is to find the first in-restaurant order that matches the
// order prepared for pick up at the counter. This operation is to return the name of group. This
// group is to be removed from the linked list. This is to be used when the r command is given as
// input.
void retrieveAndRemove()
{

}

// This operation is to return the number of orders waiting ahead of an
// order with a specific name. This is to be used when the l command is given as input
void countOrdersAhead()
{

}

// This operation is to return the estimated waiting time for the specific
// name. The function will check the number of burgers and salads ordered ahead of the specified
// name and using known preparing time (10 minutes for burger and 5 minutes for salad) calculates
// the estimated wait time. This is to be used when t command is given as input.
void displayOrdersAhead()
{

}

// This operation traverses down the list until a specific order name is
// encountered. As each node is traversed, print out that node’s orders. This command is to be
// used when the l command is given.
void displayListInformation()
{

}

// This operation to traverse down the entire list from beginning to
// end. As each node is traversed, print out that node’s name, order details and in-restaurant status.
// This command is to be used when the d command is given as input
void displayWaitingTime()
{

}

