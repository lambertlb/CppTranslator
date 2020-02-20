// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT TimeSpanValue : public ValueType {
		TimeSpan	value;
	public:
		static TimeSpan	MaxValue;
		static TimeSpan	MinValue;
		static Int64	TicksPerMillisecond;
		static Int64	TicksPerSecond;
		static Int64	TicksPerMinute;
		static Int64	TicksPerHour;
		static Int64	TicksPerDay;
		static TimeSpan	Zero;

		TimeSpanValue() { value = 0; }
		TimeSpanValue(const UInt64 value2) { value = value2; };
		TimeSpanValue(const TimeSpan value2) { value = value2.value; };

		virtual TimeSpan	get_AsTimeSpan();
		Int32				get_Days();
		Int32				get_Hours();
		Int32				get_Milliseconds();
		Int32				get_Minutes();
		Int32				get_Seconds();
		Int64				get_Ticks();
		Double				get_TotalDays();
		Double				get_TotalHours();
		Double				get_TotalMilliseconds();
		Double				get_TotalMinutes();
		Double				get_TotalSeconds();

		TimeSpan			Add(const TimeSpan& ts);
		static	Int32		Compare(const TimeSpan& ts1, const TimeSpan& ts2);
		virtual Int32		CompareTo(TimeSpan valueToCompare);
		Int32				CompareTo(Object* obj);
		Double				Divide(TimeSpan ts);
		TimeSpan			Divide(Double divisor);
		TimeSpan			Duration();
		Boolean				Equals(const TimeSpan& valueToCompare);
		static Boolean		Equals(const TimeSpan& valueToCompare, const TimeSpan& valueToCompare2);
		virtual Boolean		Equals(Object* valueToCompare);
		static	TimeSpan	FromDays(const Double data);
		static	TimeSpan	FromHours(const Double data);
		static	TimeSpan	FromMilliseconds(const Double data);
		static	TimeSpan	FromMinutes(const Double data);
		static	TimeSpan	FromSeconds(const Double data);
		static	TimeSpan	FromTicks(const Int64 data);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		virtual DataType	GetRawDataType() { return(TimeSpanType); };
		static TimeSpan		Interval(Double value, Double scale);
		TimeSpan			Multiply(Double factor);
		TimeSpan			Negate();
		static TimeSpan		Parse(String* s);
		TimeSpan			Subtract(const TimeSpan& ts1);
		static Boolean		TryParse(String* s, TimeSpan& result);
		static TimeSpan		op_Addition(const TimeSpan& ts1, const TimeSpan& ts2);
		static Double		op_Division(const TimeSpan& ts1, const TimeSpan& ts2);
		static TimeSpan		op_Division(const TimeSpan& ts1, const Double& divisor);
		static Boolean		op_Equality(const TimeSpan& ts1, const TimeSpan& ts2);
		static Boolean		op_GreaterThan(const TimeSpan& ts1, const TimeSpan& ts2);
		static Boolean		op_GreaterThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2);
		static Boolean		op_Inequality(const TimeSpan& ts1, const TimeSpan& ts2);
		static Boolean		op_LessThan(const TimeSpan& ts1, const TimeSpan& ts2);
		static Boolean		op_LessThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2);
		static TimeSpan		op_Multiply(const TimeSpan& ts1, const Double& factor);
		static TimeSpan		op_Multiply(const Double& factor, const TimeSpan& ts1);
		static TimeSpan		op_Subtraction(const TimeSpan& ts1, const TimeSpan& ts2);
		static TimeSpan		op_UnaryNegation(const TimeSpan& ts1);
		static TimeSpan		op_UnaryPlus(const TimeSpan& ts1);

	};
}
