#include<iostream>
#define SIZE 510

using namespace std;

int arr[SIZE][SIZE];
int dp[SIZE][SIZE];

int x[4] = { -1, 0 , 1 , 0 };
int y[4] = { 0 ,1 , 0 ,-1 };

void dfs(int h_x, int h_y) {
	for (int i = 0; i < 4; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		if (arr[h_x][h_y] < arr[n_x][n_y]) {
			if (dp[n_x][n_y] > 1) {
				dp[h_x][h_y] = dp[h_x][h_y] < dp[n_x][n_y] + 1 ? dp[n_x][n_y] + 1 : dp[h_x][h_y];
				continue;
			}
			dfs(n_x, n_y);
			if (dp[h_x][h_y] < dp[n_x][n_y] + 1) {
				dp[h_x][h_y] = dp[n_x][n_y] + 1;
			}
		}
	}
}
int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N; scanf("%d", &N);

		fill(&arr[0][0], &arr[SIZE][SIZE], 0);
		fill(&dp[0][0], &dp[SIZE][SIZE], 1);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		int max_cnt = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dfs(i, j);
				max_cnt = max_cnt < dp[i][j] ? dp[i][j] : max_cnt;
			}
		}

		printf("#%d %d\n", t, max_cnt);
	}
}