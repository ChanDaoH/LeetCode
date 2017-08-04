/*
19. Remove Nth Node From End of List
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode{
	int val;
    struct ListNode *next;
}; 
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dumb,*first,*second;
    dumb = (struct ListNode*)malloc(sizeof(struct ListNode));
    dumb->next = head;
    first = second = dumb;
    for( int i = 0; i < n+1; i++ ){
		first = first->next;
    }

    while( first != NULL ){
		first = first->next;
		second = second->next;
    }
    
    second->next = second->next->next;
    return dumb->next;
    
}

int main()
{
}





