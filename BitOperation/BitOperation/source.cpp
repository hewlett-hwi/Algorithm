#include <iostream>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////////////////////
//
//  void MagicBacktrack(vector<int>& score, int S, int index, int use)
//  ������ �ܸ� S�� ����� ������ ������ ã�´�(��Ʈ��ŷ)
//
//  vector<int>& score : i��° ������ ������ �ܸ������� socre[i]��ŭ ��ȭ��Ų��
//  int S : �ǿ����� ���ϴ� ������ �ܸ� ����
//  int index : index ��°�� ������ ������� �������� �˻���
//  int use : use�� i��° bit�� 1�̸� i��° ������ ����ϱ�� ������
//  int sum : ����ϱ�� �� ������ ���� ��
//
void MagicBacktrack(vector<int>& score, int S, int index, int use, int sum)
{
	// ������ ��
	int n = score.size();

	// ��� ������ ���� ���� ���θ� ��������
	if (index == n)
	{
		// ������ ������ ���� S -> ������ ������ ���
		if (sum == S)
		{
			// n���� ������ Ž��
			for (int i = 0; i < n; i++)
			{
				// i��° ������ ����ϱ�� �߳׿�
				if (use & (1 << i))
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
		return;
	}

	/* ���������� ����� �����Ѵٸ� �Ʒ� ����ġ��� Ž�������� ���� �� �ִ�.
	if (sum > S)
	{
	return;
	}
	*/

	// index ��° ������ ����ϱ�� ������
	MagicBacktrack(score, S, index + 1, use | (1 << index), sum + score[index]);

	// index ��° ������ ��� ���ϱ�� ������
	MagicBacktrack(score, S, index + 1, use, sum);
}

//////////////////////////////////////////////////////////////////////
//
//  void Magic(vector<int> socre, int S)
//  ������ �ܸ� S�� ����� ������ ������ ã�´�
//
//  vector<int> score : i��° ������ ������ �ܸ������� socre[i]��ŭ ��ȭ��Ų��
//  int S : �ǿ����� ���ϴ� ������ �ܸ� ����
//
void Magic(vector<int> score, int S)
{
	int i = 0, j = 0;
	int n = score.size(); // ������ ����

	// ��� ���(2^n)�� Ž��
	for (i = 0; i < (1 << n); i++)
	{
		// ����ϴ� ������ ���� ��
		int sum = 0;

		// ��� ���� Ž��
		for (j = 0; j < n; j++)
		{
			// i�� ��� j��° ������ ��� �ϴ°�?
			if (i & (1 << j))
			{
				// j��° ����Ѵٸ� ������ score[j]��ŭ ���Ѵ�.
				sum += score[j];
			}
		}

		// ����� ������ ���� ���� S�̸� ���� ���
		if (sum == S)
		{
			// ��� ���� Ž��
			for (j = 0; j < n; j++)
			{
				// j��° ������ ��������� ���
				if (i & (1 << j))
				{
					cout << j << " ";
				}
			}
			cout << endl;
		}
	}
}

int main()
{
	// �Լ��� �� ���� �׽�Ʈ �غ��� �ڵ��Դϴ�.
	vector<int> score;

	score.push_back(15);
	score.push_back(13);
	score.push_back(-5);
	score.push_back(7);
	score.push_back(55);
	score.push_back(12);
	score.push_back(3);
	score.push_back(1);
	score.push_back(-11);
	score.push_back(-6);
	score.push_back(4);

	//MagicBacktrack(score, 47, 0, 0, 0);
	Magic(score, 47);
}
