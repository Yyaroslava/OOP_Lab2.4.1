#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP Lab2.4.1/Matrix.h"
#include "../OOP Lab2.4.1/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest24
{
	TEST_CLASS(UnitTest24)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix A(
				new Matrix::MatrixColumn[N] {
					(new double[K] {1,1,1}),
					(new double[K] {1,2,1})
				}
			);
			Assert::AreEqual(Norm(A),3.);
		}
	};
}
