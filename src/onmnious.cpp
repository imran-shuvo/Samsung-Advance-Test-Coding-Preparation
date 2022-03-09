/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-40-campus-white-box-testing/
https://www.geeksforgeeks.org/samsung-rd-sri-noida-on-campus-interview-experience/
https://code.hackerearth.com/01ac52j?key=b462f0a802c8c1faf1d87f2b1353b9ce
Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.
Example-
Range: 24 to 12943
Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more
In above case all two digit numbers are valid.
In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.
In four digit: All the numbers containing above 3 digit numbers are not valid.
Eg: 11223 is not valid, 11222 is valid.
*/



#include<iostream>
using namespace std;

int omnious(int *del,int a,int b,int k,int n){
    int i,result=0;
    for(i=a;i<=b;i++){

        
        int arr[10],temp = i,cnt=0;

        for(int j=0;j<10;j++)
            arr[j]=0;

       
        while (temp)
        {
            arr[temp%10]++;
            temp/=10;
            
        }
        
        for(int j=0;j<n;j++){
            cnt+=arr[del[j]];
        }

        cout<<"NUM"<<i<<" "<<cnt<<endl;

        if(cnt<k)
            result++;
    


    }
    return result; 
    
   
}

int main(){

    int testcase;
    cin>>testcase;
    while (testcase--)
    {
        int a,b,k,n;
        cin>>a>>b>>k;
        cin>>n;
        int del[n+1];
        for(int i=0;i<n;i++){
            cin>>del[i];
        }
      cout<<omnious(del,a,b,k,n);
       
    
    }
    

    
}