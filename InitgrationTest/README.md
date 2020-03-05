# Integration Test
The purpose of this project is to take the translated files from the **CppTranslatorFeatureTest** project and compile them
so they can be run. All tests should pass and validate that the test and the emulation library are functioning as designed.

## Building
To build this you must have first translated the **CppTranslatorFeatureTest** using the **CppTranslator**. If building on
Windows using Visual Studio this will happen automatically as part of the PreBuild Event. On Linux you will have to do it
manually. Following is an example on Linux
```
dotnet ./Debug/CppTranslator.dll ./Debug/CppTranslatorFeatureTest.dll
```
