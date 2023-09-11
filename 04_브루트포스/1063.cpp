#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> op = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
vector <int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
vector <int> dy = {0, 0, -1, 1, 1, 1, -1, -1};
pair<int, int> king, stone;

pair<int, int> convertToCor (string str) {
    pair<int, int> p;
    p.first = str[0] - 'A' + 1;
    p.second = str[1] - '1' + 1;
    return p;
}

bool inRange(int x, int y) {
    if(x>0 && y>0 && x<=8 && y<=8){
        return true;
    } else {
        return false;
    }
}

void move(string direction) {
    int index = find(op.begin(), op.end(), direction) - op.begin();
    
    //킹을 옮겼을 때 범위 안에 없다면 종료
    if(!inRange(king.first+dx[index], king.second+dy[index])) {
        return;
    }
    
    //킹을 옮겼을 때 킹과 돌의 위치가 같다면 돌의 위치 이동
    if(king.first+dx[index] == stone.first && king.second+dy[index] == stone.second) {
        //돌을 옮겼을 때 범위 안에 없다면 종료
        if(!inRange(stone.first+dx[index], stone.second+dy[index])) {
            return;
        } else {
            king.first += dx[index];
            king.second += dy[index];
            stone.first += dx[index];
            stone.second += dy[index];
        }
    } else {
        king.first += dx[index];
        king.second += dy[index];
    }
}

int main() {
    string k, s;
    int n;
    
    cin >> k >> s >> n;
    
    //숫자 좌표로 변환
    king = convertToCor(k);
    stone = convertToCor(s);
    
    for(int i=0; i<n; i++) {
        string direction;
        cin >> direction;
        move(direction);
    }
    
    cout << (char)(king.first +'A'- 1) << king.second << '\n';    //x좌표는 다시 문자로 바꿔서 출력
    cout << (char)(stone.first +'A'- 1) << stone.second << '\n';
    
    return 0;
}