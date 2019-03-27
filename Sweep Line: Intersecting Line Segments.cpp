/*Returns pair of indices of any two intersecting line segments if there exist intersecting line segments,
and (-1, -1) if no line segments intersect.*/

const double EPS = 1e-15;
 
struct Point
{
	double x, y;
 
	Point() 
	{
		x = 0, y = 0;
	}
 
	Point(double _x, double _y)
	{
		x = _x, y = _y;
	}
 	
 	bool between(Point &P, Point &Q)
 	{
 		bool checkX = x < max(P.x, Q.x) + EPS && x + EPS > min(P.x, Q.x);
 		bool checkY = y < max(P.y, Q.y) + EPS && y + EPS > min(P.y, Q.y);
 		return checkX && checkY;
 	}

	Point operator+ (const Point& P) const
	{
		return Point(x + P.x, y + P.y);
	}
 
	Point operator- (const Point& P) const
	{
		return Point(x - P.x, y - P.y);
	}

	bool operator< (Point &o)
	{
		if(abs(x - o.x) > EPS)
			return x < o.x;
		return y < o.y;
	}
};

struct Line
{
	double a, b, c;

	Line(Point P, Point Q)
	{
		if(abs(P.x - Q.x) < EPS)
		{
			a = 1;
			b = 0;
			c = -P.x;
		}
		else
		{
			a = (P.y - Q.y) / (Q.x - P.x);
			b = 1.0;
			c = -(a * P.x + P.y);
		}
	}

	bool parallel(Line l)
	{
		return abs(a - l.a) < EPS && abs(b - l.b) < EPS;
	}

	Point intersect(Line l)
	{
		if(parallel(l))
			return Point();	
		double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
		double y;
		if(abs(b) < EPS)
			y = -l.a * x - l.c;
		else
			y = -a * x - c;
	}
};


struct Segment
{
	Point P, Q;
	int idx;
 
	Segment()
	{
		idx = -1;
	}
 
	Segment(double x1, double y1, double x2, double y2, int _idx)
	{
		P = Point(x1, y1);
		Q = Point(x2, y2);
		idx = _idx;
	}
 
	Segment(Point _P, Point _Q, int _idx)
	{
		P = _P, Q = _Q, idx = _idx;
	}
 	
 	Point intersect(Segment ls)
 	{	
 		Line l1 = Line(P, Q);
 		Line l2 = Line(ls.P, ls.Q);
 		if(l1.parallel(l2))
 			return Point();
 		Point c = l1.intersect(l2);
 		return c.between(P, Q) && c.between(ls.P, ls.Q) ? c : Point();
 	}

	double get_y(double &x) const
	{
		if(abs(P.x - Q.x)<EPS)
			return P.y;
		return P.y + (Q.y - P.y) * (x - P.x) / (Q.x - P.x);
	}
};
 
struct Event
{
	double x;
	int type, idx; //type - 1: Add, -1: Remove
 
	Event() {}
 
	Event(double x, int type, int idx) : x(x), type(type), idx(idx) {}
 
	bool operator< (const Event &e) const
	{
		if(abs(x - e.x) > EPS)
			return x < e.x;
		if(type != e.type)
			return type > e.type;
		return idx < e.idx;
	}
};
 
int vec(const Point &a, const Point &b, const Point &c)
{
	double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if(abs(s) < EPS)
		return 0;
	return s > 0 ? 1 : -1;
}
 
bool intersect1D(double l1, double r1, double l2, double r2)
{
	if(l1 > r1)
		swap(l1, r1);
	if(l2 > r2)
		swap(l2, r2);
	return max(l1, l2) <= min(r1, r2) + EPS;
}
 
bool intersect(const Segment &a, const Segment &b)
{
	return 	intersect1D(a.P.x, a.Q.x, b.P.x, b.Q.x) &&
			intersect1D(a.P.y, a.Q.y, b.P.y, b.Q.y) &&
			vec(a.P, a.Q, b.P) * vec(a.P, a.Q, b.Q) <= 0 &&
			vec(b.P, b.Q, a.P) * vec(b.P, b.Q, a.Q) <=0;
}
 
bool operator<(const Segment& a, const Segment& b)
{
	double x = max(min(a.P.x, a.Q.x), min(b.P.x, b.Q.x));
	return a.get_y(x) < b.get_y(x) - EPS;
}
 
set<Segment> s;
vector<set<Segment>::iterator > where;
 
set<Segment>::iterator prev(set<Segment>::iterator it) 
{
	return it == s.begin() ? s.end() : --it;
}
 
set<Segment>::iterator next(set<Segment>::iterator it) 
{
	return ++it;
}
 
pair<int, int> solve(const vector<Segment> &v)
{
	int n = v.size();
	set<Event> events;
	for(int i=0;i<n;i++)
	{
		events.insert(Event(min(v[i].P.x, v[i].Q.x), +1, i));
		events.insert(Event(max(v[i].P.x, v[i].Q.x), -1, i));
	}
	s.clear();
	where.resize(n);
	while(events.size())
	{
		auto E = *events.begin();
		events.erase(E);
		int idx = E.idx;
		if(E.type == +1)
		{
			set<Segment>::iterator nxt = s.lower_bound(v[idx]), prv = prev(nxt);
			if(nxt != s.end() && intersect(*nxt, v[idx]))
				return make_pair(nxt->idx, v[idx].idx);
			if(prv != s.end() && intersect(*prv, v[idx]))
				return make_pair(prv->idx, v[idx].idx);
			where[idx] = s.insert(nxt, v[idx]);
		}
		else
		{
			set<Segment>::iterator nxt = next(where[idx]), prv = prev(where[idx]);
			if(nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
				return make_pair(prv->idx, nxt->idx);
			s.erase(where[idx]);
		}
	}
	return make_pair(-1, -1);
}

//Problem 1: http://acm.timus.ru/problem.aspx?space=1&num=1469
//Solution 1: http://p.ip.fi/hRY9
