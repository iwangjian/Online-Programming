#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct crew{
    string name;
    int h;
};

bool cmp(crew x, crew y)
{
    return x.h < y.h;
}
bool cmp_name(crew x, crew y)
{
    return x.name < y.name;
}
void output(vector<crew>vec, int a, int b)
{
    sort(vec.begin(), vec.end(), cmp_name);
    for(unsigned int i=0; i<vec.size(); i++){
        cout<<vec[i].name<<" ";
    }
    cout<<a<<" "<<b<<endl;
}

int main() {
    int n;
    cin>>n;
    crew ary[1000];
    for(int i=0;i<n;i++){
        string name;
        int h;
        cin>>name>>h;
        ary[i].name = name;
        ary[i].h = h;
    }
    sort(ary, ary+n, cmp);
    
    int pmin=0, pmax=0;
    vector<crew> vec;
    while(pmax<n)
    {
        if(ary[pmax].h == ary[pmin].h){
            vec.push_back(ary[pmax]);
            pmax++;
        }
        else{
            output(vec, pmin+1, pmax);
            vec.clear();
            pmin=pmax;
        }
    }
    output(vec, pmin+1, pmax);
    return 0;
}