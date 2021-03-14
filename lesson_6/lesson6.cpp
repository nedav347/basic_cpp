/*
* Домашнее задание к уроку 
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
#include <iostream>
#include <fstream>

void err_open_file(const char *arg){
		std::cout << "Ошибка открытия файла " << arg << std::endl;
	}
	
int concat2file(const char *file1, const char *file2, const char *file3){
	std::ifstream fin;
	std::ofstream fos;
	fin.open(file1);
	if (!fin.is_open()){
		err_open_file("1");
		return 1;
	}
	fin.seekg(0, std::ios_base::end);
	int filesize = fin.tellg();
//	int countchar = fin.tellg() / sizeof(char);
//	char* char_arr = (char*) calloc(filesize / sizeof(char), sizeof(char));
	char* char_arr1 = (char*) calloc(filesize, 1);
	fin.seekg(0, std::ios_base::beg);
	fin.get(char_arr1, filesize);
//	std::cout << char_arr1 << std::endl;
	fin.close();
	fin.open(file2);
	if (!fin.is_open()){
		err_open_file("2");
		return 1;
	}
	fin.seekg(0, std::ios_base::end);
	filesize = fin.tellg();
	char* char_arr2 = (char*) calloc(filesize, 1);
	fin.seekg(0, std::ios_base::beg);
	fin.get(char_arr2, filesize);
//	std::cout << char_arr2 << std::endl;
	fin.close();
	fos.open(file3);
	if (!fos.is_open()){
		err_open_file("3");
		return 1;
	}
	fos << char_arr1 << char_arr2;
	fos.close();
	return 0;
}

int main(int argc, const char** argv){
/*Задание 1
Написать программу, которая создаст два текстовых файла, 
примерно по 50-100 символов в каждом (особого значения не имеет);
*/
	std::ofstream fos("lesson6_1.txt");
	if (!fos.is_open()){
		err_open_file("4");
		return 1;
	}
//	fos << "Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом (особого значения не имеет) << std::endl;
	fos << "Write a program that will create two text files, about 50-100 characters each (does not really matter). " << std::endl;
	fos.close();
	fos.open("lesson6_2.txt");
	if (!fos.is_open()){
		err_open_file("5");
		return 1;
	}
//	fos << "Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера." << std::endl;
	fos << "Write a function that \"glue\" these files, pre-buffering their contents into a dynamically allocated memory segment of the required size." << std::endl;
	fos.close();
	
		
/*Задание 2
Написать функцию, «склеивающую» эти файлы, 
предварительно буферизуя их содержимое 
в динамически выделенный сегмент памяти нужного размера.
*/
	if (concat2file("lesson6_1.txt", "lesson6_2.txt", "lesson6_3.txt")){
		return 1;
	}
	

/*Задание 3*
Написать программу, которая проверяет присутствует ли 
указанное пользователем при запуске программы слово 
в указанном пользователем файле 
(для простоты работаем только с латиницей).
*/
	std::ifstream fin;
	if (argc < 2){
		std::cout << "Не введено имя файла!" << std::endl;
		std::cout << "Использование: " << argv[0] << " имя_файла";
		return 1;//вывести правила использования
	}
	std::string s;
	std::cout << "Введите имя файла: ";
	std::cin >> s;
	fin.open(s);
	if (!fin.is_open()){
		err_open_file("6");
		return 1;
	}
//	for(fin >> s; !fin.eof(); fin >> s){
//		std::cout << s << std::endl;
//		if (s == argv[1]){
//			std::cout << "\033[31m" << "_Math!!!_" << "\033[0m" << std::endl;
//			return 0;
//		}
//	}
	while (!fin.eof()){		
		fin >> s;
		std::cout << s << std::endl;
		if (s == argv[1]){
			std::cout << "\033[3;44;93m_Math!!!_\033[0m" << std::endl;
			return 0;
		}
	}

	return 0;
}
