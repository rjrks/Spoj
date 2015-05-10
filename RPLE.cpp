

#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <map>
#include <stack>
#include <list>

using namespace std;
int people;
int n;
std::stack<int>stk;





bool spying;

//argument is node no.
void dfs(int ind, vector<std::list<int> >& g){
    
    stk.push(ind);
    if(stk.size()>2){spying=false; return;}
    
    
    
    std::list<int>::iterator it;
    
    
    for(it=g[ind].begin();it!=g[ind].end();++it)dfs(*it, g);
    
    stk.pop();
    
    
    return;
    
    
}




int main(){
    
    int tc;
    cin>>tc;
    for(int m=1;m<=tc;m++){
        cin>>people;
        cin>>n;
        
        
        std::vector<std::list<int> >graph(10000);
        
        
        
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            
            graph[x].push_back(y);
            
            
        }
        
        
        
        spying=true;
        
        for(int i=0;i<people && spying;i++)dfs(i,graph);
        
        if(spying)cout<<"Scenario #"<<m<<": spying";
        else cout<<"Scenario #"<<m<<": spied";
        cout<<endl;
        
        while(!stk.empty())
            stk.pop();
    }
    
    
}