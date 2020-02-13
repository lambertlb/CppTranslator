using System;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace CppTranslator
{
	/// <summary>
	/// Handle trace log
	/// </summary>
	public class CppTraceListener : TraceListener
	{
		private String pathToLog;
		/// <summary>
		/// Initializes a new instance of the <see cref="CppTraceListener"/> class.
		/// </summary>
		/// <param name="pathToLog">path to trace log</param>
		public CppTraceListener(String pathToLog)
		{
			this.pathToLog = pathToLog;
		}
		/// <summary>
		/// Write to trace log
		/// </summary>
		/// <param name="message">to write</param>
		public override void Write(string message)
		{
			using (StreamWriter writer = new StreamWriter(pathToLog, true))
			{
				writer.Write(message);
			}
		}
		/// <summary>
		/// Write to trace log
		/// </summary>
		/// <param name="message">to write</param>
		public override void WriteLine(string message)
		{
			using (StreamWriter writer = new StreamWriter(pathToLog, true))
			{
				writer.WriteLine(message);
			}
		}
		/// <summary>
		/// Write message to trace log
		/// </summary>
		/// <param name="message">to write</param>
		/// <param name="eventType">event type</param>
		private void WriteTrace(String message, TraceEventType eventType)
		{
			StringBuilder sb = new StringBuilder();
			sb.Append(DateTime.Now);
			sb.Append(": ");
			sb.Append(eventType);
			sb.Append(" = ");
			sb.Append(message);
			WriteLine(sb.ToString());
		}
		/// <summary>
		/// Trace this event
		/// </summary>
		/// <param name="eventCache">cache</param>
		/// <param name="source">source of trace</param>
		/// <param name="eventType">event type</param>
		/// <param name="id">trace id</param>
		/// <param name="message">to write</param>
		public override void TraceEvent(TraceEventCache eventCache, String source, TraceEventType eventType, int id, String message)
		{
			WriteTrace(message, eventType);
		}
		/// <summary>
		/// Trace this event
		/// </summary>
		/// <param name="eventCache">cache</param>
		/// <param name="source">source of trace</param>
		/// <param name="eventType">event type</param>
		/// <param name="id">trace id</param>
		/// <param name="format">of message</param>
		/// <param name="args">data for message</param>
		public override void TraceEvent(TraceEventCache eventCache, String source, TraceEventType eventType, int id, String format, params object[] args)
		{
			WriteTrace(String.Format(format, args), eventType);
		}
		/// <summary>
		/// Add listener
		/// </summary>
		/// <param name="pathToOutput">path to output</param>
		public static void AddListener(String pathToOutput)
		{
			foreach (TraceListener listener in Trace.Listeners)
			{
				CppTraceListener myListener = listener as CppTraceListener;
				if (myListener != null)
					return;
			}
			Trace.Listeners.Add(new CppTraceListener(pathToOutput + ".err"));
			Trace.AutoFlush = true;
		}

		/// <summary>
		/// Remove listener
		/// </summary>
		public static void RemoveListener()
		{
			foreach (TraceListener listener in Trace.Listeners)
			{
				CppTraceListener myListener = listener as CppTraceListener;
				if (myListener != null)
				{
					Trace.Listeners.Remove(myListener);
					break;
				}
			}
		}
	}
}
