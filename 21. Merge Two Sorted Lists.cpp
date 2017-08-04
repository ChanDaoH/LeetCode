/*
21. Merge Two Sorted Lists
*/
#include<stdio.h>
#include<stdlib.h>


struct ListNode{
	int val;
	struct ListNode* next;
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *L,*p;
    L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = NULL;
    p = L;
    while( l1 != NULL && l2 != NULL ){
		if( l1->val < l2-> val ){
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}else{
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}
    }
    if( l1 != NULL ){
		p->next = l1;
    }else{
		p->next = l2;
    }
    return L->next;
    
}

int main()
{
	
}
