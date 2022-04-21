#include "pch.h"
#include "CppUnitTest.h"
#include "../3.3/3.3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 2;
			Student* s = new Student[N];
			Student* toCheck = new Student[1];

			s[0].lastname = "Varhomij";
			s[0].inizials = "M.D.";
			s[0].math = 2;
			s[0].phsic = 3;
			s[0].informatic = 4;
			s[0].history = 5;
			s[0].english = 3;

			s[1].lastname = "Stasyk";
			s[1].inizials = "V.V.";
			s[1].math = 5;
			s[1].phsic = 5;
			s[1].informatic = 5;
			s[1].history = 5;
			s[1].english = 5;

			Student* cheker = OnlyOneTwo(s, N);

			toCheck[0] = s[0];
			Assert::AreEqual(cheker[0].lastname, toCheck[0].lastname);

		}
	};
}
