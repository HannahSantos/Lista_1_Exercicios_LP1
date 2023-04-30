#include <iostream>
#include <vector>

using type_var = int;

// Função para determinar a continuação do programa
int exit_or_continue();

int main(){
    std::vector<type_var> stack{};
    int opt, carry_on = 1;
    type_var new_insertion;

    do{
        std::cout << "O que deseja fazer no vetor stack?" << std::endl
                  << "1 - Inserir novo termo" << std::endl
                  << "2 - Deletar último termo" << std::endl
                  << "3 - Imprimir vetor stack" << std::endl;
        std::cin >> opt;
        
        if (opt == 1){
            std::cout << "Qual termo você deseja adicionar ao vetor stack?" << std::endl;
            std::cin >> new_insertion;
            stack.push_back(new_insertion);
        }
        else if(opt == 2){
            std::cout << "O último termo será retirado, por isso ele parte e diz adeus. :(" << std::endl;
            stack.pop_back();
        }
        else if(opt == 3){
            if (stack.size() >= 0){
                for (auto i{0}; i < stack.size(); ++i){
                    std::cout << "Stack[" << i << "] = " << stack[i] << std::endl;
                }
            }
            else {
                std::cout << "Don't be cheeky, you know there's less than nothing there.:P" << std::endl;
            }
            
        }
        else{
            std::cout << "Essa opção não existe ainda, contate-nos caso queira fazer sujestões de novas funções para o vetor stack.:D" << std::endl;
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