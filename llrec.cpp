#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivotHelper(Node*& head, Node*& smaller, Node*& smallerTail, Node*& larger, Node*& largerTail, int pivot) {
  //Base case 
  if(head == NULL) {
    return;
  }
  //Save the current node and move head forward 
  Node* current = head;
  head = head->next;
  current->next = NULL;

  //Put the current node into the correct list
  if(current->val <= pivot) {
    if(smaller == NULL) {
      smaller = current;
    }
    else {
      smallerTail->next = current;
    }
    smallerTail = current; 
  }
  else {
    if(larger == NULL) {
      larger = current;
    }
    else {
      largerTail->next = current;
    }
    largerTail = current;
  }
  //Recursively process the remaining nodes
  llpivotHelper(head, smaller, smallerTail, larger, largerTail, pivot);
}
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
  //Start with two empty output lists
  smaller = NULL;
  larger = NULL;

  Node* smallerTail = NULL;
  Node* largerTail = NULL;

  //Recursively split the original list
  llpivotHelper(head, smaller, smallerTail, larger, largerTail, pivot);
}
