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


class node{
public:
    char data;
    int xcord;
    int ycord;
    bool visited;
    node(){
        visited=false;
    }
    
};


char str[]={'L','L','I','Z','Z','W','E','L','L'};
node in[110][110];

std::stack<int>cnt;
std::stack<node>q;
bool found=false;



void dfs(int rx,int ry){
    
    if(cnt.top()==9 || found){found=true; return;}
    else if(q.empty())return;
    
    
    int k=cnt.top();
    if(in[rx+1][ry].data==str[k] && !in[rx+1][ry].visited){ q.push(in[rx+1][ry]);cnt.push(1+k);
        in[rx+1][ry].visited=true; dfs(rx+1,ry);}
    if(in[rx+1][ry-1].data==str[k] && !in[rx+1][ry-1].visited){ q.push(in[rx+1][ry-1]);cnt.push(1+k);
        in[rx+1][ry-1].visited=true;dfs(rx+1,ry-1);}
    if(in[rx][ry-1].data==str[k] && !in[rx][ry-1].visited){ q.push(in[rx][ry-1]);cnt.push(1+k);
        in[rx][ry-1].visited=true;dfs(rx,ry-1);}
    if(in[rx-1][ry-1].data==str[k] && !in[rx-1][ry-1].visited){q.push(in[rx-1][ry-1]);cnt.push(1+k);
        in[rx-1][ry-1].visited=true;dfs(rx-1,ry-1);}
    if(in[rx-1][ry].data==str[k] && !in[rx-1][ry].visited){q.push(in[rx-1][ry]);cnt.push(1+k);
        in[rx-1][ry].visited=true;dfs(rx-1,ry);}
    if(in[rx-1][ry+1].data==str[k] && !in[rx-1][ry+1].visited){q.push(in[rx-1][ry+1]);cnt.push(1+k);
        in[rx-1][ry+1].visited=true;dfs(rx-1,ry+1);}
    if(in[rx][ry+1].data==str[k] && !in[rx][ry+1].visited){q.push(in[rx][ry+1]);cnt.push(1+k);
        in[rx][ry+1].visited=true;dfs(rx,ry+1);}
    if(in[rx+1][ry+1].data==str[k] && !in[rx+1][ry+1].visited){q.push(in[rx+1][ry+1]);cnt.push(1+k);
        in[rx+1][ry+1].visited=true;dfs(rx+1,ry+1);}
    
    
    cnt.pop();
    int x=q.top().xcord;
    int y=q.top().ycord;
    in[x][y].visited=false;
    q.pop();
    
    if(q.empty())return;
    
    
    
}



using namespace std;

int main(){
    
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int r,c;
        cin>>r>>c;
        
        
        for(int i=0;i<=c+1;i++){in[0][i].data=0; in[r+1][i].data=0; in[0][i].xcord=0; in[0][i].ycord=i;
            in[r+1][i].xcord=r+1; in[r+1][i].ycord=i; }
        for(int i=0;i<=r+1;i++){in[i][0].data=0; in[i][c+1].data=0; in[i][0].xcord=i; in[i][0].ycord=0;
            in[i][c+1].xcord=i; in[i][c+1].ycord=c+1;}
        
        
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>in[i][j].data;
                in[i][j].xcord=i;
                in[i][j].ycord=j;
                in[i][j].visited=false;
            }
        }
        
        //--------INPUT COMPLETE----------
        
        while(!cnt.empty())cnt.pop();
        while(!q.empty())q.pop();
        
        
        int rx,ry;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                rx=i; ry=j;
                
                if(in[rx][ry].data=='A'){
                    
                    q.push(in[rx][ry]);
                    cnt.push(0);
                    dfs(rx,ry); }
                
                if(found)break;
                
            }
            if(found)break;
        }
        
        if(found)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        found=false;
        
        
    }
}
