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
		name = "未命名";
		No = "000000";
		credit[0]= 0;
		score [0]= 0;
		score_number = 0;
	}
	void show();           //显示该学生总学分和平均成绩
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
	void showStudentMessage();     //显示学生所有信息
	void Find();                //查找指定学号学生
	void addStudent();           //添加学生信息
	void fillMessage();     //填充指定学号学生学分和平均分
	Class()
	{
		student_number = 0;
	}
};
void menu()
{
	cout << "****************************" << endl;
	cout << "*****1.显示学生所有信息*****" << endl;
	cout << "*********2.查找学生*********" << endl;
	cout << "*******3.添加学生信息*******" << endl;
	cout << "***4.填充学生学分和平均分***" << endl;
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
	cout << "学生姓名：" << name<<" " << "学号：" << No <<" " << "总学分：" << cre <<" " << "平均成绩" << sco / score_number << endl;
	
}
void Student::add()
{
	cout << "学生姓名："; cin >> name; 
	cout << endl;
	cout << "学号："; cin >> No;
	
}
string Student::pick()
{
	return No;
}
void Student::addpoint()
{
	cout << "请输入考试科目数："; cin >> score_number;
	cout << "学分：" << endl;
	for (int i = 0; i < score_number; i++)
	{
		cin >> credit[i];
	}
	cout << "成绩：" << endl;
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
	cout << "请输入指定学号：";
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
		cout << "查无此人！" << endl;
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
	cout << "请输入指定学号：";
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
		cout << "查无此人！" << endl;
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
		cout << "请输入序号：";
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
			cout << "输入错误，请重新输入！" << endl;
		}

	}
	return 0;

}