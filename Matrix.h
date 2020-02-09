/** @file matrix.h
	@brief		Matrix class header file 
	@author		Colombe M'boungou
	@date		January 2020
 */
#pragma once

/** A matrix class
 *  This class implements matrix and its operations
 */
class Matrix
{
public:

	Matrix(int rows, int cols);					/**<	 initialize zero matrix rows * cols */
	Matrix(int rows, int cols, double value);	/**<	 initialize matrix with all elements equal to value */

	~Matrix();									/**<	default destructor */	

	Matrix operator+(Matrix &b);					/**<	Matrix addition  ; example :	M = A + B */
	Matrix operator*(Matrix &b);					/**<	Matrix multiply  ; example :	M = A * B */
	Matrix operator*(double scalar);			/**<	Matrix multiply by scalar		M = scalar * B */
	Matrix Identity(int rows, int cols);		/**<	initialize the identity matrix */

	Matrix multiply(double scalar);				/**<	multiply a matrix by a scalar */

	int getRows(void);							/**<	get the number of rows a matrix */
	int getCols(void);							/**<	get the number of columns a matrix */
	double* getArray(void);						/**<	get the array pointer a matrix */
	void display(void);							/**<	display all elements row after row */
	size_t index(int x, int y);					/**<	return the index of an element at row i , column j */
	double *element(int x, int y);				/**<	return the pointer to the element at row i , column j */

private :

	/**	number of rows*/
	int Rows;
	/**	number of columns*/
	int Cols;
	/** matrix is stored as 1D double array pointer */
	double *Array;
};

