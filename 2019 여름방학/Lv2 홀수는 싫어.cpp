#include<iostream>
#include<queue>
#define SIZE 310

using namespace std;

typedef struct Data {
	int x, y;
	int oc = 11111;
	int ec = 11111;
}Data;

struct cmp {
	bool operator () (Data d1, Data d2) {
		if (d1.oc == d2.oc) {
			return d1.ec > d2.ec;
		}
		return d1.oc > d2.oc;
	}
};

int arr[SIZE][SIZE];
Data dp[SIZE][SIZE];
bool visited[SIZE][SIZE];
int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1 , 0 , -1 ,0 };

int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N; scanf("%d", &N);

		fill(&arr[0][0], &arr[N][N], 0);
		fill(&visited[0][0], &visited[N][N], false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int num; scanf("%d", &num);
				arr[i][j] = num % 2;
			}
		}

		dp[0][0].x = 0; dp[0][0].y = 0;
		if (arr[0][0] == 0) {
			dp[0][0].ec = 1; dp[0][0].oc = 0;
		}
		else if (arr[0][0] == 1) {
			dp[0][0].ec = 0; dp[0][0].oc = 1;
		}
		priority_queue<Data, vector<Data>, cmp> pq;
		pq.push(dp[0][0]);
		visited[0][0] = true;
		while (!pq.empty()) {
			Data curr = pq.top();
			int h_x = curr.x;
			int h_y = curr.y;
			//printf("%d %d\n", h_x, h_y);

			pq.pop();

			for (int i = 0; i < 4; i++) {
				int n_x = h_x + x[i];
				int n_y = h_y + y[i];

				if (n_x >= N || n_y >= N || n_x < 0 || n_y < 0)
					continue;
				if (visited[n_x][n_y] == false) {
					if (arr[n_x][n_y] == 0) {
						dp[n_x][n_y].x = n_x; dp[n_x][n_y].y = n_y;
						dp[n_x][n_y].ec = dp[h_x][h_y].ec + 1;
						dp[n_x][n_y].oc = dp[h_x][h_y].oc;
					}
					else if (arr[n_x][n_y] == 1) {
						dp[n_x][n_y].x = n_x; dp[n_x][n_y].y = n_y;
						dp[n_x][n_y].ec = dp[h_x][h_y].ec;
						dp[n_x][n_y].oc = dp[h_x][h_y].oc + 1;
					}
					visited[n_x][n_y] = true;
					pq.push(dp[n_x][n_y]);
				}
			}
		}
		printf("#%d %d %d\n", t, dp[N - 1][N - 1].oc, dp[N - 1][N - 1].ec);
		getchar();
	}
}