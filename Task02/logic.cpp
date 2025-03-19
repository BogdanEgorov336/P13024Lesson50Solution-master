// Сумма элементов [The sum of elements]
// 
// Дана математическая квадратная матрица размером N.
// Необходимо разработать функцию (или программу), 
// которая вычисляет сумму элементов матрицы, 
// расположенных на главной и побочной диагоналях.

#include "logic.h"

int sum_main_diagonale_elements(int** matrix, int n) {

	int sum = 0;

	for (int i = 0; i < n; i++) {

		sum += matrix[i][i];
	}

	return sum;
}

int sum_second_diagonale_elements(int** matrix, int n) {

	int sum = 0;

	for (int i = 0; i < n; i++) {

		for (int j = n - 1; j >= 0; j--) {

			sum += matrix[i][j];
		}
	}

	return sum;
}

int sum_main_and_second_diagonales_elements(int** matrix, int n) {



	return n % 2 == 0 ? sum_main_diagonale_elements(matrix, n)
		+ sum_second_diagonale_elements(matrix, n);
}