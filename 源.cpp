//串的加密解密
#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;
void StrAssign(SqString& s, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		s.data[i] = cstr[i];
	}
	s.length = i;
}
void display(SqString s)
{
	int i;
	if (s.length > 0)
		for (i = 0; i < s.length; i++)
			cout << s.data[i];

}
//加密
void jam(SqString &s,SqString s1,SqString s2)
{
	int i,j;
	for (i = 0; i < s.length; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (s.data[i] == s1.data[j])
			{
				s.data[i] = s2.data[j];
				break;
			}
		}
	}
	cout << "加密串：" << endl;
	display(s);
}
//解密
void jim(SqString& s, SqString s1, SqString s2)
{
	int i, j;
	for (i = 0; i < s.length; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (s.data[i] == s2.data[j])
			{
				s.data[i] = s1.data[j];
				break;
			}
		}
	}
	cout << "解密串：" << endl;
	display(s);
}
int main()
{
	SqString str,str1,str2;
	char input[MaxSize] = "encrypt";
	char x[] = "Abcdefghijklmnopqrstuvwxyz";
	char y[] = "Ngzqtcobmuhelkpdawxfyivrsj";
	StrAssign(str, input);
	StrAssign(str1, x);
	StrAssign(str2, y);
	jam(str, str1, str2);
	cout << endl;
	jim(str, str1, str2);
	return 0;
}
