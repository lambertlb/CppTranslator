# DotNet Library
This project contains a subset of the .Net framework written in C++. What types and methods it contains are enumerated
in the ValidType.xml file in the **CppTranslator** project. All types inherit from Object. This deviates from the way .Net
does it. This is so value types like int and double can also be used as Object types if they are Newed. If not Newed they can be
passed by value.

## Primitive Types
In the _DotnetTypes.h_ file there are definitions to translate from C++ types to .Net types.
```
typedef bool Boolean;
typedef wchar_t Char;
typedef uint8_t Byte;
typedef int8_t SByte;
typedef int16_t Int16;
typedef uint16_t UInt16;
typedef int32_t Int32;
typedef uint32_t UInt32;
typedef int64_t Int64;
typedef uint64_t UInt64;
typedef float Single;
typedef Single Float;
typedef double Double;
```

## DateTime and TimeSpan
There are two structures that define DateTime and TimeSpan as primitive types.
```
struct DateTime
{
    UInt64 value;
    DateTime(UInt64 ticks);
    DateTime();
    DateTime(const DateTime& val);
    DateTime(Int32 year, Int32 month, Int32 day, Int32 hour = 0, Int32 minute = 0, Int32 second = 0, Int32 millisecond = 0);
};
struct TimeSpan
{
    Int64 value;
    TimeSpan() { value = 0; }
    TimeSpan(const Int64 value2) { value = value2; }
    TimeSpan(const TimeSpan& value2) { value = value2.value; }
    TimeSpan(Int32 hours, Int32 minutes, Int32 seconds);
    TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds = 0);
};
```
## Value Types
The project contains classes to wrap each primitive type so that methods can be called on them.
These Value Type classes derive from Object so they can also serve as Boxing classes.
Following is a small example to show an integer being used as both a Value Type and as an Object type.
```
Int32   primitiveInteger = 3;
String* integerAsString = Int32Value(primitiveInteger).ToString();
Object* integerBox = new Int32Value(primitiveInteger);
String* integerAsString2 = integerBox->ToString();
```

## UnBoxing
.Net supports a large infrastructure for doing type conversions. This subset of the .Net frameworks does not
support that. Instead is has a very simple conversion strategy. The Object class supports a series of
virtual methods for handling primitive conversions as follows.
```
virtual Boolean   get_AsBoolean();
virtual Char      get_AsChar();
virtual Byte      get_AsByte();
virtual SByte     get_AsSByte();
virtual Int16     get_AsInt16();
virtual UInt16    get_AsUInt16();
virtual Int32     get_AsInt32();
virtual UInt32    get_AsUInt32();
virtual Int64     get_AsInt64();
virtual UInt64    get_AsUInt64();
virtual Single    get_AsSingle();
virtual Double    get_AsDouble();
virtual DateTime  get_AsDateTime();
virtual TimeSpan  get_AsTimeSpan();
```

So to un-box a value the appropriate method just needs to be called.
```
Int32   primitiveInteger = 3;
Object* integerBox = new Int32Value(primitiveInteger);
Int32   unBoxedInteger = integerBox->get_AsInt32();
```
 
This scheme supports some primitive conversion such as Int32 to Double but in cases that can't be converted
 an InvalidCastException is thrown. This isn't too big a worry because the C# compiler would have
give an error or warning so that would probably been fixed before the IL was transformed to C++.

## Arrays
This project supports up to three dimensional arrays. All arrays no matter the type are wrapped by the **Array** class.
This array class can also wrap native arrays in the target platform as long as the numbers in the array
are ordered the same way .Net orders them. Following is an example of a wrapped Native array so that
translated .Net code can use it.
```
Int32   arrayData[]{ 1,2,3,4 }; // native array
Array* wrappedArray = new Array(arrayData, Int32Type, 4); // wrapped array
```
This technique is useful in the **DotNetLibrarySupport** project for interfacing the .Net world to data in
the target environment. Read the README files in **DotNetLibrarySupport** and **CppTranslatorSupport** for
more details.

## Supported Classes
Following is a list of classes that this project supports. See the ValidType.xml file in the **CppTranslator** project for
information about exactly which methods within the classes as supported.
```
System.Array
System.BitConverter
System.Buffer
System.CharEnumerator
System.Math
System.Object
System.Text.StringBuilder
```
## String Formatting
This project supports some very primitive text formatting like ToString. It also supports some very primitive
parsing. It does not support all the culture and formatting that .Net does. This is because the intent of
these projects is not to make word processors in embedded space. A limited amount of support is provided
for handling devices that talk in simple text strings that need to be built and parsed. This project can be enhanced
if more features are needed.
