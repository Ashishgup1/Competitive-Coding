#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t ;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         int prime = 0;
         for(int i = 2 ; i *i <= n-1 ; i++){

              if(n % i  == 0){
                   prime++;
              }
         }
         if(prime){
              cout<<"Not Prime"<<endl;
         }else{
              cout<<"Prime"<<endl;
         }
    }
  return 0;
}