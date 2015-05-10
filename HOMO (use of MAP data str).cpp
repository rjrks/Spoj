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
    
    
    
    map<int, int>mymap;
    int n;
    cin>>n;
    int count=0;
    int c;
    
    
    while(n--){
        
        
        char op[10];
        for(int i=0;i<6;i++)cin>>op[i];
        int key;
        cin>>key;
        std::map<int, int>::iterator it;
        
        if(op[0]=='i'){
            
            mymap[key]++;
            if(mymap[key]==2)count++;
            
        }
        else{
            
            if(mymap[key]==2)count--;
            
            
            if(mymap[key]<2){
                it=mymap.find(key);
                if(it!=mymap.end())mymap.erase(it);
            }
            
            else mymap[key]--;
            
        }
        
        
        c=mymap.size();
        
        if(c>1 && count>0)cout<<"both";
        else if(c==1 && count>0)cout<<"homo";
        else if(c>1 && count==0)cout<<"hetero";
        else cout<<"neither";
        cout<<endl;
        
    }
    
    
    
    
}


