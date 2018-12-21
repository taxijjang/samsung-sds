#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int T; // 테스트 케이스
	int t; // 테스트 케이스를 따라갈 변수
	char N[1000]; //입력받을 카드의 배열
	string word[50];
	int card_count; //카드의 갯수
	deque<char> word_dq; //만들어질 단어

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