#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1it.cpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountStars_NoStars)
		{
			char str[] = "Hello world!";
			Assert::AreEqual(0, CountStars(str));
		}

		TEST_METHOD(TestCountStars_WithStars)
		{
			char str[] = "abc***def***ghi";
			Assert::AreEqual(2, CountStars(str));
		}

		TEST_METHOD(TestReplaceStars_NoStars)
		{
			char str[] = "Hello world!";
			char expected[] = "Hello world!";
			char* result = ReplaceStars(str);
			Assert::AreEqual(expected, result);
			delete[] result;
		}

		TEST_METHOD(TestReplaceStars_WithStars)
		{
			char str[] = "abc***def";
			char expected[] = "abc!!def";
			char* result = ReplaceStars(str);
			Assert::AreEqual(expected, result);
			delete[] result;
		}

		TEST_METHOD(TestReplaceStars_MultipleGroups)
		{
			char str[] = "abc***def***ghi";
			char expected[] = "abc!!def!!ghi";
			char* result = ReplaceStars(str);
			Assert::AreEqual(expected, result);
			delete[] result;
		}
	};
}
