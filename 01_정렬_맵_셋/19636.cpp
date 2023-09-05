#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w_0, b_0, t;
    cin >> w_0 >> b_0 >> t;

    int d, i, a;
    cin >> d >> i >> a;

    //체중 W += 일일 에너지 섭취량 i − 일일 에너지 소비량
    //일일 에너지 소비량 = 일일 기초 대사량 +  일일 활동 대사량 a
    //if (abs(일일 에너지 섭취량 − 일일 에너지 소비량) > t ) 일일 기초대사량 += floor((일일 에너지 섭취량 i − 일일 에너지 소비량) / 2 )
    //if(W <= 0 || 일일 기초대사량 <= 0) 데시 사망

    //1. 일일 기초대사량 변화 x
    int w_1 = w_0;

    for(int j = 0; j < d; j++){
        w_1 += i - (b_0 + a);
    }
    
    if (w_1 <= 0){
        cout << "Danger Diet" << "\n";
    } else {
        cout << w_1 << " " << b_0 << "\n";
    }

    //2. 일일 기초대사량 변화 o
    int w_2 = w_0;
    int b_2 = b_0;   //변화하는 일일 기초대사량

    for(int j = 0; j < d; j++){
         w_2 += i - (b_2 + a);

        //기초대사량 변화
        if(abs(i - (b_2 + a)) > t)
            b_2 += floor((i-(b_2+a))/2.0);    //나눗셈 연산자는 피연산자의 데이터형을 따라감
    }

    if(w_2 <= 0 || b_2 <= 0) {
        cout << "Danger Diet" << "\n";
    } else {
        cout << w_2 << " " << b_2 << " ";
        
        if(b_0 - b_2 > 0) { // 요요 발생은 b_0 - (b_2 + A0)가 양수일 때, 다이어트 전에는 A0 = 0
            cout << "YOYO";
        } else {
            cout << "NO";
        } 
    }

    return 0;
}