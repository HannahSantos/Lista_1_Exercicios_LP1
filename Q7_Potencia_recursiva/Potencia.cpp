#include <iostream>

// Infelizmente, tem assinatura de função. :(

int potencia(int base, int expoente){ // Função recursiva
    int resultado;
    if (expoente == 0){ // Caso base
        return 1;
    }
    return base * potencia(base, --expoente);
}

int exit_or_continue(){ // Função para determinar a continuação do programa
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
    int base, expoente, resultado, carry_on = 1;

    do{
        std::cout << "Qual a base da sua equação exponencial?" << std::endl;
        std::cin >> base;
        std::cout << "Qual o expoente da sua equação exponencial?" << std::endl;
        std::cin >> expoente;
        resultado = potencia(base, expoente);
        std::cout << "O resultado da potência é " << resultado << "." << std::endl
                  << "Deseja calcular outra equação exponencial? (y/n)" << std::endl;
        carry_on = exit_or_continue();
    } while (carry_on == 1);
    
    return 0;
}