/*
92. Reverse Linked List II
*/

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *dummy,*first,*second,*tmp,*p,*p1;
    int i = 0;
    int k = n-m+1;
    dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    first = second = dummy;
    
    while( k > 0 ){
		if( first->next != NULL ){
			first = first->next;
			i++;
		}
		k--;
    }
    
    while( i < n && first != NULL ){
		second = second->next;
		first = first->next;
		i++;
    }
    
    p = second->next;
    tmp = second->next;
    first = first->next;
    
    while( p != NULL && p != first){
		p1 = p->next;
		p->next = second->next;
		second->next = p;
		p = p1;
    }
    if( tmp != NULL ){
		tmp->next = p;
    }
    return dummy->next;
    
}

int main()
{
	struct ListNode *head;
	struct ListNode *res;
	head = (struct ListNode*)malloc(sizeof(struct ListNode)*2);
	head[0].val = 3; head[0].next = &(head[1]);
	head[1].val = 5; head[1].next = NULL;
	res = reverseBetween(head,1,2);
	while( res !=NULL ){
		printf("%d ",res->val);
		res = res->next;
	}
}
