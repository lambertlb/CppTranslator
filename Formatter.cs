using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CppTranslator
{
	public class Formatter
	{
		private Dictionary<String, String> types = new Dictionary<String, String>();
		private StringBuilder stringBuilder = new StringBuilder(2048);
		int indentLevel;
		String nl = Environment.NewLine;
		String tabs = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
		bool openBraceOnNewline = true;
		private bool onNewline;
		private bool emitToConsole;
		private StreamWriter outputFiler;
		private String outputName;
		public String OutputName
		{
			get { return outputName; }
			set
			{
				outputName = value;
				NewOutputFile();
			}
		}
		private String name_space;
		public string Name_space
		{
			get { return name_space; }
			set { SetNamespace(value); }
		}
		public Formatter()
		{
			types.Add("bool", "Boolean");
			types.Add("byte", "Byte");
			types.Add("sbyte", "SByte");
			types.Add("char", "Char");
			types.Add("double", "Double");
			types.Add("float", "Float");
			types.Add("int", "Int32");
			types.Add("uint", "UInt32");
			types.Add("long", "Int64");
			types.Add("ulong", "UInt64");
			types.Add("object", "Object");
			types.Add("short", "Int16");
			types.Add("ushort", "UInt16");
			types.Add("string", "String");
		}

		private void SetNamespace(string value)
		{
			String newNamespace;
			if (value == "")
			{
				newNamespace = "UNNAMED";
			} else
			{
				newNamespace = value + "_NS";
			}
			if (name_space != null && newNamespace != name_space)
			{
				CloseNamespace();
			} else if (name_space != null)
			{
				return;
			}
			name_space = newNamespace;
			Append("namespace ");
			AppendLine(name_space);
			AddOpenBrace();
		}

		public void CloseNamespace()
		{
			if (name_space != null)
			{
				AddCloseBrace();
				name_space = null;
			}
		}

		/// <summary>
		/// Is text to be emitted to the console
		/// </summary>
		public bool EmitToConsole
		{
			get { return (emitToConsole); }
			set { emitToConsole = value; }
		}


		/// <summary>
		/// Reset formatter
		/// </summary>
		protected void Reset()
		{
			stringBuilder.Length = 0;
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
			stringBuilder.Length = 0;
		}
		/// <summary>
		/// Indent text to indentation level
		/// </summary>
		private void Indent()
		{
			Append(tabs.Substring(0, indentLevel));
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
		void DownIndent()
		{
			--indentLevel;
		}
		private String Prefix
		{
			get { return ("x_"); }
		}
		private String PrefixName(String nameToPrefix)
		{
			if (Char.IsLower(nameToPrefix[0]))
				return (Prefix + nameToPrefix);
			return (nameToPrefix);
		}
		/// <summary>
		/// Append name and prefix it if needed
		/// </summary>
		/// <param name="name"></param>
		public void AppendName(String name)
		{
			Append(PrefixName(name));
		}
		/// <summary>
		/// Append name and prefix it if needed
		/// </summary>
		/// <param name="name"></param>
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
			if (emitToConsole)
				System.Console.Out.Write(data);
		}
		/// <summary>
		/// Add this character to output
		/// </summary>
		/// <param name="character">Character to add</param>
		public void Append(Char character)
		{
			onNewline = false;
			stringBuilder.Append(character);
			if (emitToConsole)
				System.Console.Out.Write(character);
		}
		/// <summary>
		/// Add a string that might contain control characters
		/// </summary>
		/// <param name="data">String to Append</param>
		public void AppendStringsWithControl(String data)
		{
			Append("\"");
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
							Append(chr);
						else
						{
							// add as Unicode character code.
							Append("\\u");
							int ichr = Convert.ToInt32(chr);
							String num = String.Format("{0000:x}", ichr);
							Append("0000".Substring(0, 4 - num.Length));
							Append(num);
						}
					}
					break;
			};
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
				AppendLine("{");
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

		public void AppendType(String type)
		{
			if (types.ContainsKey(type))
			{
				Append(types[type]);
				return;
			}
			Append(type);
		}
	}
}
