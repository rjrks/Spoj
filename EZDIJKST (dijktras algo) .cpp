//

//  Created by Rohan on 30/08/14.

//  Copyright (c) 2014 Rohan. All rights reserved.

//



#include <math.h>

#include <iostream>
#include <vector>
//#include <string.h>
//#include <sstream>
//#include <stdio.h>
//#include <stdlib.h>
#include <stack>
#include <list>


#include <algorithm>


class node{
    
    int p;      //parent
    int d;      //distance
    
public:
    
    bool visited;
    
    node(){
        
        visited=false;
        p=NULL;
        d=10000000;
    }
    
    
    
    void setp(int x){
        
        p=x;
    }
    
    void setd(int x){
        d=x;
    }
    
    int getp(){
        return p;
    }
    
    int getd(){
        return d;
    }
    
};






class edge{
private:
    int weight;
    int ver;
    
public:
    edge(int  v, int w){
        
        ver=v;
        weight=w;
    }
    
    int getweight(){
        
        return weight;
        
    }
    
    int getvertex(){
        
        return ver;
        
    }
    
    
};




using namespace std;

int main(){
    
    int tc;
    cin>>tc;
    
    for(int j=0;j<tc;j++){
        
        int v,e;
        cin>>v>>e;
        int const temp=v+1;
        
        std::vector<node>nodes(temp);
        
        
        
        std::vector<std::list<edge> >adjlist(temp);
        
        for(int i=0;i<e;i++){
            
            int a,b,c;
            
            cin>>a>>b>>c;
            adjlist[a].push_back(edge(b,c));
            
        }
        
        
        int s,d;
        cin>>s>>d;
        
        
        // --------------INPUT COMPLETE------------------------
        
        
        nodes[s].setd(0);
        
        while(true){
            
            
            
            int dmin=INFINITY;
            int index=0;
            
            //finding the minimum distant node
            
            for(int i=0;i<v+1;i++){
                if(!nodes[i].visited && dmin>=nodes[i].getd()){dmin=nodes[i].getd(); index=i;}
                
            }
            //    --**---
            
            if(nodes[index].visited)break;          //all nodes have been covered
            
            //---------------relaxing node--------------------------
            
            
            std::list<edge>::iterator iter;
            
            
            for(iter=adjlist[index].begin();iter!=adjlist[index].end();++iter){
                
                edge ed=*iter;
                int ind=ed.getvertex();
                int wt=ed.getweight();
                
                if(!nodes[ind].visited && nodes[ind].getd()>=(wt+nodes[index].getd())){
                    
                    nodes[ind].setd(wt+nodes[index].getd());
                    nodes[ind].setp(index);
                }
                
            }
            
            
            //    ---**----
            
            
            nodes[index].visited=true;
            
        }
        if(nodes[d].getd()>=1000000)cout<<"NO";
        else cout<<nodes[d].getd();
        cout<<endl;
        
        
    }
}


