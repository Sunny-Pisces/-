#include<iostream>
#include<queue>
using namespace std;
#define MaxSize 100
typedef char Elemtype;
typedef struct node
{
	Elemtype data;          //数据元素
	struct node* lchild;   //指向左孩子
	struct node* rchild;   //指向右孩子
}BTNode,*BTList;
//创建二叉树
void CreateBTree(BTList& b)
{
	char c;
	cin >> c;
	if (c == '#') b = NULL;
	else
	{
		b = new BTNode;
		b->data = c;
		CreateBTree(b->lchild);
		CreateBTree(b->rchild);
	}
}
//先序遍历
void Preorder(BTList b)
{
	if (b)
	{
		cout << b->data;
		Preorder(b->lchild);
		Preorder(b->rchild);
	}
}
//中序遍历
void Midorder(BTList b)
{
	if (b)
	{
		Midorder(b->lchild);
		cout << b->data;
		Midorder(b->rchild);
	}
}
//后序遍历
void Postorder(BTList b)
{
	if (b)
	{
		Postorder(b->lchild);
		
		Postorder(b->rchild);
		cout << b->data;
	}
}
//求二叉树的高度
int BTHeight(BTList b)
{
	int lchild, rchild;
	if (b == NULL) return(0);
	else
	{
		lchild = BTHeight(b->lchild);
		rchild = BTHeight(b->rchild);
		return(lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}
//输出二叉树
void DispTree(BTList b)
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DispTree(b->lchild);
			if (b->rchild != NULL) cout << ",";
			DispTree(b->rchild);
			cout << ")";
		}
	}
}
//输出二叉树的所有结点个数
int Nodes(BTList b)
{
	//计算二叉树的节点数量，整棵树的节点数 == 左半边的节点数 + 右半边的节点数+根节点(1)
	/*int num1, num2;*/
	if (b == NULL) return 0;
	else
	{
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
	}
}
//输出二叉树的所有叶子结点
void DispLeaf(BTList b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
			cout << b->data;
		DispLeaf(b->lchild);
		DispLeaf(b->rchild);
	}
}
//计算二叉树的叶子节点的数量
int LeafNodes(BTList b)
{
	//   叶子节点 == 左子树的叶子节点 + 右子树的叶子节点
	if (b == NULL) return 0;
	else
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			return 1;
		}
		return LeafNodes(b->lchild) + LeafNodes(b->rchild);
	}
}
//输出二叉树的宽度（队列）
int WidthTree(BTList b)
{
	if (b == NULL) return 0;
	int nLastLevelWidth = 0;//记录上一层的宽度  
	int nCurLevelWidth = 0;//记录当前层的宽度
	queue<BTNode*> myQueue;
	myQueue.push(b);//将根节点入队列
	int nwidth = 1; //二叉树的宽度
	nLastLevelWidth = 1;
	BTList b1 = NULL;
	while (!myQueue.empty()) //当队列不为空
	{
		while (nLastLevelWidth != 0)
		{
			b1 = myQueue.front(); //取出队列头元素
			myQueue.pop();        //将队列头元素出队
			if (b1->lchild != NULL) myQueue.push(b1->lchild);
			if (b1->rchild != NULL) myQueue.push(b1->rchild);
			nLastLevelWidth--;
		}
		nCurLevelWidth = myQueue.size();
		nwidth = nCurLevelWidth > nwidth ? nCurLevelWidth : nwidth;
		nLastLevelWidth = nCurLevelWidth;
	}
	return nwidth;
}
//查找某个结点
BTList FindNode(BTList b, Elemtype x)
{
	BTList p;
	if (b == NULL) return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}
BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}
BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}
int main()
{
	
	BTList b,p;
	CreateBTree(b);
	cout << "输出二叉树：" << endl;
	DispTree(b);
	cout << endl;
	cout << "先序:" << endl;
	Preorder(b);
	cout << endl;
	cout << "中序：" << endl;
	Midorder(b);
	cout << endl;
	cout << "后序：" << endl;
	Postorder(b);
	cout << endl;
	cout << "树高为：" << BTHeight(b) << endl;
	cout << "二叉树所有结点的个数：" <<Nodes(b)<< endl;
	cout << "二叉树的所有叶子结点为：";
	DispLeaf(b);
	cout<<endl;
	cout << "叶子结点的个数：" << LeafNodes(b) << endl;
	cout << "树的宽度为：" << WidthTree(b) << endl;
	char x;
	cout << "请输入要查找的结点值：";
	cin >> x;
	p = FindNode(b, x);
	if (p != NULL)
	{
		if (LchildNode(p) != NULL)
			cout << "左孩子为：" << LchildNode(p)->data<<endl;
		else
			cout << "无左孩子" << endl;
		if (RchildNode(p) != NULL)
			cout << "右孩子为：" << RchildNode(p)->data << endl;
		else
			cout << "无右孩子" << endl;
	}

	return 0;
}
