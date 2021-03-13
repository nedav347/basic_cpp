/*
* Домашнее задание к уроку 5
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
#include <iostream>
#include <stdarg.h>

void convert(int* arr, int s){//для 1 задания
	for (size_t i=0; i < s; i++){
		arr[i] = 1 - arr[i];//у нас только 0 и 1 - зачем тут "if-else, switch, () ? :)"? :)
	}
}

void fill(int* arr, int s){//для 2 задания
	int val = 1;
	for (size_t i=0; i < s; i++){
		arr[i] = val;//это ж не Фибоначчи... :)
		val += 3;
	}
}

bool checkBalance(int* arr, int s){//для 3* задания
	int a = 0, b = 0;
	for (size_t i = 0; i < s; i++){//найдем сумму всех элементов массива
		a += arr[i];
	}
	for (size_t j = 0; j < s; j++){//последовательно передвигаясь слева-направо, проверяем, не сравнялись ли сумма элементов слева и сумма элементов справа
		a -= arr[j];
		b += arr[j];
//		printf("%d == %d\n", a, b);//проверка
		if (a == b){
			return true;//искомое найдено
		}
	}
	return false;
}

void shiftarr(int* arr, int size, int shift){//для 4* задания
	if (shift > size || (0 - shift) > size){//проверка, чтобы значение сдвига небыло больше размера массива (зачем нам круги наматывать)
		shift = shift - (shift / size) * size;//выкидываем полные обороты
	}
	if (shift % size == 0){//если сдвиг равен или кратен размеру массива - массив не изменяется
		return;
	}
	int tmp = arr[0], val_to = 0, val_from;//возможно, здесь надо register int...
	val_from = shift > 0 ? shift : size + shift;//переключатель направления сдвига
	for (int i = 0; i < size - 1; i++){//последовательно сдвигаем
		arr[val_to] = arr[val_from];
		val_to = val_from;
		val_from += shift;
		if (val_from > size){//поскольку меняем через "shift" элементов - заходим на следующий круг
			val_from -= size;//для положительного (влево)
		}
		if (val_from < 0){
			val_from += size;//для отрицательного (вправо)
		}
	}
	arr[val_to] = tmp;//возвращаем сохраненное на освободившееся в последней итерации место
//	for (size_t k = 0; k < size; k++){//вывод результата для проверки
//		std::cout << "arr[" << k << "]=" << arr[k] << std::endl;
//	}
}

void convert_v(int * arr, int count, ...){//для 5** задания
	va_list lst;
	va_start(lst, count);
	for (size_t i = 0; i < count; i++){
		arr[i] = 1 - va_arg(lst, int); 
	}
	va_end(lst);
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
	convert(arr_c, size10);
	for (size_t i = 0; i < size10; i++){//вывод массива для проверки работы функции
		printf("%d, ", arr_c[i]);
	}
	printf("\n");
		
/*Задание 2
Задать пустой целочисленный массив размером 8. 
Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
*/
	const int size8 = 8;
	int arr_f[size8];
	fill(arr_f, size8);

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
	if (checkBalance(arr_31, size_5)){
		std::cout << "1: " << "TRUE" << std::endl;
	} else {
		std::cout << "1: " << "false" << std::endl;
	}
	if (checkBalance(arr_32, size_5)){
		std::cout << "2: " << "TRUE" << std::endl;
	} else {
		std::cout << "2: " << "false" << std::endl;
	}
	if (checkBalance(arr_33, size_5)){
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
	shiftarr(arr_s, size, shdir);
	shdir = -3;
	shiftarr(arr_s, size, shdir);
	shdir = 33;
	shiftarr(arr_s, size, shdir);
	shdir = 103;
	shiftarr(arr_s, size, shdir);
	shdir = -103;
	shiftarr(arr_s, size, shdir);

/*Задание 5**
Написать функцию из первого задания так, 
чтобы она работала с аргументом переменной длины.
*/
	int arr_v[size10] = {};
	convert_v(arr_v, size10, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1);
	for (size_t i = 0; i < size10; i++){//вывод массива для проверки работы функции
		printf("%d, ", arr_v[i]);
	}
	printf("\n");


/*Задание 6**
Написать все функции в отдельных файлах в одном пространстве имён, 
вызвать их на исполнение в основном файле программы используя указатели на функции.
*/
//	int (*func_name) (int&, int&);//образец объявления указателя на функцию
//	func_name = function_name;//инициализация указателя
	//прототипы - в namespace, реализацию - вне, но с указанием  namespace!

	return 0;
}
