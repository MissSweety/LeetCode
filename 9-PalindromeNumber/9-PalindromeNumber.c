/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
*/

#include<stdio.h>
#include<stdlib.h>

int isPalindrome(int x) {
    int result = 1;
    
    //���Ϊ������ֱ����0 
    if(x<0){
    	result = 0;
	}else{
		//�����������ȣ��Ȱ�x��ֵ��y 
	    int len = 0;
	    int y = x;
	    while(y){
	    	y /= 10;
	    	len += 1;
		}
		
		//����ͷβ 
	    int head, tail;
	    for(int i=0; i< (len-1)/2; i++){
	    	//ȡ��ͷ����ÿ�μ���100����β���δζ���10 
			int period = 1;
	    	for(int j=1; j<(len-2*i); j++){
	    		period *= 10;
			}
			//printf("%d\n",period);
			
	    	head = x / period;
	    	x %= period;
	    	tail = x % 10;
	    	x /= 10;
	    	//printf("%d\n",head);
	    	//printf("%d\n",tail);
	    	//printf("%d\n",x);
	    	
	    	//�������һ����һ����ͷβ������ֵ0��Ȼ�����ѭ��������ʱ�䡣 
	    	if(head != tail){
	    		result = 0;
	    		break;
			}
		}	
	}
    return result;
}

void main(){
	//int x = 14535411;
	int x = 1441;
	printf("%d\n",isPalindrome(x));
}
