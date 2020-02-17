using System;

namespace CppTranslatorFeature2Test
{
	public class NamespaceTestClass
	{
		public NamespaceTestClass() { }
	}
}
namespace CppTranslatorFeatureTest
{
	public class FildTest
	{
		public Int32 field1;
		public static Int32 field2;
	}
	public struct StructTest
	{
		public int data;

		public StructTest(int i)
		{
			data = i;
		}
		public static StructTest operator +(StructTest ts, int newData)
		{
			ts.data += newData;
			return (ts);
		}
		public static StructTest operator &(StructTest ts, int newData)
		{
			ts.data &= newData;
			return (ts);
		}
	}
	public struct StructTest2
	{
		public StructTest st;
	}
	public abstract class Abstract
	{
		protected int data1;
		protected int data2;
		public Abstract(int i, int j) : base()
		{
			data1 = i;
			data2 = j;
		}
		public abstract int MustImplement();
		public abstract int MustImplement(int i);
		public int DidImplement()
		{
			return (data1);
		}
	}
	public class TestAbstract : Abstract
	{
		public TestAbstract()
			: base(1, 2)
		{
		}
		public override int MustImplement()
		{
			return (data2);
		}
		public override int MustImplement(int i)
		{
			return (data2);
		}
		public override String ToString() { return ("TestAbstract"); }
	}
	public enum TestNameEnu
	{
		friend,
		enemy
	}
	public class Typedef
	{
		TestNameEnu friend;
		public TestNameEnu Friend
		{
			get { return (friend); }
			set { friend = value; }
		}
	}
	public class MiscTest
	{
		FeatureTest featureTest;
		public MiscTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			featureTest.FailureMessage = "\tFailed Misc Test";
			featureTest.Send("Misc Test");
			SwitchTest();
			ForTest();
			ForEachTest();
			IfTest();
			FieldAccessTest();
			StructureTest();
			Structure2Test();
			InheritanceTest();
			DifferentNamespaceTest();
			ComplexConditionsTest();
			EnumTest();
		}
		private void SwitchTest()
		{
			bool loop = true;
			int value = 1;
			while (loop)
			{
				switch (value)
				{
					case 1:
						value = 2;
						break;
					case 2:
						value = 3;
						break;
					case 3:
						value = 1000;
						break;
					case 1000:
						value = 100000;
						break;
					case 100000:
						loop = false;
						break;
				}
			}
			featureTest.AssertTrue(!loop);
			featureTest.AssertTrue(value == 100000);
		}
		private void ForTest()
		{
			Int32[] data = new int[] { 0, 1, 2, 3 };
			for (Int32 i = 0; i < data.Length; ++i)
			{
				featureTest.AssertTrue(data[i] == i);
			}
		}
		private void ForEachTest()
		{
			Int32[] data = new int[] { 0, 1, 2, 3 };
			Int32 value = 0;
			foreach (Int32 item in data)
			{
				featureTest.AssertTrue(item == value);
				++value;
			}
			String data2 = "0123";
			value = 0;
			foreach (Char item2 in data2)
			{
				featureTest.AssertTrue(item2 == (Char)(value + '0'));
				++value;
			}
		}
		private void IfTest()
		{
			bool loop = true;
			int value = 1;
			while (loop)
			{
				if (value == 1)
				{
					value = 2;
				}
				else if (value == 2)
				{
					value = 3;
				}
				else
				{
					value = 4;
					loop = false;
					break;
				}
			}
			featureTest.AssertTrue(value == 4);
		}
		private void FieldAccessTest()
		{
			FildTest ft = new FildTest();
			ft.field1 = 1;
			FildTest.field2 = 2;
			featureTest.AssertTrue(ft.field1 == 1);
			featureTest.AssertTrue(FildTest.field2 == 2);
		}
		private void StructureTest()
		{
			StructTest st = new StructTest(1);
			featureTest.AssertTrue(st.data == 1);
			st += 1;
			featureTest.AssertTrue(st.data == 2);
			featureTest.AssertTrue((st &= 1).data == 0);
			st.data = 1;
			featureTest.AssertTrue((st &= 1).data != 0);
			featureTest.AssertTrue(st.data == 1);
			PassByValueTest(st);
			featureTest.AssertTrue(st.data == 1);
			st.data = 1;
			PassByReferenceTest(ref st);
			featureTest.AssertTrue(st.data == 2);
		}
		private void PassByValueTest(StructTest st)
		{
			st += 1;
			featureTest.AssertTrue(st.data == 2);
		}
		private void PassByReferenceTest(ref StructTest st)
		{
			st += 1;
			featureTest.AssertTrue(st.data == 2);
		}
		private void Structure2Test()
		{
			StructTest2 st2;
			st2.st.data = 1;
			featureTest.AssertTrue(st2.st.data == 1);
			PassByValueTest(st2.st);
			featureTest.AssertTrue(st2.st.data == 1);
			PassByReferenceTest(ref st2.st);
			featureTest.AssertTrue(st2.st.data == 2);
		}
		private void InheritanceTest()
		{
			TestAbstract ta = new TestAbstract();
			featureTest.AssertTrue(ta.MustImplement() == 2);
			featureTest.AssertTrue(ta.DidImplement() == 1);
			String ts = ta.ToString();
			featureTest.AssertTrue(ts == "TestAbstract");
		}
		private void DifferentNamespaceTest()
		{
			CppTranslatorFeature2Test.NamespaceTestClass nst = new CppTranslatorFeature2Test.NamespaceTestClass();
			featureTest.AssertTrue(nst != null);
		}
		private void ComplexConditionsTest()
		{
			Int32 value = 0;
			featureTest.AssertTrue(((value < 1) && (value < 2) && (value < 3)));
			value = 10;
			featureTest.AssertTrue(!((value < 1) && (value < 2) && (value < 3)));
			value = 2;
			bool u = (value < 1);
			bool v = (value < 2);
			bool q = (value < 3);
			bool r = (value < 4);
			bool s = (value < 5);
			featureTest.AssertTrue(!((u || v) && q) || ((r && s && q) || v));
			featureTest.AssertTrue(!u && !v && q && r && s);
			featureTest.AssertTrue(u || v || q && r && s);
			featureTest.AssertTrue(!u && q && !v && r && s);
			value = value == 2 ? 3 : 1;
			featureTest.AssertTrue(value == 3);
			value = value <= 3 ? 1 : 0;
			featureTest.AssertTrue(value == 1);
		}
		private void EnumTest()
		{
			Typedef td = new Typedef();
			td.Friend = TestNameEnu.friend;
			featureTest.AssertTrue(td.Friend == TestNameEnu.friend);
		}
	}
}
