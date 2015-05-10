
//  main.cpp


#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

std::stack<int> bins[100];


int fill_bins(int *in,int s){       //s stands for length of the sequence
    
    int index=0;
    bool flag=false;
    
    bins[0].push(in[0]);        //first element
    
    for(int j=1;j<s;j++){
        bins[0].push(in[j]);
        
        for(int i=1;i<=j;i++){
            
            int temp=bins[i-1].top();           //done in order to get the second element
            bins[i-1].pop();
            bins[i].push(temp-bins[i-1].top());
            bins[i-1].push(temp);
            
            // cout<<bins[i].top()<<endl;
            if(bins[i].top()==0){index=i-1; flag=flag && true;}//returns the index of the bin with the equal diff
            else flag=false;
        }
        
    }
    if(flag)return index;
    else return (s-1);
    
}


//finds the next elements in the sequence
void find_next(int index,int c){
    
    
    for(int j=0;j<c;j++){
        for(int i=0;i<index;i++){
            
            bins[index-i-1].push(bins[index-i-1].top()+bins[index-i].top());
            
            
        }
        
        cout<<bins[0].top()<<' ';
    }
    
    
    
}

//fnc ends





int main(){
    
    int test_cases;
    cin>>test_cases;
    
    for(int i=0;i<test_cases;i++){
        
        int s,c;
        cin>>s;         //length of the sequence
        cin>>c;         //numbers to be calculated
        
        
        int input[100];
        for(int i=0;i<s;i++)cin>>input[i];
        
        int index;
        index=fill_bins(input, s);
        find_next(index,c);
        
        cout<<endl;
        
    }
    
    
    
}



