struct point //Replace double with int if not required
{
	double x, y;

	point () {}

	point(int x, int y) : x(x), y(y) {}

	void operator =(const point &p)
	{
		x=p.x, y=p.y;
	}

	bool operator <(const point&p)
	{
		if(x==p.x)
			return y<p.y;
		return x<p.x;
	}

	point operator +(const point&p) const
	{
		point pt(x + p.x, y + p.y);
		return pt;
	}

	point operator -(const point&p) const
	{
		point pt(x - p.x, y - p.y);
		return pt;
	}

	double crossProduct(const point &p) const
	{	
		return x * p.y - y * p.x;
	}	

	int dotProduct(const point &p) const
	{
		return x * p.x + y * p.y;
	}

	double dist()
	{
		return x*x + y*y;
	}
};


bool comp(point &p1, point &p2)
{
	if(p1.x!=p2.x)
		return p1.x<p2.x;
	return p1.y<p2.y;
}

bool cw(point &a, point &b, point &c)
{
	int area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	return area<0;
}

bool ccw(point &a, point &b, point &c)
{
	int area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	return area>0;
}

vector<point> convex_hull(vector<point> &v)
{
	if(v.size()==1)
		return v;

	sort(v.begin(), v.end(), comp);

	point p1=v[0], p2=v.back();

	vector<point> up, down;
	up.push_back(p1);
	down.push_back(p1);

	for(int i=1;i<v.size();i++)
	{
		if(i==v.size()-1 || cw(p1, v[i], p2))
		{
			while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], v[i]))
				up.pop_back();
			up.push_back(v[i]);
		}
		if(i==v.size()-1 || ccw(p1, v[i], p2))
		{
			while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], v[i]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	for(int i=down.size()-2;i>0;i--)
		up.push_back(down[i]);

	return up;
}

//Problem 1 (Polygon Congruence): http://codeforces.com/contest/1017/problem/E
//Solution 1: http://codeforces.com/contest/1017/submission/41401690

//Problem 2 and Solution: http://codeforces.com/gym/101606/submission/41541222
