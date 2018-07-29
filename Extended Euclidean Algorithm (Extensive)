int xgcd(int a, int b, int &x, int &y) //Returns GCD of A, B
{
	if(a==0) 
	{
		x=0;
		y=1;
		return b;
	}
	int x1, y1;
	int d = xgcd(b % a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

int modular_inverse(int a, int m)
{
	int x, y;
	int g=xgcd(a, m, x, y);
	if(g!=1)
		return -1;
	else
	{
		x=(x%m + m)%m;
		return x;
	}
}

void shift_solution(int &x, int &y, int a, int b, int cnt)
{
	x+=cnt*b;
	y-=cnt*a;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0)
{
	int g=xgcd(abs(a), abs(b), x0, y0);
	if(c%g!=0)
		return false;
	x0 *= c/g;
	y0 *= c/g;
	if(a<0)
		x0*=-1;
	if(b<0)
		y0*=-1;
	return true;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) //Returns number of solutions with x∈[minx, maxx], y∈[miny, maxy]
{
	int x, y, g;
	if(!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g;  
	b /= g; 

	int sign_a = a>0 ? +1 : -1;
	int sign_b = b>0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx) shift_solution(x, y, a, b, sign_b);
	if (x > maxx) return 0;
	int lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx) shift_solution(x, y, a, b, -sign_b);
	int rx1 = x;

	shift_solution(x, y, a, b, - (miny - y) / a);
	if (y < miny) shift_solution(x, y, a, b, -sign_a);
	if (y > maxy) return 0;
	int lx2 = x;

	shift_solution(x, y, a, b, - (maxy - y) / a);
	if (y > maxy) shift_solution(x, y, a, b, sign_a);
	int rx2 = x;

	if (lx2 > rx2) 
		swap (lx2, rx2);
	int lx = max (lx1, lx2);
	int rx = min (rx1, rx2); 

	return (rx - lx) / abs(b) + 1;
}
