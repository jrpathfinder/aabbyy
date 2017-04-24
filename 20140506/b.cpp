#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 11;
int current[N], last[N];

int solve(int m, int n) {
	memset(last, 0, sizeof last);
	for (int i = 1; i <= m; ++i) {
		int k = i >> 1, remain = n;
		sort(last, last + i - 1); // ����һ�ֵĽ������
		memset(current, 0, sizeof current);
		for (int j = 0; j < k; ++j) remain -= (current[j] = last[j] + 1); // �ֺ�һ���ǿ������Ҫ������֮ǰ�ܻ�õ���ʯ��һ
		while (k > 0 && last[k - 1] == last[k]) current[k - 1] = 0, --k; // ����
		last[i - 1] = current[i - 1] = max(remain, -1); // ��ǰǿ����õ������ʯ��
		if (current[i - 1] >= 0) memcpy(last, current, sizeof last); // ������ǿ��һ��������α����ϴεĽ��
		//for (int j = 0; j < i; ++j) cout << last[j] << ' '; cout << endl;
	}
	return current[m - 1];
}

int run() {
	int m, n;
	while (cin >> m >> n) cout << solve(m, n) << endl;
	return 0;
}

int main() {
	freopen("bandits.in", "r", stdin);
	freopen("bandits.out", "w", stdout);
	ios::sync_with_stdio(0);
	return run();
}
