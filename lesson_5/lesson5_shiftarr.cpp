/*
* Домашнее задание к уроку 5
* курса "Основы языка С++"
* автор Недокунев А.В.
* среда разработки Notepad++ /компилятор MinGW/
* codepage UTF-8
*/
namespace lesson5{
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
}
