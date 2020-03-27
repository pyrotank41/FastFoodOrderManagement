#include "main.h"

void doAdd(NODE**  head, NODE** tail) {
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0) {
        printf("Error: Add command requires an integer value of at least 0\n");
        printf("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0) {
        printf("Error: Add command requires an integer value of at least 0\n");
        printf("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get group name from input */
    char * name = getName();
    if (NULL == name) {
        printf("Error: Add command requires a name to be given\n");
        printf("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }

    // add code to perform this operation here
    if(!doesNameExist(*head, name)) {
        printf("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name, NumBurgers, NumSalads);
        addToList(head, tail, name, NumBurgers, NumSalads, FALSE);
    }
    else{
        printf("Error: \"%s\" exists in the list\n", name);
    }
}

void doCallAhead(NODE** head, NODE** tail) {
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0) {
        printf("Error: Call-ahead command requires an integer value of at least 0\n");
        printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0) {
        printf("Error: Call-ahead command requires an integer value of at least 0\n");
        printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }

    /* get group name from input */
    char * name = getName();
    if (NULL == name) {
        printf("Error: Call-ahead command requires a name to be given\n");
        printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }

    // add code to perform this operation here
    if(!doesNameExist(*head, name)) {
        printf("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name, NumBurgers, NumSalads);
        addToList(head, tail, name, NumBurgers, NumSalads, TRUE);
    }
    else{
        printf("Error: \"%s\" exists in the list\n", name);
    }
}

void doWaiting(NODE* head) {
    /* get order name from input */
    char * name = getName();
    if (NULL == name) {
        printf("Error: Waiting command requires a name to be given\n");
        printf("Waiting command is of form: w <name>\n");
        printf("  where: <name> is the name of the group that is now waiting\n");
        return;
    }

    // add code to perform this operation here
    if(updateStatus(head, name))
        printf("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
}

void doRetrieve(NODE** head, NODE** tail) {
    /* get info of prepared food ready on the counter from input */
    int PreparedBurgers = getPosInt();
    if (PreparedBurgers < 0) {
        printf("Error: Retrieve command requires an integer value of at least 0\n");
        printf("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }

    int PreparedSalads = getPosInt();
    if (PreparedSalads < 0) {
        printf("Error: Retrieve command requires an integer value of at least 0\n");
        printf("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }

    clearToEoln();
    printf("Retrieve (and remove) the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers, PreparedSalads);

    // add code to perform this operation here
    char * name = retrieveAndRemove(head, tail, PreparedBurgers, PreparedSalads);
    if(strcmp(name,"-1") == 0) {
        printf("Error: group with order of %d burgers and %d salads does not exists\n", PreparedBurgers, PreparedSalads);
    }
    else {
        printf("Order complete for %s\n", name);
    }
}

void doList(NODE* head) {
    /* get order name from input */
    char * name = getName();
    if (NULL == name) {
        printf("Error: List command requires a name to be given\n");
        printf("List command is of form: l <name>\n");
        printf("  where: <name> is the name of the order to inquire about\n");
        return;
    }

    // add code to perform this operation here
    displayOrdersAhead(head, name);

}

void doDisplay(NODE* head) {
    clearToEoln();
    printf("Display information about all orders:\n");

    // add code to perform this operation here
    displayListInformation(head);
}

void doEstimateTime(NODE* head) {
    /* get order name from input */

    char * name = getName();
    if (NULL == name) {
        printf("Error: List command requires a name to be given\n");
        printf("List command is of form: t <name>\n");
        printf("  where: <name> is the name of the order to inquire about\n");
        return;
    }

    // add code to perform this operation here  
    int time = displayWaitingTime(head, name);
    if(time != -1){
        printf("estimated weight time is %d min\n", time);
    }
    else{
        printf("Error: \"%s\" does NOT exists in the list\n", name);
    }

}