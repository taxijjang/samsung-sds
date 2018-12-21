#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int T; // �׽�Ʈ ���̽�
	int t; // �׽�Ʈ ���̽��� ���� ����
	char N[1000]; //�Է¹��� ī���� �迭
	string word[50];
	int card_count; //ī���� ����
	deque<char> word_dq; //������� �ܾ�

	cin >> T;

	for (t = 0; t < T; t++) {

		word_dq.clear();
		cin >> card_count;

		for (int i = 0; i < card_count; i++) {
			cin >> N[i];
		}

		for (int i = 0; i < card_count; i++) {
			if (i == 0) {
				word_dq.push_front(N[i]);
				continue;
			}
			if (word_dq.front() <= N[i]) {
				word_dq.push_front(N[i]);
			}
			else {
				word_dq.push_back(N[i]);
			}
		}
		deque<char>::iterator iter;
		for (iter = word_dq.begin(); iter != word_dq.end(); iter++) {
			word[t].push_back(*iter);
		}
	}
	
	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " " << word[i] << endl;
	}
	return 0;
}