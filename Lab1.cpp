#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Length_Answer_Matrix(int length_required_matrix, int** Result_Matrix) {
	int count_for_rows_and_colums = 0,
		length_Answer_matrix = 100;
	for (int i = 0; i < length_required_matrix; i++)
	{
		count_for_rows_and_colums = 0;
		for (int j = 0; j < length_required_matrix; j++)
		{
			if (Result_Matrix[i][j] != 0)
			{
				count_for_rows_and_colums++;
				length_Answer_matrix = 100;
			}
		}
		if (count_for_rows_and_colums == 0 && i < length_Answer_matrix)
		{
			length_Answer_matrix = i;
		}
	}
	return length_Answer_matrix;
}

int** Input_Matrix(int length_matrix, int width_matrix, int** M) {
	for (int i = 0; i < length_matrix; i++)
		for (int j = 0; j < width_matrix; j++)
			cin >> M[i][j];
	return M;
}

int** Random_Matrix(int length_matrix, int width_matrix, int** M) {
	for (int i = 0; i < length_matrix; i++)
		for (int j = 0; j < width_matrix; j++)
			M[i][j] = rand() % 10;
	return M;
}

int** New_Matrix(int length_matrix, int width_matrix){
	int** Matrix = new int* [length_matrix];

	for (int i = 0; i < length_matrix; i++)
		Matrix[i] = new int[width_matrix];
	return Matrix;
}

int** New_Init_Matrix(int length_matrix, int width_matrix) {
	int** new_Matrix = new int* [length_matrix];
	for (int i = 0; i < length_matrix; i++)
	{
		new_Matrix[i] = new int[length_matrix];
		for (int j = 0; j < length_matrix; j++)
			new_Matrix[i][j] = 0;
		return new_Matrix;
	}
}

