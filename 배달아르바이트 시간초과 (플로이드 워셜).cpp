#include <iostream>
#include <algorithm>
#include <cstdio>
#define INF 1000000

using namespace std;


int main(void) {
	int T; // �׽�Ʈ ���̽� ��
	int T_OUT[30]; // �׽�Ʈ ���̽��� ��� ���� ����
	fill_n(T_OUT, 30, 0);
	int N; // ���� �� 1<= N <= 1000
	int M; // �� ������ �����ϴ� ������ �� 1< =M <= 3000
	int K; // ����� �ؾ� �ϴ� ������ �� 1<= K <= 10
	int S; // ����� �ϴ� ��ġ�� ���� ��ȣ

	int landscape[1000]; // ����� �����ϴ� ����
	int vil[100][100]; // ������ 2���� ��ǥ�� ����

	int v1, v2;
	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N >> M >> K >> S;

		for (int i = 0; i < K; i++) {
			cin >> landscape[i];
		}

		//�Է� ���� ���� ��ŭ ���� ��ǥ �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				vil[i][j] = (i == j) ? 0 : INF;
			}
		}

		//�������� ������ �Է� ����
		for (int i = 0; i < M; i++) {
			cin >> v1 >> v2;
			vil[v1-1][v2-1] = 1;
			vil[v2-1][v1-1] = 1;
		}

		//�÷��̵� �˰��� ����
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