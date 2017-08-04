/*
83. Remove Duplicates from Sorted List
*/

#include<stdio.h>
#include<stdlib.h>


struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *i,*j;
    i = j = head;
    while( j != NULL ){
		if( j->val != i->val ){
			i->next = j;
			i = j;
		}
		j = j->next;
    }
    if( i != NULL ){
        i->next = NULL;
    }
    return head;
}

int main()
{
	
}


