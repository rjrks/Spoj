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
#include <algorithm>
using namespace std;
typedef long long ll;





int main(){

    int tc;
    scanf("%d",&tc);
    
    while(tc--){
    
    int w,h;
    scanf("%d",&w);
    scanf("%d",&h);
    
    int   n;
    scanf("%d",&n);
    
    int const k=n;
    
    int x[n+2];
    int y[n+2];
    
    
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }

        x[n]=0;y[n]=0;
        x[n+1]=w+1; y[n+1]=h+1;
        
        
    
    sort(x, x+k+2);
    sort(y, y+k+2);
    
    
    int mx=-1,my=-1;
    
    for(int i=0;i<n+1;i++){
        
        mx=max(mx, x[i+1]-x[i]-1);
        my=max(my, y[i+1]-y[i]-1);
        
        
    }
    
   printf("%d",mx*my);
    
    printf("\n");
    
    
    }
}

/*
 
 
 1
 
 
 
 */

