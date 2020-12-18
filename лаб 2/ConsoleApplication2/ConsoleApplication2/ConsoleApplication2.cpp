#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


void qs(int* items, int left, int right) //����� �������: qs(items, 0, count-1);
{
	int i, j;
	int x, y;
	i = left; j = right;
	/* ����� ���������� */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}


int cmp(const void* a, const void* b) {    //������� ��������� ��������� �������
	{
		return *(int*)a - *(int*)b;		// ���� ��������� ��������� ����� 0, �� ����� �����
	}
}

int main()
{
	int m[100000]; int x = 0; int term, term1;

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("+--------------------------------------------+\n");
	printf("|     �������� ������ ���������� �������     |\n");
	printf("+--------------------------------------------+\n");
	printf("+  1 ���������� ������� ���������� �������   +\n");
	printf("+      2 ������������ ������������������     +\n");
	printf("+      3 ��������� ������������������        +\n");
	printf("+ 4 �����������-��������� ������������������ +\n");
	printf("+ 5 ��������-������������ ������������������ +\n");
	printf("+--------------------------------------------+\n");

	scanf_s("%d", &term);

	while (term != 0)
	{

		if (term == 1)
		{
			printf("������� ������ �������:");
			scanf_s("%d", &x);
			for (int i = 0; i < x; i++) {   //���������� ������� ���������� �������
				m[i] = rand() % 100 + 1;
			}

		}

		else if (term == 2)
		{
			printf("������� ������ �������:");
			scanf_s("%d", &x);
			for (int i = 1; i < x; i++) {		//������������ ������������������
				m[i] = m[i - 1] + 1;
			}
		}
		else if (term == 3)
		{
			printf("������� ������ �������:");
			scanf_s("%d", &x);
			for (int i = 0; i < x; i++) {	//��������� ������������������
				m[i] = x - i;
			}
		}

		else if (term == 4)
		{
			printf("������� ������ �������:");
			scanf_s("%d", &x);
			for (int i = 0; i < x / 2; i++) {	//�����������-��������� ������������������
				m[i] = m[i - 1] + 1;
			}
		}

		else if (term == 5)
		{
			printf("������� ������ �������:");
			scanf_s("%d", &x);
			for (int i = 0; i < x / 2; i++) {	//�����������-��������� ������������������
				m[i] = m[i - 1] + 1;
			}
			for (int i = 5; i < x; i++) {
				m[i] = x - i;
			}
		}

		else {
			printf("������� �������� �� 1-5");
		}

		printf("+--------------------------------+\n");
		printf("|       �������� ����������      |\n");
		printf("+--------------------------------+\n");
		printf("+       1 ���������� �����       +\n");
		printf("+     2 ������� ����������       +\n");
		printf("+     3 ������� ������� ����     +\n");
		printf("+--------------------------------+\n");

		scanf_s("%d", &term1);

		float start_time = clock();
		if (term1 == 1)
		{
			shell(m, 10000);	//���������� �����
		}

		else if (term1 = 2)
		{
			qs(m, 0, 10000 - 1);	//������� ����������
		}

		else if (term1 = 3)
		{
			qsort(m, 10000, sizeof(int), cmp); // �-� ������� ����������
		}

		float end_time = clock();
		float search_time = end_time - start_time;

		printf("����������� �����:");
		printf("%f\n", search_time);

		printf("+--------------------------------------------+\n");
		printf("|     �������� ������ ���������� �������     |\n");
		printf("+--------------------------------------------+\n");
		printf("+  1 ���������� ������� ���������� �������   +\n");
		printf("+      2 ������������ ������������������     +\n");
		printf("+      3 ��������� ������������������        +\n");
		printf("+ 4 �����������-��������� ������������������ +\n");
		printf("+ 5 ��������-������������ ������������������ +\n");
		printf("+--------------------------------------------+\n");

		scanf_s("%d", &term);
		//		system("cls"); // ������� �����
	}
	return (0);
}
