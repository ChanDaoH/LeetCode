/*
82. Remove Duplicates from Sorted List II
*/

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *dummy,*p,*q;
    dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    p = dummy;
    q = head;
    while( q != NULL ){
		if( q->next != NULL && q->next->val == q->val ){
			int val = q->val;
			while( q != NULL && q->val == val ){
				q = q->next;
			}
		}else{
			p->next = q;
			p = q;
			q = q->next;
		}
    }
    p->next = NULL; //尾插法，最后尾指针的next为NULL 
    return dummy->next;
}
