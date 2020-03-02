# CppTranslator
This project uses [CSharp Decompiler](https://github.com/icsharpcode/ILSpy) to translate IL Assemblies into C++ source files.
It works on a limited subset of the .Net Framwork. ValidTypes.xml has a list of the Classes and Methods supported by
the **DotNetLibray** that contains a C++ implementation for them.

This tool takes a single command line argument which is the path to the .Net assembly to translate. For example
```
dotnet CppTranslator.dll ./Debug/CppTranslatorFeatureTest.dll
```

## Output
The output will be placed in a subdirectory in the same location called **generated**.

## How it works
This tool uses  [CSharp Decompiler](https://github.com/icsharpcode/ILSpy) to build a syntax tree from the assembly.
It then does three passes over the tree using different visitors.
1. Pass 1  
    In the first pass the visitor extracts all the forward reference and enumerations. This is to help solve any
    circular reference issues in the other header files. The output is placed in a file called **TranslatedProtos.h**
    and will contain stuff like the following.
    **Notice** that namespaces in .Net have underscore NS appended to them to avoid collisions between
    namespace names and class names. **Notice** all names starting with lowercase letters have x_ prepended to them
    to avoid collisions with C++ keywords like _typedef_. **Notice** enumeration values have underscore _Enumeration Name_
    appended to them to make them unique.
    
```
namespace CppTranslatorFeatureTest_NS
{
    class ArrayTest;
    class TestAbstract;
    enum TestNameEnu
    {
        x_friend_TestNameEnu,
        x_enemy_TestNameEnu
    };

    class Typedef;
    class MiscTest;
}

```
2. Pass2  
    In the second pass a header file is created that has all the class definitions in it.
    This will contain namepaces, classes and their fields and methods. The name of the file will be
    **TranslatedHeader.h**. Following is a small example of what it could contain.
```
#pragma once
#include "TranslatedProtos.h"
namespace CppTranslatorFeatureTest_NS
{
    struct StructTest : public Object
    {
        Int32 x_data;
        StructTest(Int32 x_i);
        static StructTest op_Addition(StructTest x_ts,Int32 x_newData);
        static StructTest op_BitwiseAnd(StructTest x_ts,Int32 x_newData);
        StructTest(){};
    };
    class BufferTest : public Object
    {
        public:
        FeatureTest* x_featureTest;
        BufferTest(FeatureTest* x_featureTest);
        void Run();
    };
}
```
3. Pass2  
    In the third pass a code file is created that has all the static variables and method code in it called **Translated.cpp**.
    Following is a small example
```
#include "TranslatedHeader.h"
namespace CppTranslatorFeatureTest_NS
{
    void ArrayTest::PropertyTests()
    {
IL_0000:
        this->x_featureTest->set_FailureMessage((new String(L"\tFailed Array Property Test")));
        this->x_featureTest->Send((new String(L"Array Property Test")));
        this->x_featureTest->AssertTrue((Boolean)(((this->x_uint321DArray->get_Length()) == 10)));
        this->x_featureTest->AssertTrue((Boolean)(((this->x_uint321DArray->get_Rank()) == 1)));
        this->x_featureTest->AssertTrue((Boolean)(((this->x_int323DArray->get_Rank()) == 3)));
        return;
    }
}
```

## Error Handling
If any errors occur like exceptions or violations of the .Net subset defined in ValidTypes.xml then a **Translated.err**
file will be created and all errors will get appended to it.
