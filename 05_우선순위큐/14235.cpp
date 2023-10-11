#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    priority_queue <int, vector<int>> gift;

    int n, a, value;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;
        
        if(a == 0) {
            if(gift.empty()) {
                cout << -1 << '\n';
                continue;
            }
            
            cout << gift.top() << '\n';
            gift.pop();
            continue;
        }

        for(int i=0; i<a; i++){
            cin >> value;
            gift.push(value);
        }
    }

    return 0;
}