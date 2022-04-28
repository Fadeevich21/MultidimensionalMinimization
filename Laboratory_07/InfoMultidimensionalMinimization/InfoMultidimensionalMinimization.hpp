#pragma once

#include "..\utility\utility.hpp"

#include <utility>

namespace opr
{

	struct Point : protected std::pair<utility::BaseType, utility::BaseType>
	{
		utility::BaseType& x = first;
		utility::BaseType& y = second;

		Point() = default;
		Point(const utility::BaseType x_, const utility::BaseType y_);

		friend Point operator-(const Point& point1, const Point& point2);
		friend Point operator*(const Point& point, const utility::BaseType& value);
		friend Point operator*(const utility::BaseType& value, const Point& point);
		Point operator=(const Point& point);

		utility::BaseType getLength() const;

		~Point();
	};


	using Function = utility::BaseType(*) (const utility::BaseType arg1, const utility::BaseType arg2);
	using Gradient = Point(*) (const utility::BaseType arg1, const utility::BaseType arg2);

	class InfoMultidimensionalMinimization
	{
	public:
		Function func;
		Gradient grad;
		utility::BaseType epsilon;

		utility::BaseType alpha;
		utility::BaseType betta;
		utility::BaseType gamma;

		uint16_t maxIteration;

	public:
		InfoMultidimensionalMinimization() = default;
		InfoMultidimensionalMinimization(const Function func_, const Gradient grad_,
										 const utility::BaseType epsilon_, const uint16_t maxIteration_,
										 const utility::BaseType alpha_, const utility::BaseType betta_, const utility::BaseType gamma_);
		~InfoMultidimensionalMinimization();
	};

}