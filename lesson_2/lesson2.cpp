/*
* Домашнее задание к уроку 2
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
#include <iostream>

int main()
{
//Задание 1
//объявляем и сразу инициализируем
	int type_int = 2147483647; //4 байта -2 147 483 648 / 2 147 483 647
	unsigned int type_uint = 4294967295; //4 байта
	short type_short = 32767; //2 байта -32 768 / 32 767
	unsigned short type_ushort = 65535; //2 байта
	long type_long = 2147483647; //4 байта
	unsigned long type_ulong = 4294967295; //4 байта
	char type_char = 'a'; //1 байт
	float type_float = 2147483647.0; //4 байта
	double type_double = 9223372036854775807.0; //8 байт
	
//объявляем тип данных enum, заодно и Задание 2 выполним
	enum SYMBOL{PLAYER_1_WIN = 'X', PLAYER_2_WIN = 'O', SPACE = ' ', PLAYER_1 = 'x', PLAYER_2 = 'o',  HORIZ = '-', VERT = '|', CROSS = '+'};//объявляем тип данных enum	
//хотя enum вообще-то int, для удобочитаемости пишем символы, а не их коды ASCII
	enum SYMBOL p1 = PLAYER_1;//объявляем переменную и сразу инициализируем
	enum SYMBOL p2 = PLAYER_2;
	enum SYMBOL s = SPACE;
	enum SYMBOL p1w = PLAYER_1_WIN;
	enum SYMBOL p2w = PLAYER_2_WIN;
	enum SYMBOL h = HORIZ;
	enum SYMBOL v = VERT;
	enum SYMBOL x = CROSS;
	
//объявляем тип данных struct, заодно и Задание 4* выполним
	static const int size_x = 3, size_y = 3;
	struct sGame_field {
		const int in_line = 3;//количество полей для выигрыша
		struct sCell {//структура для клетки поля
			int x_coord, y_coord;//координаты клетки поля
			int mode;//состояние клетки поля, где 0 - пусто, 1 - занято игроком 1, 2 - занято игроком 2
		} cell_arr[size_x][size_y];
	} MyField;
	for (int a = 0; a < size_x; a++) {//инициализируем игровое поле 
		for (int b = 0; b < size_y; b++) {
			MyField.cell_arr[a][b].x_coord = a;
			MyField.cell_arr[a][b].y_coord = b;
			MyField.cell_arr[a][b].x_coord = 0;
		};
	};
			
//объявляем тип данных union
	union type_union {
		int i;
		char c;
		float f;
	};
	union type_union U_1;//объявляем переменную
	U_1.f = 2147483647.0;//инициализируем

//Задание 3
	char field[5][5];//создаем массив
	for (int k = 0; k < 5; k++){//инициализируем массив пустым полем для игры крестики-нолики
		for (int m = 0; m < 5; m++){
			if ((m % 2 == 0) && (k % 2 == 0)){
				field[k][m] = s;
			} else if ((m % 2 != 0) && (k % 2 != 0)) {
				field[k][m] = x;
			} else if (m % 2 != 0) {
				field[k][m] = v;
			} else if (k % 2 != 0) {
				field[k][m] = h;
			}
			printf("%c", field[k][m]);//просто, чтобы проверить себя
		}
		printf("\n");//наверное, можно было добавить перевод строки в каждый последний элемент строки (тогда размерность станет [5][6] 
	}
	
//Задание 5*
	struct s_byte {//объявляем тип данных struct,
		union type_union {//объявляем тип данных union
			int i;
			char c;
			float f;
		};
		int is_int : 1;
		int is_char : 1;
		int is_float : 1;
	};
	
	
/*
	printf("sizeof int %d, %d\n", sizeof(int), type_int);
	printf("sizeof uint %d, %u\n", sizeof(unsigned int), type_uint);
	printf("sizeof short %d, %hd\n", sizeof(short), type_short);
	printf("sizeof short %d, %hu\n", sizeof(unsigned short), type_ushort);
	printf("sizeof long %d, %ld\n", sizeof(long), type_long);
	printf("sizeof long %d, %lu\n", sizeof(unsigned long), type_ulong);
	printf("sizeof char %d, %c\n", sizeof(char), type_char);
	printf("sizeof float %d, %f\n", sizeof(float), type_float);
	printf("sizeof double %d, %f\n", sizeof(double), type_double);
*/
	return 0;
}
