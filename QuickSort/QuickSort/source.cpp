#include <iostream>

using namespace std;

#define SWAP(a,b) { int t;t=a;a=b;b=t; }
void QuickSort(char *ar, int num)
{
	int left, right;
	char key;

	// 구간이 1이면 정렬 끝
	if (num <= 1) return;

	// 기준값 결정 : 배열상의 제일 끝 요소
	key = ar[num - 1];
	for (left = 0, right = num - 2;; left++, right--) {
		while (ar[left] < key) { left++; }
		while (ar[right] > key) { right--; }
		if (left >= right) break;            // 좌우가 만나면 끝
		SWAP(ar[left], ar[right]);
	}
	SWAP(ar[left], ar[num - 1]);                   // 기준값과 i위치의 값 교환

	QuickSort(ar, left);                           // 왼쪽 구간 정렬
	QuickSort(ar + left + 1, num - left - 1);        // 오른쪽 구간 정렬
}

void main()
{
	char str[] = "greathuman";

	printf("정렬 전의 문자열 : %s\n", str);
	QuickSort(str, strlen(str));
	printf("정렬된 문자열 : %s\n", str);
}