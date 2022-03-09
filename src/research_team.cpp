/*
https://www.careercup.com/question?id=5707238197952512
https://practice.geeksforgeeks.org/problems/how-to-solve-this-bfs-problem-asked-in-samsung
https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092
1 Bsed -> https://sapphireengine.com/@/4q0evk - Ajay Verma
0 Bsed -> https://sapphireengine.com/@/iha4kq - Thusoo
*/

/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.
Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/
/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them
*/






#include<iostream>
using namespace std;
struct node
{
    int x;
    int y;
};
struct node rare[6];


int dis[20][20][5],visit[20][20],graph[20][20];
int size,n;

void init(){
    for(int i=0;i<=20;i++){
        for(int j=0;j<=20;j++){
            graph[i][j]=0;
            visit[i][j]=0;
            for(int k=0;k<=5;k++)
                dis[i][j][k]=-1;

        }
        
    }
}

bool isValid(int x,int y){

    return x>=0&&y>=0&&y<size&&x<size&&graph[x][y];
}



void dfs(int x,int y,int cost,int rth){
    //check korte hobe valid && graph[x][y] na ki
    if(!isValid(x,y)) return;
    // jodi visit kora hoye jai kom cost e kinto er theke beshi cost asche
    if(dis[x][y][rth]<cost&&visit[x][y]) return;

    visit[x][y]=1;
    dis[x][y][rth]=cost;

    dfs(x+1,y,1+cost,rth);
    dfs(x-1,y,1+cost,rth);
    dfs(x,y+1,1+cost,rth);
    dfs(x,y-1,1+cost,rth);




}



int main(){
    int testcase,test;
    cin>>testcase;
    for(test=1;test<=testcase;test++)
    {
        init();
        cin>>size>>n;
        for(int i=0;i<n;i++){
            cin>>rare[i].x>>rare[i].y;
            --rare[i].x;
            --rare[i].y;
            
            
        }

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
                cin>>graph[i][j];
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++)
                    visit[j][k]=0;
            }

            dfs(rare[i].x,rare[i].y,0,i);

        }

        int mn = 9999999;
 ///max of (i,j) theke kth rare element distance. Na hole rare elemnt shob ghulu kobar hobe na 
 // then min of max
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++){
                
                if(graph[i][j]==0)
                    continue;
                int mx=-1;

                for(int k=0;k<n;k++){                   
                    
                        if(dis[i][j][k]>mx)
                            mx = dis[i][j][k];
                       
                   
                    
                }
                if(mn>mx)
                    mn = mx;
                

            }

        }

        cout<<"test#"<<test<<" "<<mn<<endl;






    }



}
/*
5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
Output
#1 1
#2 2
#3 2
#4 12
#5 15
*/