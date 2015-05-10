///

//  Created by Rohan on 30/08/14.

//  Copyright (c) 2014 Rohan. All rights reserved.

//



#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <list>
#include <stack>
#include <algorithm>




using namespace std;
typedef long long ll;


class sq{
    
public:
    bool vis;
    int path;
    char dir;
    
    
    sq(){
        
        vis=false; path=-1;
        
    }
    
};


sq mesh[1001][1001];

int pc;
int cnt;

void check(int u, int v){
    
    if(mesh[u][v].vis){
        
        if(mesh[u][v].path!=-1)pc=mesh[u][v].path;
        
        else{
            
            pc=cnt;
            cnt++;
            
            
        }
        return;
        
    }
    
    mesh[u][v].vis=true;
    
    if(mesh[u][v].dir=='N')check(u-1, v);
    else if(mesh[u][v].dir=='S')check(u+1, v);
    else if(mesh[u][v].dir=='W')check(u, v-1);
    else check(u, v+1);
    
    
    
    
    mesh[u][v].path=pc;
    
    
    
    
    
    
    
}





int main(){
    
    int n,m;
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    
    cnt=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            char t;
            
            cin>>t;
            
            mesh[i][j].dir=t;
            
            
        }
    }
    
    
    
    
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(mesh[i][j].vis==true)continue;
            
            check(i, j);
            
            
            
            
        }
    }
    
    
    printf("%d",cnt-1);
    
}

/*
 
 
 
 
 3 4
 SWWW
 SWEN
 EEEN
 
 
 
 */



