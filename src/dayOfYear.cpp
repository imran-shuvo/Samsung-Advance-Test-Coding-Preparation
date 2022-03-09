

//solved
//www.quora.com/How-does-Tomohiko-Sakamotos-Algorithm-work
//which is day of week on this date

#include<iostream>
using namespace std;
int dayOfweek(long date,int month,int year){

    long long m[]={11,12,1,2,3,4,5,6,7,8,9,10};
    
    for(int i=0;i<12;i++){
        
        int x=(m[i]*2.6)-0.2;
        m[i] = x%7;
    }
    if(month<3)
        year = year-1;
    

    return (year + year/4 - year/100 + year/400 + m[month-1] + date)%7;

}


int main(){

    int testcase,test;
    cin>>testcase;
    for (test=1;test<=testcase;test++)
    {
        int day,date,month,year;
        cin>>date>>month>>year;
        string a[]={"sunday","monday" ,"tuesday","wednesday","thursday","friday","saturday"};
        int d=dayOfweek(date,month,year);

        cout<<"test#"<<test<<" "<<a[d]<<endl;

        
    }
    

}