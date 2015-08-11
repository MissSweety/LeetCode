/*
ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include<stdio.h>
#include<stdlib.h>

char* convert(char* s, int numRows) {
	//���s�ĳ��� 
	int length = 0;
	for(int i=0; *(s+i)!='\0'; i++){
		length += 1;
	}
	//printf("%d\n",length);
    
    //���嶯̬���� 
	char* result = (char*)malloc((length+1)*(sizeof(char)));
    
    //�ų���������� 
    if(numRows==1 || length==0){
    	result = s;
	}else{
	    //��������ÿ����Ԫ�м���������������м���ѭ����Ԫ�������ʱ������ 
		int period = 2*(numRows - 1);
		int x = length / period;
		//printf("%d\n%d\n",period,x);
		
		//�����������½Ǳ� 
		int index = 0;
		//����֮���εĺ��ſ�ʼ��ȡ 
		for(int i=1; i<=numRows; i++){
			//��һ�ŵ��������ס*��s������Ķ���Ҫ����ʵ����ż�1 
			if(i==1){
				for(int j=0; j<=x && period*j<length; j++){
					*(result+index) = *(s+period*j);
					index++;
				}
			}
			//�����м��ŵ������ÿ����������� 
			if(i>1 && i<numRows){
				for(int j=0; j<=x && (period*j+i-1)<length; j++){
					*(result+index) = *(s+period*j+i-1);
					index++;
					//�ж����һ����������ѭ���ڲ��ڣ�ȫ��ȫ�����������û�о����� 
					if((period*j+period-i+1)<length){
						*(result+index) = *(s+period*j+period-i+1);
						index++;
					}	
				}
			}
			//���һ�ŵ�������͵�һ�Ų�࣬���Ǽǵ��кź�ָ�����������1 
			if(i==numRows){
				for(int j=0; j<=x && (period*j+i-1)<length; j++){
					*(result+index) = *(s+period*j+i-1);
					index++;
				}			
			}	
		}		
	}
	return result;
}

void main(){
	//char s[]="PAYPALISHIRING";
	//char s[]="abc";
	char s[]="abcdefghijklmnopqrstuvwxyz";
	//�����ĸ��4��֮�������Ӧ��Ϊ��agmsybfhlnrtxzceikoquwdjpv�� 
	char* t = convert(s,4);
	//ѭ���ķ�ʽ���һ������ 
	for(int i=0; *(t+i)!='\0'; i++){
		printf("%c",*(t+i));
	}
}
