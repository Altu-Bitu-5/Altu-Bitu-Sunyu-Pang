#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int ALPHABET = 26;

vector<int> countAlphabet(string s){
    vector<int> alphabet(ALPHABET, 0);     //26개의 알파벳 등장횟수

    //기준 문자열의 알파벳 등장횟수 카운트
    for(int i=0; i<s.length(); i++){
        alphabet[s[i] - 'A']++;
    }
    return alphabet;
}

int countComposition(int count, vector<int> &standard_alphabet, vector<int> &compare_alphabet, vector<int> &difference){
    for(int i=0; i<ALPHABET; i++){
        if(standard_alphabet[i] != compare_alphabet[i]){
            difference.push_back(standard_alphabet[i] - compare_alphabet[i]);
        }
    }

    //두 단어가 같은 구성을 갖는 경우
    if(difference.empty()){ 
        count++;
    }
    //한 문자를 더하거나 빼서 같은 구성을 갖는 경우
    else if (difference.size() == 1 && abs(difference.front()) == 1) {    
        count++;
    }
    //하나의 문자를 다른 문자로 바꾸어 나머지 한 단어와 같은 구성을 갖게 되는 경우 
    else if (difference.size() == 2 && (abs(difference.front()) == 1 || abs(difference.back()) == 1) && difference.front()+ difference.back() == 0) { 
        count++;
    }

    return count;
}

int main() {
    int count = 0;

    int n;
    cin >> n;

    string standard;
    cin >> standard;

    vector<int> standard_alphabet = countAlphabet(standard);   

    for(int i=1; i<n; i++){
        string compare;
        cin >> compare;

        vector<int> compare_alphabet = countAlphabet(compare);
        vector<int> difference; //문자 등장횟수의 차 저장

        count = countComposition(count, standard_alphabet, compare_alphabet, difference);
    }

    cout << count << '\n';

    return 0;
}