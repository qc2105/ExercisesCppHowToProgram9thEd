#include "pch.h"
#include "../9.27/InputProcessor.h"

TEST(TestInputProcessor, TestGetInts)
{
	InputProcessor ip("1,2;2,3;5,1;");
	std::vector<std::vector<size_t> > expectedInts = { {1,2}, {2,3}, {5,1} };

	std::vector<std::vector<size_t> > realInts;
	ip.getInts(realInts);

	EXPECT_EQ(expectedInts, realInts);
}