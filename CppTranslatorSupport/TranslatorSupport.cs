using System;

namespace CppTranslatorSupport
{
	public class TranslatorSupport
	{
		public void Send(String message)
		{
			Console.WriteLine(message);
		}
		public void Run()
		{
			try
			{
				RunCode();
			}
			catch (Exception ex)
			{
				Console.WriteLine("Exception {0}", ex.Message);
				Console.WriteLine(ex.StackTrace);
			}
		}
		public virtual void RunCode()
		{

		}
	}
}
