#include <bits/stdc++.h>
using namespace std;

char upper(char c)
{
	// return 'A' + (c - 'a');
	char c1 = c-32;
	return c1;

}
char lower(char c)
{
	char c1 = c+32;
	return c1;

}
int main()
{

	while (true)
	{
		string s;
		cin >> s;

		//   getline(cin , s);

		// for(int i = 0 ; i < s.size() ; ++i){
		// 	if(s[i] == ' '){
		// 		cout<<endl;
		// 	}
		// 	else{
		//  	putchar(toupper(s[i]));

		//     }
		//    }

		for (int i = 0; i < s.size(); ++i)
		{
			s[i] = upper(s[i]);
		}
	
		cout << s << endl;
	}
	
	
}