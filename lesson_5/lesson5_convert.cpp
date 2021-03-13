/*
* Домашнее задание к уроку 5
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
namespace lesson5{
	void convert(int* arr, int s){//для 1 задания
		for (int i=0; i < s; i++){
			arr[i] = 1 - arr[i];//у нас только 0 и 1 - зачем тут "if-else, switch, () ? :)"? :)
		}
	}
}