// ���� ������� �����, ���� ������ ����������� ������� s[0], ..., s[n], ...
// 1. ��������, �� � � ��� ����������� ��� �������� s[i�1] , s[i+1]
// �� s[i�1] � �� ���� ���� ('+'), � s[i+1] � ���� ���� ('-'),
// �� ��������� �� �������.
// 2. ������� ����� ����� ������� s[i�1] , s[i] , s[i+1] � �����, �� s[i�1] �
// �� ���� ���� ('+'), � s[i+1] � ���� ���� ('-') �������� ������ "****".
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str)
{
	int k = 0;
	for (int i = 1; str[i + 1] != 0; i++)
		if (str[i] == '+' or str[i] == '-' or str[i] == '=')
			k++;
	return k+1;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
		while (i < len && str[i] != 0)
		{
			if (str[i] == '+' or str[i] == '-' or str[i] == '=')
			{
				strcat(t, "**");
				t += 1;
				i += 1;
			}
			else
			{
				*t++ = str[i++];
				*t = '\0';
			}
		}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " of '+ - ='" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}