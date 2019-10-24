#pragma once
typedef	void				Void;
#ifndef CC3_PLATFORM_BUILD
typedef	unsigned char		Boolean;
typedef	unsigned char		BOOLEAN;
#endif

typedef	wchar_t				Char;
typedef	char				Byte;
typedef	signed char			SByte;
typedef	short				Int16;
typedef	unsigned short		UInt16;
typedef	int					Int32;
typedef	unsigned int		UInt32;
typedef	unsigned long		ULInt32;
#ifdef	WIN32
typedef	__int64				Int64;
typedef	unsigned __int64	UInt64;
#else
typedef	long long			Int64;
typedef	unsigned long long	UInt64;
#endif
typedef	float				Single;
typedef	double				Double;
#define	null				0
typedef	Int64				time_Cab;
namespace System_NS
{
	class Object
	{
	};
	class Array : public Object {

	};
	class DateTime : public Array {
	public:
		static DateTime* Now() {
			return(nullptr);
		}
	};
	class TimeSpan : public Array {

	};
	class string : Object {

	};
	class StringBuilder : Object {

	};
}
using namespace System_NS;
