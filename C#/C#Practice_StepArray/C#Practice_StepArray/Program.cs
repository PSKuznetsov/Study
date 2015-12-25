using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CPractice_StepArray
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int[][] arr;
			readData(out arr);
			insertZeroAfterPrimeNumber(arr);
			writeData(arr);
			deletePrimeNumbers(arr);
			writeData(arr);
		}

		public static void readData(out int[][]arr) {

			int n = int.Parse(Console.ReadLine());
			arr = new int[n][];

			for (int i = 0; i < n; i++) {
				int j = int.Parse(Console.ReadLine());
				arr[i] = new int[j];

					for (j = 0; j < arr[i].Length; j++) {
						Console.Write("a[{0}][{1}]= ", i, j); 
						arr[i][j] = int.Parse(Console.ReadLine());
					}
			}
		}

		public static void writeData(int[][] arr) {
			for (int i = 0; i < arr.Length; i++) {
				for (int j = 0; j < arr[i].Length; j++) {
					Console.Write("{0} ", arr[i][j]);
				}
				Console.WriteLine();
			}
			Console.WriteLine("----------------------------");
		}

		public static bool isPrimeNumber(int a) {
			if (a == 1) return false;
			if (a == 2) return true;
			for (int i = 2; i*i <= a; i++) {
				if (a % i == 0) return false;
			}
			return true;
		}

		public static void deletePrimeNumbers(int[][] arr) {

			for (int i = 0; i < arr.Length; i++) {
				for (int j = 0; j < arr[i].Length; j ++) {

					if (isPrimeNumber(arr[i][j])) {

						int numberToDelete = arr[i][j];

//						var list = new List<int>(arr[i]);
//						list.Remove(numberToDelete);
//						arr[i] = list.ToArray();

						int numIndex = Array.IndexOf(arr[i], numberToDelete);
						arr[i] = arr[i].Where((val, idx) => idx != numIndex).ToArray();
					}
				}
			}
		}

		public static void insertZeroAfterPrimeNumber(int[][] arr) {
			for (int i = 0; i < arr.Length; i++) {
				for (int j = 0; j < arr[i].Length; j++) {
					if (isPrimeNumber(arr[i][j])) {
						int[] row = new int[arr[i].Length + 1];

						arr[i].CopyTo(row, 0);
						Array.Copy(row, j, row, j + 1, row.Length - 1 - j);

						row[j++ + 1] = 0;
						arr[i] = row;
					}
				}
			}
		}
	}
}
