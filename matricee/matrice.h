#pragma once
namespace mat {
	class matrice
	{
	private:
		int col;
		int lig;
		int** mat;
	public:
		matrice(int, int);
		void remplissage(int);
		matrice& operator+(const matrice& m);
		matrice& operator-(const matrice& m);
		matrice& operator*(const matrice& m);
		~matrice();
		void printf() const;




	};
}