#include <iostream>

using namespace std;

int main(void) {
	int T; // 테스트 케이스 수
	int T_OUT[50]; // 테스트 케이스의 출력값을 저장 할 배열
	int N; // 외계 우주선의 총 수
	int M; // 미사일 종류의 수
	int B; // 외계 우주선의 방어막 세기

	int missile[20001];
	int mis_p, mis_c; // 미사일의 파워, 갯수

	int mis_sum[20001];

	int break_cnt = 0;

	int mis_min_sum = 0;

	cin >> T;

	//테스트 케이스 수 만큼 반복
	for (int t = 0; t < T; t++) {
		fill_n(missile, 20001, 0);
		fill_n(mis_sum, 20001, 0);
		break_cnt = 0;
		mis_min_sum = 0;
		cin >> N >> M >> B;

		//미사일 화력과 갯수 입력
		for (int n = 1; n <= M; n++) {
			cin >> mis_p >> mis_c;
			missile[mis_p] = mis_c;
		}
		
		copy(missile + B, missile + 20000, mis_sum + B);

		if (B / 2 == 0) { //방어막 홀수 일때
			for (int b = 1; b <= B / 2; b++) {
				if (mis_sum[B] == N) {
					break;
				}
				if (missile[b] <= 0 || missile[B - b] <= 0) {
					continue;
				}
				if (missile[b] > 0 && missile[B - b] > 0)
				{
					mis_sum[B]++;
					missile[b]--; missile[B - b]--;
				}
				
			}
		}

		else { // 짝수 일때
			for (int b = 1; b <= B / 2; b++) {
				if (mis_sum[B] >= N) {
					break;
				}
				if (missile[b] <= 0 || missile[B - b] <= 0) {
					continue;
				}
				if (missile[b] > 0 && missile[B - b] > 0) {
					if (b != B - b) {
						mis_sum[B]++;
						missile[b]--; missile[B - b]--;
					}
					else {
						if (b == B / 2 && missile[b] >= 2) {
							mis_sum[B]++;
							missile[b] -= 2;
						}
					}
				}
				
			}
		}

		/*if (mis_sum[B] < N) {
			for (int b = 0; b < missile[B]; b++) {
				mis_sum[B]++;
				if (mis_sum[B] >= N) {
					break;
				}
			}
		}*/
		if (mis_sum[B] < N) {
			for (int b = 2; b <= B / 2; b++) {
				if (missile[b] <= 0) {
					continue;
				}
				for (int b2 = B - b +1; b2 < B; b2++) {
					if (missile[b2] <= 0) {
						continue;
					}

					mis_sum[missile[b] + missile[b2]]++;
					missile[b]--; missile[b2]--;
					if (mis_sum[B] >= N) {
						break;
					}
					if (mis_sum[B] >= N) {
						break;
					}
				}
			}

		}
		
		for (int b = B; b <= 20000; b++) {
			if (mis_sum[b] != 0) {
				for (int i = 1; i <= mis_sum[b]; i++) {
					break_cnt++;
					mis_min_sum += b;
					if (break_cnt >= N) {
						break;
					}
				}
			}
			if (break_cnt >= N) {
				break;
			}
		}

		if (break_cnt < N) {
			mis_min_sum = -1;
		}
		T_OUT[t] = mis_min_sum;


	}

	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " " << T_OUT[i] << endl;
	}

	return 0;
}
