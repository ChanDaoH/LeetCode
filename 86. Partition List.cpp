/*
86. Partition List
*/

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *dummys,*dummyb,*s,*b;
    dummys = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyb = (struct ListNode*)malloc(sizeof(struct ListNode));
    s = dummys; b = dummyb;
    
    while( head != NULL ){
		if( head->val < x ){
			s->next = head;
			s = head;
		}else{
			b->next = head;
			b = head;
		}
		head = head->next;
    }
    
    b->next = NULL;
    s->next = dummyb->next;
    
    return dummys->next;
       
}
