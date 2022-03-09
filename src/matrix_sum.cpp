/*
Given an NxM (N rows and M columns) integer matrix with non-negative values (0..MAX_INT inclusive). 
What is the maximum sum from going top left (0, 0) to bottom right (N-1, M-1)? 
The condition is that when you're at the point (p, q), 
you can only move to either right (p, q+1) or down (p+1, q).

*/
#include<iostream>
using namespace std;
int matrix[100][100];
int sum[100][100];
 int n,row,col;
int sumOfmatrix(){

    sum[0][0]=matrix[0][0];

    for(int i=1;i<row;i++)
        sum[i][0]=sum[i-1][0]+matrix[i][0];
    for(int i=1;i<col;i++)
        sum[0][i]=sum[0][i-1]+matrix[0][i];

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            sum[i][j]=max(sum[i][j-1],sum[i-1][j])+matrix[i][j];
        }
    }
    return sum[row-1][col-1];
}

int main(){

    int testcase,test;
    cin>>testcase;

    for(test=1;test<=testcase;test++){
       
        cin>>row>>col;
        for(int i=0;i<row;i++){
            for( int j=0;j<col;j++){
                cin>>matrix[i][j];
            }
        }

        int x = sumOfmatrix();
        cout<<"test#"<<test<<" "<<x<<endl;

    }
    

}
/*

2
4 4
2 3 4 1
1 1 3 9
2 2 3 1
2 2 3 1
test#1 23

2 2
1 2 
3 4
test#2 8



*/