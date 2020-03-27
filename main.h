#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma once

typedef enum {
    FALSE = 0, TRUE,
    NO = 0, YES
}boolean;

typedef struct node{
    char* name;
    int numBurgers;
    int numSalads;
    boolean isCallAhead;
    struct node* next;
}NODE;

// main functions declaration.
void clearToEoln();
int getNextNWSChar();
int getPosInt();
char* getName();
void printCommands();
boolean getDebug();

// interact with Linked List functions.
void doAdd(NODE** head, NODE** tail);
void doCallAhead(NODE** head, NODE** tail);
void doWaiting(NODE* head);
void doRetrieve(NODE** head, NODE** tail);
void doList(NODE* head);
void doDisplay(NODE* head);
void doEstimateTime(NODE* head);

// helper function declerations. 
void addToList(NODE** head, NODE** tail, char * name, int numBurgers, int numSalads, boolean isCalledAhead);
boolean doesNameExist(NODE* head, char * name);
boolean updateStatus(NODE* head, char* name);
char * retrieveAndRemove(NODE** head, NODE** tale, int numBurgers, int numSalads);
void displayOrdersAhead(NODE* head, char* name);
void displayListInformation(NODE* head);
int displayWaitingTime(NODE* head, char* name);