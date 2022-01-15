#include<iostream>
#include<queue>
#define Flag -1
using namespace std;
void menu()
{
	cout << "                    主菜单                       " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "----------      1.二叉树的遍历         ----------" << endl;
	cout << "----------      2.纸牌游戏             ----------" << endl;
	cout << "----------      3.各种排序             ----------" << endl;
	cout << "----------      4.猴子选大王           ----------" << endl;
	cout << "-------------------------------------------------" << endl;
}
void menu_1()
{

	cout << "*************************************************" << endl;
	cout << "***   1.创建树                   2.先序遍历   ***" << endl;
	cout << "***   3.中序遍历                 4.后序遍历   ***" << endl;
	cout << "***   5.层次遍历                 0.返回       ***" << endl;
	cout << "*************************************************" << endl;
}
void menu_2()
{
	cout << "*************************************************" << endl;
	cout << "*****      1.查看指定编号的翻牌记录         *****" << endl;
	cout << "*****      2.查看最终正面朝上的纸牌编号     *****" << endl;
	cout << "*****                0.返回                 *****" << endl;
	cout << "*************************************************" << endl;
}
void menu_3()
{
	cout << "*************************************************" << endl;
	cout << "*****            1.直接插入排序             *****" << endl;
	cout << "*****            2.选择排序                 *****" << endl;
	cout << "*****            3.冒泡排序                 *****" << endl;
	cout << "*****              0.返回                   *****" << endl;
	cout << "*************************************************" << endl;
}
void menu_4()
{
	cout << "*************************************************" << endl;
	cout << "*****             1.开始游戏                *****" << endl;
	cout << "*****               0.返回                  *****" << endl;
	cout << "*************************************************" << endl;
}
//二叉树的遍历
typedef struct node
{
	char data;
	struct node* lchild;   //左孩子
	struct node* rchild;   //右孩子
}BNode,*BTree;
int front = 0, rear = 0; //初始化队头队尾
class Tree
{
public:
	BTree b;
	Tree() { b = NULL; }
	void CreateTree(BTree& b);     //创建树
	void PreOrder(BTree b);        //先序遍历
	void MidOrder(BTree b);        //中序遍历
	void PostOrder(BTree b);       //后序遍历
	void WOrder(BTree b);          //层次（广度）遍历,利用队列实现
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
		CreateTree(b->lchild);     //创建左孩子
		CreateTree(b->rchild);     //创建右孩子
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
	queue<BTree>que;  //构造一个树节点的队列
	que.push(b);
	while (!que.empty())
	{
		BTree b1 = que.front();   
		cout << b1->data;
		que.pop();    //出队
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



//纸牌游戏
class Card
{
private:
	int flag[52];    //flag存放翻牌次数
public:
	int number[52];  //number存放编号
	void input();    //输入52个数
	void algorithm();  //最终正面朝上的牌号
	int flagnum(int i);     //返回翻牌次数的值
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
	for (int i = 2; i <= 52; i++)    //外循环，基数循环
	{
		for (int j = 1; j <= 52; j++)   //倍数条件判断
		{
			if (j % i == 0)
			{
				number[j - 1] = number[j - 1] * Flag;  //通过正负判断是正面还是反面
				flag[j - 1]++;      ///翻转次数
			}
		}
	}
}
int Card::flagnum(int i)
{
	return flag[i - 1];
}

//各种排序
typedef struct lnode
{
	int data;
	struct lnode* next;
}LNode,*LinkList;
LinkList CreateList(int length)   //有头结点尾插法创建链表
{
	int i,j;
	LinkList H = new LNode;
	H->data = 0;
	H->next = NULL;
	//设置一个指针遍历时可用
	LinkList s = H;
	for (i = 1; i <= length; i++)
	{
		LinkList a = new LNode;   //创建新节点并初始化
		cin >> j;
		a->data = j;
		//将新结点链接到链表表尾
		s->next = a;
		s = a;

	}
	s->next = NULL;
	return H;
}
void output(LinkList L) //输出
{
	LinkList p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
//直接插入排序
void sort_link(LinkList& L)   
{
	LinkList p = L->next->next;   //指向无序区的第一个
	L->next->next = NULL;    //有序区间最后一个指针赋空
	while (p != NULL)
	{
		//拷贝一份信息
		LinkList s = new LNode;
		s->data = p->data;
		s->next = NULL;
		//准备将S插入到有序序列中
		LinkList p1 = L;
		LinkList p2 = L->next;
		while (p2 != NULL)
		{
			if (p2->data <= s->data)  //升序
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
//选择排序
void select_sort(LinkList& L) 
{
	LinkList max, premax, p, pre,pos;
	pos = L->next;    //pos指向未排序链表的第一个
	L->next = NULL;   //头结点后序置空
	while (pos != NULL)
	{
		pre = premax = NULL;
		p = max = pos;
		while (p != NULL)
		{
			if (p->data > max->data)     //找到较大值
			{
				max = p; premax = pre;
			}
			pre = p;
			p = p->next;    //指针向后移动
		}
		if (premax == NULL)
		{
			pos = max->next;      //最大值是未排序中的第一个结点
		}
		else
		{
			premax->next = max->next;      //从未排序链中移除最大结点
		}
		max->next = L->next;
		L->next = max;
	}
	
}
//冒泡排序
LinkList maopao(LinkList& head) 
{
	LinkList p,  q;
	int num = 0, j = 0;
	q = head;
	//获取链表的长度 
	while (q != NULL) {
		q = q->next;
		num++;
	}
	//冒泡排序的基本思路 
	for (int i = 0; i < num - 1; i++)
	{
		p = q = head;
		j = num - i - 1; //减少每一趟循环中两两比较的次数 
		while (p->next != NULL && j != 0) {
			j--;
			if (p->data > p->next->data) {
				//节点的交换 
				if (p == head) head = p->next;
				else q->next = p->next;
				q->next = p->next;
				q = q->next;
				p->next = q->next;
				q->next = p;
				//执行完上面的过程后，为了能够让p顺利地执行移动到交换后的下一位 . 
				p = q;
			}
			q = p; //为了能让q保持在p的前面 
			p = p->next; //p指针后移，即p变成了在q的前面 
		}
	}
	return head;
}

//猴子选大王
void king(int m, int n)       //m为猴子编号，n为报号数
{
	if (m < n)
	{
		cout << "输入错误，报数不能大于猴子数量！" << endl;
		return;
	}
	LinkList head,p1,p2;
	int i;
	head = p1 = p2 = new LNode;      //三个指针指向同一个内存
	for (i = 1; i < m; i++)
	{
		p1 = new LNode;
		p2->next = p1;
		p2 = p1;
	}
	p2->next = head;//把链表的首尾相连
	p1 = head;//p1指向了第一个结点
	//给猴子编号
	for (i = 1; i <= m; i++)
	{
		p1->data = i;//从第一个结点到最后一个结点依次给猴子编号
		
		p1 = p1->next;
	}//循环结束，p1指向了最后一个结点

	i = 0;
	p1 = head;//再把p1指向第一个结点
	cout << "猴子被淘汰的顺序为：" << endl;
	while (1)
	{
		i++;
		if (p1->next == p1)
			break;

		if (i == n)//if语句中是删除结点的过程
		{
			i = 0;
			cout << p1->data << " ";
			p2->next = p1->next;// 删除结点p1
			p1 = p2->next;//p1指向它的下一个结点
			continue;
		}
		else
		{
			if (i == n - 1)
				p2 = p1;//保存将要退出结点的前一个结点（存到p2中）
			p1 = p1->next;
		}
	}
	cout << endl;
	cout << "最后获胜的猴子为：" << p1->data << endl;
}
int main()
{
	Tree trees;
	Card card;
	int chose, a,b,c;
	while (1)
	{
		menu();
		cout << "请输入你的选择：";
		cin >> chose;
		switch (chose)
		{
		case 1:do
		{
			menu_1();
			cout << "请输入你的选择：";
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
			cout << "请输入你的选择：";
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "请输入编号："; cin >> b;
				if (b < 1 || b>52) cout << "编号错误！" << endl;
				else
				{
					cout << "翻牌记录为：" << endl;
					cout << b << "编号的翻牌次数为：" << card.flagnum(b) << endl;
					for (int i = 2; i <= 52; i++)
					{
						if (b % i == 0)
							cout << "在以编号" << i << "为基数时翻转一次" << endl;
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
			cout << "请输入你的选择：";
			cin >> a;
			switch (a)
			{
			case 1:cout << "请输入要输入数据的数量："; cin >> b;
				cout << "请输入数据：" << endl;
				LinkList L;
				L = CreateList(b);
				sort_link(L);
				cout << "按升序排序后："; output(L); cout << endl; break;
			case 2:
				cout << "请输入要输入数据的数量："; cin >> b;
				cout << "请输入数据：" << endl;
				LinkList P;
				P = CreateList(b);
				select_sort(P);
				cout << "按升序排序后："; output(P); cout << endl; break;
			case 3:cout << "请输入要输入数据的数量："; cin >> b;
				cout << "请输入数据：" << endl;
				LinkList p, s;
				p = CreateList(b);
				s = maopao(p);
				cout << "按升序排序后："; output(s); cout << endl; break;
			}
		} while (a != 0); break;
		case 4:do
		{
			menu_4();
			cout << "请输入你的选择：";
			cin >> a;
			if (a == 1)
			{
				cout << "请输入猴子数量："; cin >> b;
				cout << "请输入报数："; cin >> c;
				king(b, c);
			}
		} while (a != 0); break;
		}
	}
	return 0;
}
