#include <iostream>

// Todas as funções são recursivas

int soma_intervalo_fechado(int A, int B){ 
    if (A == B){ // Caso base
        return B;
    }
    return A + soma_intervalo_fechado(++A, B);
}

int soma_intervalo_aberto(int A, int B){
    return soma_intervalo_fechado(++A, --B);
}

int soma_intervalo_fechado_aberto(int A, int B){
    if (A == B-1){ // Caso base
        return B-1;
    }
    return A + soma_intervalo_fechado_aberto(++A, B);
}

int soma_intervalo_aberto_fechado(int A, int B){
    return soma_intervalo_fechado(++A, B);
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
    int A, B, opt, resultado, carry_on = 1;

    do{
        std::cout << "Qual o tipo de soma de intervalo você deseja calcular?" << std::endl
                  << "1 - Fechado" << std::endl
                  << "2 - Aberto" << std::endl
                  << "3 - Fechado no início e aberto no fim" << std::endl
                  << "4 - Aberto no início e fechado no fim" << std::endl;
        std::cin >> opt;
        
        if (opt == 1){
            std::cout << "Qual o primeiro inteiro do intervalo?" << std::endl;
            std::cin >> A;
            std::cout << "Qual o último inteiro do intervalo?" << std::endl;
            std::cin >> B;
            resultado = soma_intervalo_fechado(A, B);
            std::cout << "O resultado da soma do intervalo fechado é " << resultado << std::endl;
        }
        else if (opt == 2){
            std::cout << "Qual o primeiro inteiro do intervalo?" << std::endl;
            std::cin >> A;
            std::cout << "Qual o último inteiro do intervalo?" << std::endl;
            std::cin >> B;
            resultado = soma_intervalo_aberto(A, B);
            std::cout << "O resultado da soma do intervalo aberto é " << resultado << std::endl;
        }
        else if (opt == 3){
            std::cout << "Qual o primeiro inteiro do intervalo?" << std::endl;
            std::cin >> A;
            std::cout << "Qual o último inteiro do intervalo?" << std::endl;
            std::cin >> B;
            resultado = soma_intervalo_fechado_aberto(A, B);
            std::cout << "O resultado da soma do intervalo fechado no primeiro inteiro e aberto no último é " << resultado << std::endl;
        }
        else if (opt == 4){
            std::cout << "Qual o primeiro inteiro do intervalo?" << std::endl;
            std::cin >> A;
            std::cout << "Qual o último inteiro do intervalo?" << std::endl;
            std::cin >> B;
            resultado = soma_intervalo_aberto_fechado(A, B);
            std::cout << "O resultado da soma do intervalo aberto no primeiro inteiro e fechado no último é " << resultado << std::endl;
        }
        else{
            std::cout << "Opção inválida." << std::endl;
        }

        std::cout << "Deseja calcular outro intervalo? (y/n)" << std::endl;
        carry_on = exit_or_continue();
        
    }while (carry_on == 1);

    return 0;
}