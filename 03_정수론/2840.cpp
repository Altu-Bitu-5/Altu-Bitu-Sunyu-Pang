#include<iostream>
#include<vector>

using namespace std;

bool checkDuplicate (int n, vector<char> wheel) {
    for (int i = 0; i < n; i++) {
	    if(wheel[i] == '?'){    //'?'는 예외
	        continue;
	    }
	    
	    for (int j = i + 1; j < n; j++) {
	        if(wheel[i] == wheel[j]) {  
	            cout << '!';
	            return true;
	        }
	    }
	}

    return false;
}

int main() {
    int n, k;
	cin >> n >> k;
	
	vector<char> wheel(n, '?'); //바퀴 '?'로 초기화

	int arrow = 0;  //화살표, 현재 가리키고 있는 배열의 index
	
	for (int i = 0; i < k; i++) {
		int cnt;
		char c;
		cin >> cnt >> c;
		
		arrow += cnt;   //cnt만큼 arrow를 반시계방향 이동, 반시계방향을 양수로 설정
		arrow %= n;   //바퀴의 크기를 넘지 않도록 함
		
		if (wheel[arrow] == '?'){
		    wheel[arrow] = c;
		} else if(wheel[arrow] != c){   //돌렸을 때 나온 문자와 배열에 저장되어 있는 문자가 다르다면 바퀴 존재 x
		    cout << '!';
			return 0; 
		}
	}
	
	//같은 글자는 두 번 이상 등장 X
	if(checkDuplicate(n, wheel)){
        return 0;
    }
	
	//출력, 마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로
	for (int i = 0; i < n; i++) {
	    cout << wheel[arrow];
	    arrow--;    //시계방향으로 출력하므로 --
	    if (arrow < 0){
	        arrow += n;
	    }
	}
	
	return 0;
}