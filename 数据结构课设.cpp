#include<iostream>
#include<queue>
#define Flag -1
using namespace std;
void menu()
{
	cout << "                    ���˵�                       " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "----------      1.�������ı���         ----------" << endl;
	cout << "----------      2.ֽ����Ϸ             ----------" << endl;
	cout << "----------      3.��������             ----------" << endl;
	cout << "----------      4.����ѡ����           ----------" << endl;
	cout << "-------------------------------------------------" << endl;
}
void menu_1()
{

	cout << "*************************************************" << endl;
	cout << "***   1.������                   2.�������   ***" << endl;
	cout << "***   3.�������                 4.�������   ***" << endl;
	cout << "***   5.��α���                 0.����       ***" << endl;
	cout << "*************************************************" << endl;
}
void menu_2()
{
	cout << "*************************************************" << endl;
	cout << "*****      1.�鿴ָ����ŵķ��Ƽ�¼         *****" << endl;
	cout << "*****      2.�鿴�������泯�ϵ�ֽ�Ʊ��     *****" << endl;
	cout << "*****                0.����                 *****" << endl;
	cout << "*************************************************" << endl;
}
void menu_3()
{
	cout << "*************************************************" << endl;
	cout << "*****            1.ֱ�Ӳ�������             *****" << endl;
	cout << "*****            2.ѡ������                 *****" << endl;
	cout << "*****            3.ð������                 *****" << endl;
	cout << "*****              0.����                   *****" << endl;
	cout << "*************************************************" << endl;
}
void menu_4()
{
	cout << "*************************************************" << endl;
	cout << "*****             1.��ʼ��Ϸ                *****" << endl;
	cout << "*****               0.����                  *****" << endl;
	cout << "*************************************************" << endl;
}
//�������ı���
typedef struct node
{
	char data;
	struct node* lchild;   //����
	struct node* rchild;   //�Һ���
}BNode,*BTree;
int front = 0, rear = 0; //��ʼ����ͷ��β
class Tree
{
public:
	BTree b;
	Tree() { b = NULL; }
	void CreateTree(BTree& b);     //������
	void PreOrder(BTree b);        //�������
	void MidOrder(BTree b);        //�������
	void PostOrder(BTree b);       //�������
	void WOrder(BTree b);          //��Σ���ȣ�����,���ö���ʵ��
};
void Tree::CreateTree(BTree& b)
{
	char c;
	cin >> c;
	if (c == '#') b = NULL;
	else
	{
		b = new BNode;
		b->data = c;
		CreateTree(b->lchild);     //��������
		CreateTree(b->rchild);     //�����Һ���
	}
}
void Tree::PreOrder(BTree b)
{
	if (b != NULL)
	{
		cout << b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
	
}
void Tree::MidOrder(BTree b)
{
	if (b != NULL)
	{
		MidOrder(b->lchild);
		cout << b->data;
		MidOrder(b->rchild);
	}
}
void Tree::PostOrder(BTree b)
{
	if (b != NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data;
	}
}
void Tree::WOrder(BTree b)
{
	if (b == NULL) return;
	queue<BTree>que;  //����һ�����ڵ�Ķ���
	que.push(b);
	while (!que.empty())
	{
		BTree b1 = que.front();   
		cout << b1->data;
		que.pop();    //����
		if (b1->lchild != NULL)
		{
			que.push(b1->lchild);
		}
		if (b1->rchild != NULL)
		{
			que.push(b1->rchild);
		}
	}
	cout << endl;
}



//ֽ����Ϸ
class Card
{
private:
	int flag[52];    //flag��ŷ��ƴ���
public:
	int number[52];  //number��ű��
	void input();    //����52����
	void algorithm();  //�������泯�ϵ��ƺ�
	int flagnum(int i);     //���ط��ƴ�����ֵ
};
void Card::input()
{
	for (int i = 1; i <= 52; i++)
	{
		number[i-1] = i;
		flag[i-1] = 0;
	}
}
void Card::algorithm()
{
	for (int i = 2; i <= 52; i++)    //��ѭ��������ѭ��
	{
		for (int j = 1; j <= 52; j++)   //���������ж�
		{
			if (j % i == 0)
			{
				number[j - 1] = number[j - 1] * Flag;  //ͨ�������ж������滹�Ƿ���
				flag[j - 1]++;      ///��ת����
			}
		}
	}
}
int Card::flagnum(int i)
{
	return flag[i - 1];
}

//��������
typedef struct lnode
{
	int data;
	struct lnode* next;
}LNode,*LinkList;
LinkList CreateList(int length)   //��ͷ���β�巨��������
{
	int i,j;
	LinkList H = new LNode;
	H->data = 0;
	H->next = NULL;
	//����һ��ָ�����ʱ����
	LinkList s = H;
	for (i = 1; i <= length; i++)
	{
		LinkList a = new LNode;   //�����½ڵ㲢��ʼ��
		cin >> j;
		a->data = j;
		//���½�����ӵ������β
		s->next = a;
		s = a;

	}
	s->next = NULL;
	return H;
}
void output(LinkList L) //���
{
	LinkList p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
//ֱ�Ӳ�������
void sort_link(LinkList& L)   
{
	LinkList p = L->next->next;   //ָ���������ĵ�һ��
	L->next->next = NULL;    //�����������һ��ָ�븳��
	while (p != NULL)
	{
		//����һ����Ϣ
		LinkList s = new LNode;
		s->data = p->data;
		s->next = NULL;
		//׼����S���뵽����������
		LinkList p1 = L;
		LinkList p2 = L->next;
		while (p2 != NULL)
		{
			if (p2->data <= s->data)  //����
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			else
			{
				s->next = p2;
				p1->next = s;
				break;
			}
		}
		if (p2 == NULL)
			p1->next = s;
		p = p->next;
	}

}
//ѡ������
void select_sort(LinkList& L) 
{
	LinkList max, premax, p, pre,pos;
	pos = L->next;    //posָ��δ��������ĵ�һ��
	L->next = NULL;   //ͷ�������ÿ�
	while (pos != NULL)
	{
		pre = premax = NULL;
		p = max = pos;
		while (p != NULL)
		{
			if (p->data > max->data)     //�ҵ��ϴ�ֵ
			{
				max = p; premax = pre;
			}
			pre = p;
			p = p->next;    //ָ������ƶ�
		}
		if (premax == NULL)
		{
			pos = max->next;      //���ֵ��δ�����еĵ�һ�����
		}
		else
		{
			premax->next = max->next;      //��δ���������Ƴ������
		}
		max->next = L->next;
		L->next = max;
	}
	
}
//ð������
LinkList maopao(LinkList& head) 
{
	LinkList p,  q;
	int num = 0, j = 0;
	q = head;
	//��ȡ����ĳ��� 
	while (q != NULL) {
		q = q->next;
		num++;
	}
	//ð������Ļ���˼· 
	for (int i = 0; i < num - 1; i++)
	{
		p = q = head;
		j = num - i - 1; //����ÿһ��ѭ���������ȽϵĴ��� 
		while (p->next != NULL && j != 0) {
			j--;
			if (p->data > p->next->data) {
				//�ڵ�Ľ��� 
				if (p == head) head = p->next;
				else q->next = p->next;
				q->next = p->next;
				q = q->next;
				p->next = q->next;
				q->next = p;
				//ִ��������Ĺ��̺�Ϊ���ܹ���p˳����ִ���ƶ������������һλ . 
				p = q;
			}
			q = p; //Ϊ������q������p��ǰ�� 
			p = p->next; //pָ����ƣ���p�������q��ǰ�� 
		}
	}
	return head;
}

//����ѡ����
void king(int m, int n)       //mΪ���ӱ�ţ�nΪ������
{
	if (m < n)
	{
		cout << "������󣬱������ܴ��ں���������" << endl;
		return;
	}
	LinkList head,p1,p2;
	int i;
	head = p1 = p2 = new LNode;      //����ָ��ָ��ͬһ���ڴ�
	for (i = 1; i < m; i++)
	{
		p1 = new LNode;
		p2->next = p1;
		p2 = p1;
	}
	p2->next = head;//���������β����
	p1 = head;//p1ָ���˵�һ�����
	//�����ӱ��
	for (i = 1; i <= m; i++)
	{
		p1->data = i;//�ӵ�һ����㵽���һ��������θ����ӱ��
		
		p1 = p1->next;
	}//ѭ��������p1ָ�������һ�����

	i = 0;
	p1 = head;//�ٰ�p1ָ���һ�����
	cout << "���ӱ���̭��˳��Ϊ��" << endl;
	while (1)
	{
		i++;
		if (p1->next == p1)
			break;

		if (i == n)//if�������ɾ�����Ĺ���
		{
			i = 0;
			cout << p1->data << " ";
			p2->next = p1->next;// ɾ�����p1
			p1 = p2->next;//p1ָ��������һ�����
			continue;
		}
		else
		{
			if (i == n - 1)
				p2 = p1;//���潫Ҫ�˳�����ǰһ����㣨�浽p2�У�
			p1 = p1->next;
		}
	}
	cout << endl;
	cout << "����ʤ�ĺ���Ϊ��" << p1->data << endl;
}
int main()
{
	Tree trees;
	Card card;
	int chose, a,b,c;
	while (1)
	{
		menu();
		cout << "���������ѡ��";
		cin >> chose;
		switch (chose)
		{
		case 1:do
		{
			menu_1();
			cout << "���������ѡ��";
			cin >> a;
			switch (a)
			{
			case 1:trees.CreateTree(trees.b); break;
			case 2:trees.PreOrder(trees.b); cout << endl; break;
			case 3:trees.MidOrder(trees.b); cout << endl; break;
			case 4:trees.PostOrder(trees.b); cout << endl; break;
			case 5:trees.WOrder(trees.b); cout << endl; break;
			}
		} while (a != 0); break;
		case 2:do
		{
			menu_2();
			card.input();
			card.algorithm();
			cout << "���������ѡ��";
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "�������ţ�"; cin >> b;
				if (b < 1 || b>52) cout << "��Ŵ���" << endl;
				else
				{
					cout << "���Ƽ�¼Ϊ��" << endl;
					cout << b << "��ŵķ��ƴ���Ϊ��" << card.flagnum(b) << endl;
					for (int i = 2; i <= 52; i++)
					{
						if (b % i == 0)
							cout << "���Ա��" << i << "Ϊ����ʱ��תһ��" << endl;
					}
				}
				break;
			case 2:for (int i = 1; i <= 52; i++)
			{
				if (card.number[i - 1] > 0)
					cout << i << " ";
			}cout << endl; break;
			}
		} while (a != 0); break;
		case 3:do
		{
			menu_3();
			cout << "���������ѡ��";
			cin >> a;
			switch (a)
			{
			case 1:cout << "������Ҫ�������ݵ�������"; cin >> b;
				cout << "���������ݣ�" << endl;
				LinkList L;
				L = CreateList(b);
				sort_link(L);
				cout << "�����������"; output(L); cout << endl; break;
			case 2:
				cout << "������Ҫ�������ݵ�������"; cin >> b;
				cout << "���������ݣ�" << endl;
				LinkList P;
				P = CreateList(b);
				select_sort(P);
				cout << "�����������"; output(P); cout << endl; break;
			case 3:cout << "������Ҫ�������ݵ�������"; cin >> b;
				cout << "���������ݣ�" << endl;
				LinkList p, s;
				p = CreateList(b);
				s = maopao(p);
				cout << "�����������"; output(s); cout << endl; break;
			}
		} while (a != 0); break;
		case 4:do
		{
			menu_4();
			cout << "���������ѡ��";
			cin >> a;
			if (a == 1)
			{
				cout << "���������������"; cin >> b;
				cout << "�����뱨����"; cin >> c;
				king(b, c);
			}
		} while (a != 0); break;
		}
	}
	return 0;
}
