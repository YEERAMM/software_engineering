#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20] = " 5th Symphony";
	char s2[40] = "Tchaikovsky";

	// �� �迭�� Ȱ���Ͽ� Tchaikovsky 5th Symphony ���ڿ��� �迭 s2�� ����
	int pointer = 0;
	int i = 0;

	for (int i = 0; i < sizeof(s2); i++)
	{
		if (s2[i] == '\0')
		{
			s2[i] = s1[pointer];
			pointer++;
		}
	}

	printf("%s\n", s2);
	return 0;
}