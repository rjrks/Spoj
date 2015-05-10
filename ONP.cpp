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
#include <stack>
#include <list>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int const mod=314159;
int e[1000001];
int o[1000001];


int main(){
    
    
    o[1]=1; e[1]=9;
    o[2]=18; e[2]=82;
    
    for(int i=3;i<=1000000;i++){
        e[i]=((e[i-1]*9)%mod+(o[i-1])%mod)%mod;
        o[i]=((o[i-1]*9)%mod+(e[i-1])%mod)%mod;
    }
    
    
    int tc;
    cin>>tc;
    while(tc--){
        
        int in;
        cin>>in;
        cout<<e[in]<<endl;
        
    }
    
}
