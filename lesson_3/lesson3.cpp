/*
* Домашнее задание к уроку 3
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
#include <iostream>

extern int ae, be, ce, de;//goto lesson3_ext.cpp

int variable_inint();

int main()
{
/*Задание 1
Написать программу, вычисляющую выражение a * (b + (c / d)) и 
выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы
*/
	const int a = 2, b = 3, c = 4, d = 23;
		printf("a * (b + (c / d)) = %f\n", a * (b + ((float)c / d)));
/*Задание 2
Дано целое число, выведите на экран разницу между этим числом и числом 21. 
Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу 
между этим числом и 21. При выполнении задания следует использовать тернарный оператор.
*/
	printf("delta %d\n", d > 21 ? 2 * (d - 21) : d - 21); 

/*Задание 3
Написать программу, вычисляющую выражение из первого задания, 
а переменные для неё инициализировать в другом файле
*/
		float r;//вначале, до "int main(){", объявим внешние переменные и функцию, которые будут в файле lesson3_ext.cpp
		variable_inint();
		r = ae * (be + ((float)ce / de));
		printf("%f\n", r);

/*Задание 4*
Описать трёхмерный целочисленный массив, размером 3х3х3, указатель на значения внутри массива 
и при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1]
*/
	int arr[3][3][3], *arrptr;
	arrptr = &arr[0][0][0];//в методичке сказано, что arrptr = arr[0] корректная инициализация, но мой компилятор ругается на невозможность присвоить 'int [3][3][3]' указателю 'int*'
	for (int i = 0; i < 3; i++){//чтобы вывести значение какого-то элемента массива, надо сначала занести туда что-то...
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				arr[i][j][k] = i * 100 + j * 10 + k;
//				*(arrptr + i*9 + j*3 + k) = i * 100 + j * 10 + k;//или с использованием указателя
//				printf("Cube (arr[%d][%d][%d]) = %d, %d\n", i, j, k, arr[i][j][k], *(arrptr + i*9 + j*3 + k));
			}
		}
	}
	printf("Center of Cube (arr[1][1][1]) = %d\n", *(arrptr + 13));//*arrptr + 1*9 + 1*3 + 1
	return 0;
}
