using System;

namespace KMP
{
	class MainClass
	{
		public static void Main (string[] args) {

			string inputString   = Console.ReadLine();
			string patternString = Console.ReadLine();

			char[] inputStringChars   = inputString.ToCharArray();
			char[] patternStringChars = patternString.ToCharArray();

			KMPSearcher searcher = new KMPSearcher(patternStringChars);

			int index = searcher.Search(inputStringChars);

			Console.WriteLine("Input string: {0} pattern string: {1} index: {2}", inputString, patternString, index);
			
		}
	}
}
