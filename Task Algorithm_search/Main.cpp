#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<unordered_map>

class DataManager {
	std::vector<int> _keys = { 1,1,2,2,4,2,6,7,7,7,2 };
public:
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount;// 
		for (size_t i = 0; i < _keys.size(); i++) {// пробежка по вектору
			const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 });// вставка данных, если вставки не произошло,
			//isInserted = 0, итератор указывает на ключ из-за которого это произошло
			if (!isInserted) {//если вставки не произошло
				auto value = it->second;// создаем переменную и помещаем в нее значение
				value++;// увеличиваем значение на 1
				keyAmount[_keys[i]] = value;// кладем значение в ключ(используя квадратные скобки для обязательной вставки)
				// для перехода на следующую итерацию
			}
		}
		// бежим по мапу
		std::pair<int, int> key_biggesValue = { 0,0 };// создаем пару и инициализируем ее нулями
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {// бежим по мапу
			if (key_biggesValue.second < it->second) {// если значение пары меньше значения мап
				key_biggesValue = std::make_pair(it->first, it->second);// помещаем в пару ключ и значение мап и т.д
			}
		}
		return key_biggesValue.first;// возвращаем ключ пары - максимальное количество обращений
	}
};