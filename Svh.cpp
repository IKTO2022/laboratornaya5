#include <iostream>
#include <string>

class SVH {
	private:
		//Свойства
		bool powerOn;      //Состояние: включен\нет
		bool energized;      //Состояние: запитан\нет
		bool does; // Состояние: готово\нет

	public:
		// Конструктор по умолчанию
		SVH() : powerOn(false), energized(false), does(false) {}

		// Конструктор с параметрами
		SVH(bool power, bool energe, bool boil)
			: powerOn(power), energized(energe), does(boil) {}

		// Методы
		void turnOn() {
			powerOn = true;
			std::cout << "микроволновка включена";
		}

		void turnOff() {
			powerOn = false;
			std::cout << "микроволновка выключена";
		}

		void energe() {
			energized = true;
			std::cout << "микроволновка включена в сеть";
		}

		void discharge() {
			energized = false;
			std::cout << "микроволновка не включена в сеть";
		}

		void connectToWifi() {
			does = true;
			std::cout << "еда готова";
		}

		void disconnectFromWifi() {
			does = false;
			std::cout << "еда не готова";

			// Отображения текущего состояния
			void displayState() const {
				std::cout << "Состояния СВЧ печи";
				std::cout << "Включена: " << (powerOn ? "1" : "0") << "\n";
				std::cout << "Запитана: " << (energized ? "Да" : "Нет") << "\n";
				std::cout << "Еда готова: " << (does ? "Да" : "Нет") << "\n";
			}

			// Метод установки свойств
			void setProperties(bool power, bool energe, bool boil); {
				powerOn = power;
				energized = energe;
				does = boil;
			}
		};

		int main() {
			// Создание объекта ноутбука
			SVH elSVH;

			// Меню взаимодействия
			int choice;
			setlocale(LC_ALL, "Russian");

			std::cout << "1. Создать СВЧ печь\n";
			std::cout << "2. Состояния\n";
			std::cout << "3. Включен\n";
			std::cout << "4. Выключен\n";
			std::cout << "5. Запитана\n";
			std::cout << "6. Не запитана\n";
			std::cout << "7. Еда готова\n";
			std::cout << "8.  Еда не готова\n";
			std::cout << "9. Выход\n";
			std::cout << "Введите цифру: ";
			std::cin >> choice;

			switch (choice) {
				case 1: {
					bool power, energe, boil;
					std::cout << "Введите состояние (включен/выключен): ";
					std::string powerInput;
					std::cin >> powerInput;
					power = (powerInput == "включен");

					std::cout << "Введите состояние питания (да/нет): ";
					std::string chargeInput;
					std::cin >> chargeInput;
					energe = (chargeInput == "да");

					std::cout << "Введите состояние приготовления (готово/не готово): ";
					std::string wifiInput;
					std::cin >> wifiInput;
					boil = (wifiInput == "готово");

					elSVH.setProperties(power, energe, boil);
					break;
				}
				case 2:
					elSVH.displayState();
					break;
				case 3:
					elSVH.turnOn();
					break;
				case 4:
					elSVH.turnOff();
					break;
				case 5:
					elSVH.energe();
					break;
				case 6:
					elSVH.discharge();
					break;
				case 7:
					elSVH.connectToWifi();
					break;
				case 8:
					elSVH.disconnectFromWifi();
					break;
				case 9:
					std::cout << "Выйти";
					break;
				default:
					std::cout << "Что-то пошло не так, попробуйте снова";
					while (choice != 9);
			}
			return 0;
		};
