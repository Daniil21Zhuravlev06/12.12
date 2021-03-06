//Даниил Журавлёв
#include <iostream>
#include <Windows.h>
using namespace std;
class Knight {
	
	//данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;
public:
	
	//setter, функции - сеттеры (заменяют присваивание)
	void set_hp(double hp) { m_hp = hp; }
	void set_damage(double damage) { m_damage = damage; }
	void set_name(string name) { m_name = name; }
	
	//вместо всех сеттеров можно написать один конструктор
	Knight(string name, double hp, double damage) {
		m_hp = hp;
		m_damage = damage;
		m_name = name;
	}
	
	//геттер
	double get_hp() { return m_hp; }
	double get_damage() { return m_damage; }
	string get_name() { return m_name; }

	//увеличение дамага
	void increaseDamage() {
		m_damage *= 1.1;
	}
	void print() {
		cout << "Knight name " << m_name << endl;
		cout << "Knight hp " << m_hp << endl;
		cout << "Knight damage " << m_damage << endl;
	}
	//атака
	void attack(Mage& m1) {
		m1.set_hp(m1.get_hp() - get_damage());
	}
};



	class Mage {
		//данные объекта
	private:
		double m_hp;
		double m_damage;
		string m_name;
		//методы класса (функции, определяющие поведение объекта)
	public:
		
		//setter, функции - сеттеры (заменяют присваивание)
		void set_hp(double hp) { m_hp = hp; }
		void set_damage(double damage) { m_damage = damage; }
		void set_name(string name) { m_name = name; }
		
		//геттер
		double get_hp() { return m_hp; }
		double get_damage() { return m_damage; }
		string get_name() { return m_name; }

		//увеличение дамага
		void increaseHp(double addHp) {
			m_hp += addHp;
		}
		void print() {
			cout << "Mage name " << m_name << endl;
			cout << "Mage hp " << m_hp << endl;
			cout << "Mage damage " << m_damage << endl;
		}
	};
	int main() {
		
		//создали рыцаря
		Knight k1("Valera", 100, 20);
		// записали в него данные
		/*k1.set_name("Dadalka");
		k1.set_hp(100);
		k1.set_damage(20);
		k1.print();*/
		cout << endl;
		
		//создали мага
		Mage m1;
		
		// записали в него данные
		m1.set_name("Galyunia");
		m1.set_hp(50);
		m1.set_damage(20);
		m1.print();
		
		//основной игровой цикл
		while (true) {
			cout << "Dadalka hit mage" << endl;
			//бьёт мага
			k1.attack(m1);
			//распечатываем мага
			m1.print();
			
			//проверяем на смерть
			if (m1.get_hp() <= 0) {
				cout << "Dadalka win!" << endl;
				break;
			}
			
			//рыцарь увеличил дамаг
			cout << "What is your choice? Press 1 to increase damage by 10%";
			int choice;
			cin >> choice;
			switch (choice) {
			case 1:
				k1.increaseDamage();
				break;
				// case 2:
				//case 3:
			}
			k1.increaseDamage();
			
			//задержка на 3000мс = 3с
			
			//ход мага
			cout << "Galyunia hit knight" << endl;
			k1.set_hp(m1.get_hp() - m1.get_damage());
			//
			k1.print();
			if (k1.get_hp() <= 0) {
				cout << "Galyunia win!" << endl;
				break;
			}
			m1.increaseHp(50);
			Sleep(3000);
		}
		return 0;
    }