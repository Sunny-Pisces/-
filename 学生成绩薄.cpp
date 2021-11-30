#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	string No;
	float credit[10];
	float score[10];
	int score_number;
public:
	Student()
	{
		name = "δ����";
		No = "000000";
		credit[0]= 0;
		score [0]= 0;
		score_number = 0;
	}
	void show();           //��ʾ��ѧ����ѧ�ֺ�ƽ���ɼ�
	void add();
	void addpoint();
	string pick();
};
class Class
{
private:
	int student_number;
	Student s[100];
public:
	void showStudentMessage();     //��ʾѧ��������Ϣ
	void Find();                //����ָ��ѧ��ѧ��
	void addStudent();           //���ѧ����Ϣ
	void fillMessage();     //���ָ��ѧ��ѧ��ѧ�ֺ�ƽ����
	Class()
	{
		student_number = 0;
	}
};
void menu()
{
	cout << "****************************" << endl;
	cout << "*****1.��ʾѧ��������Ϣ*****" << endl;
	cout << "*********2.����ѧ��*********" << endl;
	cout << "*******3.���ѧ����Ϣ*******" << endl;
	cout << "***4.���ѧ��ѧ�ֺ�ƽ����***" << endl;
	cout << "****************************" << endl;
}
void Student::show()
{
	float cre = 0, sco = 0;
	for (int i = 0; i < score_number; i++)
	{
		cre = cre + credit[i];
		sco = sco + score[i];
	}
	cout << "ѧ��������" << name<<" " << "ѧ�ţ�" << No <<" " << "��ѧ�֣�" << cre <<" " << "ƽ���ɼ�" << sco / score_number << endl;
	
}
void Student::add()
{
	cout << "ѧ��������"; cin >> name; 
	cout << endl;
	cout << "ѧ�ţ�"; cin >> No;
	
}
string Student::pick()
{
	return No;
}
void Student::addpoint()
{
	cout << "�����뿼�Կ�Ŀ����"; cin >> score_number;
	cout << "ѧ�֣�" << endl;
	for (int i = 0; i < score_number; i++)
	{
		cin >> credit[i];
	}
	cout << "�ɼ���" << endl;
	for (int i = 0; i < score_number; i++)
	{
		cin >> score[i];
	}
}
void Class::showStudentMessage()
{
	for (int i=0; i < student_number; i++)
	{
		s[i].show();
		
	}
	system("pause");
	system("cls");

}
void Class::Find()
{
	string no;
	int i;
	cout << "������ָ��ѧ�ţ�";
	cin >> no;
	for ( i=0; i<student_number ; i++)
	{
		if (no == s[i].pick())
		{
			s[i].show();
			break;
		}
	}
	if (i == student_number)
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void Class::addStudent()
{
	while (1)
	{
		if (student_number == 100) return;
		else
		{
			s[student_number].add();
			student_number++;
			break;
		}
	}
	system("pause");
	system("cls");
}
void Class::fillMessage()
{
	string no;
	int i;
	cout << "������ָ��ѧ�ţ�";
	cin >> no;
	for ( i=0; i < student_number; i++)
	{
		if (no == s[i].pick())
		{
			s[i].addpoint();
			break;
		}
		
	}
	if (i == student_number)
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	Class c;
	int putin;
	while (1)
	{
	    menu();
		cout << "��������ţ�";
		cin >> putin;
		if (putin == 1)
		{
			c.showStudentMessage();
		}
		else if (putin == 2)
		{
			c.Find();
		}
		else if (putin == 3)
		{
			c.addStudent();
		}
		else if (putin == 4)
		{
			c.fillMessage();
		}
		else
		{
			cout << "����������������룡" << endl;
		}

	}
	return 0;

}