//Many times result for the given problem can not be stored even in long long int.
// to finding value of these type problem we use modulo , basicallu we tell
// that give the modulo value of exect result and we can easily store this in int data type.
// Basically it it given in 10^9+7 which can be stored in int   and this is a prime number.

// let's understand it with question.
// Q - find the factorial of a given number N;
// Constrain 1<= N <=100.
//Sol :-  Now factorail of 100 will is very big num , even we can not store factorail of 21 in long lng int.
// so here we have given to print modulo value. 
 
 // like print modulo of 47. so then factorail modulo will be less than 47 .

#include<iostream>
using namespace std;
int main()
{
   int n ;
   cin>>n;
   long long int fact = 1;
   int factmod = 1;
   int mod = 47;
   for (int i = 2; i <=n; i++)
   {
        fact = fact*i;  // here the largest value we can store is factorial of 20. 21 factorail will be negative.
        factmod = (factmod*i) % mod;
   }
   cout<<fact<<endl;
   cout<<factmod<<endl;  // it will evaluate for every value of i for 47 modulo. value will be less than modulo
   

  return 0;
}

/*
Some Basic rule for evaluting Modulo.
(a + b) % M = ((a % M) + (b % M)) % M
(a * b) % M = ((a % M) * (b % M)) % M
(a - b) % M = (((a % M) - (b % M))+M) % M
(a / b) % M = ((a % M) * (b^-1)%M) % M

*/