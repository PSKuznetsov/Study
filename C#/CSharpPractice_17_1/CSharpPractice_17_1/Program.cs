using System;
using System.IO;

namespace CSharpPractice_17_1
{
	class MainClass
	{
		private static int FindPositionOfDivider(string inputString) {
            if (inputString.Length > 1) { 
                int ptr_idx = 0;

                for (int idx = 0; idx < inputString.Length; idx++) {

                    if (inputString[idx] == '(') {
                        ptr_idx++;
                    }
                    else if (inputString[idx] == ')') {
                        ptr_idx--;
                    }

                    if (inputString[idx] == ',' && ptr_idx == 1 ) {
                        return idx;
                    }
                }
            }
            
            return -1;
        }

        private static int StringDivider(string inputString) {

            int idx = FindPositionOfDivider(inputString);

            if (inputString[0] == 'M') {
                return Math.Max(StringDivider(inputString.Substring(2, idx - 2)), 
                StringDivider(inputString.Substring(idx + 1, inputString.Length - 2 - idx)));
           	}
          	else if (inputString[0] == 'm') {
                return Math.Min(StringDivider(inputString.Substring(2, idx - 2)), 
                StringDivider(inputString.Substring(idx + 1, inputString.Length - 2 - idx)));
            }
            return int.Parse(inputString);
        }

		public static void Main (string[] args) {

			StreamReader input  = new StreamReader("formula.txt");
            StreamWriter output = new StreamWriter("output.txt");

            output.WriteLine(StringDivider(input.ReadLine().Trim()));
            
            input.Close();
            output.Close();
		}
	}
}


        
