/*
https://www.careercup.com/question?id=5137923582722048
*/

/*
Given a graph print either of the set of the vertices that are colored with the same color. And if the graph
is not bipartite print “-1”. Test cases also included the cases when a graph is not connected.
*/
#include<iostream>
using namespace std;
int graph[50][50];
int color[50];
int bfs[200];
int n;

void init(){

    for(int i=0;i<50;i++){
        color[i]=-1;
        for(int j=0;j<50;j++){
            graph[i][j]=0;
        }
    }
}

bool bipartite(int src){

    int bfs[100];
    int front=0,rear=0;
    bfs[rear++]=src;
    int check=0;
    while(front<rear){

            int u = bfs[front++];
            
            for(int i=0;i<n;i++){

                if(graph[u][i]==1){

                    if(color[i]==color[u]||graph[u][u]){
                        check=1;
                        break;
                    }
                    if(color[i]==-1){
                        color[i] = 1-color[u];
                        bfs[rear++]=i;
                    }


                }




            }
            if(check==1)
                break;


    }



    if(check)
        return false;
    else
        return true;



}





int main()
{
    int testCase,test;
    cin>>testCase;
    for(test=1;test<=testCase;test++){

        int i,j;
        init();
        cin>>n;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>graph[i][j];
            }
        }
        int check=0;
        for(i=0;i<n;i++){

            if(color[i]==-1){

                color[i]=0;
                if(!bipartite(i)){
                    check=1;
                    break;

                }

            }


        }
        if(check)
            cout<<"test"<<test<<" NO"<<endl;
        else
            cout<<"test"<<test<<" YES"<<endl;
            
       for(i=0;i<n;i++){
           cout<<color[i]<<" ";
       }
        

        

    }

}

/*
2
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
3
0 1 0
0 0 1
1 0 0

test1 YES
test2 NO
*/