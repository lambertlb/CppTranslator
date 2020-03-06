# Integration Test
The purpose of this project is to take the translated files from the **CppTranslatorFeatureTest** project and compile them
so they can be run. All tests should pass and validate that the test and the emulation library are functioning as designed.

## Building
To build this you must have first translated the **CppTranslatorFeatureTest** using the **CppTranslator**. The **CppTranslatorFeatureTest**
project will automatically do the translation in a build event but you can manually do it as follows.
```
dotnet ./Debug/CppTranslator.dll ./Debug/CppTranslatorFeatureTest.dll
```
