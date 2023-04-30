#include <iostream>
#include <list>

using type_var = int;

// Função para determinar a continuação do programa.
int exit_or_continue();

int main(){
    std::list<type_var> queue{};
    std::list<type_var>::iterator cheeky_printer;
    int opt, carry_on = 1, kount = 0;
    type_var new_insertion;

    do{
        std::cout << "O que deseja fazer na lista queue?" << std::endl
                  << "1 - Inserir novo termo" << std::endl
                  << "2 - Deletar primeiro termo" << std::endl
                  << "3 - Imprimir lista queue" << std::endl;
        std::cin >> opt;
        
        if (opt == 1){
            std::cout << "Qual termo você deseja adicionar à lista queue?" << std::endl;
            std::cin >> new_insertion;
            queue.push_back(new_insertion);
        }
        else if(opt == 2){
            std::cout << "O primeiro termo será retirado, pois ele não precisa mais ficar na fila esperando atendimento.:D" << std::endl;
            queue.pop_front();
        }
        else if(opt == 3){
            if (queue.size() >= 0){
                for (cheeky_printer = queue.begin(); cheeky_printer != queue.end(); ++cheeky_printer){
                    std::cout << "Queue[" << kount << "] = " << *cheeky_printer << std::endl;
                    ++kount;
                }
            }
            else{
                std::cout << "Cheeky is not happy you decided to delete everything and more, so he's mad at you and won't print this." << std::endl;
            }
        }
        else{
            std::cout << "Essa opção não existe ainda, contate-nos caso queira fazer sujestões de novas funções para a lista queue.:D" << std::endl;
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