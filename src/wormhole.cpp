/*
https://github.com/arjunsk/samsung_interview/blob/master/wormhole.cpp
https://gist.github.com/gunpreet34/b58c38b3556271059182244676ba06a1
https://hack.codingblocks.com/contests/c/782/870
https://discuss.codingblocks.com/t/test-case-of-minimum-time-traversal-problem/12944
http://ideone.com/Sbx7MA
*/

/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/





#include<iostream>
using namespace std;
#define size 2000
int sx,sy,dx,dy,visit[size],n,ans,temp;

struct node
{
	int x1;
	int y1;
	int x2;
	int y2;
	int cost;
};
struct node worm[size];

void init(){
	int i,j;
	ans = 9999999;
	for(i=0;i<size;i++){
		visit[i]=0;			
			
	}
}

int dis(int x1,int y1,int x2,int y2){

	int a = x2-x1;
	int b = y2-y1;
	if(a<0) 
		a = -1*a;
	if(b<0)
		b= -1*b;
	
	return a+b;
	

}

void wormhole(int x,int y,int cost){

	int temp = cost+dis(x,y,dx,dy);
	 
	 ans = min(ans,temp);


	for(int i=0;i<n;i++){
		if(visit[i]==0){

			visit[i]=1;
			temp = cost+dis(x,y,worm[i].x1,worm[i].y1)+worm[i].cost;
			wormhole(worm[i].x2,worm[i].y2,temp); 

			temp = cost+dis(x,y,worm[i].x2,worm[i].y2)+worm[i].cost;
			wormhole(worm[i].x1,worm[i].y1,temp); 
			visit[i]=0;
			

		}
	}

}


int main(){

	int test,testcase;
	cin>>testcase;
	for(test=1;test<=testcase;test++){

		init();
		
		cin>>n;
		cin>>sx>>sy>>dx>>dy;
		for(int i=0;i<n;i++)
			cin>>worm[i].x1>>worm[i].y1>>worm[i].x2>>worm[i].y2>>worm[i].cost;
		
		cout<<endl;

		wormhole(sx,sy,0);
		cout<<"test# "<<test<<" "<<ans<<endl;

	}


}
/*
3
1 1 4 4
1 1 2 2 1
2 2 3 3 1
3 3 4 4 1
ans=3
3
1 1 4 4
1 1 4 4 1
2 2 3 3 1
3 3 4 4 1
ans=1

1 1 4 4
1
1 1 2 2 1
ans=5
*/