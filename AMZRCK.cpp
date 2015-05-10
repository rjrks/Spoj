//

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
#include <cmath>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;





int main(){

    int tc;
    scanf("%d",&tc);
    
    
    while(tc--){
    ll n;
    scanf("%lld",&n);
    ll dpi[n+1], dpn[n+1];
    
    dpi[1]=1;
    dpn[1]=1;
    
    for(ll i=2;i<=n;i++){
        
        dpi[i]=dpn[i-1];
        dpn[i]=dpi[i-1]+dpn[i-1];
    }
    
    printf("%lld\n",dpi[n]+dpn[n]);
    
    
    }
    }

/*
 
 
 1
 
 
 
 */

