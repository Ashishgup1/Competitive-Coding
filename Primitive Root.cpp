// g is O(log^6 n).
// Run Time of algorithm is O(ans * log phi(n) * log n), which is approximately O(log^8 n).

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(1LL*ans*a)%m;
		b/=2;
		a=(1LL*a*a)%m;
	}
	return ans;
}

int totient(int n)
{
	int ans=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n/=i;
			ans-=n/i;
		}
	}
	if(n>1)
		ans-=ans/n;
	return ans;
}

//Primitive root only exists if X=1, 4, Prime, (Odd Prime)^k, 2*(Odd Prime)^K

int getPrimitive(int x) //Returns -1 if there is no primitive root
{
	vector<int> factors;
	int phi=totient(x);
	int n=phi;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			factors.push_back(i);
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		factors.push_back(n);
	for(int prim=2;prim<=x;prim++)
	{
		bool check=true;
		for(int i=0;i<factors.size()&&check;i++)
			check&=(pow(prim, phi/factors[i], x)!=1);
		if(check)
			return prim;
	}
	return -1;
}

//Source: https://cp-algorithms.com/algebra/primitive-root.html

