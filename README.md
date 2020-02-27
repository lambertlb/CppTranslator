# CppTranslator

This project uses [IlDecompiler](https://github.com/icsharpcode/ILSpy) to translate a subset of .Net IL Code to unmanaged C++.
I did this as an experimant to see if it could be done. I envision that this could be used to generate algorithms
that can be run in embedded spaces like Embedded controllers or Edge Controllers.
This would allow people unfamiliar with that space to program and debug using a language like C# then translate, compile,
load and run the code in embedded space. I have also provided a library (**DotNetLibrary**) in C++
that duplicates the supported subset of .Net so it can be linked to and run in embedded space.

Following is a list of supplied sub-projects and what they provide. See their README files for more details.

## C# code projects
* **Cpptranslator** This project does the translation of the IL code to C++ and validates the supported .Net subset.
* **CppTranslatorSupport** This project has support for simulating embedded features in .Net environment.
* **CppTranslatorFeatureTest** This project has a set of tests that ensure that the supported .Net subset runs the same everywhere.

## C++ code projects
* **DotNetLibrary** Supported subset of .Net written to C++.
* **DotNetLibrarySupport** Matches **CppTranslatorSupport** written in C++ to run in embedded space.
* **PlatformSupport** Project to interface between the embedded platform and .Net translated world.
* **DotnetLibraryTests** C++ Google tests for the **DotNetLibrary**
* **IntegrationTest** This project compiles the translated **CppTranslatorFeatureTest** so they can be run to ensure compatability in embedded space.

## How to build
### Windows
You can use Visual Studio 2017 or 2019 on the **CppTranslator.sln** solution to build everything. After doing a build you can run the CppTranslator to translate the
**CppTranslatorFeatureTest**. You can then build the **IntegrationTest** project to compile and link the tests.
### Linux
If you want to build the C# portions of the project you will need .Net and Visual Studio Code installed.
Add the CppTranslator folder as workspace then open terminal and do **dotnet build**. The C++ files will error out but thats ok.
To build the C++ portions you will need [Google Test](https://github.com/google/googletest) installed. Then do the following
```
mkdir build
cd build
cmake ..
make

```
For the **IntegrationTest** to build and run you will either have to run the **Cpptranslator** on the **CppTranslatorFeatureTest**
or copy in the translated C++ files from windows into the Debug folder before building.

## License

These projects are licensed under the [MIT](LICENSE.TXT) license.
