#include<iostream>
#include<vector>
using namespace std;
const int ALPHABET = 26;	//알파벳 개수

int main() {
    int n, k;
	cin >> n >> k;
	
	vector<char> wheel(n, '?'); //바퀴 '?'로 초기화
	vector<bool> is_duplicate(ALPHABET, false);	//알파벳 중복 검사

	int arrow = 0;  //화살표, 현재 가리키고 있는 배열의 index
	
	for (int i = 0; i < k; i++) {
		int cnt;
		char c;
		cin >> cnt >> c;
		
		arrow = (arrow + cnt) % n;   //cnt만큼 arrow를 반시계방향 이동, 반시계방향을 양수로 설정, 바퀴의 크기를 넘지 않도록 함
		
		if(wheel [arrow] == c) {
			continue;
		}

		//돌렸을 때 나온 문자와 배열에 저장되어 있는 문자가 다르거나 중복된 알파벳이라면 바퀴 존재 x
		if (wheel[arrow] != '?' || is_duplicate[c - 'A']){
		    cout << '!';
			return 0; 
		}

		wheel[arrow] = c;
		is_duplicate[c - 'A'] = true;
	}
	
	//출력, 마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로
	for (int i = arrow + n; i > arrow; i--) {
	    cout << wheel[i % n];
	}
	
	return 0;
}