#include <iostream>
#include <fstream>
#include <string>

// Função para determinar a continuação do programa.
int exit_or_continue();

int main(){
    std::fstream Playlist;
    std::string musica, linha;
    int opt, carry_on{1}, kount{0}, found{0};

    do{
        std::cout << "O que você deseja fazer?" << std::endl
                  << "1 - Inserir nova música" << std::endl
                  << "2 - Procurar música na Playlist" << std::endl;
        std::cin >> opt;

        if (opt == 1){
            std::cout << "Qual é o nome da música a ser inserida?" << std::endl;
            Playlist.open("Biblioteca_de_Músicas.txt", std::ios::out|std::ios::app);
            std::getline(std::cin >> std::ws, musica);
            Playlist << musica << std::endl;
            Playlist.close();
        }
        else if (opt == 2){
            std::cout << "Qual é a música que você está procurando?" << std::endl;
            std::getline(std::cin >> std::ws, musica);
            Playlist.open("Biblioteca_de_Músicas.txt", std::ios::in|std::ios::app);
            while (std::getline(Playlist, linha)){
                ++kount;
                if (musica.compare(linha) == 0){
                    std::cout << "Música achada na linha " << kount << "." << std::endl;
                    found = 1;
                    break;
                }
            }
            Playlist.close();
            if (found != 1){
                std::cout << "Essa música não foi encontrada, cheque maiúsculas e minúsculas ou adicione uma nova música." << std::endl;
            }
            found = 0;
        }
        else {
            std::cout << "Essa opção não existe ainda, contate-nos caso queira fazer sujestões de novas funções para a Playlist.:D" << std::endl;
        }

        std::cout << "Deseja continuar? (y/n)" << std::endl;
        carry_on = exit_or_continue();
    }while (carry_on == 1);

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