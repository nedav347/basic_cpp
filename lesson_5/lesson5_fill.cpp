/*
* Домашнее задание к уроку 5
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
namespace lesson5{
	void fill(int* arr, int s){//для 2 задания
		int val = 1;
		for (int i=0; i < s; i++){
			arr[i] = val;//это ж не Фибоначчи... :)
			val += 3;
		}
	}
}