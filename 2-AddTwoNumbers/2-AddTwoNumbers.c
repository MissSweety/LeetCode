/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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

//����һ���ṹ�� 
struct ListNode {
	int val;
	struct ListNode* next;
};

//������������ĺ� 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //��Ҫ����һ����������malloc�ռ䣬�õ��ռ��ַ 
	struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
	//��Ҫ����������һ������������и���ָ�벽��׷�� 
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* r = l;
	
	//����������l�ĵ�һ���ڵ㣬һ��ڵ㶼��Ҫ��NULL��β������Whileѭ��֮ǰ����õ�һ���ڵ�ܱ�Ҫ 
	int sum = 0;
	int result = 0;
	int rest = 0;
					
	sum = p->val + q->val;
	result = sum % 10;
	r->val = result + rest;
	r->next = NULL;
	rest = sum / 10;
	
	//��p��q��ָ��l1��l2����ƶ�һ���ڵ� 
	p = p->next;
	q = q->next;
	
	while(p || q){
		//����һ���ڵ����ռ䣬�Ѿ���ָ�����һ���ڵ��ָ�� 
		r->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		r = r->next;

		sum = p->val + q->val;
		result = sum % 10;
		r->val = result + rest;
		r->next = NULL;
		rest = sum / 10;
		
		p = p->next;
		q = q->next;
		
		//�����һ����һ���̵�list�����´��� 
		if((p == NULL) && (q != NULL)){
			r->next = q;
			q->val += rest;
			break;
		}
		if((q == NULL) && (p != NULL)){
			r->next = p;
			p->val += rest;
			break;
		}
	}
	return l;
}

void main(){
	struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p = l1;
	struct ListNode *q = l2;
	int num1, num2;
	
	//��ʼ������list1 
	printf("������List1�����ǵ�1��\n");
	scanf("%d",&num1);
	p->val = num1;
	p->next = NULL;
	for(int i=2; i<=3; i++){
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		printf("������List1�����ǵ�%d��\n",i);
		scanf("%d",&num1);
		p->val = num1;
		p->next = NULL;
	}
	
	/*
	���Գ�ʼ��������list1�Ƿ�ɹ� 
	struct ListNode* s = l1;
	while(s != NULL){
		printf("%d\n",s->val);
		s = s->next;
	}
	*/
	
	//��ʼ������list2
	printf("������List2�����ǵ�1��\n");
	scanf("%d",&num2);
	q->val = num2;
	q->next = NULL;
	for(int i=2; i<=4; i++){
		q->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		q = q->next;
		printf("������List2�����ǵ�%d��\n",i);
		scanf("%d",&num2);
		q->val = num2;
		q->next = NULL;
	}
	
	//������������ĺ� 
	struct ListNode* l = addTwoNumbers(l1,l2);
	
	//��������ÿ���ڵ㣬����ָ��r������ 
	struct ListNode* r = l;
	while(r){
		printf("%d\n",r->val);
		r = r->next;
	}
}
