#include<iostream>  
#include<iomanip>  
using namespace std;   
int main()  
{ 
    int arry1[100000],arry2[100000];  
    int pos1,pos2,len;  
    cin>>pos1>>pos2>>len;  
    int i,j,k;  
    char ch;  
    for(i=0;i<len;i++)  
    {  
        cin>>j>>ch>>k;  
        arry1[j]=k;  
    }  
    while(pos1!=-1)  
    {  
        arry2[pos1]=1;  
        pos1=arry1[pos1];  
    }  
    int tag=0;  
    while(pos2!=-1)  
    {  
        if(arry2[pos2]==1)  
        {  
            tag=1;  
            k=pos2;  
            break;  
        }  
        pos2=arry1[pos2];  
    }  
    if(tag) cout<<setfill('0')<<setw(5)<<k<<endl;  
    else cout<<"-1"<<endl;  
    return 0;  
}  