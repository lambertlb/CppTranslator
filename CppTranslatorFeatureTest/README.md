# CppTranslator Feature Tests
The purpose of this project is to test all classes, methods and operators in the .Net framework that are supported by the
CPP translator. The rationale for this project is that if all features pass the tests by running them in native
.Net and then also passing them in the translated C++ then the **DotNetLibrary** and the translator itself are working correctly.
A post build event will trigger to translate these tests.
The **IntegrationTest** project is setup to compile and run the tests that are translated from this project.

Unit tests along are not good enough to ensure that the **DotNetLibrary** and **CppTranslator** are correct.
There might be some bad assumptions made about what the Library should do versus how the Native .Net actually does it.
By using these translated tests no assumptions need be made.
