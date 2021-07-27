#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string s , str_rev;
	cin>>s;
	for (int i = s.size()-1; i>=0; --i)
	{
		str_rev.push_back(s[i]);
	}
	if(s==str_rev){
		cout<<"Pelendrom"<<endl;
	}
	else{
		cout<<"Not Pelendrom"<<endl;
	}

}