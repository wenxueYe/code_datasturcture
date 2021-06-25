#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
}BiTNode,*BiTree;
/*	
	==========================函数原型=====================================
*/


//先序创建二叉树
BiTree PreCreateBTree();
//先序遍历二叉树
void PreOrder(BiTree T);
//中序遍历二叉树
void InOrder(BiTree T);
//后序遍历二叉树
void PostOrder(BiTree T);

//TODO	非递归遍历：栈
//TODO	层序遍历：队列

//访问节点数据
void Visit(BiTree);
//树深
int  Depth(BiTree);

//叶子节点个数
	//方式1：递归	体，左孩子个数->右孩子个树;递归出口就是当叶子的时候返回1，为NULL返回0；
	//方式2：选择一种遍历，按照条件筛选，让全局变量num计算结果
int LeafNum(BiTree);
//TODO	度为1的节点个数
//TODO	度为2的节点个数，其实可以直接由叶子节点-1算出来，但是还是用算法求一下

//TODO	打印树形



/*
	==========================MAIN=====================================
*/



int main()
{
	printf("中序创建二叉树:用#代表空节点吧\n");
	BiTree T = PreCreateBTree();
	getchar();
	if(T == NULL)
		printf("T is null.");
	printf("先序遍历:\n");
	PreOrder(T);
	printf("\n");
	printf("中序遍历:\n");
	InOrder(T);
	printf("\n");
	printf("后序遍历:\n");
	PostOrder(T);
	printf("\n");
	printf("树深为%d\n",Depth(T));
	printf("叶子节点个树:%d\n",LeafNum(T));
	return 0;
}
/*
	==========================函数定义=====================================
*/
BiTree PreCreateBTree() {
	char item;
	BiTree BT;
	scanf("%c",&item);
	if(item == '#')
		BT = NULL;
	else {
		BT = (BiTree)malloc(sizeof(BiTNode));
		BT->data = item;
//		printf("%c被插入了\n",BT->data);
		BT->lchild = PreCreateBTree();
		BT->rchild = PreCreateBTree();
	}
	return BT;
}

void PreOrder(BiTree T) {
	if(T) {
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T) {
	if(T) {
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}
void PostOrder(BiTree T) {
	if(T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}
void Visit(BiTree T) {
	printf("%c\t",T->data);
}
int Depth(BiTree T) {
	if(!T)
		return 0;
	int ldepth = Depth(T->lchild) + 1;
	int rdepth = Depth(T->rchild) + 1;
	return ldepth > rdepth ? ldepth : rdepth;
}
int LeafNum(BiTree T) {
	if(!T)
		return 0;
	if(!T->lchild && !T->rchild)
		return 1;
	int leftLeafNum = LeafNum(T->lchild);
	int rightLeafNum = LeafNum(T->rchild);
	return leftLeafNum + rightLeafNum;		
}
