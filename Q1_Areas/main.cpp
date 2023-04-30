#include <iostream>
#include <iomanip>
#include "HAreas.hpp"

using type_var = double; // Usando type_var para generalizar o código.


int exit_or_continue(){
    char yes_or_no;
    std::cin >> yes_or_no;
    switch (yes_or_no){
        case 'n':
            return 0;
            break;
        case 'N':
            return 0;
            break;
        case 'y':
            return 1;
            break;
        case 'Y':
            return 1;
            break;
        default:
            std::cout << "Resposta inválida, tente novamente :(" << std::endl;
            return exit_or_continue();
            break;
    }
}

int main(){
    int carry_on = 1, N;
    type_var base, altura, raio, resultado;

    do{
        std::cout << "Qual área você quer calcular hoje?" << std::endl
                  << "1 - Triângulo" << std::endl
                  << "2 - Quadrilátero (Retângulo/Quadrado)" << std::endl
                  << "3 - Círculo" << std::endl;
        std::cin >> N;

        if (N == 1){
            std::cout << "Qual é o tamanho da Base?" << std::endl;
            std::cin >> base;
            std::cout << "Qual é a altura do triângulo?" << std::endl;
            std::cin >> altura;
            resultado = area_triangulo(base, altura);
            std::cout << "A área do triângulo é " << std::fixed << std::setprecision(2) << resultado << "." << std::endl;
        }
        else if (N == 2){
            std::cout << "Qual é o tamanho da Base?" << std::endl;
            std::cin >> base;
            std::cout << "Qual é a altura do quadrilátero?" << std::endl;
            std::cin >> altura;
            resultado = area_quadrilatero(base, altura);
            std::cout << "A área do quadrilátero é " << std::fixed << std::setprecision(2) << resultado << "." << std::endl;
        }
        else if (N == 3){
            std::cout << "Qual é o tamanho do raio do círculo?" << std::endl;
            std::cin >> raio;
            resultado = area_circulo(raio);
            std::cout << "A área do círculo é " << std::fixed << std::setprecision(2) << resultado << "." << std::endl;
        }
        else {
            std::cout << "Opção inválida :(" << std::endl;
        }

        std::cout << "Você deseja calcular uma nova área? (y/n)" << std::endl;
        carry_on = exit_or_continue();

    } while (carry_on == 1);

    return 0;
}