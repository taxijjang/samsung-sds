#include <iostream>

using namespace std;

typedef struct Missile {
	int power = 20001;
	int count = 0;
}MISSILE;
int descending(const void* a, const void* b);
int compare(const void *a, const void *b);

int main() {
	int T;// �׽�Ʈ ���̽�

	int Test[50]; //���� �׽�Ʈ ���̽��� �ּҰ��� ������
	int N; //���ּ� ��
	int M;//�̻��� ��
	int B; //�� ��
	cin >> T;

	for (int i = 0; i < T; i++) {
		int mis_count = 0;// ���ּ��� ���� ���� �̻��� ���� ��
		int a1, a2; // ���� �̻����� ȭ���� ��
		int mis_sum; // ���� �̻����� ȭ���� ���� ��


		MISSILE mis[1000]; // �̻����� ȭ�°� ���� ����ü
		int mmis[200000]; // �̻����� ���� ���� �� �ִ� ȭ���� �� �迭
		fill_n(mmis, 200000, 40001);
		int total_sum = 0; //�̻����� �ּҰ��� ����
		cin >> N >> M >> B;

		//�̻����� ȭ�°� ���� �Է�
		for (int j = 0; j < M; j++) {
			cin >> mis[j].power >> mis[j].count;
		}

		//�Է¹��� �̻����� ����
		qsort(mis, 1000, sizeof(MISSILE), compare);

		//�̻����� ȭ���� ������ ������ �ΰ��� �̻����� �����Ͽ� �ּ�ȭ�Ͽ� ����ŭ ȭ�� ���
		for (int mis1 = 0; mis1 < M, mis[mis1].power <= B; mis1++) {
			//�̻����� ������ ������
			if (mis[mis1].count == 0)
				continue;

			//�̻����� ȭ���� ���� ������ 
			if (mis[mis1].power == B &&mis[mis1].count > 0) {
				mis[mis1].count--;
				mmis[mis_count++] = mis[mis1].power;
				break;

				//�̻����� ȭ���� ������ �۰� ������ 1�� �̻� ������
			}
			if (mis[mis1].count != 0) {
				mis_sum = 0;
				a1 = mis[mis1].power;
				mis[mis1].count--;
			}

			//�ι�° �̻���
			for (int mis2 = 0; mis2 < M, mis[mis2].power < B; mis2++) {
				//�̻��� ������ ������
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