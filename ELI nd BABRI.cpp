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
#include <queue>


using namespace std;
typedef long long ll;





int grundy(std::vector<std::list<int> >& g, int ind){
    
     bool nchild=true;
    
    std::list<int>::iterator it;

    bool trk[100001]={false};
    
    
    for(it=g[ind].begin();it!=g[ind].end();++it){
     
        int t=grundy(g, *it);
        trk[t]=true;
        
        nchild=false;
        
        
    }
    
    if(nchild)return 0;
    
    int grund;
    for(int i=0;i<=100001;i++){
        
        if(trk[i]==true)continue;
        
        grund=i; break;
        
    }
    

    return grund;
    
}





int main(){

    int tc;
    scanf("%d",&tc);
    while(tc--){
    
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    
    std::vector<std::list<int> >graph(n+1);
    
    for(int i=1;i<=n-1;i++){
        
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        
        graph[x].push_back(y);
        
    }
   

    
  int ans=  grundy(graph, 1);
    

    if(ans==0)printf("Babri");
    else{
     
        if(k%2==0)printf("Babri");
        else printf("Eli");
        
    }
    
    printf("\n");
    
    
    }
    
   
}

/*
 
 TESTCASES
 
 9 10
 1 2
 2 6
 2 3
 3 4
 3 5
 1 7
 7 8
 8 9
 

 
 
 */



