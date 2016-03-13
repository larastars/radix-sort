
#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Error! program takes 5 command line argument\n");
		exit(0);
	}
	int seed = atoi(argv[1]);
	srandom(seed);
	int N = atoi(argv[2]);
	if (N < 5 || N >= 1000)
	{
		printf("Error! N is too low or too high\n");
		exit(0);
	}
	int low = atoi(argv[3]);
	// check if low is > 0
	if(low < 0)
	{
		printf("Error! Low has to be greater than zero\n");
		exit(0);
	}
	int high = atoi(argv[4]);
	//check if high  > low
	if(high < low)
	{
		printf("high should be greater than low!\n");
		exit(0);
	}
	int loop_size = atoi(argv[4]);
	int x=0;
	while (loop_size !=0)
	{
		loop_size = loop_size/10;
		x++;
	}

	//create a list of random number that returns head
	ListNode *randomList = createRandomList(N, low, high);
	//check if it is proper 
        ListNode *current = randomList;
	printList(randomList, N);
	int j =0;
	int mod = 10;
	int divide =1;
	for (j=0; j<x;j++)
	{	
       	//create an array of elements of linked list
		ListNode *bucketArray [10];
		//initilized bucketArray to dummy head node
		int i=0;
		for (i = 0; i <10;i++)
		{
			bucketArray [i] = newList(); 
		}
		//go through linked list postion s in this loop
		for (i = 0; i < N; i++)//for each number in the linked list
		{	int num = current->next ->data;
                        int pos = 0;	
			if (randomList->next == NULL)
			{
				printf("Error! the list is empty!\n");
				exit(0);
			}
			else
			{
				pos = (num% mod)/divide;
			}
			insert_head(bucketArray[pos],num); 
			current = current ->next;		
		}
		mod = mod *10;
		divide = divide*10;
		//stitch function
		int k =0;
       		for (k=0; k<10;k++)
       		 {
                	while (bucketArray[k]-> next != NULL)
               		 {
			    //insert in linkedlist
			    insert_head(current ,bucketArray[k]->next->data);
			    
                               if (bucketArray[k]->next != NULL)
				{
					#ifndef NDEBUG
					printf("%d\n", bucketArray[k]->next->data);
					#endif
					ListNode *node = bucketArray[k];
					bucketArray[k]=bucketArray[k]->next;
					free(node);
					
				}
               		 }
       		 }
		printList(current,N);
		int s=0;
		for (s=0; s<10;s++)
		{
			deleteList(bucketArray[s]);
		}
	}
	deleteList(current);
	deleteList(randomList);
	return 0;
}
