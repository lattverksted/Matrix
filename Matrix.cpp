/** @file matrix.cpp
	@brief		Matrix class file
	@author		Colombe M'boungou
	@date		January 2020
 */

#include "Matrix.h"

#include <stdio.h>
#include <iostream>

using namespace std;

/**
* @brief	get the index an element in a matrix
*
* @param[in]	i	int	The row index
* @param[in]	j	int The column index
* @return	size_t	The index of the element at row i ; column j 
*/
size_t Matrix::index( int i, int j )
{
	return j + this->Cols * i; 
}

/*0 1 2 3
4 5 6 7 
8 9 10 11*/

/**
* @brief	initialize a uniform zero matrix
*
* @param[in]		rows int	The row index
* @param[in]		cols int	The column index
* @return	Matrix		The initialized matrix
*/
Matrix::Matrix(int rows, int cols)
{
	this->Array = (double*)calloc(rows * cols, sizeof(double));

	this->Rows = rows;
	this->Cols = cols;
}
/**
* @brief	initialize a uniform matrix
*
* @param[in]	rows	The row index
* @param[in]	cols	The column index
* @param[in]	value	The value of all the elements	
* @return	Matrix		The initialized matrix
*/
Matrix::Matrix(int rows, int cols, double value)
{
	this->Array = (double*)malloc(rows * cols* sizeof(double));

	this->Rows = rows;
	this->Cols = cols;

	double *p_element = this->Array;
	for (int i = 0; i < rows * cols; i++)
	{
		*p_element++ = value;
	}
}


/**
*	@brief	initialize an identity matrix
*
*	@param[in]	rows	The number of rows
*	@param[in]	cols	The number of columns
*	@return	Matrix		The initialized matrix
*/
Matrix Matrix::Identity(int rows, int cols)
{
	Matrix identity = Matrix(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j)
			{
				double *p_element = identity.element(i, j);
				*p_element = 1;
			}
		}


	}

	return identity;
}


/**
* @brief	default matrix destructor
*/
Matrix::~Matrix()
{
}

/**
* @brief	get the number of rows in a matrix
*
* @return	The  number of rows
*/
int Matrix::getRows(void)
{
	return this->Rows;
}



/**
* @brief	get the number of columns in a matrix
*
* @return	The  number of columns
*/
int Matrix::getCols(void)
{
	return this->Cols;
}



/**
* @brief	get the array pointer of a matrix
*
* @return	double*		The array pointer
*/
double* Matrix::getArray(void)
{
	return this->Array;
}



/**
* @brief	get the pointer to the element at row i , column j of a matrix
*
* @param[in]	i	The row index
* @param[in]	j	The column index
* @return	double*	The pointer to the element at row i , column j
*/
double* Matrix::element(int i, int j)
{
	double* address =  this->Array + this->index(i,j);
	return address;
}


/**
 * @brief	add two matrices together
 *
 * @param[in]	b	The other matrix to add with
 * @return		Matrix		The result of the addition
 */

Matrix  Matrix::operator+( Matrix &b)
{
	int rows = this->getRows();
	int cols = this->getCols();
	Matrix m = Matrix(rows, cols);

	if ((rows != b.getRows()) || (cols != b.getCols()))
	{
		return  Matrix(0,0);
	}

	double *p_m = m.Array;
	double *p_a = this->Array;
	double *p_b = b.Array;

	//only  1 loop  also works
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*p_m++ = *p_a++ + *p_b++;
		}
	}
	return m;
}



/**
 * @brief	multiply two matrices together
 *
 * @param[in,out]	b	The other matrix to multiply with
 * @return			Matrix		The result of the multiplication
 */

Matrix  Matrix::operator*(Matrix &b)
{
	int rows = this->getRows();
	int cols = this->getCols();
	
	if (cols != b.getRows())
	{
		return  Matrix(0, 0);
	}

	Matrix m = Matrix(rows, b.getCols());

	int cols_rows = cols;
	double *p_m = m.Array;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			double *p_a = this->Array;
			double *p_b = b.Array;
			double sum = 0;
			for (int k = 0; k < cols_rows; k++)
			{
				
				double a_ik = *this->element(i, k);
				double b_kj = *b.element(k, j);
				sum += a_ik * b_kj;

			}
			*p_m++ = sum; 

		}
	}
	return m;
}



/**
 * @brief	operator multiply a matrix with a scalar
 *
 * @param[in]	scalar	The scalar to multiply the matrix with
 * @return		Matrix			The result
 */
Matrix  Matrix::operator*(double  scalar)
{

	return this->multiply(scalar);

}
/**
 * @brief	multiply a matrix with a scalar 
 *
 * @param[in]	scalar	The scalar to multiply the matrix with
 * @return		Matrix			The result
 */
Matrix Matrix::multiply(double scalar) 
{
	int rows = this->Rows;
	int  cols = this->Cols;
	Matrix M = Matrix(rows, cols);

	double *a_element = this->Array;
	double *m_element = M.Array;
	for (int i = 0; i < rows* cols; i++)
	{
			*m_element++ = scalar * *a_element++ ;	
	}
	return M ; 
}



/**
 * @brief	display the elements of the matrix row after row
 */
void Matrix::display(void)
{
	int rows = this->Rows;
	int cols = this->Cols;

	cout << rows <<" rows x " << cols << " columns"<< endl;
	double *p_element = this->Array;

	for (int i = 0; i < rows; i++)
	{
		for(int j = 0; j<cols; j++)
		{
			
			cout << *p_element++  << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
