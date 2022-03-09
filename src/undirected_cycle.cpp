
/*
cycle detection undirected graph && num of simple cycle count

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
         
    for(int i=0;i<N;i++){

        if(graph[u][i]&&state[u]!=2&&parent[u]!=i){
             state[u]=1;
           
            if(state[i]==1){
                result++;
                t=0;           
                int x = u;
                cout<<"cycle#"<<result<<endl;
                
                while (x!=i)
                {
                    cout<<x<<"<----";
                    x = parent[x];
                    
                }
                cout<<i<<endl;   

            }
            else if(state[i]==0){

                state[i]=1;
                parent[i]=u;
                // cout<<"dfs("<<i<<")"<<endl;
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
        if(state[i]==0){
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
            graph[--x][--y]=1;
            graph[y][x]=1;
        }

        if(isCycle()){
             cout<<"TEST #"<<test<<"YES "<<endl;
            
            cout<<endl;



        }
           
        else
            cout<<"TEST #"<<test<<"NO "<<endl;




    }


}
/*
7 8
1 2
1 6
2 3
2 5
3 4
3 7
4 5
4 7
*/