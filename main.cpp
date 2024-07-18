#include <iostream>
#include "structE1.h"
#include <cstring>

int main() {
    Stack *stack = new Stack();
    int ch = 0;

    while (ch != 5) {
        std::cout << "1. Положить\n2. Удалить\n3. Посмотреть\n4.Отсортировать\n5. Выйти\n";
        std::cin >> ch;

        switch (ch) {
            case 1: {
                Data t;
                std::cout << "Введите слово\n";
                char temp[100];
                std::cin >> temp;
                std::strcpy(t.str, temp);
                std::cout << "Введите число\n";
                int i = 0;
                std::cin >> i;
                t.number = i;
                stack->push(t);
                break;
            }
            case 2:
                try{
                stack->pop();
                }catch(...){
                    std::cout<<"ошибка удаления\n";
                }
                break;
            case 3:
                try{
                std::cout << stack->peek().str << " " << stack->peek().number << '\n';
                }catch(...){
                    std::cout<<"ошибка просмотра\n";
                }
                break;
            case 4:
                stack->sort();
                break;
            case 5:
                delete stack;
                break;
            default:
                std::cout << "Неизвестная команда\n";
                break;
        }
    }
    return 0;
}
