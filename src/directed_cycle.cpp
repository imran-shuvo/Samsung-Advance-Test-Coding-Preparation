/*
Given a directed graph, check whether the graph contains a cycle or not. 
Your function should return true if the given graph contains at least one cycle,
 else return false. && print the cycle.

 2
 4 5
 0 1
 0 2
 2 1
 2 0
 2 3
 3 3
 
 4 5
 0 1
 0 2
 2 1
 2 0
 2 3
 test#1 yes
 test#2 Yes
*/




#include<iostream>
using namespace std;

int graph[50][50];
int parent[50];
int state[50];
int N,t;
int cycle[100];
int result;

void init(){
    for(int i=0;i<50;i++){
        state[i]=0;
        parent[i]=-1;
      for(int j=0;j<50;j++){
          graph[i][j]=0;
      }

    }
}

void dfs(int u){
         
    state[u]=1;

    for(int i=0;i<N;i++){

        if(graph[u][i]){
           
            if(state[i]==1){
                result++;
                         
                int x = u;
                if(result<2){
                     t=0; 
                while (x!=i)
                {
                    cycle[t++]=x;
                    x = parent[x];
                    
                }
                cycle[t++]=i;}
                
                

            }
            else if(state[i]==0){

                state[i]=1;
                parent[i]=u;
                dfs(i);

            }
        }

    }

    state[u]=2;
    return;



}







int isCycle(){

    result=0;

    int i;
    for(i=0;i<N;i++){
        if(state[i]==0&&result==0){
            dfs(i);
        }
    }
    return result;


}



int main(){

    int testcase,test;
    cin>>testcase;
    for(test=1;test<=testcase;test++){
        int m;
        cin>>N>>m;
        init();
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x][y]=1;
        }

        if(isCycle()){
             cout<<"TEST #"<<test<<"YES "<<endl;
             for(int i=0;i<t;i++)
                cout<<cycle[i]<<" ";
            
            cout<<endl;



        }
           
        else
            cout<<"TEST #"<<test<<"NO "<<endl;




    }


}