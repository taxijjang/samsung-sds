#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int compare(const void *A, const void *B);


typedef struct Missile {
	int power = 20001;
	int count = 0;
}MISSILE;


int main(void) {

	int T; // 테스트 케이스
	int T_OUT[50];
	fill_n(T_OUT, 50, 0);
	int N; // 우주선의 총 수
	int M; // 미사일 종류의 수
	int B; // 우주선의 방어막 세기

	MISSILE mis1[1000];
	MISSILE mis2[1000];
	
	int m1, m2, m_s;
	int power, count;

	int mis_sum[40000];

	int judge;
	cin >> T;

	for (int t = 0; t < T; t++) {
		m1 = 0; m2 = 0; m_s = 0;
	
		fill_n(mis_sum, 40000, 40001);
		
		judge = 1;

		cin >> N >> M >> B;

		for (int m = 0; m < M; m++) {
			cin >> power >> count;
			if (power < B) {
				mis1[m1].power = power;
				mis1[m1++].count = count;
			}
			else {
				mis2[m2].power = power;
				mis2[m2++].count = count;
			}
		}

		qsort(mis1, 1000, sizeof(MISSILE), compare);
		qsort(mis2, 1000, sizeof(MISSILE), compare);

		for (int k = 0; k < m1; k++) {
			for (int i = 0; i < mis1[k].count; i++ ) {
				mis1[k].count--;
				judge = 1;
 				for (int j = 0; j < m1 ; j++) {

					if (mis1[k].power + mis1[j].power >= B && mis1[j].count > 0) {
						mis_sum[m_s++] = mis1[k].power + mis1[j].power;
						mis1[j].count--;
						judge = 1;
						continue;
					}
					judge = 0;
					
				}
				if (judge == 0) {
					mis1[k].count++;
				}
			}
		}

		if (m2 != 0) {
			for (int i = 0; i < m2; i++) {
				for (int j = 0; j < mis2[i].count; j++) {
					mis_sum[m_s++] = mis2[i].power;
				}
			}
		}

		qsort(mis_sum, 40000, sizeof(int), compare);

		if (m_s >= N) {
			for (int i = 0; i < N; i++) {
				T_OUT[t] += mis_sum[i];
			}
		}
		else {
			T_OUT[t] = -1;
		}
	}
	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " " << T_OUT[i] << endl;
	}
}

int compare(const void *A, const void *B) {
	const MISSILE *m, *n;
	m = (const MISSILE *)A;
	n = (const MISSILE *)B;
	if (m->power < n->power) {
		return -1;
	}
	else if (m->power == n->power) {
		return 0;
	}
	else {
		return 1;
	}
}