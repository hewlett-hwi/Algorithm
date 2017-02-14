#include <iostream>

using namespace std;

#define SWAP(a,b) { int t;t=a;a=b;b=t; }
void QuickSort(char *ar, int num)
{
	int left, right;
	char key;

	// ������ 1�̸� ���� ��
	if (num <= 1) return;

	// ���ذ� ���� : �迭���� ���� �� ���
	key = ar[num - 1];
	for (left = 0, right = num - 2;; left++, right--) {
		while (ar[left] < key) { left++; }
		while (ar[right] > key) { right--; }
		if (left >= right) break;            // �¿찡 ������ ��
		SWAP(ar[left], ar[right]);
	}
	SWAP(ar[left], ar[num - 1]);                   // ���ذ��� i��ġ�� �� ��ȯ

	QuickSort(ar, left);                           // ���� ���� ����
	QuickSort(ar + left + 1, num - left - 1);        // ������ ���� ����
}

void main()
{
	char str[] = "greathuman";

	printf("���� ���� ���ڿ� : %s\n", str);
	QuickSort(str, strlen(str));
	printf("���ĵ� ���ڿ� : %s\n", str);
}