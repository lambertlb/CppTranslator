#include "pch.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

class TestClass
{
	Int32 field1;
public:
	TestClass() {
		field1 = 1;
	}
	~TestClass() {};
	Int32	GetField1() {
		return(field1);
	}
	void	SetField1(Int32 value) {
		field1 = value;
	}
};

TEST(DotnetTypeTests, Int32PointerTest) {
	PointerType<int32_t>	pointer1;
	int32_t			testInt = 1;
	pointer1 = &testInt;
	ASSERT_TRUE(pointer1 == 1);
	pointer1 += 1;
	ASSERT_TRUE(testInt == 2);
	ASSERT_TRUE(pointer1 == 2);
}

TEST(DotnetTypeTests, ClassPointerTest) {
	PointerType<TestClass>	pointer1;
	TestClass	testClass;
	pointer1 = &testClass;
	ASSERT_TRUE(pointer1->GetField1() == 1);
	ASSERT_TRUE(testClass.GetField1() == 1);
}

PointerType<TestClass>	PassingTest(PointerType<TestClass> pointerToTest) {
	pointerToTest->SetField1(pointerToTest->GetField1() + 1);
	return(pointerToTest);
}
TEST(DotnetTypeTests, PassPointerTest) {
	PointerType<TestClass>	pointer1;
	TestClass	testClass;
	pointer1 = &testClass;
	ASSERT_TRUE(pointer1->GetField1() == 1);
	pointer1 = PassingTest(pointer1);
	ASSERT_TRUE(pointer1->GetField1() == 2);
	ASSERT_TRUE(testClass.GetField1() == 2);
}
TEST(DotnetTypeTests, PassPointerTest2) {
	PointerType<TestClass>	pointer1;
	pointer1 = new TestClass();
	ASSERT_TRUE(pointer1->GetField1() == 1);
	pointer1 = PassingTest(pointer1);
	ASSERT_TRUE(pointer1->GetField1() == 2);
}
TEST(DotnetTypeTests, PassPointerTest3) {
	PointerType<TestClass>	pointer1;
	pointer1 = new TestClass();
	ASSERT_TRUE(pointer1->GetField1() == 1);
	PointerType<TestClass>	pointer2;
	pointer2 = pointer1;
	pointer2->SetField1(5);
	ASSERT_TRUE(pointer2->GetField1() == 5);
	ASSERT_TRUE(pointer1->GetField1() == 5);
}

TEST(DotnetTypeTests, Int32ValueTypeTest) {
	Int32 value = 3;
	ASSERT_TRUE(value == 3);
	value += 5;
	ASSERT_TRUE(value == 8);
	value = 1;
	ASSERT_TRUE(value == 1);
}
Int32	Int32PassByValue(Int32 value) {
	return(value + 3);
}
TEST(DotnetTypeTests, Int32PassValueTypeTest) {
	Int32 value = 3;
	ASSERT_TRUE(value == 3);
	Int32 value2 = Int32PassByValue(value);
	ASSERT_TRUE(value == 3);
	ASSERT_TRUE(value2 == 6);
}
Int32	Int32PassByRef(Int32& value) {
	return(value += 3);
}
TEST(DotnetTypeTests, Int32PassRefTypeTest) {
	Int32 value = 3;
	ASSERT_TRUE(value == 3);
	Int32 value2 = Int32PassByRef(value);
	ASSERT_TRUE(value == 6);
	ASSERT_TRUE(value2 == 6);
}
TEST(DotnetTypeTests, CreateInt32ArratTest) {
	PointerType<RawArray<Int32>> array = RawArray<Int32>::CreateArray(5);
	array->SetValue(22, 0);
	array->SetValue(33, 1);
	array->SetValue(44, 2);
	array->SetValue(55, 3);
	array->SetValue(66, 4);
	ASSERT_TRUE(array->GetValue(0) == 22);
	ASSERT_TRUE(array->GetValue(1) == 33);
	ASSERT_TRUE(array->GetValue(2) == 44);
	ASSERT_TRUE(array->GetValue(3) == 55);
	ASSERT_TRUE(array->GetValue(4) == 66);
}
TEST(DotnetTypeTests, DateTimeTest) {
	DateTime	time = DateTime::Now();
	ASSERT_TRUE(time == 0);
	DateTime	time1 = 1;
	ASSERT_TRUE(time1 == 1);
}
TEST(DotnetTypeTests, TimeSpanTest) {
	TimeSpan	time1 = 1;
	ASSERT_TRUE(time1 == 1);
}
