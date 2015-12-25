using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;

namespace RegexDot
{
	public class UnionTest
	{
		private double[] regexTime;
		private double[] stringTime;
		private double[] stringBuilderTime;

		public UnionTest ()
		{
		}

		public void StartTest() {

			StreamReader input  = new StreamReader("input.txt");
			StreamWriter output = new StreamWriter("output.txt");


			//Parsing whole text info to string array
			var wholeText = input.ReadToEnd().Split(new[]{"$"}, StringSplitOptions.RemoveEmptyEntries);
			Stopwatch stopWatch = new Stopwatch();

			//Start regex test
			double[] overallRegexTime = new double[5];
			var reg_resultString = "";
			int index = 0;
			foreach(string textPart in wholeText) {

				RegexSolve reg_solve = new RegexSolve(textPart);

					stopWatch.Start();
					reg_resultString = reg_solve.deletePonctuationMarks();
			    	stopWatch.Stop();

				    overallRegexTime[index] = stopWatch.ElapsedTicks;
			    	index++;
			    	stopWatch.Reset();

				output.Write("\nRegex string result n{0}\n{1}\n",index, reg_resultString);
			}

			//Start String class tests
			double[] overallStringTime = new double[5];
			var str_resultString = "";
			index = 0;
			foreach(string textPart in wholeText) {

					stopWatch.Start();
					foreach(char c in textPart) {
						if (!char.IsPunctuation(c)) {
							str_resultString += c.ToString();
						}
					}
					stopWatch.Stop();

					overallStringTime[index] = stopWatch.ElapsedTicks;
					index++;
					stopWatch.Reset();
				
				output.Write("\nString result n{0}\n{1}\n",index, str_resultString);
			}

			//Start StringBuilder tests
			double[] overallStringBuilderTime = new double[5];
			StringBuilder sb = new StringBuilder();
			string space = "";
			index = 0;
			foreach(string textPart in wholeText) {
				sb.Clear();
				sb.Append(textPart);

					stopWatch.Start();
					foreach(char c in sb.ToString()) {
						if (char.IsPunctuation(c)) {
							sb.Replace(c.ToString(), space);
						}
					}
					stopWatch.Stop();

				    overallStringBuilderTime[index] = stopWatch.ElapsedTicks;
					index++;
					stopWatch.Reset();
				
				output.Write("\nStringBuilder result n{0}\n{1}\n",index, sb.ToString());
			}

			this.regexTime  = overallRegexTime;
			this.stringTime = overallStringTime;
			this.stringBuilderTime = overallStringBuilderTime;

			input.Close();
			output.Close();

		}
		public void WriteTimeResultsToFile() {

			StreamWriter outputResult = new StreamWriter("outputResult.txt");
			if (this.regexTime != null && this.stringTime != null && this.stringBuilderTime != null) {

				double avrgRegexTime  = 0;
				double avrgStringTime = 0;
				double avrgStringBuilderTime = 0;

				for(int index = 0; index < 5; index++) {

					avrgRegexTime  += this.regexTime[index];
					avrgStringTime += this.stringTime[index];
					avrgStringBuilderTime += this.stringBuilderTime[index];

				}

				avrgRegexTime  /= 5;
				avrgStringTime /= 5;
				avrgStringBuilderTime /= 5;

				outputResult.Write("\nTest avrg results:\nRegex result: {0}\nString result: {1}\nStringBuilder result: {2}\n", avrgRegexTime, avrgStringTime, avrgStringBuilderTime);

				outputResult.Write("\nRegex results:\n");
				foreach(double item in this.regexTime) {
					outputResult.Write("{0} ",item);
				}
				outputResult.Write("\nString results:\n");
				foreach(double item in this.stringTime) {
					outputResult.Write("{0} ",item);
				}
				outputResult.Write("\nString Builder results:\n");
				foreach(double item in this.stringBuilderTime) {
					outputResult.Write("{0} ",item);
				}
			}
			outputResult.Close();
		}
	}
}

