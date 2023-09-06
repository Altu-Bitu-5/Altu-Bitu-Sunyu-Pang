#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()  {
    while(true){
        string sentence;
        stack<char> s;  //문자열의 문자를 담을 스택 s 선언
        bool flag = 0;  //문자열의 균형 여부, 0이면 균형/1이면 불균형
        
        getline(cin, sentence);
        
        if(sentence == "."){
            break;
        }
        
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == '(' || sentence[i] == '['){
                s.push(sentence[i]);
            }      
            else if(sentence[i] == ')') {
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }
                else {
                    flag = 1;
                    break;
                }
            }
            else if (sentence[i] == ']') {
                if(!s.empty() && s.top() == '['){
                    s.pop();
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }
        
        
        if(flag == 0 && s.empty()){
            cout << "yes" << '\n';
        } 
        else {
             cout << "no" << '\n';
        }
           
    }
}