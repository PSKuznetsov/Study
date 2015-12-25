using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace C_Practic_5_III_RecMatrix
{
	
	static public class Matrix
	{
		//determinate the sign og the element
        static internal int SignOfElement (int i, int j)
        {
            int result = (i + j) % 2 == 0 ? 1:-1;
            return result;
        }

        //create smaller matrix with given element
        static internal double[,] CutMatrixWithElementAtIndex (double[,]inputMatrix, int i, int j)
        {
            int rank = int.Parse(System.Math.Sqrt(inputMatrix.Length).ToString());

            double[,] outputMatrix = new double[rank-1, rank-1];

            int x = 0, y = 0;

            for (int m = 0; m < rank; m++, x++)
            {
                if (m != i)
                {
                    y = 0;

                    for (int n = 0; n < rank; n++)
                    {
                        if (n != j)
                        {
                            outputMatrix[x, y] = inputMatrix[m, n];
                            y++;
                        }
                    }
                }
                else
                {
                    x--;
                }
            }
            return outputMatrix;
        }
        //Recursion method 
        static public double Determinant(double[,] inputMatrix)
        {
            int rank = int.Parse(System.Math.Sqrt(inputMatrix.Length).ToString());
            if (rank > 2)
            {
                double value = 0;

                for (int j = 0; j < rank; j++)
                {
                    double[,] Temp = CutMatrixWithElementAtIndex(inputMatrix, 0, j);

                    value += inputMatrix[0, j]*(SignOfElement(0, j) * Determinant(Temp));
                }
                return value;
            }
            else if (rank == 2)
            {
                return (inputMatrix[0, 0] * inputMatrix[1, 1]) - (inputMatrix[1, 0] * inputMatrix[0, 1]);
            }
            else
            {
                return inputMatrix[0, 0];
            }
        }

	}
}

