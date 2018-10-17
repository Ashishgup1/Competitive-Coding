----------------------------------------------------------------------------------------------------------------------------------------
4 Call FFT with MOD:

typedef complex<double> base;

const double PI = acos(-1.0l);
const int N = 8e5+5;
const int Maxb = 19;
const int Maxp = 450;
const int MOD=13313;

vector<int> rev;
vector<base> omega;

void calc_rev(int n, int log_n) //Call this before FFT
{
	omega.assign(n, 0);
	rev.assign(n, 0);
	for(int i=0;i<n;i++)
	{
		rev[i]=0;
		for(int j=0;j<log_n;j++)
		{
			if((i>>j)&1)
				rev[i] |= 1<<(log_n-j-1);
		}
	}
}

void fft(vector<base> &A, int n, bool invert)
{
	for(int i=0;i<n;i++)
	{
		if(i<rev[i])
			swap(A[i], A[rev[i]]);
	}
	for(int len=2;len<=n;len<<=1)
	{
		double ang=2*PI/len * (invert?-1:+1);
		int half=(len>>1);

		base curomega(cos(ang), sin(ang));
		omega[0]=base(1, 0);

		for(int i=1;i<half;i++)
			omega[i]=omega[i-1]*curomega;

		for(int i=0;i<n;i+=len)
		{
			base t;
			int pu = i,
				pv = i+half,
				pu_end = i+half,
				pw = 0;
			for(; pu!=pu_end; pu++, pv++, pw++)
			{
				t=A[pv] * omega[pw];
				A[pv] = A[pu] - t;
				A[pu] += t;
			}
		}
	}

	if(invert)
		for(int i=0;i<n;i++)
			A[i]/=n;
}

void multiply(int n, vector<base> &A, vector<base> &B, vector<int> &C)
{
	fft(A, n, false);
	fft(B, n, false);
	for(int i=0;i<n;i++)
		A[i] *= B[i];
	fft(A, n, true);
	for(int i=0;i<n;i++)
	{
		C[i] = (int)(A[i].real() + 0.5);
		C[i] %= MOD;
	}
}

void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result, bool big1, bool big2) //Call 4 times: 00, 01, 10, 11
{
	vector<base> A(n), B(n);
	for(int i=0;i<n;i++)
	{
		A[i]=big1?coeffA[i]/Maxp : coeffA[i]%Maxp;
		B[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		B[i]=big2?coeffB[i]/Maxp : coeffB[i]%Maxp;
	}
	vector<int> C(n);
	multiply(n, A, B, C);
	for(int i=0;i<n;i++)
	{
		int add=C[i];
		if(big1)
			add*=Maxp;
		if(big2)
			add*=Maxp;
		add%=MOD;
		result[i]+=add;
		result[i]%=MOD;
	}
}

void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result)
{
	int n=1, bits=0;
	while(n<2*A.size() || n<2*B.size())
		n<<=1, bits++;
	result.assign(n, 0);
	calc_rev(n, bits);
	vector<int> tempA(A.begin(), A.end());
	vector<int> tempB(B.begin(), B.end());
	tempA.resize(n);
	tempB.resize(n);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			Solve(n, tempA, tempB, result, i, j);
		}
	}
}

----------------------------------------------------------------------------------------------------------------------------------------
Single Call without MOD:

typedef complex<double> base;
 
const double PI = acos(-1.0l);
const int N = 8e5+5;
const int Maxb = 19;
const int Maxp = 450;
const int MOD=13313;
 
vector<int> rev;
vector<base> omega;
 
void calc_rev(int n, int log_n) //Call this before FFT
{
	omega.assign(n, 0);
	rev.assign(n, 0);
	for(int i=0;i<n;i++)
	{
		rev[i]=0;
		for(int j=0;j<log_n;j++)
		{
			if((i>>j)&1)
				rev[i] |= 1<<(log_n-j-1);
		}
	}
}
 
void fft(vector<base> &A, int n, bool invert)
{
	for(int i=0;i<n;i++)
	{
		if(i<rev[i])
			swap(A[i], A[rev[i]]);
	}
	for(int len=2;len<=n;len<<=1)
	{
		double ang=2*PI/len * (invert?-1:+1);
		int half=(len>>1);
 
		base curomega(cos(ang), sin(ang));
		omega[0]=base(1, 0);
 
		for(int i=1;i<half;i++)
			omega[i]=omega[i-1]*curomega;
 
		for(int i=0;i<n;i+=len)
		{
			base t;
			int pu = i,
				pv = i+half,
				pu_end = i+half,
				pw = 0;
			for(; pu!=pu_end; pu++, pv++, pw++)
			{
				t=A[pv] * omega[pw];
				A[pv] = A[pu] - t;
				A[pu] += t;
			}
		}
	}
 
	if(invert)
		for(int i=0;i<n;i++)
			A[i]/=n;
}
 
void multiply(int n, vector<base> &A, vector<base> &B, vector<int> &C)
{
	fft(A, n, false);
	fft(B, n, false);
	for(int i=0;i<n;i++)
		A[i] *= B[i];
	fft(A, n, true);
	for(int i=0;i<n;i++)
	{
		C[i] = (int)(A[i].real() + 0.5);
	}
}
 
 
void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result)
{
	vector<base> A(n), B(n);
	for(int i=0;i<n;i++)
	{
		A[i]=coeffA[i];
		B[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		B[i]=coeffB[i];
	}
	vector<int> C(n);
	multiply(n, A, B, C);
	for(int i=0;i<n;i++)
	{
		int add=C[i];
		result[i]+=add;
	}
}
 
void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result)
{
	int n=1, bits=0;
	while(n<2*A.size() || n<2*B.size())
		n<<=1, bits++;
	result.assign(n, 0);
	calc_rev(n, bits);
	vector<int> tempA(A.begin(), A.end());
	vector<int> tempB(B.begin(), B.end());
	tempA.resize(n);
	tempB.resize(n);
	Solve(n, tempA, tempB, result);
}

//Problem 1: https://www.codechef.com/problems/COUNTWAY/
//Solution 1 (Divide and Conquer): https://www.codechef.com/viewsolution/19144054

//Problem 2: https://codeforces.com/contest/993/problem/E
//Solution 2: https://codeforces.com/contest/993/submission/40115289

//Problem 3: https://codeforces.com/contest/954/problem/I
//Solution 3: https://codeforces.com/contest/954/submission/40926618
