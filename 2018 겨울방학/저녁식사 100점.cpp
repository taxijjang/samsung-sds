#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

#define MAX 200000

using namespace std;

typedef long long ll;

struct POINT {
	int x, y;
	int num;
	POINT(int x1 = 0, int y1 = 0, int num = 0) : x(x1), y(y1), num(num) {}
};

bool comp(const POINT &A, const POINT &B) {
	if (A.y != B.y)
		return A.y < B.y;

	return A.x < B.x;
}

bool comp2(const POINT A, const POINT B) {
	return A.x < B.x;
}

ll ccw(const POINT &A, const POINT &B, const POINT &C) {
	return 1LL * -1 * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

POINT p[MAX];

int main() {
	int T; // 테스트 케이스 수
	vector <vector <int>> T_OUT;
	vector<int> a;
	int N; //점의 갯수
	int cnt = 0;
	vector <POINT> filter_p;
	stack<int> s;
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			p[i] = POINT(x, y, i + 1);
		}

		// y좌표, x좌표가 작은 순으로 정렬
		sort(p, p + N, comp);

		POINT temp = p[cnt];
		filter_p.push_back(p[cnt]);

		for (int i = 0; i < N; i++) {
			if (temp.x > p[i].x) {
				temp = p[i];
				filter_p.push_back(p[i]);
			}
		}

		int filter_p_size = filter_p.size();

		vector<POINT>::reverse_iterator iter(filter_p.end());

		//T_OUT[t].resize(filter_p_size);
		for (; iter != filter_p.rend(); ++iter) {
			a.push_back(iter->num);
		}
		T_OUT.push_back(a);

		a.clear();
		filter_p.clear();
	}

	for (int t = 0; t < T; t++) {
		int t_out_size = T_OUT[t].size();
		cout << "#" << t + 1 << " ";
		for (int i = 0; i < t_out_size; i++) {
			cout << T_OUT[t][i] << " ";
		}
		cout << endl;
	}

	return 0;
}