#include <iostream>

class Str {
private:
	char* S;                  //  Строка
	int len;              //  Длина строки
	void Filling(const char* s) {
		len = strlen(s);
		S = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			S[i] = s[i];
		}
		S[len] = '\0';
	}
public:
	Str(){			//конструктор
		S = nullptr;          //  начальная инициализация
		len = 0;
	}

	Str(const char *s){
		Filling(s);
	}

	~Str(){
		delete[] this->S;
	}
	
	Str& operator =(const Str &other) {
		if (this->S != nullptr) delete[] S;
		Filling(other.S);
		return *this;
	}

	Str *Separators(char* sepatators) {
		int count = 0;
		Str temp = S;
		char* temp2 = S;
		Str* arr = new Str[count];

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < strlen(sepatators); j++)
			{
				if (temp.S[i] == sepatators[j]) {
					for (int k = 0; k < i; ++k) temp2[k] = ' ';
					temp.S[i] = 0;
					arr[count].Filling(temp.S);
					count++;
					temp = temp2;
				}
			}
		}
		return arr;
	}

	bool Contains(char* symbol) {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < strlen(symbol); j++)
			{
				if (S[i] == symbol[j]) return true;
			}
		}
		return false;
	}

	int GetLength() { return len; }

	void Print() {
		std::cout << S;
	}
};