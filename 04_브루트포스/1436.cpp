#include <iostream>
#include <string>
using namespace std;

// 해당 수(cur)가 종말의 수인지 여부 반환
bool isValid(int apocalypse) {
    while (apocalypse >= 666) {
        if (apocalypse % 1000 == 666) {
            return true;
        }
        apocalypse /= 10;
    }
    return false;
}

int findApocalypse (int n){
    int cnt = 0;
    int apocalypse = 666;    ///첫번째 종말의수인 666부터 시작
    
    while(true) {
        if(isValid(apocalypse)){
            cnt++;
        }
        
        if(cnt == n){
            return apocalypse;
        }
        
        apocalypse++;
    }
}

int main() {
    int n;

    cin >> n;
    
    cout << findApocalypse(n) << '\n';

    return 0;
}