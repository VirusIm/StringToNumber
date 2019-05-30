#include <iostream>
#include <Windows.h>

#define tab "\t"


void InputLine(char str[], const int n);
int StrLen(char str[]);
void UpperCase(char str[]);	//��������� ������ � ������� �������;		+
void LowerCase(char str[]); //��������� ������ � ������ �������;		+
void Capitalize(char str[]); //������ ����� ������� ����� � ����������� ������ � ������� ��������;
void Shrink(char str[]);	//������� ������ ������� ����� ������� � �����������.
void RemoveSpaces(char str[]);	//������� ��� ������� �� �����������.
bool isPalindrome(char str[]);	//����������, �������� �� ������ �����������.
								//void shrink_to_fit(char str[]);	//������� ������ ����� ����� ����� ������. (��������� ��������������� ������).

bool isIntNumber(char str[]);	//���� � ������ �����, 1
int  StringToInt(char str[]);	//���� 1, �� ������ �������� � int(������������� ����������)


void main()
{
	setlocale(0, "");

	/*char str[] = {'h', 'e', 'l', 'l', 'o','\0'};
	char msg[] = "Hello";
	std::cout << str << std::endl;
	std::cout << msg << std::endl;
	std::cout << sizeof(msg) << std::endl;*/
	const int n = 30;
	char str[n] = {};
	std::cout << "������� ������: ";
	//std::cin >> str;
	int Counter;
	InputLine(str, n);
	/*std::cout << str << std::endl;
	std::cout << StrLen(str) << std::endl;
	std::cout << "������� �������:  " << std::endl;
	UpperCase(str);
	std::cout << str << std::endl;
	std::cout << "������ �������: " << std::endl;
	LowerCase(str);
	std::cout << str << std::endl;
	std::cout << "������ ����� ������� ������: " << std::endl;
	Capitalize(str);
	std::cout << str << std::endl;
	std::cout << "�������� ������ ��������: " << std::endl;
	Shrink(str);
	std::cout << str << std::endl;
	std::cout << "������� ��� �������: " << std::endl;
	RemoveSpaces(str);
	std::cout << str << std::endl;*/

	std::cout << "�������� ����� �� ��������: " << std::endl;
	std::cout << isPalindrome(str) << std::endl;
	std::cout << str << std::endl;
	std::cout << "�������� ������ �� �����: " << std::endl;
	std::cout << isIntNumber(str) << std::endl;
	std::cout << "������� ������ � ��� INT: " << std::endl;
	std::cout << StringToInt(str)*2 << std::endl;
}

void InputLine(char str[], const int n)
{

	SetConsoleCP(1251);
	std::cin.getline(str, n);
	SetConsoleCP(866);
}

int StrLen(char str[])
{
	/*int Counter = 0;
	for (; *str; str++)Counter++;
	return Counter;*/
	int i = 0; for (; str[i]; i++); return i;
}

void UpperCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if
			(
				str[i] >= 97 && str[i] <= 'z'
				|| str[i] >= '�'&&str[i] <= '�'
				)
			str[i] -= 32;
	}

}

void LowerCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if
			(
				str[i] >= 'A' && str[i] <= 'Z' ||
				str[i] >= '�' && str[i] <= '�'
				)
			str[i] += 32;
	}
}

void Capitalize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�'&&str[0] <= '�')str[0] -= 32;
	for (int i = 1; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{

			if
				(str[i] >= 97 && str[i] <= 'z' || str[i] >= '�'&&str[i] <= '�')
				str[i] -= 32;
		}
	}
}

void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' '&& str[i + 1] == ' ')
		{

			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}

	}
}

void RemoveSpaces(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}

}

bool isPalindrome(char str[])
{
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)
	{
		buffer[i] = str[i];
	}
	LowerCase(buffer);
	RemoveSpaces(buffer);
	n = StrLen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			return false;
		}
	}
	return true;
}

bool isIntNumber(char str[])
{
	int n = strlen(str);
	char* Buffer = new char[n + 1]{};
	/*for (int i = 0; str[i]; i++)
	{
		Buffer[i] = str[i];
	}*/
	strcpy_s(Buffer, n + 1, str);
	RemoveSpaces(Buffer);
	/*for (int i = 0; Buffer[i]; i++)
	{
		if (Buffer[i] >= 'a'&&Buffer[i] <= 'z'
			|| Buffer[i] >= 'A'&&Buffer[i] <= 'Z'
			|| Buffer[i] >= '�'&&Buffer[i] <= '�'
			|| Buffer[i] >= '�'&&Buffer[i]<='�'&&Buffer[i]>='�')
		{
			return false;
		}
	}
	for (int i = 0; str[i]; i++)
	{
		if (Buffer[i] >= '0' && Buffer[i] <= '9')
		{
			return true;
		}
	}*/

	bool contain_point = false;

	for (int i = Buffer[0] == '+' || Buffer[0] == '-' ? 1 : 0; Buffer[i]; i++)
	{
		if (Buffer[i] == '.' && !contain_point)
		{
			contain_point = true;
			continue;	//��������� ������� �������� ����� � ��������� � ���������
		}
		if (!(Buffer[i] >= '0'&&Buffer[i] <= '9'))return false;
	}
	return true;
}

int  StringToInt(char str[])
{
	if (!isIntNumber(str))
	{
		std::cout << "Error: String not a number";
		return 0;
	}

	int Number = 0;
	int n = strlen(str);
	char* buffer = new char[n + 1];
	strcpy_s(buffer, n + 1, str);
	RemoveSpaces(buffer);
	for (int i = 0; buffer[i]; i++)
	{
		Number *= 10;
		Number += buffer[i] - 48;
	}
	return Number;
}