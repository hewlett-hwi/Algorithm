#include <iostream>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////////////////////
//
//  void MagicBacktrack(vector<int>& score, int S, int index, int use)
//  슈렉의 외모를 S로 만드는 마법의 조합을 찾는다(백트레킹)
//
//  vector<int>& score : i번째 마법이 슈렉의 외모점수를 socre[i]만큼 변화시킨다
//  int S : 피오나가 원하는 슈렉의 외모 점수
//  int index : index 번째의 마법을 사용할지 안할지를 검사함
//  int use : use의 i번째 bit가 1이면 i번째 마법을 사용하기로 결정함
//  int sum : 사용하기로 한 마법의 점수 합
//
void MagicBacktrack(vector<int>& score, int S, int index, int use, int sum)
{
	// 마법의 수
	int n = score.size();

	// 모든 마법에 대해 선택 여부를 결정했음
	if (index == n)
	{
		// 선택한 마법의 합이 S -> 선택한 마법을 출력
		if (sum == S)
		{
			// n개의 마법을 탐샙
			for (int i = 0; i < n; i++)
			{
				// i번째 마법을 사용하기로 했네요
				if (use & (1 << i))
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
		return;
	}

	/* 마법점수가 양수만 존재한다면 아래 가지치기로 탐색범위를 줄일 수 있다.
	if (sum > S)
	{
	return;
	}
	*/

	// index 번째 마법을 사용하기로 결정함
	MagicBacktrack(score, S, index + 1, use | (1 << index), sum + score[index]);

	// index 번째 마법을 사용 안하기로 결정함
	MagicBacktrack(score, S, index + 1, use, sum);
}

//////////////////////////////////////////////////////////////////////
//
//  void Magic(vector<int> socre, int S)
//  슈렉의 외모를 S로 만드는 마법의 조합을 찾는다
//
//  vector<int> score : i번째 마법이 슈렉의 외모점수를 socre[i]만큼 변화시킨다
//  int S : 피오나가 원하는 슈렉의 외모 점수
//
void Magic(vector<int> score, int S)
{
	int i = 0, j = 0;
	int n = score.size(); // 마법의 갯수

	// 모든 경우(2^n)를 탐색
	for (i = 0; i < (1 << n); i++)
	{
		// 사용하는 마법의 점수 합
		int sum = 0;

		// 모든 마법 탐색
		for (j = 0; j < n; j++)
		{
			// i의 경우 j번째 마법을 사용 하는가?
			if (i & (1 << j))
			{
				// j번째 사용한다면 점수는 score[j]만큼 변한다.
				sum += score[j];
			}
		}

		// 사용한 마법의 점수 합이 S이면 마법 출력
		if (sum == S)
		{
			// 모든 마법 탐색
			for (j = 0; j < n; j++)
			{
				// j번째 마법을 사용했으면 출력
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
	// 함수가 잘 도나 테스트 해보는 코드입니다.
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
