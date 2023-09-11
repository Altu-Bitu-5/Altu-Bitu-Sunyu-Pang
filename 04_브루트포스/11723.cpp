#include <iostream>
#include <string>
using namespace std;

int addX (int s, int x) {
    s |= (1<<x);
    return s;
}

int removeX (int s, int x) {
    s &= ~(1<<x);
    return s;
}

bool xExists (int s, int x) {
    //AND 연산을 해서 s에 x가 있으면 1(true), 없으면 0(false)이 나옴
    return (s & (1<<x));
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int m, x;
    int s = 0;
    string op;

    cin >> m;
    
    for(int i=0; i<m; i++){
        cin >> op;
        
        if(op == "add"){
            cin >> x;
            s = addX(s,x);
        } else if (op == "remove"){
            cin >> x;
            s = removeX(s,x);
        } else if (op == "check") {
            cin >> x;
            
            if (xExists(s,x)){    
                cout << 1 <<'\n';
            } else {
                cout << 0 <<'\n';
            }
        } else if (op == "toggle") {
            cin >> x;
            
            if (xExists(s,x)){
                s = removeX(s,x);
            } else {
                s = addX(s,x);
            }
        } else if (op == "all") {
            s = (1<<21) - 1;    //(111...111)2 = (1000...000)2 - 1 = 2^21 -1
        } else if (op == "empty") {
            s = 0;
        }
    }

    return 0;
}