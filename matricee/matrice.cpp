#include "pch.h"
#include "matrice.h"
#include <assert.h>
#include <iostream>

using namespace std;
using namespace mat;

matrice::matrice(int x = 0, int y = 0)
{
	this->col = x;
	this->lig = y;
	mat = new int* [this->lig];
	for (int i = 0; i < this->lig; i++)
	{
		mat[i] = new int[this->col];
	}

	this->remplissage(0);

}

void matrice::remplissage(int a)
{
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->mat[i][j] = a;
		}

	}
}

matrice& matrice::operator+(const matrice& m)
{
	assert((this->lig == m.lig) && (this->col == m.col));

	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->mat[i][j] += m.mat[i][j];
		}

	}
	return *this;

}

matrice& matrice::operator-(const matrice& m)
{
	assert((this->lig == m.lig) && (this->col == m.col));

	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->mat[i][j] -= m.mat[i][j];
		}

	}
	return *this;

}

matrice& matrice::operator*(const matrice& m)
{

	assert(this->col == m.lig);
	matrice* res = new matrice(this->lig, m.col);
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			int somme = 0;
			for (int k = 0; k < this->col; k++)
			{
				somme += this->mat[i][k] * m.mat[k][j];
			}
			res->mat[i][j] = somme;
		}
	}
	*this = *res;
	return *this;
}
matrice::~matrice()
{
	for (int i = 0; i < this->lig; i++) 
	{
		delete this->mat[i];
		this->mat[i] = NULL;
	}
	delete this->mat;
	this->mat = NULL;
}

void matrice::printf() const
{
	for (int i = 0; i < this->lig; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			cout << this->mat[i][j] << "\t";

		}
		cout << endl;
	}
}

