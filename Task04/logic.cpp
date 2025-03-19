// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int get_max(int** matrix, int n, int m) {

	int value = matrix[0][0];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (matrix[i][j] > value) {
				value = matrix[i][j];
			}
		}
	}

	return value;
}

int get_min(int** matrix, int n, int m) {

	int value = matrix[0][0];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (matrix[i][j] < value) {
				value = matrix[i][j];
			}
		}
	}

	return value;
}

bool is_there_any_extreme(int** matrix, int n, int index, int min, int max) {

	for (int i = 0; i < n; i++) {

		if (matrix[i][index] == max || matrix[i][index] == min) {

			return true;
		}
	}

	return false;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {

	if (n <= 0 || m <= 0 || matrix == nullptr) {
		return 0;
	}

	int max = get_max(matrix, n, m);
	int min = get_min(matrix, n, m);

	int sum = 0;

	for (int j = 0; j < m; j++) {

		if (is_there_any_extreme(matrix, n, j, min, max)) {
			
			for (int i = 0; i < n; i++) {

				sum += matrix[i][j];
			}
		}
	}

	return sum;
}