using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace C_Practic_VII_8
{
	class MainClass
	{
		static bool isFansyNumber(int n) {

			SortedSet<int> tmpArgs = new SortedSet<int>();
			int digitNumber = 0;

			while (n > 0) {

				tmpArgs.Add(n % 10);
				n /= 10;
				digitNumber++;
				//
			}
			return digitNumber == tmpArgs.Count ? true : false;
		}

		static int NOD(int m, int n)
        {
            int nod = 0;

            for (int i = 1; i < (n * m + 1); i++) {

                if (m % i == 0 && n % i == 0) {
                    nod = i;
                }
            }
            return nod;
        }

		public static void Main (string[] args)
		{
			string[] inputArgs = Console.ReadLine().Trim().Split();

			int a = int.Parse(inputArgs[0]);
			int b = int.Parse(inputArgs[1]);

			for (int i = a; i <= b; ++i) {
				if (isFansyNumber(i)) Console.WriteLine("{0} is a good number for us ;)", i);
			}
		}
	}
}
