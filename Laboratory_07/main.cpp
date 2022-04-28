// Решение задачи многомерной минимизации

#include <iostream>
#include "SolveMultidimensionalMinimization/SolveMultidimensionalMinimization.hpp"
#include "MethodGradientStepSplitting/MethodGradientStepSplitting.hpp"
#include "utility/utility.hpp"

using namespace std;
using namespace opr;

void test();

int main()
{
	cout << "Hello, World!\n\n";

	test();

	return 0;
}

#define WRITE_TEST_NAME(nameTest) cout << "Test name: " << nameTest << "\n";
#define WRITE_STATUS(status) cout << "Status: " << (status ? "true" : "false") << "\n";

void test_example()
{
	WRITE_TEST_NAME("test_example");

	Function func = [](const utility::BaseType x1, const utility::BaseType x2)
	{
		return powl(x1, 2) - 2 * x1 + 2 * powl(x2, 2) + 8 * x2 + 4;
	};

	Gradient grad = [](const utility::BaseType x1, const utility::BaseType x2)
	{
		return Point(2 * x1 - 2, 4 * x2 + 8);
	};

	utility::BaseType epsilon = 0.01L;
	uint16_t maxIteration = 1000;
	utility::BaseType alpha = .9L;
	utility::BaseType betta = 0.5L;
	utility::BaseType gamma = 0.5L;

	InfoMultidimensionalMinimization* info = new InfoMultidimensionalMinimization(func, grad, epsilon, maxIteration, alpha, betta, gamma);
	SolveMultidimensionalMinimization solver(info, new MethodGradientStepSplitting());
	bool checkGetResult = solver.solve(Point(0, 0));
	WRITE_STATUS(checkGetResult);
	cout << '\n';
}

void test_variant10()
{
	WRITE_TEST_NAME("test_variant10");

	Function func = [](const utility::BaseType x1, const utility::BaseType x2)
	{
		return powl(x1, 2) + powl(x2, 2) + 3 * x2 - 3 * x1 + 8;
	};

	Gradient grad = [](const utility::BaseType x1, const utility::BaseType x2)
	{
		return Point(2 * x1 - 3, 2 * x2 + 3);
	};

	utility::BaseType epsilon = 0.01L;
	uint16_t maxIteration = 1000;
	utility::BaseType alpha = 1.L;
	utility::BaseType betta = 0.5L;
	utility::BaseType gamma = 0.5L;

	InfoMultidimensionalMinimization* info = new InfoMultidimensionalMinimization(func, grad, epsilon, maxIteration, alpha, betta, gamma);
	SolveMultidimensionalMinimization solver(info, new MethodGradientStepSplitting());
	bool checkGetResult = solver.solve(Point(0, 0));
	WRITE_STATUS(checkGetResult);
	cout << '\n';
}

void test_variant18()
{
	WRITE_TEST_NAME("test_variant18");

	Function func = [](const utility::BaseType x1, const utility::BaseType x2)
	{
		return 2 * powl(x1, 2) + powl(x2, 2) - 4 * x1 - 8 * x2 + 2;
	};

	Gradient grad = [](const utility::BaseType x1, const utility::BaseType x2)
	{
		return Point(4 * x1 - 4, 2 * x2 - 8);
	};

	utility::BaseType epsilon = 0.001L;
	uint16_t maxIteration = 30;
	utility::BaseType alpha = 1.L;
	utility::BaseType betta = 0.5L;
	utility::BaseType gamma = 0.5L;

	InfoMultidimensionalMinimization* info = new InfoMultidimensionalMinimization(func, grad, epsilon, maxIteration, alpha, betta, gamma);
	SolveMultidimensionalMinimization solver(info, new MethodGradientStepSplitting());
	bool checkGetResult = solver.solve(Point(0, 0));
	WRITE_STATUS(checkGetResult);
	cout << '\n';
}

void test()
{
	test_example();
	test_variant10();
	test_variant18();
}