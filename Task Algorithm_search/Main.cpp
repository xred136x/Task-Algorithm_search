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
		for (size_t i = 0; i < _keys.size(); i++) {// �������� �� �������
			const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 });// ������� ������, ���� ������� �� ���������,
			//isInserted = 0, �������� ��������� �� ���� ��-�� �������� ��� ���������
			if (!isInserted) {//���� ������� �� ���������
				auto value = it->second;// ������� ���������� � �������� � ��� ��������
				value++;// ����������� �������� �� 1
				keyAmount[_keys[i]] = value;// ������ �������� � ����(��������� ���������� ������ ��� ������������ �������)
				// ��� �������� �� ��������� ��������
			}
		}
		// ����� �� ����
		std::pair<int, int> key_biggesValue = { 0,0 };// ������� ���� � �������������� �� ������
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {// ����� �� ����
			if (key_biggesValue.second < it->second) {// ���� �������� ���� ������ �������� ���
				key_biggesValue = std::make_pair(it->first, it->second);// �������� � ���� ���� � �������� ��� � �.�
			}
		}
		return key_biggesValue.first;// ���������� ���� ���� - ������������ ���������� ���������
	}
};