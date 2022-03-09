//solved
/*You are given N unique numbers a1<a2<a3<...an.
Find out the count of all possible binary search trees
that can be constructed using these numbers.
For example with 3 elements 1,2,3, there are 5 possible BST
and for 1,2,3,4 there are 14 BST.*/

//www.youtube.com/watch?v=YDf982Lb84o



#include<iostream>
using namespace std;
int main(){

    int test,testcase,i,j,n;
    cin>>testcase;
    for(test=1;test<=testcase;test++){
        cin>>n;
        int a[n],T[n+1];
        for(i=0;i<n;i++){
            T[i]=0;
            cin>>a[i];
        }
        T[n]=0;
        T[0]=1;
        T[1]=1;
        for(i=2;i<=n;i++){
            for(j=0;j<i;j++)
            {
                T[i]+=(T[j]*T[i-j-1]);
            }
        }
        cout<<"test#"<<test<<" : "<<T[n]<<endl;


    }



}
/*
5
3
1 2  3
2
1 2
4
1 2 3 4
5
1 2 3 4 5
test#1 : 5
test#2 : 2
test#3 : 14
test#4 : 42

*/