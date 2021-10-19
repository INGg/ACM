// Arup Guha
// 8/20/2020
// Solution to 2020 UCF Locals Round 1A Problem: Gone Fishing

import java.util.*;

public class fish {

	public static int n;
	public static double radius;
	public static pt[] pts;
	
	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		radius = stdin.nextDouble();
		n = stdin.nextInt();
		
		// Read in the points.
		pts = new pt[n];
		for (int i=0; i<n; i++) {
			int x = stdin.nextInt();
			int y = stdin.nextInt();
			pts[i] = new pt(x, y);
		}
		
		// Ta da!
		System.out.println(solve());
	}
	
	public static int solve() {

		// We can always do 1.
		int res = 1;
				
		// Now, try all pairs of points in a single circle.
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				
				// Go to the midpoint.
				pt mid = pts[i].midpt(pts[j]);
				
				// See how far we can move along the perpendicular bisector.
				double dsqr = radius*radius - mid.distsq(pts[i]);
				if (dsqr < 0) continue;
				double move = Math.sqrt(dsqr);
				
				// Get both directions of movement from here.
				pt dir = pts[j].sub(pts[i]).getUnitPerpDir();
				dir = dir.multiply(move);
				pt negdir = dir.negative();
				
				// Calculate both possible centers that are exactly radius from the 2 pts.
				pt c1 = mid.add(dir);
				pt c2 = mid.add(negdir);
				
				// Test both.
				res = Math.max(res, test(c1));
				res = Math.max(res, test(c2));
				
			} // end j
		} // end i
		
		// Ta da!
		return res;
	}
	
	// Returns number of pts within net if we use center.
	public static int test(pt center) {
		int res = 0;
		for (int i=0; i<n; i++)
			if (center.dist(pts[i]) < radius + 1e-6)
				res++;
		return res;
	}
}

class pt {
	
	public double x;
	public double y;
	
	public pt(double myx, double myy) {
		x = myx;
		y = myy;
	}
	
	public pt midpt(pt other) {
		return new pt((x+other.x)/2, (y+other.y)/2);
	}
	
	public pt sub(pt other) {
		return new pt(x-other.x, y-other.y);
	}
	
	public pt add(pt other) {
		return new pt(x+other.x , y+other.y);
	}
	
	public pt multiply(double c) {
		return new pt(c*x, c*y);
	}
	
	public pt negative() {
		return new pt(-x, -y);
	}
	
	// Returns a unit vector that is perpendicular to this one.
	public pt getUnitPerpDir() {
		double d = Math.sqrt(x*x+y*y);
		return new pt(y/d, -x/d);
	}	
	
	public double dist(pt other) {
		return Math.sqrt( (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) );
	}
	
	public double distsq(pt other) {
		return (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) ;
	}	
}
