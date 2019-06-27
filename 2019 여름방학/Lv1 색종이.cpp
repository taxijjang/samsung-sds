#include<iostream>
#include<algorithm>
#define SIZE 10010

using namespace std;

int arr[SIZE];
int d[SIZE];

void search(int T, int N, int K) {
	int num = 1;
	int zero_cnt = 0;
	int right = 1, left = 1;
	int m_num = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] != 0) {
			if (num == arr[i]) {
				if (zero_cnt != 0) {
					d[arr[i]] += zero_cnt;
					zero_cnt = 0;
				}
				d[arr[i]]++;
			}
			else if (num != arr[i]) {
				if (zero_cnt != 0) {
					if (arr[i] - num > zero_cnt) {
						d[num]++;
						d[arr[i] - 1]++;
					}
					else if (arr[i] - num == zero_cnt) {
						d[arr[i]] += zero_cnt - (arr[i] - num) + 1;
						d[num] += zero_cnt - (arr[i] - num) + 1;
					}
					else if (arr[i] - num < zero_cnt) {
						d[arr[i]] += zero_cnt - (arr[i] - num) + 1;
						d[num] += zero_cnt - (arr[i] - num) + 1;
					}
					zero_cnt = 0;
				}
				num = arr[i];
				d[arr[i]]++;
			}
		}

		else if (arr[i] == 0) {
			zero_cnt++;
		}
	}
	sort(d, d + K + 1);
	printf("#%d %d\n", T, d[K]);
}
int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, K; scanf("%d %d", &N, &K);

		fill(d, d + SIZE, 0);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}

		arr[1] = 1; arr[N] = K;

		search(t, N, K);
	}
}