void Print_Matrix(int length_matrix, int width_matrix, int** M) {
	for (int i = 0; i < length_matrix; i++)
	{
		for (int j = 0; j < width_matrix; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}

void Delete_Matrix(int need_size, int** M) {
	for (int i = 0; i < need_size; i++)
		delete[] M[i];
}

void main()
{
	srand(time(NULL));
	int length_matrix_1, width_matrix_1, length_matrix_2, 
		width_matrix_2, selection, length_required_matrix = 2;
	system("chcp 1251");
	cout << "��� ������������ ���������" << endl <<
		"�������� ������������ ������ ������� ���������\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////���� �������� ������� �������������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "������� ������� ������ �������  \n";
		cin >> length_matrix_1 >> width_matrix_1;
	} while (length_matrix_1 <= 0 || width_matrix_1 <= 0);
	do
	{
		cout << "������� ������� ������ �������  \n";
		cin >> length_matrix_2 >> width_matrix_2;
	} while (length_matrix_2 <= 0 || width_matrix_2 <= 0);

	//int** Matrix_1 = new int* [length_matrix_1];
	int** Matrix_1 = New_Matrix(length_matrix_1, width_matrix_1);
	int** Matrix_2 = New_Matrix(length_matrix_2, width_matrix_2);
	

	///////////////////////////////////////////////////////////////////////////////
	////////////////����� ������� ���������� � ���������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "�������� ������ ���������� ������\n" <<
			"1 - �������     2 - ��������� �������\n";
		cin >> selection;
	} while (selection < 1 || selection > 2);
	switch (selection)
	{
	case 1:
		Matrix_1 = Input_Matrix(length_matrix_1, width_matrix_1, Matrix_1);
		Matrix_2 = Input_Matrix(length_matrix_2, width_matrix_2, Matrix_2);
		cout << "\n������� 1\n\n";
		Print_Matrix(length_matrix_1, width_matrix_1, Matrix_1);
		cout << "\n������� 2\n\n";
		Print_Matrix(length_matrix_2, width_matrix_2, Matrix_2);
		break;
	case 2:
		Matrix_1 = Random_Matrix(length_matrix_1, width_matrix_1, Matrix_1);
		Matrix_2 = Random_Matrix(length_matrix_2, width_matrix_2, Matrix_2);
		cout << "\n������� 1\n\n";
		Print_Matrix(length_matrix_1, width_matrix_1, Matrix_1);
		cout << "\n������� 2\n\n";
		Print_Matrix(length_matrix_2, width_matrix_2, Matrix_2);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////���������� ������ � ���������� �������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (length_required_matrix < length_matrix_1 ||
		   length_required_matrix < length_matrix_2 ||
		   length_required_matrix < width_matrix_1 ||
		   length_required_matrix < width_matrix_2)
		   length_required_matrix *= 2;
	//int** new_Matrix_1 = New_Init_Matrix(length_required_matrix, length_required_matrix);
	//int** new_Matrix_2 = New_Init_Matrix(length_required_matrix, length_required_matrix);
	int** new_Matrix_1 = new int* [length_required_matrix];
	for (int i = 0; i < length_required_matrix; i++)
	{
		new_Matrix_1[i] = new int[length_required_matrix];
		for (int j = 0; j < length_required_matrix; j++)
			new_Matrix_1[i][j] = 0;
	}
	int** new_Matrix_2 = new int* [length_required_matrix];
	for (int i = 0; i < length_required_matrix; i++)
	{
		new_Matrix_2[i] = new int[length_required_matrix];
		for (int j = 0; j < length_required_matrix; j++)
			new_Matrix_2[i][j] = 0;
	}

	for (int i = 0; i < length_matrix_1; i++)
	{
		for (int j = 0; j < width_matrix_1; j++)
			new_Matrix_1[i][j] = Matrix_1[i][j];
	}
	for (int i = 0; i < length_matrix_2; i++)
	{
		for (int j = 0; j < width_matrix_2; j++)
			new_Matrix_2[i][j] = Matrix_2[i][j];
	}
	cout << "����������� �������\n";
	cout << "\n����������� ������� 1\n\n";
	Print_Matrix(length_required_matrix, length_required_matrix, new_Matrix_1);
	cout << "\n����������� ������� 2\n\n";
	Print_Matrix(length_required_matrix, length_required_matrix, new_Matrix_2);

	///////////////////////////////////////////////////////////////////////////////
	///////////////��������� ������ �� ���������� � �� ����������//////////////////
	///////////////////////////////////////////////////////////////////////////////
	int** sub_matrix_1 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_2 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_3 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_4 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_5 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_6 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_7 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** sub_matrix_8 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);

	
	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{
			sub_matrix_1[i][j] = new_Matrix_1[i][j];
			sub_matrix_2[i][j] = new_Matrix_1[i][j + length_required_matrix / 2];
			sub_matrix_3[i][j] = new_Matrix_1[i + length_required_matrix / 2][j];
			sub_matrix_4[i][j] = new_Matrix_1[i + length_required_matrix / 2][j + length_required_matrix / 2];
			sub_matrix_5[i][j] = new_Matrix_2[i][j];
			sub_matrix_6[i][j] = new_Matrix_2[i][j + length_required_matrix / 2];
			sub_matrix_7[i][j] = new_Matrix_2[i + length_required_matrix / 2][j];
			sub_matrix_8[i][j] = new_Matrix_2[i + length_required_matrix / 2][j + length_required_matrix / 2];
		}
	}




	///////////////////////////////////////////////////////////////////////////////
	////////////////////////�������� ������������� ������//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	
	int** intermediate_matrix_1 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** intermediate_matrix_2 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** intermediate_matrix_3 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** intermediate_matrix_4 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** intermediate_matrix_5 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** intermediate_matrix_6 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** intermediate_matrix_7 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	


	///////////////////////////////////////////////////////////////////////////////
	////////////////////���������� �������� ������������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{
			intermediate_matrix_1[i][j] = 0;
			intermediate_matrix_2[i][j] = 0;
			intermediate_matrix_3[i][j] = 0;
			intermediate_matrix_4[i][j] = 0;
			intermediate_matrix_5[i][j] = 0;
			intermediate_matrix_6[i][j] = 0;
			intermediate_matrix_7[i][j] = 0;
			for (int z = 0; z < length_required_matrix / 2; z++)
			{
				intermediate_matrix_1[i][j] += (sub_matrix_1[i][z] + sub_matrix_4[i][z]) * (sub_matrix_5[z][j] + sub_matrix_8[z][j]);
				intermediate_matrix_2[i][j] += (sub_matrix_3[i][z] + sub_matrix_4[i][z]) * sub_matrix_5[z][j];
				intermediate_matrix_3[i][j] += sub_matrix_1[i][z] * (sub_matrix_6[z][j] - sub_matrix_8[z][j]);
				intermediate_matrix_4[i][j] += sub_matrix_4[i][z] * (sub_matrix_7[z][j] - sub_matrix_5[z][j]);
				intermediate_matrix_5[i][j] += (sub_matrix_1[i][z] + sub_matrix_2[i][z]) * sub_matrix_8[z][j];
				intermediate_matrix_6[i][j] += (sub_matrix_3[i][z] - sub_matrix_1[i][z]) * (sub_matrix_5[z][j] + sub_matrix_6[z][j]);
				intermediate_matrix_7[i][j] += (sub_matrix_2[i][z] - sub_matrix_4[i][z]) * (sub_matrix_7[z][j] + sub_matrix_8[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////�������� ��������������� ������/////////////////////////
	///////////////////////////////////////////////////////////////////////////////


	int** help_matrix_9 =  New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** help_matrix_10 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** help_matrix_11 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);
	int** help_matrix_12 = New_Matrix(length_required_matrix / 2, length_required_matrix / 2);



	///////////////////////////////////////////////////////////////////////////////
	////////////������� �������� ��������������� ������ �� �������������///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{
			help_matrix_9[i][j] = intermediate_matrix_1[i][j] + intermediate_matrix_4[i][j] - intermediate_matrix_5[i][j] + intermediate_matrix_7[i][j];
			help_matrix_10[i][j] = intermediate_matrix_3[i][j] + intermediate_matrix_5[i][j];
			help_matrix_11[i][j] = intermediate_matrix_2[i][j] + intermediate_matrix_4[i][j];
			help_matrix_12[i][j] = intermediate_matrix_1[i][j] - intermediate_matrix_2[i][j] + intermediate_matrix_3[i][j] + intermediate_matrix_6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////�������� �������������� �������/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** Result_Matrix = New_Matrix(length_required_matrix, length_required_matrix);
	

	///////////////////////////////////////////////////////////////////////////////
	///////��������� ���������� �� ��������������� ������ � ��������������/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{
			Result_Matrix[i][j] = help_matrix_9[i][j];
			Result_Matrix[i][j + length_required_matrix / 2] = help_matrix_10[i][j];
			Result_Matrix[i + length_required_matrix / 2][j] = help_matrix_11[i][j];
			Result_Matrix[i + length_required_matrix / 2][j + length_required_matrix / 2] = help_matrix_12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////������������ ������ �������������� �������/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int count_for_rows_and_colums = 0, 
		length_Answer_matrix = Length_Answer_Matrix(length_required_matrix, Result_Matrix),
		width_Answer_matrix =  Length_Answer_Matrix(length_required_matrix, Result_Matrix);
	

	int** Answer_Matrix = new int* [length_Answer_matrix];
	for (int i = 0; i < length_Answer_matrix; i++)
	{
		Answer_Matrix[i] = new int[width_Answer_matrix];
		for (int j = 0; j < width_Answer_matrix; j++)
			Answer_Matrix[i][j] = Result_Matrix[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////����� �������������� �������////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\n�������������� �������\n\n";
	Print_Matrix(length_Answer_matrix, width_Answer_matrix, Answer_Matrix);
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////������� ������������ ������///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	Delete_Matrix(length_matrix_1, Matrix_1);
	Delete_Matrix(length_matrix_2, Matrix_2);
	Delete_Matrix(length_required_matrix, new_Matrix_1);
	Delete_Matrix(length_required_matrix, new_Matrix_2);
	Delete_Matrix(length_required_matrix, Result_Matrix);
	Delete_Matrix(length_Answer_matrix, Answer_Matrix);
	Delete_Matrix(length_required_matrix/2, sub_matrix_1);
	Delete_Matrix(length_required_matrix/2, sub_matrix_2);
	Delete_Matrix(length_required_matrix/2, sub_matrix_3);
	Delete_Matrix(length_required_matrix/2, sub_matrix_4);
	Delete_Matrix(length_required_matrix/2, sub_matrix_5);
	Delete_Matrix(length_required_matrix/2, sub_matrix_6);
	Delete_Matrix(length_required_matrix/2, sub_matrix_7);
	Delete_Matrix(length_required_matrix/2, sub_matrix_8);
	Delete_Matrix(length_required_matrix/2, help_matrix_9);
	Delete_Matrix(length_required_matrix / 2, help_matrix_10);
	Delete_Matrix(length_required_matrix / 2, help_matrix_11);
	Delete_Matrix(length_required_matrix / 2, help_matrix_12);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_1);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_2);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_3);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_4);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_5);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_6);
	Delete_Matrix(length_required_matrix / 2, intermediate_matrix_7);
	
	
	delete[] Matrix_1, Matrix_2, new_Matrix_1, new_Matrix_2, Result_Matrix, Answer_Matrix;
	delete[] sub_matrix_1, sub_matrix_2, sub_matrix_3, sub_matrix_4, sub_matrix_5, sub_matrix_6, sub_matrix_7, sub_matrix_8, help_matrix_9, help_matrix_10, help_matrix_11, help_matrix_12;
	delete[] intermediate_matrix_1, intermediate_matrix_2, intermediate_matrix_3, intermediate_matrix_4, intermediate_matrix_5, intermediate_matrix_6, intermediate_matrix_7;
}
