/*
61. Rotate List
*/


#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *dummy, *p, *p1, *tail, *front;
    int i = 0;
    dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    if( head == NULL || k == 0 ){
		return head;
    }
    //就地逆置
	p = head;
	while( p != NULL ){
		p1 = p->next;
		p->next = dummy->next;
		dummy->next = p;
		p = p1;
		i++; //链表个数 
	} 
	//重设k
	if ( k % i > 0 ) k = k % i;
	
	//rotate
	tail = dummy->next;
	p = dummy->next;
	dummy->next = NULL;
	i = k;
	while( p != NULL && i > 0 ){
		p1 = p->next;
		p->next = dummy->next;
		dummy->next = p;
		p = p1;
		i--;
	}
	//if( dummy->next == NULL ) tail = dummy; 如果k为0 那么tail就是哑结点 
	//rotate2
	front = (struct ListNode*)malloc(sizeof(struct ListNode));;
	front->next = NULL;
	while( p != NULL ){
		p1 = p->next;
		p->next = front->next;
		front->next = p;
		p = p1;
	}
	
	//merge
	tail->next = front->next;
	
	return dummy->next;
}

int main()
{
	struct ListNode n[1];
	n[0].val = 1; n[0].next = NULL;
	//n[1].val = 2; n[1].next = NULL;
	struct ListNode *res = rotateRight(n,1);
	struct ListNode *p = res;
	while( p != NULL ){
		printf("%d\t",p->val);
		p = p->next;
	}
}
