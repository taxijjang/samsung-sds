#include <iostream>
#include <vector>

using namespace std;

typedef struct missile {
	int power;
	int cnt;
}MISSILE;

typedef struct com {
	int index1;
	int index2;
}MIS_COM;

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

vector<MIS_COM> comm[40001]; //�̻��� ����

int main(void) {
	int T; // �׽�Ʈ ���̽� ��
	int T_OUT[50];
	int N; // ���ּ� ��
	int M; // �̻��� ������ ��
	int B; // �� ����

	MISSILE m_input[1002]; //�̻����� �����͸� �Է¹��� ����ü �迭
						   //�̻����� �Ѱ��ε� ���� �νǼ� �ִ�
	int sum;
	int judge;
	int cnt;
	cin >> T;

	//���ּ� ��, �̻��� ������ ��, �� ���� �� �Է�
	for (int t = 0; t < T; t++) {
		sum = 0;
		cnt = 0;
		cin >> N >> M >> B;

		m_input[0].power = 0; m_input[0].cnt = 3333333;

		//�̻��� ������ �Է�
		for (int n = 1; n <= M; n++) {
			cin >> m_input[n].power >> m_input[n].cnt;
		}

		//������������ ����
		//qsort(m_input, 1001, sizeof(MISSILE), compare);

		//���͸� �ʱ�ȭ ������� ���� ���̽��� ���� �� ����
		for (int i = 0; i < 40001; i++) {
			vector<MIS_COM>().swap(comm[i]);
		}

		//���º��� ���� �̻��� 
		for (int i = 0; i <= M; i++) {
			for (int j = i; j <= M; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				if (m_input[i].power + m_input[j].power >= B) {
					comm[m_input[i].power + m_input[j].power].push_back({ i,j });
				}
			}
		}

		for (int i = B; i < 40001; i++) {
			int com_size = comm[i].size();
			if (com_size == 0)
				continue;
			for (int j = 0; j < com_size; j++) {
				int m_cnt = m_input[comm[i][j].index1].cnt < m_input[comm[i][j].index2].cnt ? m_input[comm[i][j].index1].cnt : m_input[comm[i][j].index2].cnt;
				if (comm[i][j].index1 == comm[i][j].index2) {
					m_cnt = m_cnt / 2;
				}
				
				m_cnt = m_cnt < N ? m_cnt : N;

				m_input[comm[i][j].index1].cnt -= m_cnt;
				m_input[comm[i][j].index2].cnt -= m_cnt;
				
				N = N - m_cnt;

				if (comm[i][j].index1 == comm[i][j].index2) {
					sum = sum + (m_input[comm[i][j].index1].power) * m_cnt;
				}
				else {
					sum = sum + (m_input[comm[i][j].index1].power + m_input[comm[i][j].index2].power) * m_cnt;
				}
				
				if (N <= 0) {
					i = 40000;
					break;
				}
			}
		}
		if (N > 0) {
			sum = -1;
		}
		
		T_OUT[t] = sum;
		

	}

	for (int t = 0; t < T; t++) {
		cout << "#" << t + 1 << " " << T_OUT[t] << endl;
	}

	return 0;
}
