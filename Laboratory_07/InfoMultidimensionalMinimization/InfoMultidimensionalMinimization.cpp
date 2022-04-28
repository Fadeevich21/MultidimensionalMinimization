#include "InfoMultidimensionalMinimization.hpp"
#include <cmath>

namespace opr
{

	Point::Point(const utility::BaseType x_, const utility::BaseType y_)
		: pair(x_, y_)
	{
	}

	Point Point::operator=(const Point& point)
	{
		this->x = point.x;
		this->y = point.y;

		return *this;
	}

	utility::BaseType Point::getLength() const
	{
		return sqrtl(powl(this->x, 2) + powl(this->y, 2));
	}

	Point::~Point()
	{
	}



	Point operator-(const Point& point1, const Point& point2)
	{
		return Point(point1.x - point2.x, point1.y - point2.y);
	}

	Point operator*(const Point& point, const utility::BaseType& value)
	{
		return Point(point.x * value, point.y * value);
	}

	Point operator*(const utility::BaseType& value, const Point& point)
	{
		return point * value;
	}

	InfoMultidimensionalMinimization::InfoMultidimensionalMinimization(const Function func_, const Gradient grad_, const utility::BaseType epsilon_, const uint16_t maxIteration_, const utility::BaseType alpha_, const utility::BaseType betta_, const utility::BaseType gamma_)
		:func(func_), grad(grad_), epsilon(epsilon_), maxIteration(maxIteration_), alpha(alpha_), betta(betta_), gamma(gamma_)
	{
	}

	InfoMultidimensionalMinimization::~InfoMultidimensionalMinimization()
	{
	}


}