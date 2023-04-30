#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

// Função para determinar a continuação do programa.
int exit_or_continue();

// Função para escrever na Planilha.
void insert_students(std::fstream *Planilha);

// Função para ler o arquivo
void read_students(std::vector<std::string> &Aeeee);

// Calcular média
double calcular_media(std::string nota1, std::string nota2, std::string nota3);

// Inserir médias no map.
void map_insert(std::map<std::string, double> &Medias, std::string nome, double media);

// Imprimir alunos e médias.
void print_map(std::vector<std::string> &Aeeee, std::map<std::string, double> &Medias);

int main(){
    std::map<std::string, double> Medias{};
    std::fstream Planilha;
    int carry_on = 1;
    std::vector<std::string> Aeeee{}; // Despicable Me reference :P
    double media;

    do{
        Planilha.open("Alunos_Notas.txt", std::ios::out|std::ios::app);
        insert_students(&Planilha);
        Planilha.close();

        std::cout << "Deseja adicionar mais alunos? (y/n)" << std::endl;
        carry_on = exit_or_continue();
    }while (carry_on == 1);

    read_students(Aeeee);

    for (auto i{0}; i < Aeeee.size(); i+=4){
        media = calcular_media(Aeeee[i+1], Aeeee[i+2], Aeeee[i+3]);
        map_insert(Medias, Aeeee[i], media);
    }

    std::cout << "As médias dos alunos foram: " << std::endl;
    print_map(Aeeee, Medias);

    return 0;
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

void insert_students(std::fstream *Planilha){
    std::string nome;
    double nota1, nota2, nota3;
    std::cout << "Qual o nome de seu aluno(a)?" << std::endl;
    std::getline(std::cin >> std::ws, nome);
    *Planilha << nome << std::endl;
    std::cout << "Qual foi a primeira nota do aluno(a)?" << std::endl;
    std::cin >> nota1;
    *Planilha << nota1 << std::endl;
    std::cout << "Qual foi a segunda nota do aluno(a)?" << std::endl;
    std::cin >> nota2;
    *Planilha << nota2 << std::endl;
    std::cout << "Qual foi a terceira nota do aluno(a)?" << std::endl;
    std::cin >> nota3;
    *Planilha << nota3 << std::endl;
}

void read_students(std::vector<std::string> &Aeeee){
    std::fstream Leitor;
    std::string linha;
    Leitor.open("Alunos_Notas.txt", std::ios::in|std::ios::app);
    while (std::getline(Leitor, linha)){
        Aeeee.push_back(linha);
    }
    Leitor.close();
}

double calcular_media(std::string nota1, std::string nota2, std::string nota3){
    double media;
    media = (std::stod(nota1) + std::stod(nota2) + std::stod(nota3))/3;
    return media;
}

void map_insert(std::map<std::string, double> &Medias, std::string nome, double media){
    Medias[nome] = media;
}

void print_map(std::vector<std::string> &Aeeee, std::map<std::string, double> &Medias){
    for (auto i{0}; i < Aeeee.size(); i+=4){
        std::cout << Aeeee[i] << " = " << std::fixed << std::setprecision(2) << Medias[Aeeee[i]] << std::endl;
    }
}