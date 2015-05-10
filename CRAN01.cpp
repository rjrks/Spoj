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



int main(){
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
        
        int n,m;
        scanf("%d",&n);
        scanf("%d",&m);
        
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        
        
        int t1,t2;
        
        int tl=0,tr=0,bl=0,br=0;
        
        //top left
        t1=x-1; t2=y-1;
        
        tl=2*min(t1, t2);
        
        if(t1>t2)tl+=t1-t2;
        else tl+=t2-t1;
        
        
        //top right
        t1=x-1; t2=m-y;
        
        tr=2*min(t1, t2);
        
        if(t1>t2){ tr+=t1-t2;}
        else tr+=t2-t1;
        
        
        //bottom left
        t1=n-x; t2=y-1;
        
        bl=2*min(t1, t2);
        
        if(t1>t2){ bl+=t1-t2;}
        else bl+=t2-t1;
        
        //bottom right
        t1=n-x; t2=m-y;
        
        br=2*min(t1, t2);
        
        if(t1>t2){ br+=t1-t2;}
        else br+=t2-t1;
        
        
        int ans=0;
        
        ans=max(tl, max(tr, max(bl, br)));
        printf("%d",ans);
        printf("\n");
        
        
    }
    
}

// 1 1 3 1 2

