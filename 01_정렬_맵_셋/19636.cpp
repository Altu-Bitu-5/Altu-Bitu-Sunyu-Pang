#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int W0, B0, T;
    cin >> W0 >> B0 >> T;

    int D, I, A;
    cin >> D >> I >> A;

    //체중 W += 일일 에너지 섭취량 I − 일일 에너지 소비량
    //일일 에너지 소비량 = 일일 기초 대사량 +  일일 활동 대사량 A
    //if (abs(일일 에너지 섭취량 − 일일 에너지 소비량) > T ) 일일 기초대사량 += floor((일일 에너지 섭취량 I − 일일 에너지 소비량) / 2 )
    //if(W <= 0 || 일일 기초대사량 <= 0) 데시 사망

    //1. 일일 기초대사량 변화 x
    int W1 = W0;

    for(int i = 0; i < D; i++){
        W1 += I - (B0 + A);
    }
    
    if (W1 <= 0)
        cout << "Danger Diet" << "/n";
    else
        cout << W1 << " " << B0 << "\n";

    //2. 일일 기초대사량 변화 o
    int W2 = W0;
    int B2 = B0;   //변화하는 일일 기초대사량

    for(int i = 0; i < D; i++){
         W2 += I - (B2 + A);

        //기초대사량 변화
        if(abs(I - (B2 + A)) > T)
            B2 += floor((I-(B2+A))/2.0);    //나눗셈 연산자는 피연산자의 데이터형을 따라감
    }

    if(W2 <= 0 || B2 <= 0)
        cout << "Danger Diet" << "\n";
    else {
        cout << W2 << " " << B2 << " ";
        if(B0 - B2 > 0) // 요요 발생은 B0 - (B2 + A0)가 양수일 때, 다이어트 전에는 A0 = 0
            cout << "YOYO";
        else   
            cout << "NO";
    }

    return 0;
}