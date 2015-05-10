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

using namespace std;
typedef long long ll;

ll btree[1000001];
int n,q;

ll getsum(int ind){
    
    ll sum=0;
    while(ind>0){
        
        sum+=btree[ind];
        ind-=ind&(-ind);
        
        
    }
    
    return sum;
    
    
}


void update(int ind, ll val){
    
    while(ind<=n){
        btree[ind]+=val;
        ind+=ind&(-ind);
        
    }
    
    
}



int main(){
    
    
    scanf("%d",&n);
    scanf("%d",&q);
    
    for(int i=0;i<=n;i++)btree[i]=0;
    
    while(q--){
        
        
        
        char in[5];
        scanf("%s",in);
        
        if(in[0]=='a'){
            int p;
            ll f;
            
            scanf("%d",&p);
            scanf("%lld",&f);
            update(p, f);
            
        }
        
        else{
            
            int a,b;
            scanf("%d",&a);scanf("%d",&b);
            
            ll t=getsum(b)-getsum(a-1);
            printf("%lld",t);
            printf("\n");
            
        }
        
        
        
        
    }
    
}

// 1 1 3 1 2

