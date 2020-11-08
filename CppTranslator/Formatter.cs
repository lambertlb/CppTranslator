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
using System;
using System.Globalization;
using System.IO;
using System.Text;

namespace CppTranslator
{
	/// <summary>
	/// Worker for formatting output
	/// </summary>
	public class Formatter : IDisposable
	{
		private StringBuilder stringBuilder = new StringBuilder(2048);
		private int indentLevel;
		private String nl = Environment.NewLine;
		private String tabs = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
		private bool openBraceOnNewline = true;
		private bool onNewline;
		/// <summary>
		/// Is formatter at start of new line
		/// </summary>
		public bool IsOnNewline
		{
			get { return (onNewline); }
		}
		/// <summary>
		/// Were any characters added to the current line
		/// </summary>
		public bool CharactersAddedToLine { get; set; }
		/// <summary>
		/// Is text to be emitted to the console
		/// </summary>
		public bool EmitToConsole { get; set; }
		private StreamWriter outputFiler;
		private String outputName;
		/// <summary>
		/// File name of output
		/// </summary>
		public String OutputName
		{
			get
			{
				return outputName;
			}
			set
			{
				outputName = value;
				NewOutputFile();
			}
		}
		private String nameSpace;
		/// <summary>
		/// Name space we are currently in
		/// </summary>
		public string NameSpace
		{
			get { return nameSpace; }
			set { SetNamespace(value); }
		}
		/// <summary>
		/// Initializes a new instance of the <see cref="Formatter"/> class.
		/// Constructor
		/// </summary>
		public Formatter()
		{
		}

