#include<stdio.h>

#define MAXSIZE 50

typedef struct Node {
	char data[MAXSIZE];
	int length;
}SqList;

//void InitList(SqList &L);//such as: int &a
void InitList(SqList *L);
//如果我们传入一个L进去，栈中就会创造一个L，则大大的浪费空间，所以传地址就行，但是，如果非要传结构体也没事儿，反正新结构体和传入的结构体类似，所以读的话，传啥就行；如果写的话，则传指针
int  Length(SqList *L);
int ListInsert(SqList *L,int pos,int value);
void PrintList(SqList *L);
int IsEmpty(SqList *L);
void Destory(SqList *L);
int GetPos(SqList *L,int pos,int* result);//返回值返回操作正确与否，结果让一个指针带出来
int Locate(SqList *L,int value,int *pos);//返回值返回操作正确与否，结果让pos指针带出来
int ListDelete(SqList *L,int pos,int *result);
/*
 *
 *	其实不管怎么说，从来都只有传值，没有传地址这么一说；
 *	按照这个说法来理解，
 *	函数声明的时候，就是我们在栈中定义的局部变量；
 *	如int a;int *a;
 *	但是从来也没有什么int &a;这样的定义法则；
 *	
 *
 * */
/*void exchange(int &a,int &b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
*/

int main()
{

	SqList sqL;
	InitList(&sqL);//==SqList *
	printf("初始化完成，现在的顺序表长度为:%d\n",sqL.length);
	printf("长度:%d\n",Length(&sqL));

	int value;
	int pos;
	
	printf("insert result:%d\n",ListInsert(&sqL,1,9));
	printf("insert result:%d\n",ListInsert(&sqL,2,5));
	printf("insert result:%d\n",ListInsert(&sqL,2,2));
	printf("insert result:%d\n",ListInsert(&sqL,1,7));
	printf("长度:%d\n",Length(&sqL));
	printf("遍历顺序表:");
	PrintList(&sqL);
	printf("判断一下是否为空:%d\n",IsEmpty(&sqL));
	int result = 0;
	printf("按位查询返回结果%d\n",GetPos(&sqL,2,&result));
	printf("查询结果值%d\n",result);
	printf("按值查询返回结果%d\n",Locate(&sqL,7,&result));
	printf("查询结果位置%d\n",result);
	printf("===开始删除===\n");
	printf("删除结果%d:\n",ListDelete(&sqL,2,&result));
	printf("删除的值:%d\n",result);
	printf("最终结果\n");
	PrintList(&sqL);
	printf("开始销毁\n");
	Destory(&sqL);
	printf("判断一下是否为空:%d\n",IsEmpty(&sqL));
	
//	int a = 1;
//      int b = 2;
//	exchange(&a,&b);
//	printf("%d\t",a);
//	printf("%d\t",b);

	return 0;
}

void InitList(SqList* L) 
{
	L->length = 0;
}



int  Length(SqList *L) {
	return L->length;
}

int ListInsert(SqList *L,int pos,int value) {
	
	if(pos < 1 || pos > L->length+1) 
		return 0;
	if(L->length > MAXSIZE)
		return 0;
	int i;
	for(i = L->length; i >= pos; i-- )
		L->data[i] = L->data[i-1];
	L->data[pos - 1] = value;
        L->length++;
	return 1;	
}


void PrintList(SqList *L) {
	
	int i;
	for(i = 0; i < L->length;i++) {
		printf("%d\t",L->data[i]);	
	}
	printf("\n遍历完毕\n");

}

int IsEmpty(SqList *L) {
	return L->length == 0 ? 1 : 0;
}

void Destory(SqList *L) {
	L->length = 0;	
}


int GetPos(SqList *L,int pos,int* result) {
	if(pos <1 || pos > L->length)
		return 0;
	else {
		*result = L->data[pos-1];
		return 1;
	}
}

int Locate(SqList *L,int value,int *pos) {
	int i;
	for(i = 0; i < L->length;i++) {
		if(L->data[i] == value)
			*pos = i;
			return 1;
	}
	return 0;
}

int ListDelete(SqList *L,int pos,int *result) {
	if(pos < 1 || pos > L->length)
		return 0;
	*result = L->data[pos-1];
	int i;
	for(i = pos; i< L->length;i++)
		L->data[i-1] = L->data[i];
	L->length--;
	return 1;
}
