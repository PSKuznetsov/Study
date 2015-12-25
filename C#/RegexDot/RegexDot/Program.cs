using System;
using System.Text;
using System.IO;
using System.Diagnostics;


namespace RegexDot
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			UnionTest onceTest = new UnionTest();
			onceTest.StartTest();
			onceTest.WriteTimeResultsToFile();
		}
	}
}
