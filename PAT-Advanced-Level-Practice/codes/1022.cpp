#include <iostream>  
#include <algorithm>  
#include <string>  
#include <sstream>  
#include <map>  
#include <vector>  
#include <cstdio>  
using namespace std;  
struct bookInfo  
{  
    string ID;  
    string title;  
    string author;  
    string publisher;  
    string year;  
};  
bookInfo book[10001];  
map<string,vector<string> >keymap;  
bool cmp(bookInfo a,bookInfo b)  
{  
    return a.ID<b.ID;  
}  
int main()  
{  
    int N,i=0;  
    cin>>N;  
    string keyword,temp;  
    while(i<N)  
    {  
        cin>>book[i].ID;  
        getchar();  
        getline(cin,book[i].title,'\n');  
        getline(cin,book[i].author,'\n');  
        getline(cin,keyword,'\n');  
        istringstream is(keyword);  
        while(is>>temp)keymap[temp].push_back(book[i].ID);  
        getline(cin,book[i].publisher,'\n');  
        getline(cin,book[i].year,'\n');  
        i++;  
    }  
    sort(&book[0],&book[N],cmp);  
    int M;  
    cin>>M;  
    int j=0;  
    int index;  
    string query;  
    int flag;  
    while(j<M)  
    {  
        flag=0;  
        scanf("%d: ",&index);  
        getline(cin,query,'\n');  
        cout<<index<<": "<<query<<endl;  
        if(index==1)  
        {  
            for(int k=0;k<N;k++)  
            {  
                if(book[k].title==query)  
                {  
                    flag=1;  
                    cout<<book[k].ID<<endl;  
                }  
            }  
        }  
        else if(index==2)  
        {  
            for(int k=0;k<N;k++)  
            {  
                if(book[k].author==query)  
                {  
                    flag=1;  
                    cout<<book[k].ID<<endl;  
                }  
            }  
        }  
        else if(index==3)  
        {  
            sort(keymap[query].begin(),keymap[query].end());  
            if(keymap[query].size()>0)  
            {  
                flag=1;  
                vector<string >::iterator iter=keymap[query].begin();  
                for(;iter!=keymap[query].end();iter++)  
                {  
                    cout<<*iter<<endl;  
                }  
            }  
        }  
        else if(index==4)  
        {  
            for(int k=0;k<N;k++)  
            {  
                if(book[k].publisher==query)  
                {  
                    flag=1;  
                    cout<<book[k].ID<<endl;  
                }  
            }  
        }  
        else  
        {  
            for(int k=0;k<N;k++)  
            {  
                if(book[k].year==query)  
                {  
                    flag=1;  
                    cout<<book[k].ID<<endl;  
                }  
            }  
        }  
        if(flag==0)cout<<"Not Found"<<endl;  
        j++;  
    }  
    return 0;  
} 