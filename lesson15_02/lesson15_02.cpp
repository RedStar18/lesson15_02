// lesson15_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

class Adress
{
    std::string city;
    std::string street;
    unsigned int house;
    unsigned int apartment;
public:
    Adress() : city(""), street(""), house(0), apartment(0) {}
    Adress(std::string city, std::string street, unsigned int house, unsigned int apartment) :
        city(city), street(street), house(house), apartment(apartment) {
    }
    std::string get_output_address()
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
    std::string get_city()
    {
        return city;
    }
};

void sort(Adress* addresses, unsigned int size);

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);

    std::ifstream fileIn("..\\in.txt");
    std::string str{};
    unsigned int elements = 0;
    Adress* adr = NULL;

    if (fileIn.is_open())
    {
        fileIn >> str;
        elements = std::stoi(str);

        adr = new Adress[elements];

        for (unsigned int i = 0; i < elements; i++)
        {
            fileIn >> str;
            std::string tempCity = str;

            fileIn >> str;
            std::string tempStreet = str;

            fileIn >> str;
            unsigned int tempHouse = std::stoi(str);

            fileIn >> str;
            unsigned int tempApartment = std::stoi(str);

            adr[i] = Adress(tempCity, tempStreet, tempHouse, tempApartment);
        }
    }
    fileIn.close();

    sort(adr, elements);

    std::ofstream fileOut("..\\out.txt");
    if (fileOut.is_open())
    {
        fileOut << std::to_string(elements) << std::endl;

        for (unsigned int i = 0; i < elements; i++)
        {
            fileOut << adr[i].get_output_address() << std::endl;
        }
    }
    fileOut.close();
}

void sort(Adress* addresses, unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; ++i) {
        bool swapped = false;

        for (unsigned int j = 0; j < size - 1 - i; ++j) {
            if (addresses[j].get_city() > addresses[j + 1].get_city()) {
                Adress temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
