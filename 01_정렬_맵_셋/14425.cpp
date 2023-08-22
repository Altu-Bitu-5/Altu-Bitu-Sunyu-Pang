#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N, M;
    string str;
    map <string, bool> S;
    int check;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> str;
        S[str] = true;
    }

    for(int i=0; i<M; i++){
        cin >> str;
        if(S[str] == true)
            check++;
    }

    cout << check;

    return 0;
}