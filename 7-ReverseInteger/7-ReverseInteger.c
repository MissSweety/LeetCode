/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include<stdio.h>
#include<stdlib.h>

int reverse(int x) {
    int reverse[10]={};
    int index=0;
    int result=0;
    
    if(x==0){
        result=0;
    }
    if(x>0){
        while(x){
            reverse[index++]=x%10;
            x/=10;
        }
        /*
        ���Է�ת�Ƿ�ɹ� 
        for(int i=0;i<index;i++){
            printf("%d\n",reverse[i]);
        } 
        */
        //����index�Ƿ��Ԥ��һ�� 
    	//printf("%d\n",index);
    	
        for(int i=0;i<index;i++){
        	//����ÿ�γ��Եı���������10�Ķ��ٴη� 
            int times=1;
            for(int j=0;j<(index-i);j++){
                if(j==0){
                    times*=1;
                }else{
                    times*=10;
                }
            }
            result+=reverse[i]*times;
        }
    }
    if(x<0){
        int y;
        y=x*(-1);
        while(y){
            reverse[index++]=y%10;
            y/=10;
        }
    
        for(int i=0;i<index;i++){
            int times=1;
            for(int j=1;j<(index-i);j++){
                if(j==0){
                    times*=1;
                }else{
                    times*=10;
                }
            }
            result+=reverse[i]*times;
        }
        result=result*(-1);
    }
    return result;
}

void main(){
	printf("%d\n",reverse(-123));
	//���꣬���Խ�����⴦�����ˣ������ 
	printf("%d\n",reverse(1534236469));
}
