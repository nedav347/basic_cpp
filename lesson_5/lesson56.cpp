/*
* Домашнее задание к уроку 5
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
#include <iostream>
#include <stdarg.h>

namespace lesson5{
	void convert(int* arr, int s);//для 1 задания

	void fill(int* arr, int s);//для 2 задания
		
	bool checkBalance(int* arr, int s);//для 3* задания

	void shiftarr(int* arr, int size, int shift);//для 4* задания

	void convert_v(int * arr, int count, ...);//для 5** задания
}

void printarr(int* arr, int size){
	for (size_t i = 0; i < size; i++){//вывод массива для проверки работы функции
			printf("%d, ", arr[i]);
		}
		printf("\n");
}	

int main(){
/*Задание 1
Задать целочисленный массив, состоящий из элементов 0 и 1. 
Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
Написать функцию, заменяющую в принятом массиве 0 на 1, 
1 на 0 
(** без применения if-else, switch, () ? :);
*/
	const int size10 = 10;
	int arr_c[size10] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
	void (*pconvert)(int*, int);
	pconvert = lesson5::convert;
	pconvert(arr_c, size10);
	printarr(arr_c, size10);//вывод массива для проверки работы функции
		
/*Задание 2
Задать пустой целочисленный массив размером 8. 
Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
*/
	const int size8 = 8;
	int arr_f[size8];
	
	void (*pfill)(int*, int);
	pfill = lesson5::fill;
	pfill(arr_f, size8);
	printarr(arr_f, size8);//вывод массива для проверки работы функции

/*Задание 3*
Написать функцию, в которую передается не пустой одномерный целочисленный массив, 
функция должна вернуть истину если в массиве есть место, 
в котором сумма левой и правой части массива равны. 
Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, 
checkBalance ([2, 1, 1, 2, 1]) → false, 
checkBalance ([10, || 1, 2, 3, 4]) → true. 
Абстрактная граница показана символами ||, эти символы в массив не входят.
*/
	const int size_5 = 5;
	int arr_31[size_5] = {1, 1, 1, 2, 1};
	int arr_32[size_5] = {2, 1, 1, 2, 1};
	int arr_33[size_5] = {10, 1, 2, 3, 4};
	bool (*pcheckBalance)(int*, int);
	pcheckBalance = lesson5::checkBalance;
	if (pcheckBalance(arr_31, size_5)){
		std::cout << "1: " << "TRUE" << std::endl;
	} else {
		std::cout << "1: " << "false" << std::endl;
	}
	if (pcheckBalance(arr_32, size_5)){
		std::cout << "2: " << "TRUE" << std::endl;
	} else {
		std::cout << "2: " << "false" << std::endl;
	}
	if (pcheckBalance(arr_33, size_5)){
		std::cout << "3: " << "TRUE" << std::endl;
	} else {
		std::cout << "3: " << "false" << std::endl;
	}

/*Задание 4*
Написать функцию, которой на вход подаётся одномерный массив и число n 
(может быть положительным, или отрицательным), 
при этом функция должна циклически сместить все элементы массива на n позиций.
*/
	int shdir = 3, size = 11;
	int arr_s[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	void (*pshiftarr)(int*, int, int);
	pshiftarr = lesson5::shiftarr;
	pshiftarr(arr_s, size, shdir);
	printarr(arr_s, size);//вывод массива для проверки работы функции
	shdir = -3;
	pshiftarr(arr_s, size, shdir);
	printarr(arr_s, size);//вывод массива для проверки работы функции
	shdir = 33;
	pshiftarr(arr_s, size, shdir);
	printarr(arr_s, size);//вывод массива для проверки работы функции
	shdir = 103;
	pshiftarr(arr_s, size, shdir);
	printarr(arr_s, size);//вывод массива для проверки работы функции
	shdir = -103;
	pshiftarr(arr_s, size, shdir);
	printarr(arr_s, size);//вывод массива для проверки работы функции

/*Задание 5**
Написать функцию из первого задания так, 
чтобы она работала с аргументом переменной длины.
*/
	int arr_v[size10] = {};
	void (*pconvert_v)(int*, int, ...);
	pconvert_v = lesson5::convert_v;
	pconvert_v(arr_v, size10, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1);
	printarr(arr_v, size10);//вывод массива для проверки работы функции


/*Задание 6**
Написать все функции в отдельных файлах в одном пространстве имён, 
вызвать их на исполнение в основном файле программы используя указатели на функции.
*/
//	int (*func_name) (int&, int&);//образец объявления указателя на функцию
//	func_name = function_name;//инициализация указателя
	//прототипы - в namespace, реализацию - вне, но с указанием  namespace!

	return 0;
}
