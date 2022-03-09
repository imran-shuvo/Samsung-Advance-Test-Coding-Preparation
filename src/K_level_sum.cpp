#include<iostream>
using namespace std;
int main(){

    int testcase,test;
    cin>>testcase;
    for(test=1;test<=testcase;test++){
        int k;
        cin>>k;
        string str;
        cin>>str;
        int level=-1,sum=0;


        for(int i=0;i<str.length();i++){
            if(str[i]=='(')
                level++;
            else if(str[i]==')')
                level--;
            else{

                if(level==k){
                    if(str[i]=='-'){
                        int x = str[i+1]-'0';
                        sum+=(-x);
                    }
                    else
                        sum+=(str[i]-'0');
                }
            }

        }

        cout<<"test#"<<test<<" "<<sum<<endl;


    }
}
/*
5
3 
(0(5(6()())(-4()(9()())))(7(1()())(3()())))
test#1 9
2
(0(5(6()())(4()(9()())))(7(1()())(3()())))
test#2 14
3
(8(3(2()())(6(5()())()))(5(10()())(7(13()())())))
test#3 9 
*/