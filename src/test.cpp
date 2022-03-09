//solved
#include<iostream>
using namespace std;
#define node_max 100
float weight[node_max][node_max];
float probability_all_node[node_max];
float total_probability[node_max];
//int queu[node_max];
//int front_que=0,back_que=-1;
float ans=0;
int ans_node;
void find_division(int node,int time){

        int t=0;
        while(t<time){
            cout<<"counter  "<<t<<endl;
            for(int u=0;u<node;u++){
                for(int i=0;i<node;i++){

                    
                    if(weight[u][i]!=-1&&probability_all_node[u]!=0){
                    float temp=probability_all_node[u]*weight[u][i];//temp e rakte hobe karon ekta iteration ses na howa porjonto same value(prob_all_node)
                                                           //nea kaj korte hobe
                    total_probability[i]+=temp;
                      cout<<u+1<<"--->"<<i+1<<"   "<<temp<<" total "<<total_probability[i]<<endl; 
                    }
                }

                
            }
            for(int i=0;i<node;i++){
                probability_all_node[i]=total_probability[i];
                total_probability[i]=0;//zero na korle pore duibar kore count hobe
            }
            t+=10;
        }
}

int main()
{
    int node,edge,time;
    cin>>node>>edge>>time;
    for(int i=0;i<node;i++){
        probability_all_node[i]=0;
        for(int j=0;j<node;j++){
            weight[i][j]=-1;
        }
    }
    for(int i=0;i<edge;i++){
        int u,v;
        float probability;
        cin>>u>>v>>probability;
        weight[u-1][v-1]=probability;
    }
    probability_all_node[0]=1; //initial probability=1 (starting node)
    find_division(node,time);

    float ans=0.0;
    int highest_pro_node;
    for(int i=0;i<node;i++){
        if(ans<probability_all_node[i]){
            ans=probability_all_node[i];
            highest_pro_node=i;
        }
    }
    cout<<highest_pro_node<<endl;
    cout<<ans<<endl;
}