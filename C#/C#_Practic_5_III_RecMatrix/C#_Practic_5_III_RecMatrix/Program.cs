using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Linq;


namespace C_Practic_5_III_RecMatrix
{
	class MainClass
	{

		static void Main(string[] args)
        {

        		Console.WriteLine("Please, enter matrix rank: ");
                int n = int.Parse(Console.ReadLine().ToString());

                if (n > 0) {

                    double[,] matrix = new double[n, n];

                    for (int i = 0; i < n; i++) {

                    	string[] parse = Console.ReadLine().Split(' ');

                    	for (int j = 0; j < n; ++j) {

                            matrix[i, j] = double.Parse(parse[j]);
                        }

                    }

                    Console.WriteLine("Matrix entered: ");

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            Console.Write(matrix[i, j].ToString() + " ");
                        }
                        Console.WriteLine();
                    }

                    Console.WriteLine("Value of the det is: " + Matrix.Determinant(matrix));
                }
                else
                {
                    Console.WriteLine("Rank should be a positive number.");
                }
            }

     }
}
