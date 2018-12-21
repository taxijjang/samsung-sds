#include <iostream>
#include <algorithm>
#include <cstdio>
#define INF 1000000

using namespace std;


int main(void) {
	int T; // 테스트 케이스 수
	int T_OUT[30]; // 테스트 케이스의 출력 값을 저장
	fill_n(T_OUT, 30, 0);
	int N; // 마을 수 1<= N <= 1000
	int M; // 두 마을을 연결하는 도로의 수 1< =M <= 3000
	int K; // 배달을 해야 하는 마을의 수 1<= K <= 10
	int S; // 배달을 하는 위치의 마을 번호

	int landscape[1000]; // 배달을 가야하는 마을
	int vil[100][100]; // 마을을 2차원 좌표로 도식

	int v1, v2;
	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N >> M >> K >> S;

		for (int i = 0; i < K; i++) {
			cin >> landscape[i];
		}

		//입력 받은 마을 만큼 마을 좌표 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				vil[i][j] = (i == j) ? 0 : INF;
			}
		}

		//마을간의 연결을 입력 받음
		for (int i = 0; i < M; i++) {
			cin >> v1 >> v2;
			vil[v1-1][v2-1] = 1;
			vil[v2-1][v1-1] = 1;
		}

		//플로이드 알고리즘 적용
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (vil[i][j] > vil[i][k] + vil[k][j]) {
						vil[i][j] = vil[i][k] + vil[k][j];
					}
				}
			}
		}


		for (int i = 0; i < K+1; i++) {
			if (i == 0) {
				T_OUT[t] += vil[S - 1][landscape[i] - 1];
			}
			else if (i == K) {
				T_OUT[t] += vil[landscape[i - 1] - 1][S - 1];
			}
			else {
				T_OUT[t] += vil[landscape[i - 1] - 1][landscape[i] - 1];
			}
			
		}
	}

	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " " << T_OUT[i] << endl;

	}
	return 0;
}