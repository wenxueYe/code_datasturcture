#include<stdio.h>
int main() {
	//int a[3];//存储到栈区了，没有人给他赋值
	//static int a[3] = {1};//在静态区，系统默认赋值
	//static int a[] = {1,2,3};
	int a[][3] = {1,2,3,4,5};
	int i;
	for(i=0;i<5;i++) {
		printf("%d\n",*(*a+i));
	}
	return 0;
}
