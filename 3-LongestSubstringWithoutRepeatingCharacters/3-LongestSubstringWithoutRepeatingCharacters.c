/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include<stdio.h>
#include<stdlib.h>

//��������Ľṹ�� 
typedef struct node{
	int data;
	struct node* next;
}Node;

//��ƺ��������һ���ַ����ϸ��Ѿ������ޡ��ظ�Ԫ�ص��ַ����е��ظ�Ԫ��λ�ã����ظ�Ԫ�����0 
int repeatNum(char s, Node* l){
	int i = 0;
	int j = 0;
	Node* p = l;
	while(p){
		i = i + 1;
		if(s == p->data){
			j = i;
			//break;
		}
		p = p->next;
	}
	return j;
}

int lengthOfLongestSubstring(char* s) {
	//�������ĳ��ȣ��ַ��� 
	int slength = 0;
	for(int i=0; *(s+i)!=0; i++){
		slength += 1;
	}
	//�������s�����Ƿ������� 
	//printf("in f slength: %d\n",slength);
	
	//�ѷ���ֵ�������涨�壬��Ȼ���������涨�壬���˴����ž͵����������� 
	int longest = 0;
	
	//�ų�������Ϊ1��2�Ķ����� 
	if(slength==0){
		return 0;
	}else if(slength==1){
		return 1;
	}else{
		//����һ���½ṹ��l,���Ҷ���q��׷�ٴ���l 
		Node* l = (Node*)malloc(sizeof(Node));
		Node* p = l;
		
		//ֱ�Ӱ������һ��Ԫ�ش��ݸ������һ���ڵ� 
		p->data = *s;
		p->next = NULL;
		
		int Num = 0;
		
		for(int i=1; *(s+i) != '\0'; i++){
			//����ظ�Ԫ�ص�λ�� 
			Num = repeatNum(*(s+i),l);
			
			//���������ֵ������������������ĵڶ���ֵ�� 
			p->next = (Node*)malloc(sizeof(Node));
			p = p->next;
			p->data = *(s+i);
			p->next = NULL;
			
			//����ǰ�����ظ��ģ��������ָ������ƶ���Ӧ��λ�ã�l��������null 
			if(Num != 0){
				for(int j=0; j<Num; j++){
					l = l->next;
				}
			}
			
			//���ϵļ���lָ���ƶ��������û���ظ�Ԫ�ص�������Ľڵ���� 
			Node* q = l;
			int sum = 0;
			while(q){
				sum += 1;
				q = q->next;
			}
			
			//���û���ظ�Ԫ�ص�������Ľڵ�����������е���������滻� 
			if(sum > longest){
				longest = sum;
			}			
		}		
	}
	return longest;
}

void main(){
	char s[] = "abcdecdefabc";
	//char s[] = "abcabcbb";
	//char s[] = "bbbb";
	//char s[] = "abcdefg";
	//char s[] = "a";
	//char s[] = "";
	printf("�������%d\n",lengthOfLongestSubstring(s));
}
