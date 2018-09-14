struct Segment {
	typedef long double T;
	PT p1, p2;
	T a, b, c;

	Segment() {}

	Segment(PT st, PT en) {
		p1 = st, p2 = en;
		a = -(st.y - en.y);
		b = st.x - en.x;
		c = a * en.x + b * en.y;
	}

	T plug(T x, T y) {
		// plug >= 0 is to the right
		return a * x + b * y - c;
	}

	T plug(PT p) {
		return plug(p.x, p.y);
	}

	bool inLine(PT p) { return (p - p1) % (p2 - p1) == 0; }
	bool inSegment(PT p) {
		return inLine(p) && (p1 - p2) * (p - p2) >= 0 && (p2 - p1) * (p - p1) >= 0;
	}

	PT lineIntersection(Segment s) {
		long double A = a, B = b, C = c;
		long double D = s.a, E = s.b, F = s.c;
		long double x = (long double) C * E - (long double) B * F;
		long double y = (long double) A * F - (long double) C * D;
		long double tmp = (long double) A * E - (long double) B * D;
		x /= tmp;
		y /= tmp;
		return PT(x, y);
	}
};