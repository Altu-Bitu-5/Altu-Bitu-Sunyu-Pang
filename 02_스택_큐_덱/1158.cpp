#include <iostream>
#include <queue>

using namespace std;

void pushNum (int n, queue<int> &q) {
    for(int i=1; i<=n; i++){
        q.push(i);
    }
}

void printJosephusP (int k, queue<int> q) {
    cout << "<";

    while(!q.empty()){
        //K번째 원소가 제일 앞에 오도록
        for(int i=1; i<k; i++){
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
}

int main(){
    int n, k;
    queue<int> q;
    
    cin >> n >> k;
    
    pushNum(n, q);
    
    //출력
    printJosephusP(k, q);

    return 0;
}