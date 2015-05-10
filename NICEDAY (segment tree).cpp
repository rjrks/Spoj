//

//  Created by Rohan on 23/12/14.

//  Copyright (c) 2014 Rohan. All rights reserved.

//



#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <list>
#include <stack>
#include <map>
#include <string.h>
#include <set>
#include <algorithm>


using namespace std;
//typedef uint64_t ll;



int fmini(int node, int b, int e, int j, int *m){
    
    if(j<b)return 0;
    else if(e<=j)return m[node];
    
    int p1=fmini(2*node, b, (b+e)/2, j,m);
    int p2=fmini(2*node+1, (b+e)/2+1, e, j,m);
    
    if(p1==0)return p2;
    else if(p2==0)return p1;
    else return min(p1,p2);
    
    
}


void setq(int node,int b,int e,int j,int val, int *m){
    
    
    if(e<j || b>j)return;
    if(b==e){m[node]=val; return;}
    
    
    int mid=(b+e)/2;
    
    setq(2*node, b, mid, j,val,m);
    setq(2*node+1, mid+1, e, j,val,m);
    
    if(m[node]==0)m[node]=val;
    else m[node]=min(m[node],val);
    
}


class pos{
public:
    int a,b,c;
    
};

bool comp(pos p1,pos p2){
    return p1.a<p2.a;
    
}



int main(){
    
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
        
        
        
        int n;
        scanf("%d",&n);
        
        int m[400000]={0};     // change here
        
        pos p[n+1];
        
        for(int i=1;i<=n;i++){
            
            scanf("%d",&p[i].a);
            scanf("%d",&p[i].b);
            scanf("%d",&p[i].c);
            
        }
        
        sort(p+1, p+n+1, comp);
        
        int cnt=0;
        
        for(int i=1;i<=n;i++){
            
            int fmin=fmini(1, 1, n, p[i].b,m);
            //   cout<<fmin<<endl;
            
            if(fmin==0 || p[i].c<fmin){
                cnt++;
                setq(1, 1, n, p[i].b, p[i].c,m);
            }
            
            
            //  cout<<m[4]<<endl;
            
        }
        
        printf("%d\n",cnt);
        
        
    }
}
/*
 
 1
 
 
 */