		private void SetNamespace(string value)
		{
			String newNamespace;
			if (String.IsNullOrEmpty(value))
			{
				newNamespace = "UNNAMED";
			}
			else
			{
				newNamespace = value + "_NS";
			}
			if (nameSpace != null && newNamespace != nameSpace)
			{
				CloseNamespace();
			}
			else if (nameSpace != null)
			{
				return;
			}
			nameSpace = newNamespace;
			Append("namespace ");
			Append(nameSpace);
			AddOpenBrace();
		}
		/// <summary>
		/// Close current namespace
		/// </summary>
		public void CloseNamespace()
		{
			if (nameSpace != null)
			{
				AddCloseBrace();
				nameSpace = null;
			}
		}
		/// <summary>
		/// Reset formatter
		/// </summary>
		protected void Reset()
		{
			stringBuilder.Clear();
			indentLevel = 0;
			onNewline = true;
		}
		/// <summary>
		/// Flush the current text to the output file and reset
		/// </summary>
		/// <param name="streamWriter">StreamWriter to output file</param>
		public void Flush(TextWriter streamWriter)
		{
			streamWriter.Write(stringBuilder.ToString());
			stringBuilder.Clear();
		}
		/// <summary>
		/// Indent text to indentation level
		/// </summary>
		private void Indent()
		{
			Append(tabs.Substring(0, indentLevel));
			CharactersAddedToLine = false;
		}
		/// <summary>
		/// Increase indentation
		/// </summary>
		public void UpIndent()
		{
			++indentLevel;
		}
		/// <summary>
		/// Decrease indentation
		/// </summary>
		public void DownIndent()
		{
			--indentLevel;
		}
		/// <summary>
		/// Prefix for lower class names to avoid collision woth c++ keywords
		/// </summary>
		private String Prefix
		{
			get { return ("x_"); }
		}
		private String PrefixName(String nameToPrefix)
		{
			if (Char.IsLower(nameToPrefix[0]) && nameToPrefix != "this")
				return (Prefix + nameToPrefix);
			return (nameToPrefix);
		}
		/// <summary>
		/// Append name and prefix it if needed
		/// </summary>
		/// <param name="name">name to prefix</param>
		public void AppendName(String name)
		{
			String nm = PrefixName(name);
			if (nm == "Void")
				nm = "void";
			Append(nm);
		}
		/// <summary>
		/// Append name and prefix it if needed
		/// </summary>
		/// <param name="name">name to add</param>
		public void AppendIndentedName(String name)
		{
			AppendIndented(PrefixName(name));
		}
		/// <summary>
		/// Add this string to output
		/// </summary>
		/// <param name="data">String to add</param>
		public void Append(String data)
		{
			onNewline = false;
			stringBuilder.Append(data);
			if (!String.IsNullOrEmpty(data))
				CharactersAddedToLine = true;
			if (EmitToConsole)
				System.Console.Out.Write(data);
		}
		/// <summary>
		/// Add this character to output
		/// </summary>
		/// <param name="character">Character to add</param>
		public void Append(Char character)
		{
			onNewline = false;
			CharactersAddedToLine = true;
			stringBuilder.Append(character);
			if (EmitToConsole)
				System.Console.Out.Write(character);
		}
		/// <summary>
		/// Add a string that might contain control characters
		/// </summary>
		/// <param name="data">String to Append</param>
		public void AppendStringsWithControl(String data)
		{
			Append("L\"");
			Char[] chars = data.ToCharArray();
			foreach (Char chr in chars)
			{
				AppendCharWithControls(chr, true);
			}
			Append("\"");
		}
		/// <summary>
		/// Append control character
		/// </summary>
		/// <param name="chr">to append</param>
		/// <param name="forString">if for string constant</param>
		public void AppendCharWithControls(Char chr, bool forString)
		{
			if (!forString)
				Append("L'");
			switch (chr)
			{
				case '"': Append("\\\""); break;
				case '\\': Append("\\\\"); break;
				case '\a': Append("\\a"); break;
				case '\b': Append("\\b"); break;
				case '\t': Append("\\t"); break;
				case '\r': Append("\\r"); break;
				case '\v': Append("\\v"); break;
				case '\f': Append("\\f"); break;
				case '\n': Append("\\n"); break;
				case '\'': if (forString) Append("'"); else Append("\\'"); break;
				default:
					{
						if (!Char.IsControl(chr) && chr >= ' ' && chr <= '~')
						{
							Append(chr);
						}
						else
						{
							// add as Unicode character code.
							Append("\\u");
							int ichr = Convert.ToInt32(chr);
							String num = String.Format(CultureInfo.InvariantCulture, "{0000:x}", ichr);
							Append("0000".Substring(0, 4 - num.Length));
							Append(num);
						}
					}
					break;
			}
			if (!forString)
				Append("'");
		}
		/// <summary>
		/// Add a newline
		/// </summary>
		public void Newline()
		{
			Append(nl);
			onNewline = true;
			CharactersAddedToLine = false;
		}
		/// <summary>
		/// Add this data and start a new line
		/// </summary>
		/// <param name="data">Data to add</param>
		public void AppendLine(String data)
		{
			Append(data);
			Newline();
		}
		/// <summary>
		/// Indent then add this data
		/// After that start a new line.
		/// </summary>
		/// <param name="data">Data to add</param>
		public void AppendIndentedLine(String data)
		{
			Indent();
			AppendLine(data);
		}
		/// <summary>
		/// Indent then add this data
		/// </summary>
		/// <param name="data">Data to add</param>
		public void AppendIndented(String data)
		{
			Indent();
			Append(data);
		}
		/// <summary>
		/// Add an open brace to data.
		/// It will increase the indentation level after adding brace
		/// </summary>
		public void AddOpenBrace()
		{
			if (openBraceOnNewline && !onNewline)
			{
				Newline();
				AppendIndentedLine("{");
			}
			else
			{
				AppendLine(" {");
			}
			UpIndent();
		}
		/// <summary>
		/// Add a close brace.
		/// It will decrease the indentation level first
		/// </summary>
		public void AddCloseBrace()
		{
			AddCloseBrace(false);
		}
		/// <summary>
		/// Add close brace with semicolon if needed
		/// </summary>
		/// <param name="needSemicolon">add semi-colon</param>
		public void AddCloseBrace(bool needSemicolon)
		{
			if (!onNewline)
				Newline();
			DownIndent();
			AppendIndented("}");
			if (needSemicolon)
			{
				Append(";");
			}
			Newline();
		}
		/// <summary>
		/// Close up formatter
		/// </summary>
		public void Close()
		{
			if (outputFiler != null)
			{
				CloseNamespace();
				Flush(outputFiler);
				outputFiler.Close();
				outputFiler = null;
			}
		}
		private void NewOutputFile()
		{
			Close();
			outputFiler = new StreamWriter(outputName);
		}
		/// <summary>
		/// Stringify everything
		/// </summary>
		/// <returns>String from stringbuilder</returns>
		public override String ToString()
		{
			return (stringBuilder.ToString());
		}
		/// <summary>
		/// Dispose
		/// </summary>
		/// <param name="dispose">dispose</param>
		protected virtual void Dispose(bool dispose)
		{
			Close();
		}
		/// <summary>
		/// Dispose
		/// </summary>
		public void Dispose()
		{
			Dispose(true);
			GC.SuppressFinalize(this);
		}
	}
}
