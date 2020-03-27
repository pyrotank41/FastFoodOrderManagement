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

// interact with Linked List functions.
void doAdd(NODE** head, NODE** tail);
void doCallAhead(NODE** head, NODE** tail);
void doWaiting();
void doRetrieve();
void doList();
void doDisplay();
void doEstimateTime();

// helper function declerations. 
void addToList(NODE** head, NODE** tail, char * name, int numBurgers, int numSalads, boolean isCalledAhead);
boolean doesNameExist(NODE* head, char * name);