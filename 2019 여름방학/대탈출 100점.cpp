#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T; // �׽�Ʈ ���̽�
	vector<int> T_OUT;//�׽�Ʈ ���̽� ��� ���� ���� �� �迭
	int N; // �����Ʈ�� ����� ������ ��
	int M; // ������ �� �ִ� ������ ���� ��
	
	vector<int> window;// ������ Ÿ�� �ڵ����� ������ Ǯ�� ������
	int color;// ������ Ÿ�� ���� �Է�

	//N 1000 M 50
	//int car_color[50];

	int c;
	int pass_car;
	vector<int> pass;

	int judge;
	cin >> T;

	for (int t = 0; t < T; t++) {
		color = 0;
		pass_car = 0;
		judge = 1;
		cin >> N >> M;//������ ���� ������ �� �Է�

		for (int m = 0; m < M; m++) {
			cin >> c;
			if (c == 0) {
				continue;
			}
			for (int cc =0 ; cc < c; cc++) {
				window.push_back(m + 1);
			}
		}

		for (int n = 0; n < N; n++) {
			cin >> pass_car;
			pass.push_back(pass_car);
		}
		int window_size = window.size();
		int pass_size = pass.size();
		vector<int> temp;

		if (window_size == pass_size) {
			sort(pass.begin(), pass.end());
			if (window == pass) {
				T_OUT.push_back(1);
				judge = 0;
			}
		}
		else {
			for (int ww = 0; ww <= pass_size - window_size; ww++) {
				temp.assign(pass.begin() + ww, pass.begin() + ww + window_size);
				sort(temp.begin(), temp.end());
				if (window == temp) {
					T_OUT.push_back(ww + 1);
					judge = 0;
				}
			}
		}
		if (judge == 1) {
			T_OUT.push_back(0);
		}
		window.clear();
		pass.clear();
		temp.clear();
	}

	int T_OUT_SIZE = T_OUT.size();
	for (int t = 0; t < T_OUT_SIZE;t++) {
		cout << "#" << t + 1 << " " << T_OUT[t] << endl;
	}

	
}