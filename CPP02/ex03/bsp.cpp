#include "Point.hpp"

static Fixed crossProduct( Point const &v1, Point const &v2, Point const &p ) {
	return (v2.getX() - v1.getX()) * (p.getY() - v1.getY()) - (v2.getY() - v1.getY()) * (p.getX() - v1.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed const d1 = crossProduct(a, b, point);
	Fixed const d2 = crossProduct(b, c, point);
	Fixed const d3 = crossProduct(c, a, point);

	Fixed const zero(0);

	if (d1 == zero || d2 == zero || d3 == zero)
		return false;

	bool const all_pos = (d1 > zero) && (d2 > zero) && (d3 > zero);
	bool const all_neg = (d1 < zero) && (d2 < zero) && (d3 < zero);

	return all_pos || all_neg;
}
