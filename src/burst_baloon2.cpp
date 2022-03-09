/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/
#include<iostream>
using namespace std;
int main(){

    int N;
    cin>>N;
    int a[N+2],dp[N+4][N+4];
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    a[0]=1;
    a[N+1]=1;
    for(int i=0;i<=N+2;i++){
        for(int j=0;j<=N+2;j++)
            dp[i][j]=0;
    }


    for(int len=1;len<=N;len++){

        for(int left=1;left<=N-len+1;left++)
        {
           int  right = left+len-1;

          for(int i=left;i<=right;i++){
                   
                  int x =  dp[left][right];
                   int y = dp[left][i-1]+a[left-1]*a[i]*a[right+1]+dp[i+1][right];
                    dp[left][right]=max(x,y);
               }
        }

    }



    cout<<dp[1][N];


    
}