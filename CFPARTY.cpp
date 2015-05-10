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
#include <map>
#include <list>
#include <stack>


using namespace std;


#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}







int main(){
    
    
    
    int tc;
    scanint(tc);
    
    while(tc--){
        
        
        
        int n;
        scanint(n);
        if(n==1){printf("%d",0);printf("\n"); continue;}
        printf("%d",n-2);
        printf("\n");
        
        
        
    }
}
