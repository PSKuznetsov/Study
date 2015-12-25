using System;

namespace C_Practic_4_VI_11
{
	class MainClass
	{
		static bool isPrime (int n)
		{
			if (n == 1)
				return false;

			for (int i = 2; i <= Math.Sqrt(n); ++i) {
				if (n % i == 0) return false;
			}
			return true;
		}

		static void divNumber(int n) {
			for (int i = 1; i <= n/2; ++i) {
				if (n % i == 0) {
					Console.WriteLine("{0} divider for {1}",i,n);
				}
			}
		}	
			
		public static void Main (string[] args)
		{
			int n = int.Parse(Console.ReadLine());

			if (isPrime(n)) {
				Console.WriteLine("Number {0} is a prime number. ", n);
			}
			else {
				divNumber(n);
			}
		}
	}
}
