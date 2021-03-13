/*
* Домашнее задание к уроку 5
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
#include <stdarg.h>
namespace lesson5{
	void convert_v(int * arr, int count, ...){//для 5** задания
		va_list lst;
		va_start(lst, count);
		for (int i = 0; i < count; i++){
			arr[i] = 1 - va_arg(lst, int); 
		}
		va_end(lst);
	}
}