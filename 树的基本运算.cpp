#include<iostream>
#include<queue>
using namespace std;
#define MaxSize 100
typedef char Elemtype;
typedef struct node
{
	Elemtype data;          //����Ԫ��
	struct node* lchild;   //ָ������
	struct node* rchild;   //ָ���Һ���
}BTNode,*BTList;
//����������
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
//�������
void Preorder(BTList b)
{
	if (b)
	{
		cout << b->data;
		Preorder(b->lchild);
		Preorder(b->rchild);
	}
}
//�������
void Midorder(BTList b)
{
	if (b)
	{
		Midorder(b->lchild);
		cout << b->data;
		Midorder(b->rchild);
	}
}
//�������
void Postorder(BTList b)
{
	if (b)
	{
		Postorder(b->lchild);
		
		Postorder(b->rchild);
		cout << b->data;
	}
}
//��������ĸ߶�
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
//���������
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
//��������������н�����
int Nodes(BTList b)
{
	//����������Ľڵ��������������Ľڵ��� == ���ߵĽڵ��� + �Ұ�ߵĽڵ���+���ڵ�(1)
	/*int num1, num2;*/
	if (b == NULL) return 0;
	else
	{
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
	}
}
//���������������Ҷ�ӽ��
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
//�����������Ҷ�ӽڵ������
int LeafNodes(BTList b)
{
	//   Ҷ�ӽڵ� == ��������Ҷ�ӽڵ� + ��������Ҷ�ӽڵ�
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
//����������Ŀ�ȣ����У�
int WidthTree(BTList b)
{
	if (b == NULL) return 0;
	int nLastLevelWidth = 0;//��¼��һ��Ŀ��  
	int nCurLevelWidth = 0;//��¼��ǰ��Ŀ��
	queue<BTNode*> myQueue;
	myQueue.push(b);//�����ڵ������
	int nwidth = 1; //�������Ŀ��
	nLastLevelWidth = 1;
	BTList b1 = NULL;
	while (!myQueue.empty()) //�����в�Ϊ��
	{
		while (nLastLevelWidth != 0)
		{
			b1 = myQueue.front(); //ȡ������ͷԪ��
			myQueue.pop();        //������ͷԪ�س���
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
//����ĳ�����
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
	cout << "�����������" << endl;
	DispTree(b);
	cout << endl;
	cout << "����:" << endl;
	Preorder(b);
	cout << endl;
	cout << "����" << endl;
	Midorder(b);
	cout << endl;
	cout << "����" << endl;
	Postorder(b);
	cout << endl;
	cout << "����Ϊ��" << BTHeight(b) << endl;
	cout << "���������н��ĸ�����" <<Nodes(b)<< endl;
	cout << "������������Ҷ�ӽ��Ϊ��";
	DispLeaf(b);
	cout<<endl;
	cout << "Ҷ�ӽ��ĸ�����" << LeafNodes(b) << endl;
	cout << "���Ŀ��Ϊ��" << WidthTree(b) << endl;
	char x;
	cout << "������Ҫ���ҵĽ��ֵ��";
	cin >> x;
	p = FindNode(b, x);
	if (p != NULL)
	{
		if (LchildNode(p) != NULL)
			cout << "����Ϊ��" << LchildNode(p)->data<<endl;
		else
			cout << "������" << endl;
		if (RchildNode(p) != NULL)
			cout << "�Һ���Ϊ��" << RchildNode(p)->data << endl;
		else
			cout << "���Һ���" << endl;
	}

	return 0;
}
