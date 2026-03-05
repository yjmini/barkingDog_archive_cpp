#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int parent[10] = { 0,0,0,3,3,3,6,6,8,8 };
//테스트
int find(int tar)
{
	if (tar == parent[tar])
		return tar;

	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;

	parent[t2] = t1;
}

int main()
{
	int N;
	cin >> N;

	char a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		setUnion(a - 'A', b - 'A');
	}

	set<int> myset;
	for (int i = 0; i < 10; i++)
	{
		myset.insert(find(i));
	}

	cout << myset.size() << "개" << '\n';

	return 0;
}