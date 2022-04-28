#pragma once

#include "..\InfoMultidimensionalMinimization\InfoMultidimensionalMinimization.hpp"
#include "..\MethodMultidimensionalMinimization\MethodMultidimensionalMinimization.hpp"
#include "..\utility\utility.hpp"

namespace opr
{

	class SolveMultidimensionalMinimization
	{
	private:
		InfoMultidimensionalMinimization* info_;
		MethodMultidimensionalMinimization* method_;

	public:
		SolveMultidimensionalMinimization(InfoMultidimensionalMinimization* const info, MethodMultidimensionalMinimization* const method);
		~SolveMultidimensionalMinimization();
		
		void setInfo(InfoMultidimensionalMinimization *const info);
		void setMethod(MethodMultidimensionalMinimization *const method);

		utility::BaseType solve(const Point point) const;
	};

}