/*
https://www.careercup.com/question?id=5652067409461248
https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/
http://ideone.com/JXMl4L
https://ide.geeksforgeeks.org/tiyLThcuSN -> Zero
https://ide.geeksforgeeks.org/3Ks1tpOkwn
*https://code.hackerearth.com/ea07cfD?key=1cb190b158c79639d66d35f7dfa8ef7a -> One
Similr Problem - https://ide.codingblocks.com/s/95965
You’ll be given a grid as below:
    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x
In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.
  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get 
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone 
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:
    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x
  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the 
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. 
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.
    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x
   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/




#include<iostream>
using namespace std;
#define size 100
int graph[size][5],n,ans=0;
int a[size][5];

void init(){
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<5;j++)
        {
            graph[i][j]=0;
            a[i][j]=0;
        }
    }
}
void dfs(int row,int col,int temp){

    if(row<0)
        return;
    ans = max(ans,temp);

    for(int i=-1;i<=1;i++)
    {
        if(col+i>=0&&col+i<5&&a[row-1][col+i]!=2)
            dfs(row-1,col+i,temp+a[row-1][col+i]);

    }

}



int spaceship(int b){
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)   
            a[i][j]=graph[i][j];
         
    
    for(int i=b;i<b+5;i++){
        for(int j=0;j<5;j++)
        {
            if(graph[i][j]==2)
                a[i][j]=0;
         }

    }
    ans = 0;
    dfs(n,2,0);
    return ans;

    

}


int main(){

    int testcase,test;
    cin>>testcase;
    
    for(int test=1;test<=testcase;test++){
        init();
        int result=0;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>graph[i][j];

        for(int i=0;i<n-4;i++){

            result = max(result,spaceship(i));

        }

        cout<<"test#"<<test<<" "<<result<<endl;

      
    }


}

/*
5
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1

10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0                       
0 0 0 0 0
1 0 0 0 2
0 0 0 0 0
0 2 0 2 1
0 2 2 2 0

12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1


10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0
0 0 0 0 0
1 2 0 0 2
1 2 0 0 0
0 2 0 2 1
0 2 0 2 0

ans#1 : 6
ans#2 : 3
ans#3 : 0
ans#4: 1
ans#5 : 9 */