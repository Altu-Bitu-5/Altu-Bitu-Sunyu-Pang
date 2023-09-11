#include <iostream>

using namespace std;

int getGcd(int a, int b)  {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int numerator_a, denominator_a, numerator_b, denominator_b;
    cin >> numerator_a >> denominator_a >> numerator_b >> denominator_b;
    
    int numerator_sum = numerator_a * denominator_b + numerator_b * denominator_a;
    int denominator_sum = denominator_a * denominator_b;
    
    int gcd = getGcd(numerator_sum, denominator_sum);
    
    //출력
    cout << numerator_sum/gcd << ' ' << denominator_sum/gcd;
    
    return 0;
}