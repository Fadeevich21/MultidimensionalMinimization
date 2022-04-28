#include "MethodGradientStepSplitting.hpp"
#include <cmath>
#include <iostream>
#include "..\utility\utility.hpp"

namespace opr
{

	bool MethodGradientStepSplitting::solve(const InfoMultidimensionalMinimization* info, const Point point) const
	{
		uint16_t countIteration = uint16_t();

		Point x0;
		Point x1 = point;
		do
		{
			countIteration++;

			x0 = x1;
			uint16_t i = uint16_t();
			x1 = x0 - info->alpha * powl(info->gamma, i) * info->grad(x0.x, x0.y);

			while (utility::almost_equal(info->func(x1.x, x1.y) - info->func(x0.x, x0.y) -
				    - info->betta * info->alpha * powl(info->gamma, i) * powl(info->grad(x0.x, x0.y).getLength(), 2), .0L) ||
				   info->func(x1.x, x1.y) - info->func(x0.x, x0.y) >
				   - info->betta * info->alpha * powl(info->gamma, i) * powl(info->grad(x0.x, x0.y).getLength(), 2))
			{
				i++;
				x1 = x0 - info->alpha * powl(info->gamma, i) * info->grad(x0.x, x0.y);


			}


		}
		while (fabsl(info->func(x0.x, x0.y) - info->func(x1.x, x1.y)) >= info->epsilon && countIteration < info->maxIteration);


		return countIteration < info->maxIteration;
	}

}