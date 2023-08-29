#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string bigNumAdd(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string result;
	int carry = 0;
	int size = max(a.size(), b.size());

	for (int i = 0; i < size; i++) {
		int digitA = (i < a.size()) ? a[i] - '0' : 0;   //자릿수 안 맞으면 0으로 채우기
		int digitB = (i < b.size()) ? b[i] - '0' : 0;

		int digitSum = digitA + digitB + carry;

		carry = digitSum / 10;  //올림으로 십의 자리만 남기기

		result.push_back(digitSum % 10 + '0');
	}

	if (carry){
        result.push_back(carry % 10 + '0'); //올림이 있으면 맨 뒤에 더하기
    }

	reverse(result.begin(), result.end());  //결과값 뒤집어주기

	return result;
}

int main() {
    string a, b;

    cin >> a >> b;

    cout << bigNumAdd(a,b);

    return 0;
}