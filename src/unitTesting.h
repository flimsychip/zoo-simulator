#ifndef UNITTESTING_H 
#define UNITTESTING_H

#include <string>

enum menuOptions {
    EXIT,
    TEST_NODE_TYPES,
    TEST_LINKED_LIST,
    TEST_ZOO
};

void testNodeTypes();
void testLinkedListTypes();

int getTestMenuChoice();
void promptUnitTest();

void movedFromMain();

#endif
// UNITTESTING_H