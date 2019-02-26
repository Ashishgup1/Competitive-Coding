/*Returns pair of indices of any two intersecting line segments if there exist intersecting line segments,
and (-1, -1) if no line segments intersect.*/

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

	Point operator+ (const Point& P) const
	{
		return Point(x + P.x, y + P.y);
	}

	Point operator- (const Point& P) const
	{
		return Point(x - P.x, y - P.y);
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

	Segment(double &x1, double &y1, double &x2, double &y2, int _idx)
	{
		P = Point(x1, y1);
		Q = Point(x2, y2);
		idx = _idx;
	}

	Segment(Point &_P, Point &_Q, int _idx)
	{
		P = _P, Q = _Q, idx = _idx;
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
		return type > e.type;
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
	vector<Event> events;
	for(int i=0;i<n;i++)
	{
		events.push_back(Event(min(v[i].P.x, v[i].Q.x), +1, i));
		events.push_back(Event(max(v[i].P.x, v[i].Q.x), -1, i));
	}
	sort(events.begin(), events.end());
	s.clear();
	where.resize(n);
	for(int i=0;i<events.size();i++)
	{
		int idx = events[i].idx;
		if(events[i].type == +1)
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
