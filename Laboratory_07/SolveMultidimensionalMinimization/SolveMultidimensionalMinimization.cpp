#include "SolveMultidimensionalMinimization.hpp"

namespace opr
{

	SolveMultidimensionalMinimization::SolveMultidimensionalMinimization(InfoMultidimensionalMinimization* const info, MethodMultidimensionalMinimization* const method)
		: info_(info), method_(method)
	{
	}

	SolveMultidimensionalMinimization::~SolveMultidimensionalMinimization()
	{
		delete this->info_;
		delete this->method_;
	}

	void SolveMultidimensionalMinimization::setInfo(InfoMultidimensionalMinimization* const info)
	{
		delete this->info_;
		this->info_ = info;
	}

	void SolveMultidimensionalMinimization::setMethod(MethodMultidimensionalMinimization* const method)
	{
		delete this->method_;
		this->method_ = method;
	}

	utility::BaseType SolveMultidimensionalMinimization::solve(const Point point) const
	{
		return this->method_->solve(this->info_, point);
	}

}