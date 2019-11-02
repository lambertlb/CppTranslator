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
	ASSERT_TRUE(value.getValue()== 8);
	value = 1;
	ASSERT_TRUE(value == 1);
}
