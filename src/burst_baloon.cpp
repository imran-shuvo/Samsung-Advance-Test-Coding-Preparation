/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
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

           for(int last=left;last<=right;last++){

               if(left==1&&right==N)
                    dp[left][right] = max(dp[left][right],dp[left][last-1]+(a[left-1]*a[last]*a[right+1])+
                    dp[last+1][right]);
                else 
                 dp[left][right] = max(dp[left][right],dp[left][last-1]+(a[left-1]*a[right+1])+
                    dp[last+1][right]);

            }
        }

    }



    cout<<dp[1][N];


    
}