#pragma once

#include "..\MethodMultidimensionalMinimization\MethodMultidimensionalMinimization.hpp"
#include "..\InfoMultidimensionalMinimization\InfoMultidimensionalMinimization.hpp"
#include "..\utility\utility.hpp"

namespace opr
{

	class MethodGradientStepSplitting : public MethodMultidimensionalMinimization
	{
	public:
		bool solve(const InfoMultidimensionalMinimization *info, const Point point) const;

	};

}