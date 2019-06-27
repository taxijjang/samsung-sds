#include <iostream>

using namespace std;

typedef struct Missile {
	int power = 20001;
	int count = 0;
}MISSILE;
int descending(const void* a, const void* b);
int compare(const void *a, const void *b);

int main() {
	int T;// 테스트 케이스

	int Test[50]; //각각 테스트 케이스의 최소값을 저장함
	int N; //우주선 수
	int M;//미사일 수
	int B; //방어막 값
	cin >> T;

	for (int i = 0; i < T; i++) {
		int mis_count = 0;// 우주선의 방어막을 깨는 미사일 합의 수
		int a1, a2; // 각각 미사일의 화력의 값
		int mis_sum; // 각각 미사일의 화력을 더한 값


		MISSILE mis[1000]; // 미사일의 화력과 갯수 구조체
		int mmis[200000]; // 미사일이 방어막을 뚫을 수 있는 화력의 값 배열
		fill_n(mmis, 200000, 40001);
		int total_sum = 0; //미사일의 최소값을 구함
		cin >> N >> M >> B;

		//미사일의 화력과 갯수 입력
		for (int j = 0; j < M; j++) {
			cin >> mis[j].power >> mis[j].count;
		}

		//입력받은 미사일을 정렬
		qsort(mis, 1000, sizeof(MISSILE), compare);

		//미사일의 화력이 방어막보다 작을때 두개의 미사일을 조합하여 최소화하여 방어막만큼 화력 사용
		for (int mis1 = 0; mis1 < M, mis[mis1].power <= B; mis1++) {
			//미사일의 갯수가 없을때
			if (mis[mis1].count == 0)
				continue;

			//미사일의 화력이 방어막과 같을때 
			if (mis[mis1].power == B &&mis[mis1].count > 0) {
				mis[mis1].count--;
				mmis[mis_count++] = mis[mis1].power;
				break;

				//미사일의 화력이 방어막보다 작고 갯수가 1개 이상 있을때
			}
			if (mis[mis1].count != 0) {
				mis_sum = 0;
				a1 = mis[mis1].power;
				mis[mis1].count--;
			}

			//두번째 미사일
			for (int mis2 = 0; mis2 < M, mis[mis2].power < B; mis2++) {
				//미사일 갯수가 없을때
				if (mis[mis2].count == 0)
					continue;


				if (mis[mis2].count != 0) {
					a2 = mis[mis2].power;
				}
				mis_sum = a1 + a2;
				if (mis_sum == B) {
					mmis[mis_count++] = mis_sum;
					mis[mis2].count--;
					break;
				}
				if (mis_count == N)
					break;
			}
			if (mis_sum == B) {
				mmis[mis_count++] = mis_sum;
				if (i == B) {
					break;
				}
			}
			else {
				mis[mis1].count++;
			}
			if (mis_count == N)
				break;

		}

		for (int mis1 = 0; mis1 < M, mis[mis1].power < B; mis1++) {
			a1 = 0;
			if (mis[mis1].count == 0)
				continue;
			if (mis[mis1].count != 0) {
				mis_sum = 0;
				a1 = mis[mis1].power;
				mis[mis1].count--;
			}

			for (int mis2 = 0; mis2 < M, mis[mis2].power < B; mis2++) {
				a2 = 0;
				if (mis[mis2].count == 0)
					continue;
				if (mis[mis2].count != 0) {
					a2 = mis[mis2].power;
				}
				mis_sum = a1 + a2;
				if (mis_sum >= B) {
					mmis[mis_count] = mis_sum;
					mis[mis2].count--;
					break;
				}
				if (mis_count == N)
					break;
			}
			if (mis_sum > B) {
				mmis[mis_count++] = mis_sum;
				if (i == B) {
					break;
				}
			}
			else {
				mis[mis1].count++;
			}
			if (mis_count == N)
				break;
		}

		if (mis_count < N) {
			for (int mis3 = 0; mis3 < M; mis3++) {
				if (mis[mis3].power >= B) {
					if (mis[mis3].count > 0) {
						for (int i = 0; i <= mis[mis3].count; i++) {
							mmis[mis_count++] = mis[mis3].power;
							mis[mis3].count--;
							if (mis_count == N)
								break;
						}
					}
				}
				if (mis_count == N)
					break;
			}
		}

		if (mis_count < N) {
			total_sum = -1;
		}

		else if (mis_count >= N) {
			qsort(mmis, 200000, sizeof(mmis[0]), descending);
			for (int i = 0; i < mis_count; i++) {
				total_sum += mmis[i];
			}
		}

		Test[i] = total_sum;
	}
	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " " << Test[i] << endl;
	}
	return 0;
}
int descending(const void* v1, const void* v2) {
	return(*(int*)v1 - *(int*)v2);
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