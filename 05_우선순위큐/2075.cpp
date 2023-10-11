#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    priority_queue <int, vector<int>, greater<int>> pq; //greater는 Min heap, 내림차순 정렬

    int n, temp;
    cin >> n;

    for(int i=0; i<n*n; i++){
        cin >> temp;
        pq.push(temp);
            
        //n번째 큰 수를 출력해야 하기 때문에 전체 자료를 저장할 필요 없음
        if(pq.size() > n){
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}