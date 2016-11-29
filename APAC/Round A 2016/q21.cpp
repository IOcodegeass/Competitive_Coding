#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
main(){
    int T;
    cout.precision(10);
    cin>>T;
    int i;
    for(i=0;i<T;i++){
        int N,M;
        cin>>N>>M;
        int j,l,r,d,k;
        double vol,len;
        double arr[N];
        for(j=0;j<N;j++)
            cin>>arr[j];
        cout<<"Case #"<<i+1<<":"<<endl;
        for(j=0;j<M;j++){
            cin>>l>>r;
            d=(r-l)+1;
            vol=1;
            for(k=l;k<=r;k++)
                vol*=pow(arr[k],1.0/d);
            printf("%.8f\n",vol);
        }
        
    }
}
