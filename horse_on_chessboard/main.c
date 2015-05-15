

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS    6
#define COLS    6

/*axis i move matrix*/
const int iktmove[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
/*axis j move matrix*/
const int jktmove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int board[ROWS][COLS];

/*inital the matrix*/
void matrix_init(int matrix[][COLS], int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; ++i)
	for (j = 0; j < cols; ++j) {
		matrix[i][j] = 0;
	}
}
/*print the matrix*/
void print_matrix(int matrix[][COLS], int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; ++i) {
		for (j = 0; j < cols; ++j)
			printf("%d\t", matrix[i][j]);
		printf("\n\n\n");
	}
}
/*find the index of min non-zeros positive*/
int minindex_in_matrix(int a[], int cols) {
	int i = 0, index = 0;
	int min = a[0];
	for (i = 0; i< cols; ++i) {
		if (a[i] >0) {
			min = a[i];
			index = i;
			break;
		}
	}
	for (i = index + 1; i < cols; ++i) {
		if (a[i] > 0 && min > a[i]) {
			min = a[i];
			index = i;
		}
	}
	if (a[index] > 0)
		return index;
	return -1;
}
int maxindex_in_matrix(int a[], int cols) {
	int i = 0, index;
	int max;
	for (i = 0; i< cols; ++i) {
		if (a[i] >0) {
			max = a[i];
			index = i;
			break;
		}
	}
	for (i = index + 1; i < cols; ++i) {
		if (a[i] > 0 && max < a[i]) {
			max = a[i];
			index = i;
		}
	}
	if (a[index] > 0)
		return index;
	return -1;
}

/**/
void warnsdorff_role(int matrix[][COLS], int rows, int cols, int start_i, int start_j) {
	int i, npos, m, min, j, nnpos;

	int nexti[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int nextj[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int exit[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	/*steps a*/
	matrix_init(matrix, rows, cols);
	/*steps b*/
	matrix[start_i][start_j] = 1;
	/*steps c*/
	for (m = 1; m < 64; ++m) {
		/*steps d*/
		npos = 0;
		for (i = 0; i < 8; ++i) {
			/*ignore the point which doesn't satisfy the conditions*/
			if (start_i + iktmove[i] < 0 ||
				start_i + iktmove[i] >= rows ||
				start_j + jktmove[i] < 0 ||
				start_j + jktmove[i] >= cols ||
				matrix[start_i + iktmove[i]][start_j + jktmove[i]] > 0) {
				continue;
			}
			/*save the point which satisfy the conditions*/
			nexti[npos] = start_i + iktmove[i];
			nextj[npos] = start_j + jktmove[i];
			/*statistics how many point satisfy conditions*/
			npos++;
		}
		/*steps e*/
		if (npos == 0) {
			printf("Can not finish the game!!\n,The steps of game can be %d\n", m);
			goto print;
		}
		/*steps e*/
		if (npos == 1) {
			min = 0;
			goto set_nextpoint;
		}
		/*steps f*/
		if (npos > 1) {
			/*calculate the possible way of the next next step */
			for (i = 0; i < npos; ++i) {
				nnpos = 0;
				for (j = 0; j < 8; ++j) {
					/*statistics the point which satisfy conditions*/
					if (nexti[i] + iktmove[j] >= 0 &&
						nexti[i] + iktmove[j] < rows &&
						nextj[i] + jktmove[j] >= 0 &&
						nextj[i] + jktmove[j] < cols &&
						matrix[nexti[i] + iktmove[j]][nextj[i] + jktmove[j]] == 0) {
						nnpos++;
					}
				}
				/*save the numbers of points for next step*/
				exit[i] = nnpos;
			}
			/*find the proper point*/
			if ((min = minindex_in_matrix(exit, npos)) >= 0) {
				goto set_nextpoint;
			}
			else /*failed*/
			{
				printf("Can not finish the game!!\n,The steps of game can be %d\n", m);
				goto print;
			}
		}
	set_nextpoint:
		/*step g*/
		/*set the next start point of game*/
		start_i = nexti[min];
		start_j = nextj[min];
		matrix[start_i][start_j] = m + 1;
	}
print:
	/*step h*/
	print_matrix(matrix, rows, cols);
}

void main() {
	warnsdorff_role(board, ROWS, COLS, 0, 3);
	system("pause");
}