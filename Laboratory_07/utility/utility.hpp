#pragma once

#include <cmath>
#include <limits>
#include <algorithm>

namespace utility
{

	using BaseType = long double;
	
	template<class T>
	typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
		almost_equal(T x, T y)
	{
		static constexpr T eps = 1e-8;
		return fabsl(x - y) < eps;
	}
}