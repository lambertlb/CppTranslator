# Cpp Translator Support
The purpose of this project is to provide an example of how access to methods and data outside the .Net world can be emulated
within the .Net world. There is a companion project called **DotNetLibrarySupport** that will implement the same classes
and methods in the C++ world. By doing this, features in the target environment can be emulated in .Net so that any algorithms
to be translated can be fully tested within .Net. To have access to this, the algorithm to be translated must inherit from the
DataAccess class. For example in the **CppTranslatorFeatureTest** project the FeatureTest class inherits from it as follows.
```
public class FeatureTest : DataAccess
{
}
```

## Translator Support Class
This class can hold all the methods that the algorithm needs to call to the target environment. For example the following
```
public void Send(String message)
{
    Console.WriteLine(message);
}
```

This would expose a method called **Send**. It might be used for sending an alarm or something. In .Net it would just send
the message to the console. The actual code in the **DotNetLibrarySupport** could look like this
```
void DotnetLibrarySupport::TranslatorSupport::Send(String* message)
{
    printf("%ls\n", message->get_Buffer());
}

```

This could actually hook into the target environments native alarm system.

A **Run** method is exposed also. This methods allows the target environment to actually run the code in the algorithm.
It expects that the algorithm will override the **RunCode** method. This run method is a convenient place to
do any setup work needed by the runtime to be done before actually running the algorithm. For example in the
.Net world some simulation of data might be done before execution. In the translated world some initialization
of platform services might be done like setting up memory allocator.

## Data Access Class
This class can hold all the properties needed for the algorithm to have access to external data. These properties in the
.Net world can use simulated data. The properties in the C++ world can expose access to live data. The following code
shows how scalar and array data can be simulated and exposed in .Net world.
```
private Int32[] arrayData = new Int32[] { 1, 2, 3, 4 };
public  int[]   ArrayData { get => arrayData; set => arrayData = value; }
private Double  doubleData = 5.5;
public  double  DoubleData { get => doubleData; set => doubleData = value; }
```

In this case a scalar double called _DoubleData_ is expose and also an Integer array called _ArrayData_. In the
**DotNetLibrarySupport** project the C++ code can be implemented to allow access to live data as follows.
```
Int32	arrayData[]{ 1,2,3,4 };
Array* DotnetLibrarySupport::DataAccess::get_ArrayData()
{
    return(new Array(arrayData, Int32Type, 4));
}

Double doubleData = 5.5;
Double DotnetLibrarySupport::DataAccess::get_DoubleData()
{
    return doubleData;
}
```

Notice how the property wraps the native array into a .Net Array class.
