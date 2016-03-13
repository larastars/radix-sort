
#include "link.h"

int largest(ListNode *head)
{	int num = 0;
	int large = 0;
	ListNode *prev = head;
	if (prev->next == NULL)
	{
		num = prev ->next->data;
	}
	else
	{
		while(prev != NULL)
		{	if (num < prev->data)
			{
				num = prev->data;
			}
			prev = prev->next;
                }
	}	
	while (num != 0)
	{
		num /= 10;
		large++;
	}
	return large;			
}

void insert_head(ListNode *head, int num)
{
        ListNode *newNode =(ListNode *)malloc(sizeof(ListNode));
        newNode->data = num;
        ListNode *current = head;
	//check if the next node is null
        while (current->next != NULL)
        {
                current = current->next;
        }
	//insert
        current ->next = newNode;
        newNode->next = NULL;
}

ListNode *newList(void)
{
  ListNode *dummy;
  dummy = (ListNode *)malloc(sizeof(ListNode));
  dummy->next = NULL;
  return dummy;
}
void deleteList(ListNode *head)
{
	//delete the whole linked list
        struct Node *current = head;
        struct Node *tmp = NULL;
        while (current != NULL)
        {
                tmp = current ->next;
                free(current);
                current = tmp;
        }
}
void printList(ListNode *head, int length)
{
        struct Node *current = head;
        int i=0;
        printf("[ ");
        for (i=0; i < length; i++)
        {
                if (head->next != NULL)
                {
                        int number = current->next->data;
                        printf("%d ", number);
                        current = current->next;
                }
        }
        printf("]\n");
}
ListNode *createRandomList(int N, int low, int high)
{
        ListNode *head = newList();
        ListNode *current = head;
        int i =0;
        for (i=0; i < N; i++)
        {
                //allocate memory for new node 
                ListNode *newNode =(ListNode *)malloc(sizeof(ListNode));
                //assign random number
                int randNum = random()%(high-low+1) +low;
                //point to new node
                current ->next = newNode;
                newNode ->data = randNum;
                newNode ->next = NULL;
                current = current ->next;
        }
        return head;
}


