using System;
using System.Text.RegularExpressions;

namespace RegexDot
{
	public class RegexSolve
	{
		private string text {
			get;
			set;
		}

		public RegexSolve () {
			text = "";
		}

		public RegexSolve (string text) {
			this.text = text;
		}

		public string deletePonctuationMarks() {
			if (text.Length > 0) {

				var newText = Regex.Replace(text, @"[\p{P}]", "");

				return newText;
			}
			else {
				throw new ArgumentException("text property should contain a value");
			}
		}
	}
}
