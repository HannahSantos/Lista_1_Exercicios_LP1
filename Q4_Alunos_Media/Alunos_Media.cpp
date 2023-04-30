#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using type_var = double;

typedef struct{
    type_var nota1;
    type_var nota2;
    type_var nota3;
}Notas;

type_var calcular_media(std::map<std::string, Notas> Student_situation, std::string nome);

int exit_or_continue();

int main(){
    int carry_on = 1;
    type_var media;
    std::string nome;
    std::map<std::string, Notas> Student_situation;  

    do{
        std::cout << "Por favor, forneça o nome do aluno(a)." << std::endl;
        std::getline(std::cin, nome);
        std::cout << "Qual foi a nota da primeira avaliação desse aluno(a)?" << std::endl;
        std::cin >> Student_situation[nome].nota1;
        std::cout << "Qual foi a nota da segunda avaliação desse aluno(a)?" << std::endl;
        std::cin >> Student_situation[nome].nota2;
        std::cout << "Qual foi a nota da terceira avaliação desse aluno(a)?" << std::endl;
        std::cin >> Student_situation[nome].nota3;
        media = calcular_media(Student_situation, nome);
        std::cout << "A média desse aluno é " << std::fixed << std::setprecision(1) << media << "." << std::endl;
        std::cout << "Deseja calcular a média de outro aluno? (y/n)" << std::endl;
        carry_on = exit_or_continue();
    }while (carry_on == 1);


    return 0;
}

type_var calcular_media(std::map<std::string, Notas> Student_situation, std::string nome){
    type_var media;
    media = (Student_situation[nome].nota1 + Student_situation[nome].nota2 + Student_situation[nome].nota3)/3;
    return media;
}

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