#include<iostream>
using namespace std;

int node,edges,times;
double graph[100][100];
double prob[100];

void init(){
    for(int i=0;i<100;i++){

        prob[i]=0.0;
        for(int j=0;j<100;j++){
            graph[i][j]=-1;
        }
    }
}


void doctor(){

    int t=0;
    double a[node+1];
    for(int i=0;i<node;i++){
        a[i]=0.0;
    }

    while (t<times)
    {

        for(int u=0;u<node;u++){
            for(int v=0;v<node;v++){
                if(graph[u][v]!=-1 && prob[u]!=0){
                    double p = graph[u][v]*prob[u];
                    a[v]+=p;
                }
            }
        }
        for(int i=0;i<node;i++)
        {
            prob[i]=a[i];
            a[i]=0;
        }
        
        
        t+=10;
    }
    





}


int main(){
    int test,testcase;
    cin>>testcase;
    for(test=1;test<=testcase;test++){
        cin>>node>>edges>>times;
         init();
        for(int i=0;i<edges;i++){

            int x,y;
            float p;
            cin>>x>>y>>p;
            graph[x-1][y-1]=p;            

        }
        prob[0]=1;
        doctor();
        int indx;
        double mx = 0;
        for(int i=0;i<node;i++){
            
            if(mx<prob[i])
            {
                mx = prob[i];
                indx = i+1;

            }
        }

        


        cout<<"test#"<<test<<" "<<indx<<endl;
        printf("%0.4lf",mx);
        cout<<endl;


    }
}
/*
2
6 10 40 
1 2 0.3 
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5




*/