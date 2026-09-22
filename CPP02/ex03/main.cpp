#include <iostream>
#include "Point.hpp"

static void testPoint( std::string const &testName, Point const &a, Point const &b, Point const &c, Point const &p, bool expected ) {
	bool result = bsp(a, b, c, p);
	std::cout << testName << ": Point(" << p.getX() << ", " << p.getY() << ") -> "
			  << (result ? "INSIDE" : "OUTSIDE")
			  << " | Expected: " << (expected ? "INSIDE" : "OUTSIDE")
			  << " -> " << (result == expected ? "PASS" : "FAIL")
			  << std::endl;
}

int main( void ) {
	std::cout << "--- Triangle 1: Counter-Clockwise (0,0), (10,0), (0,10) ---" << std::endl;
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	// Inside points
	testPoint("Test 1 (Strictly inside)", a, b, c, Point(2.0f, 2.0f), true);
	testPoint("Test 2 (Strictly inside)", a, b, c, Point(1.0f, 1.0f), true);
	testPoint("Test 3 (Strictly inside near edge)", a, b, c, Point(4.9f, 4.9f), true);

	// Outside points
	testPoint("Test 4 (Outside top-right)", a, b, c, Point(10.0f, 10.0f), false);
	testPoint("Test 5 (Outside negative coords)", a, b, c, Point(-1.0f, -1.0f), false);
	testPoint("Test 6 (Outside just beyond hypotenuse)", a, b, c, Point(5.1f, 5.1f), false);

	// On edges
	testPoint("Test 7 (On edge AB)", a, b, c, Point(5.0f, 0.0f), false);
	testPoint("Test 8 (On edge BC / hypotenuse)", a, b, c, Point(5.0f, 5.0f), false);
	testPoint("Test 9 (On edge CA)", a, b, c, Point(0.0f, 5.0f), false);

	// On vertices
	testPoint("Test 10 (On vertex A)", a, b, c, Point(0.0f, 0.0f), false);
	testPoint("Test 11 (On vertex B)", a, b, c, Point(10.0f, 0.0f), false);
	testPoint("Test 12 (On vertex C)", a, b, c, Point(0.0f, 10.0f), false);

	std::cout << "\n--- Triangle 2: Clockwise (0,0), (0,10), (10,0) ---" << std::endl;
	Point cw_a(0.0f, 0.0f);
	Point cw_b(0.0f, 10.0f);
	Point cw_c(10.0f, 0.0f);

	testPoint("Test 13 (CW strictly inside)", cw_a, cw_b, cw_c, Point(2.0f, 2.0f), true);
	testPoint("Test 14 (CW strictly outside)", cw_a, cw_b, cw_c, Point(10.0f, 10.0f), false);
	testPoint("Test 15 (CW on edge)", cw_a, cw_b, cw_c, Point(5.0f, 0.0f), false);

	return 0;
}
