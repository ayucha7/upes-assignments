#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int A[1][1];
int B[1][1];
int C[1][1];
int X[1][1];
int Y[1][1];
    int ind; //intial distance
	int cho1; //storing total distace through Passenger X
	int cho2; ////storing total distace through Passenger Y
    
    for(int i=0;i<=0;i++){
        for(int j=0;j<=1;j++)
        {
            cin>>A[i][j];
        }
    }
    
    
    for(int i=0;i<=0;i++){
        for(int j=0;j<=1;j++)
        {
            cin>>B[i][j];
        }
    }
    ind=(abs(A[0][0]-B[0][0]))+abs((A[0][1]-B[0][1]));
    
    
    for(int i=0;i<=0;i++){
        for(int j=0;j<=1;j++)
        {
            cin>>C[i][j];
        }
    }
    
    for(int i=0;i<=0;i++){
        for(int j=0;j<=1;j++)
        {
            cin>>X[i][j];
        }
    }
   
    for(int i=0;i<=0;i++){
        for(int j=0;j<=1;j++)
        {
            cin>>Y[i][j];
        }
    }
	//Calculating distance using Co-ordinate x and y
	
    cho1=(abs(C[0][0]-A[0][0]))+abs((C[0][1]-A[0][1])+abs(C[0][0]-X[0][0])+abs(C[0][1]-X[0][1])+abs(X[0][0]-B[0][0])+abs(X[0][1]-B[0][1]));
	
    cho2=(abs(C[0][0]-A[0][0]))+abs((C[0][1]-A[0][1])+abs(C[0][0]-Y[0][0])+abs(C[0][1]-Y[0][1])+abs(Y[0][0]-B[0][0])+abs(Y[0][1]-B[0][1]));
    
    
    if(cho1&&cho2>2*ind){ 
        cout<<-1; //impossible to serve any requests
    }
    else if(cho1<cho2){
        cout<<1;  //Passenger at point X should be picked up
    }
    else{
        cout<<2; //Passenger at point Y should be picked up
    }
}
