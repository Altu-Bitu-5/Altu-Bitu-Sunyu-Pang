#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K;
    queue<int> q;
    
    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    
    cout << "<";

    while(!q.empty()){
        //K번째 원소가 제일 앞에 오도록
        for(int i=1; i<K; i++){
            q.push(q.front());  //K번째 앞에 있는 원소들은 뒤에 삽입
            q.pop();    //뒤에 삽입한 원소들은 삭제
        }

        cout << q.front();  //K번째 원소 출력

        if(q.size() == 1){
            cout << ">";    //마지막 원소 출력일 경우, 괄호 닫아주기
        } else {
            cout << ", ";
        }

        q.pop();
    }

    return 0;
}