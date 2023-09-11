#include <iostream>
#include <cmath>
#include <vector>

const int MAX = 1000000; //n의 최대 범위
using namespace std;

void isPrime(int n, vector<bool> &is_prime) {
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=sqrt(n); i++) {
        if(is_prime[i]) {
            for(int j = i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n;
    vector<bool> is_prime(MAX+1, true);
    bool flag = false;
    
    isPrime(MAX, is_prime); //n의 범위를 알고 있으므로 while문 안에서 돌릴 필요없음
    
    while(cin >> n){
        if(n == 0){
            break;
        }
        
        for(int i = n-1; i>=3; i-=2){
            if(!is_prime[i]){
                continue;
            }
            
            if(is_prime[n-i]){
                flag = true;
                cout << n << " = " << n-i << " + " << i << "\n";
                break;
            }
        }
        
        if(!flag){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    
    return 0;
}