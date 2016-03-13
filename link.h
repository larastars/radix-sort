
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
        int data;
        struct Node *next;
}ListNode;
int largest(ListNode *head);
//insert element at tail
void insert_head(ListNode *head, int num);
//make a new list 
ListNode *newList(void);
//delete all
void deleteList(ListNode *head);
//print list  
void printList(ListNode *head, int length);
//creates a linked list that uses random number
ListNode *createRandomList(int N, int low, int high);
