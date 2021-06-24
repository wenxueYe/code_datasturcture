#include<stdio.h>
#include<stdlib.h>
/*
	数据类型描述
*/
typedef struct Node {
	char data;
	struct Node* next;
}LinkNode,*PLinkList;

/*
	函数原型声明
*/
PLinkList InitList();
void HeadInsert(PLinkList pl);
void TailInsert(PLinkList pl);
void PrintList(PLinkList pl);
int IsEmpty(PLinkList pl);
void Destory(PLinkList pl);
LinkNode* Locate(PLinkList pl,char val);
void ListDelete(PLinkList pl,char val,PLinkList resdel);//删除一个固定的值，用resdel带回删除的内容，如果为NULL，自然就删除失败咯
int Length(PLinkList pl);
int main()
{
		
	PLinkList pl = InitList();
	printf("判断是否为空:%d\n",IsEmpty(pl));	
	HeadInsert(pl);
	printf("遍历结果为:\t");	
	PrintList(pl);
	printf("判断是否为空:%d\n",IsEmpty(pl));
	printf("长度为%d\n",Length(pl));	
	printf("输入一个数据元素的成员值来查找吧:\n");
	char val;
	scanf("%c",&val);
	getchar();
	LinkNode* resPos = Locate(pl,val);
	if(resPos)
		printf("查找到了结果，你要查的成员值是%c嘛?\n",resPos->data);

	printf("输入一个数据元素来删除吧\n");
	scanf("%c",&val);
	getchar();
	ListDelete(pl,val,resPos);
	printf("遍历结果为:\t");	
	PrintList(pl);
	printf("销毁单链表\n");
	Destory(pl);	
	printf("遍历结果为:\t");	
	printf("\n尾插法准备！\n");
	TailInsert(pl);
	printf("遍历结果为:\t");	
	PrintList(pl);

	return 0;
}

/*
	=========
	=========
		--------函数定义部分---------
	=========
	=========

*/
PLinkList InitList() {
	//头节点
	PLinkList pl;
	pl = (PLinkList)malloc(sizeof(LinkNode));
	pl->next = NULL;
	return pl;
}
void HeadInsert(PLinkList pl) {
	/*
		头插法插入单链表
		1.接收一个数据
		2.判断数据是否是结束符号：如#为结束符号
		3.如果为结束符号则结束，否则进入循环
		4.循环体：
			1.申请空间
			2.插入内容
			3.修改链表
			4.重新接受新的数据
		
	*/	
	char val;
	printf("头插法：插入数据元素，数据类型为字符，以#作为结束,中间不要有空白符，否则会被当字母读进去\n");
	scanf("%c",&val);
	PLinkList tmp = NULL;
	while(val != '#') {
		tmp = (PLinkList)malloc(sizeof(LinkNode));
		tmp->data = val;
		tmp->next = pl->next;
		printf("===插入%c===\n",tmp->data);
		pl->next = tmp;
		scanf("%c",&val);
	}
	getchar();//吸收回车符号
	printf("插入结束\n");
}
void TailInsert(PLinkList pl) {
	/*
		尾插法
		1.接收一个数据
		2.判断是否是结束符号
		3.进入循环体
			1.申请空间
			2.插入内容
			3.修改链表
			4.重新接收新的内容
	*/
	char val;
	printf("尾插法：插入数据元素，数据类型为字符，以#作为结束,中间不要有空白符，否则会被当字母读进去\n");
	scanf("%c",&val);
	PLinkList tmp = NULL;
	PLinkList rear = pl;
	while(val != '#') {
		tmp = (LinkNode*)malloc(sizeof(LinkNode));
		tmp->data = val;
		tmp->next = rear->next;
		rear->next = tmp;
		rear = tmp;
		scanf("%c",&val);
	}
	getchar();
	rear->next = NULL;

}
void PrintList(PLinkList pl) {
	PLinkList tmp = pl->next;
	while(tmp) {
		printf("%c\t",tmp->data);
		tmp = tmp->next;	
	}
	printf("\n");
}
int IsEmpty(PLinkList pl) {
	return pl->next == NULL?0:1;	
}
void Destory(PLinkList pl) {
	//销毁就是把后面的内存全部释放了，最后设置为头节点的指针域为NULL
	PLinkList tmp = pl->next;
	PLinkList t = tmp;
	while(tmp) {
		t = tmp;
		tmp = tmp->next;
		free(t);
	}
	
}
LinkNode* Locate(PLinkList pl,char val) {
	PLinkList tmp = pl->next;
	while(tmp) {
		if(tmp->data == val)
			break;
		tmp = tmp->next;
	}
	
	//return (tmp == NULL)?(NULL):(*tmp);
	if(tmp == NULL)
		return NULL;
	else
		return tmp;
}

//找到前驱节点
void ListDelete(PLinkList pl,char val,PLinkList resdel) {
	PLinkList tmp = pl;
	while(tmp->next) {
		if(tmp->next->data == val)	{
			resdel = tmp->next;
			printf("del:%c\n",tmp->data);
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
}
int Length(PLinkList pl) {
	PLinkList tmp = pl->next;
	int len = 0;
	while(tmp) {
		len++;
		tmp = tmp->next;
	}
	return len;
}
