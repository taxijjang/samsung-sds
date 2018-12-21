#include <iostream>

using namespace std;

int descending(const void* v1, const void* v2);

int main(void) {
	int T; // 테스트 케이스
	int T_OUT[50];
	fill_n(T_OUT, 50, 0);
	int N; // 톨게이트를 통과한 차량의 수
	int M; // 존재할 수 있는 차량의 색상 수
	int car_N[1000]; // 톨게이트를 통과하는 차량의 색상 순서
	int car_color[50]; // 차량의 존재하는 색상을 카운트

	int window[50];
	int window_cnt;

	int car_win[50];

	string WINDOW, CAR_WIN;
	int location;
	int judge;
	cin >> T;

	for (int t = 0; t < T; t++) {
		judge = 0;
		window_cnt = 0;
		location = 0;
		fill_n(window, 50, 51);
		fill_n(car_win, 50, 51);
		cin >> N >> M; //차량의 수와 색상의 수 입력

		for (int m = 0; m < M; m++) {
			cin >> car_color[m]; // 차량의 존재하는 색상 입력			
		}

		for (int w = 0; w < M; w++) {
			for (int z = 0; z < car_color[w]; z++) {
				window[window_cnt++] = w + 1;
			}
			
		}
		
		for (int n = 0; n < N; n++) {
			cin >> car_N[n]; // 톨게이트를 통과한 차량의 순서
		}

		if (N == window_cnt) {
			for (int car_w = 0; car_w <= N - window_cnt, M<=N; car_w++) {
				judge = 0;
				for (int i = 0; i < window_cnt; i++) {
					car_win[i] = car_N[car_w + i];
				}
				qsort(car_win, 50, sizeof(car_win[0]), descending);

				for (int j = 0; j < window_cnt; j++) {
					if (car_win[j] == window[j]) {
						judge++;
					}
					if (judge == window_cnt) {
						T_OUT[t] = car_w + 1;
					}
				}
			}
		}
		else {
			for (int car_w = 0; car_w < N - window_cnt, M <= N; car_w++) {
				judge = 0;
				for (int i = 0; i < window_cnt; i++) {
					car_win[i] = car_N[car_w + i];
				}
				qsort(car_win, 50, sizeof(car_win[0]), descending);

				for (int j = 0; j < window_cnt; j++) {
					if (car_win[j] == window[j]) {
						judge++;
					}
					if (judge == window_cnt) {
						T_OUT[t] = car_w + 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " " << T_OUT[i] << endl;
	}
	return 0;
}

int descending(const void* v1, const void* v2) {
	return(*(int*)v1 - *(int*)v2);
}