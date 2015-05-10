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




int main(){
    
    
    while(true){
        
        int  a,b,c;
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0)break;
        
        
        if(2*b==(a+c))cout<<"AP"<<" "<<c+(c-b);
        else cout<<"GP"<<" "<<c*(c/b);
        cout<<endl;
        
        
        
        
    }
    
    
}
