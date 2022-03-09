/*
https://github.com/twowaits/SDE-Interview-Questions/tree/master/Samsung
first question

*/


#include<iostream>
#define size 1001
using namespace std;


int x,y,k,n,m;

struct node{
    int left;
    int right;
    int up;
    int down;
};
struct dir{
    int x;
    int y;
};

struct node pipe[size][size];
struct dir queue[size*size];

int graph[size][size];
int cost[size][size];
int visit[size][size];




void init(){

    for(int i=0;i<size;i++){     

        queue[i].x=-1;
        queue[i].y=-1;

        for(int j=0;j<size;j++){
            
            graph[i][j]=0;
            cost[i][j]=0;
            visit[i][j]=0;
            pipe[i][j].left=0;
            pipe[i][j].right=0;
            pipe[i][j].up=0;
            pipe[i][j].down=0;
            


        }
    }


}

void endoscope(){

    int i,j;

       for(i=0;i<n;i++){
            for( j=0;j<m;j++){

                if(graph[i][j]==1){

                    pipe[i][j].left=1;
                    pipe[i][j].right=1;
                    pipe[i][j].up=1;
                    pipe[i][j].down=1;
                    
                }
                else if(graph[i][j]==2){

                    pipe[i][j].left=0;
                    pipe[i][j].right=0;
                    pipe[i][j].up=1;
                    pipe[i][j].down=1;
                    
                }
                else if(graph[i][j]==3){

                    pipe[i][j].left=1;
                    pipe[i][j].right=1;
                    pipe[i][j].up=0;
                    pipe[i][j].down=0;
                    
                }
                else if(graph[i][j]==4){

                    pipe[i][j].left=0;
                    pipe[i][j].right=1;
                    pipe[i][j].up=1;
                    pipe[i][j].down=0;
                    
                }
                else if(graph[i][j]==5){

                    pipe[i][j].left=0;
                    pipe[i][j].right=1;
                    pipe[i][j].up=0;
                    pipe[i][j].down=1;
                    
                }
                else if(graph[i][j]==6){

                    pipe[i][j].left=1;
                    pipe[i][j].right=0;
                    pipe[i][j].up=0;
                    pipe[i][j].down=1;
                    
                }
                else if(graph[i][j]==7){

                    pipe[i][j].left=1;
                    pipe[i][j].right=0;
                    pipe[i][j].up=1;
                    pipe[i][j].down=0;
                    
                }
                
                

            }
                
        }

}
int isValid(int a,int b){
    if(a<n&&a>=0&&b<m&&b>=0)
        return 1;
    else
        return 0;
}

int bfs(){

        int front=0;
        int rear=0;
        int result=1;


        queue[rear].x=x;
        queue[rear].y=y;
        rear++;
        visit[x][y]=1;
        cost[x][y]=1;

        if(graph[x][y]==0)
            return 0;
        else{

            
            while (front<rear)
            {
                int sx = queue[front].x;
                int sy = queue[front].y;
                front++;
                               
                if(sx>=0&&sy>=0&&1+cost[sx][sy]<=k){

                    if(isValid(sx+1,sy)&&pipe[sx][sy].down&&pipe[sx+1][sy].up&&!visit[sx+1][sy]){

                        queue[rear].x=sx+1;
                        queue[rear].y=sy;
                        rear++;
                        cost[sx+1][sy]=1+cost[sx][sy];
                        visit[sx+1][sy]=1;
                        result++;

                    }
                    if(isValid(sx-1,sy)&&pipe[sx][sy].up&&pipe[sx-1][sy].down&&!visit[sx-1][sy]){

                   
                         queue[rear].x=sx-1;
                        queue[rear].y=sy;
                        rear++;
                        cost[sx-1][sy]=1+cost[sx][sy];
                        visit[sx-1][sy]=1;
                        result++;
                   
                    }
                    if(isValid(sx,sy+1)&&pipe[sx][sy].right&&pipe[sx][sy+1].left&&!visit[sx][sy+1]){

                     queue[rear].x=sx;
                        queue[rear].y=sy+1;
                        rear++;
                        cost[sx][sy+1]=1+cost[sx][sy];
                        visit[sx][sy+1]=1;
                        result++;
                    
                    
                    }
                    if(!visit[sx][sy-1]&&isValid(sx,sy-1)&&pipe[sx][sy].left&&pipe[sx][sy-1].right){

                         queue[rear].x=sx;
                        queue[rear].y=sy-1;
                        rear++;
                        cost[sx][sy-1]=1+cost[sx][sy];
                        visit[sx][sy-1]=1;
                        result++;
                    }
                    
                
                }

            }
        }


    return result;
}




int main(){

    int testcase,test;
    cin>>testcase;
    for(test=0;test<testcase;test++){

        init();

        int i,j;

        cin>>n>>m>>x>>y>>k;
        for(i=0;i<n;i++){
            for( j=0;j<m;j++)
                cin>>graph[i][j];
        }

        endoscope();
        int x = bfs();
        cout<<x<<endl;

    


    }



}