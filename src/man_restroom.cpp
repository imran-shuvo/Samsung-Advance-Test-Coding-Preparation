/*

Men's restroom problem: It is a well-researched fact that men in a restroom generally prefer
 to maximize their distance from already occupied stalls, 
 by occupying the middle of the longest sequence of unoccupied places. For a detailed version, c
 heck the following link.
Link: https://stackoverflow.com/questions/32645046/urinal-algorithm-a-simple-optimization


*/


#include<iostream>
using namespace std;
int a[100],n;

int findMid(){

    int mid,prev_count=0,count=0,index,start,end;

    for(int i=0;i<n;i++){
        if(a[i]==1){
            if(count>prev_count)
            {
                prev_count=count;
                index = i;
                count=0;
            }
            else
                count=0;
        }
        else
            count++;
    }

    if(count>prev_count){
        index=n;
        prev_count=count;


    }
    mid = index+(index-prev_count);


    return mid/2;
}


int main(){
    int testcase,test;
    cin>>testcase;
    for(test=1;test<=testcase;test++){
        cin>>n;

        for(int i=0;i<n;i++){
            a[i]=0;
        }
        for(int i=0;i<n;i++){
            int indx = findMid();
            a[indx]=1;
            for(int j=0;j<n;j++){
                if(a[j]==1)
                    cout<<"x";
                else 
                    cout<<"-";
            }
            cout<<endl;
        }
    }
}