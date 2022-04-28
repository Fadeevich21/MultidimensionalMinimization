#pragma once

#include "..\InfoMultidimensionalMinimization\InfoMultidimensionalMinimization.hpp"
#include "..\utility\utility.hpp"

namespace opr
{

	class MethodMultidimensionalMinimization
	{
	public:
		MethodMultidimensionalMinimization() = default;
		~MethodMultidimensionalMinimization();

		virtual bool solve(const InfoMultidimensionalMinimization* info, const Point point) const = 0;
	};

}