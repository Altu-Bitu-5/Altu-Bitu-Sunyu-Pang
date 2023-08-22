#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cmp(string a, string b) {
	int a_len = a.length();
	int b_len = b.length();
	int a_sum = 0;
	int b_sum = 0;

	// 1. 길이가 다르면, 짧은 것 먼저
	if (a_len != b_len) {
		return a_len < b_len;
	}

	// 2. 길이가 같다면, 모든 자리수의 합 비교해서 작은 합을 가지는 것이 먼저 (숫자인 것만 더하기)
	for (int i = 0; i < a_len; i++) {
		if (isdigit(a[i])) {
			a_sum += ((a[i]) - '0');
		}

		if (isdigit(b[i])) {
			b_sum += ((b[i]) - '0');
		}
	}

	if (a_sum != b_sum) {
		return a_sum < b_sum;
	}

    // 3. 사전순 비교 (숫자가 알파벳보다 사전순으로 작다.)
	return a < b;

}

int main() {
	int N;
	string serial[50];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}

	sort(serial, serial + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << serial[i] << '\n';
	}
	
	return 0;
}