// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

int** compress(int** matrix, int n, int m, int* nn, int* mm);

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {

	*ii = 0;
	*jj = 0;

	if (n <= 0 || m <= 0 || matrix == nullptr) {
		return;
	}

	//corner right down
	if (matrix[n - 1][m - 1] < matrix[n - 1][m - 2]
		&& matrix[n - 1][m - 1] < matrix[n - 2][m - 1]) {

		*ii = n;
		*jj = m;
		return;
	}

	//down line
	if (n > 1) {

		for (int j = m - 2; j > 0; j--) {

			if (matrix[n - 1][j] < matrix[n - 1][j + 1]
				&& matrix[n - 1][j] < matrix[n - 1][j - 1]
				&& matrix[n - 1][j] < matrix[n - 2][j]) {

				*ii = n;
				*jj = j + 1;
				return;
			}
		}
	}
	else {

		if (matrix[n - 1][m - 1] < matrix[n - 1][m - 2]) {

			*ii = n;
			*jj = m;
		}

		for (int j = m - 2; j > 0; j--) {

			if (matrix[n - 1][j] < matrix[n - 1][j + 1]
				&& matrix[n - 1][j] < matrix[n - 1][j - 1]) {

				*ii = n;
				*jj = j + 1;
				return;
			}
		}

		if (matrix[n - 1][0] < matrix[n - 1][1]
			&& matrix[n - 1][0] < matrix[n - 2][0]) {

			*ii = n;
			*jj = 1;
			return;
		}
	}

	//left down corner
	if (matrix[n - 1][0] < matrix[n - 1][1]
		&& matrix[n - 1][0] < matrix[n - 2][0]) {

		*ii = n;
		*jj = 1;
		return;
	}

}