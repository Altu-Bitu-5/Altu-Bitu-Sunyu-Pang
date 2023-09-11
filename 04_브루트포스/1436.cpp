#include <iostream>
#include <string>
using namespace std;

string findApocalypse (int n){
    int cnt = 0;
    string apocalypse;
    
    int i = 666;    ///첫번째 종말의수인 666부터 시작
    
    while(true) {
        apocalypse = to_string(i);
        
        if(apocalypse.find("666") != -1){
            cnt++;
        }
        
        if(cnt == n){
            return apocalypse;
        }
        
        i++;
    }
}

int main() {
    int n;

    cin >> n;
    
    cout << findApocalypse(n) << '\n';

    return 0;
}