/*
24. Swap Nodes in Pairs
*/


#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p,*i,*j;
    struct ListNode *dummy;
    //ͷ���
	dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;
	
	p = dummy;
	while( p->next != NULL && p->next->next != NULL ){
		i = p->next;
		j = i->next;
		
		/*����*/
		i->next = j->next;
		j->next = i;
		p->next = j;
		
		/*���¸�ֵp*/
		p = i;
	} 
	return dummy->next;
} 


int main()
{
	
}
