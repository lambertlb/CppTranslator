# CppTranslator

This project uses [CSharp Decompiler](https://github.com/icsharpcode/ILSpy) to translate a subset of .Net IL Code to unmanaged C++.
I did this as an experiment to see if it could be done. I envision that this could be used to generate algorithms that can be run in embedded spaces like Embedded controllers or Edge Controllers.
This would allow people unfamiliar with that space to program and debug using a language like C# then translate, compile, load and run the code in embedded space. I have also provided a library (**DotNetLibrary**) in C++ that duplicates the supported subset of .Net so it can be linked to and run in embedded space.

Following is a list of supplied sub-projects and what they provide. See their README files for more details.

## C# code projects
* **CppTranslator** This project does the translation of the IL code to C++ and validates the supported .Net subset.
* **CppTranslatorLinux** This project is the same as **CppTranslator** but uses build events targeting Linux.
* **CppTranslatorSupport** This project has support for simulating embedded features in .Net environment.
* **CppTranslatorFeatureTest** This project has a set of tests that ensure that the supported .Net subset runs the same everywhere.
* **CppTranslatorFeatureTestLinux** This project is the same as **CppTranslatorFeatureTest** but uses build events targeting Linux.

## C++ code projects
* **DotNetLibrary** Supported subset of .Net written to C++.
* **DotNetLibrarySupport** Matches **CppTranslatorSupport** written in C++ to run in embedded space.
* **PlatformSupport** Project to interface between the embedded platform and .Net translated world.
* **DotnetLibraryTests** C++ Google tests for the **DotNetLibrary**
* **IntegrationTest** This project compiles the translated **CppTranslatorFeatureTest** so they can be run to ensure compatibility in embedded space.

## How to build
### Windows
You can use Visual Studio 2017 or 2019 on the **CppTranslator.sln** solution to build everything. After doing a build you can run the **IntegrationTest** project to run that test. You can also use Test Explorer to run the unit tests on the **DotNetLibrary** project.
### Linux
If you want to build the C# portions of the project you will need .Net and Visual Studio Code installed. I have both .Net Core 2.2 and Core 3.1 installed. Visual Studio Code will need to have C# and Package Manager add-ins installed also. Add the CppTranslator folder as workspace. If any alerts pop up for required items make sure to get them like ICSharp.Decompiler package. Then open terminal and do **dotnet build CppTranslatorLinux.sln**. This solution is nearly the same as **CppTranslator.sln** but uses some Linux specific projects instead. This is because it uses build events and commands for Linux that are different than Windows. Also The Linux Solution only builds the C# projects.

To build the C++ portions you will need [Google Test](https://github.com/google/googletest) installed. Then do the following
```
mkdir build
cd build
cmake ..
make

```
For the **IntegrationTest** to build and run you will either have to run the **CppTranslator** on the **CppTranslatorFeatureTest** or copy in the translated C++ files from windows into the Debug folder before building. If you build the C# projects using Visual Studio Code the translation would have happened in a post build event so you don't have to worry about it.

### Eclipse
You can also build the C++ projects using Eclipse CDT. You just need to make sure it has the CMake4Eclipse plug-in installed 
(I believe it comes by default but not sure).
Then in eclipse do the following
1.  Create a new C++ Project (not C/C++ Project).
2.  Name the project CppTranslator
3.  Un-check the "Use Default Location" Check Box
4.  Hit the Browse... button and select the CppTranslator folder for the location
3.  Choose "Empty Project"
6.  Hit finish button.

Now we need to make Eclipse use CMake for the project as follows.
1.  Open the project properties Project->Properties.
2.  Go to dialog C/C++ Build->Tool Chain Editor
3.  In the "Current Builder" drop down select "CMake Builder".
4.  Apply and Close

Everything should now build in eclipse and you can use that for editing and debugging.

## License

These projects are licensed under the [MIT](LICENSE.TXT) license. I chose this because a lot of the code in **DotNetLibrary** is nearly identical to the Open Source code in .Net framework provided by Microsoft so i used the same license they did [.Net Runtime](https://github.com/dotnet/runtime.git).
