#ifndef UNITTESTING_H 
#define UNITTESTING_H

#include <string>

enum menuOptions {
    EXIT,
    TEST_NODE_TYPES,
    TEST_LINKED_LIST,
    TEST_EXHIBITS,
    TEST_ZOO
};

void testNodeTypes();
void testLinkedListTypes();
void testExhibits();
int getTestMenuChoice();
void promptUnitTest();

void outputList ();
void movedFromMain();

#endif
// UNITTESTING_H