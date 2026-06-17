#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define MAX 100

// Estrutura Clientes
struct Cliente {
    int id;
    char nome[50];
    int compras;
};

// Estrutura Produtos
struct Produto {
    int id;
    char nome[50];
    float valor;
    int estoque;
    char fornecedor[50];
    char garantia[50];
    int quantvendas;
};

// Estrutura Fornecedores
struct Fornecedor {
    int id;
    char nome[50];
};

// Estrutura Vendas
struct Venda {
    int idcliente;
    int produtos[50];
    int quantidades[50];
    int totalprodutos;
    float valor;
};

int main() {
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "pt_BR.UTF-8");
    struct Cliente clientes[MAX];
    struct Produto produtos[MAX];
    struct Fornecedor fornecedores[MAX];
    struct Venda vendas[MAX];

    // Variáveis
    int totalvendas = 0;
    float faturamento = 0;
    int totalcli = 0;
    int totalpro = 0;
    int totalfor = 0;
    int opcaomenu = 0;
    int opcaocad = 0;
    int opcaopro = 0;
    int opcaofor = 0;
    int opcaoven = 0;
    int opcaogar = 0;
    int opcaorel = 0;

    // Menu Principal
    while (1) {
        printf("==================================\n");
        printf("  SISTEMA DE LOJA DE INFORMÁTICA  \n");
        printf("==================================\n");

        printf("1 - Clientes\n");
        printf("2 - Produtos\n");
        printf("3 - Fornecedores\n");
        printf("4 - Vendas\n");
        printf("5 - Garantias\n");
        printf("6 - Relatórios\n");
        printf("7 - Encerrar Programa\n");

        printf("Selecione um módulo: ");
        scanf("%d", &opcaomenu);
        getchar();

        while (opcaomenu > 7 || opcaomenu < 1) {
            printf("Opção inválida! Tente novamente!\n");

            printf("Selecione um módulo: ");
            scanf("%d", &opcaomenu);
            getchar();
        }

        // Módulo Clientes
        if (opcaomenu == 1) {
            opcaocad = 0;

            while (1) {
                printf("==================================\n");
                printf("             Clientes             \n");
                printf("==================================\n");

                printf("1 - Cadastrar\n");
                printf("2 - Buscar\n");
                printf("3 - Alterar\n");
                printf("4 - Excluir\n");
                printf("5 - Sair\n");

                printf("Selecione uma opção: ");
                scanf("%d", &opcaocad);
                getchar();
                
                while (opcaocad > 5 || opcaocad < 1) {
                    printf("Opção inválida! Tente novamente!\n");

                    printf("Selecione uma opção: ");
                    scanf("%d", &opcaocad);
                    getchar();
                }

                // Cadastro de Novo Cliente
                if (opcaocad == 1) {
                    if (totalcli < MAX) {
                        printf("==================================\n");
                        printf("      Cadastrar Novo Cliente      \n");
                        printf("==================================\n");

                        clientes[totalcli].id = totalcli + 1;
                        clientes[totalcli].compras = 0;

                        printf("Nome: ");
                        fgets(clientes[totalcli].nome, 50, stdin);
                        clientes[totalcli].nome[strcspn(clientes[totalcli].nome, "\n")] = '\0';

                        totalcli++;
                        
                        printf("Cliente cadastrado com sucesso!\n");
                    } else {
                        printf("Limite de clientes atingido!\n");
                    }
                }

                // Buscar Clientes
                else if (opcaocad == 2) {
                    if (totalcli == 0) {
                        printf("Nenhum cliente cadastrado.\n");
                    } else {
                        printf("==================================\n");
                        printf("          Buscar Cliente          \n");
                        printf("==================================\n");

                        int encontrado = 0;
                        char busca[50];

                        printf("Digite o nome ou ID do cliente para buscar: ");
                        fgets(busca, 50, stdin);
                        busca[strcspn(busca, "\n")] = '\0';

                        int idbusca = atoi(busca);

                        for (int i = 0; i < totalcli; i++) {
                            if (strcmp(clientes[i].nome, busca) == 0 || clientes[i].id == idbusca) {
                                printf("Cliente encontrado!\n");
                                printf("ID: %d\n", clientes[i].id);
                                printf("Nome: %s\n", clientes[i].nome);
                            
                                encontrado = 1;

                                break;
                            }
                        }
                        
                        if (!encontrado) {
                            printf("Cliente não encontrado!\n");
                        }
                    }
                }
                
                // Alterar Clientes
                else if (opcaocad == 3) {
                    if (totalcli == 0) {
                        printf("Nenhum cliente cadastrado.\n");
                    } else {
                        int idalterar = 0;
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("         Alterar Clientes         \n");
                        printf("==================================\n");
                        printf("====== Clientes Cadastrados ======\n");

                        for (int i = 0; i < totalcli; i++) {
                            printf("ID: %d\n", clientes[i].id);
                            printf("Nome: %s\n", clientes[i].nome);
                            printf("----------------------------------\n");
                        }

                        printf("Digite o ID do cliente que deseja alterar: ");
                        scanf("%d", &idalterar);
                        getchar();

                        for (int i = 0; i < totalcli; i++) {
                            if (clientes[i].id == idalterar) {
                                printf("Novo nome: ");
                                fgets(clientes[i].nome, 50, stdin);
                                clientes[i].nome[strcspn(clientes[i].nome, "\n")] = '\0';

                                printf("Cliente alterado com sucesso!\n");

                                encontrado = 1;

                                break;
                            }
                        }
                        if (!encontrado) {
                            printf("Cliente não encontrado.\n");
                        }
                    }
                }
                
                // Excluir Clientes
                else if (opcaocad == 4) {
                    if (totalcli == 0) {
                        printf("Nenhum cliente cadastrado.\n");
                    } else {
                        int idexcluir = 0;
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("         Excluir Clientes         \n");
                        printf("==================================\n");
                        printf("====== Clientes Cadastrados ======\n");

                        for (int i = 0; i < totalcli; i++) {
                            printf("ID: %d\n", clientes[i].id);
                            printf("Nome: %s\n", clientes[i].nome);
                            printf("----------------------------------\n");
                        }

                        printf("Digite o ID do cliente que deseja excluir: ");
                        scanf("%d", &idexcluir);
                        getchar();

                        for (int i = 0; i < totalcli; i++) {
                            if (clientes[i].id == idexcluir) {
                                encontrado = 1;
                                for (int m = i; m < totalcli - 1; m++) {
                                    clientes[m] = clientes[m + 1];
                                }
                                totalcli--;
                                for (int a = 0; a < totalcli; a++) {
                                    clientes[a].id = a + 1;
                                }

                                printf("Cliente excluido com sucesso!\n");

                                break;
                            }
                        }

                        if (!encontrado) {
                            printf("Cliente não encontrado.\n");
                        }
                    }
                }

                // Voltar ao menu principal
                else if (opcaocad == 5) {
                    break;
                }
            }
        }
        
        // Módulo Produtos
        else if (opcaomenu == 2) {
            opcaopro = 0;

            while (1) {
                printf("==================================\n");
                printf("             Produtos             \n");
                printf("==================================\n");
                
                printf("1 - Cadastrar\n");
                printf("2 - Ver Estoque\n");
                printf("3 - Buscar\n");
                printf("4 - Alterar Preço\n");
                printf("5 - Excluir Produto\n");
                printf("6 - Sair\n");

                printf("Selecione uma opção: ");
                scanf("%d", &opcaopro);
                getchar();

                while (opcaopro > 6 || opcaopro < 1) {
                    printf("Opção inválida! Tente novamente!\n");

                    printf("Selecione uma opção: ");
                    scanf("%d", &opcaopro);
                    getchar();
                }

                // Cadastro de Produto
                if (opcaopro == 1){
                    if (totalpro < MAX && totalfor > 0) {
                        int numfor = 0;

                        printf("==================================\n");
                        printf("      Cadastrar Novo Produto      \n");
                        printf("==================================\n");

                        produtos[totalpro].id = totalpro + 1;
                        produtos[totalpro].quantvendas = 0;

                        printf("Produto: ");
                        fgets(produtos[totalpro].nome, 50, stdin);
                        produtos[totalpro].nome[strcspn(produtos[totalpro].nome, "\n")] = '\0';

                        printf("Preço: R$");
                        scanf("%f", &produtos[totalpro].valor);
                        getchar();

                        printf("Quantidade em Estoque: ");
                        scanf("%d", &produtos[totalpro].estoque);
                        getchar();

                        printf("==== Fornecedores Cadastrados ====\n");

                        for (int i = 0; i < totalfor; i++) {
                            printf("ID: %d\n", fornecedores[i].id);
                            printf("Fornecedor: %s\n", fornecedores[i].nome);
                            printf("----------------------------------\n");
                        }

                        printf("Digite o ID do fornecedor desse produto: ");
                        scanf("%d", &numfor);
                        getchar();
                        
                        while (numfor < 1 || numfor > totalfor) {
                            printf("Fornecedor não encontrado! Tente novamente.");
                            printf("Digite o ID do fornecedor desse produto: ");
                            scanf("%d", &numfor);
                            getchar();
                        }

                        strcpy(produtos[totalpro].fornecedor, fornecedores[numfor - 1].nome);

                        printf("Tempo de garantia: ");
                        fgets(produtos[totalpro].garantia, 50, stdin);
                        produtos[totalpro].garantia[strcspn(produtos[totalpro].garantia, "\n")] = '\0';

                        totalpro++;

                        printf("Produto cadastrado com sucesso!\n");
                    } else {
                        printf("Número máximo de produtos cadastrados atingido, ou sem fornecedores cadastrados!\n");
                    }
                }

                // Controle de Estoque
                else if (opcaopro == 2) {
                    if (totalpro == 0) {
                        printf("Nenhum produto cadastrado!\n");
                    } else {
                        printf("==================================\n");
                        printf("   Lista de Produtos no Estoque   \n");
                        printf("==================================\n");
                        
                        for (int i = 0; i < totalpro; i++) {
                            printf("ID: %d\n", produtos[i].id);
                            printf("Produto: %s\n", produtos[i].nome);
                            printf("Quantidade em estoque: %d\n", produtos[i].estoque);
                            printf("----------------------------------\n");
                        }
                    }
                }
                
                // Buscar Produto
                else if (opcaopro == 3) {
                    if (totalpro == 0) {
                        printf("Nenhum produto cadastrado!\n");
                    } else {
                        int encontrado = 0;
                        char prodbusca[50];

                        printf("==================================\n");
                        printf("          Buscar Produto          \n");
                        printf("==================================\n");

                        printf("Digite o nome ou ID do produto para buscar: ");
                        fgets(prodbusca, 50, stdin);
                        prodbusca[strcspn(prodbusca, "\n")] = '\0';

                        int idprodbusca = atoi(prodbusca);

                        for (int i = 0; i < totalpro; i++) {
                            if(strcmp(produtos[i].nome, prodbusca) == 0 || produtos[i].id == idprodbusca) {
                                printf("Produto encontrado!\n");
                                printf("ID: %d\n", produtos[i].id);
                                printf("Produto: %s\n", produtos[i].nome);
                                printf("Preço: %.2f\n", produtos[i].valor);
                                printf("Quantidade em estoque: %d\n", produtos[i].estoque);
                                printf("Fornecedor: %s\n", produtos[i].fornecedor);
                                printf("Tempo de Garantia: %s\n", produtos[i].garantia);

                                encontrado = 1;

                                break;
                            }
                        }

                        if (!encontrado) {
                                printf("Produto não encontrado!\n");
                        }
                    }
                }

                // Alterar Preços
                else if (opcaopro == 4) {
                    if (totalpro == 0) {
                        printf("Nenhum produto cadastrado.\n");
                    } else {
                        int idalt = 0;
                        int encontrado = 0;
                        float novop = 0;

                        printf("==================================\n");
                        printf("          Alterar Preços          \n");
                        printf("==================================\n");

                        for (int i = 0; i < totalpro; i++) {
                            printf("ID: %d\n", produtos[i].id);
                            printf("Produto: %s\n", produtos[i].nome);
                            printf("Preço: %.2f\n", produtos[i].valor);
                            printf("----------------------------------\n");
                        }

                        printf("Digite o ID do produto do qual deseja alterar o preço: ");
                        scanf("%d", &idalt);
                        getchar();

                        for (int i = 0; i < totalpro; i++) {
                            if (produtos[i].id == idalt) {
                                printf("Novo preço: R$");
                                scanf("%f", &novop);
                                getchar();
                                produtos[i].valor = novop;

                                printf("Preço alterado com sucesso!\n");

                                encontrado = 1;

                                break;
                            }
                        }
                        if (!encontrado) {
                            printf("Produto não encontrado.\n");
                        }
                    }
                }

                // Excluir Produtos
                else if (opcaopro == 5) {
                    if (totalpro == 0) {
                        printf("Nenhum produto cadastrado.\n");
                    } else {
                        int idexcluir = 0;
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("         Excluir Produtos         \n");
                        printf("==================================\n");

                        printf("Digite o ID do produto que deseja excluir: ");
                        scanf("%d", &idexcluir);
                        getchar();

                        for (int i = 0; i < totalpro; i++) {
                            if (produtos[i].id == idexcluir) {
                                encontrado = 1;
                                for (int m = i; m < totalpro - 1; m++) {
                                    produtos[m] = produtos[m + 1];
                                }
                                totalpro--;
                                for (int a = 0; a < totalpro; a++) {
                                    produtos[a].id = a + 1;
                                }

                                printf("Produto excluido com sucesso!\n");

                                break;
                            }
                        }

                        if (!encontrado) {
                            printf("Produto não encontrado!\n");
                        }
                    }
                }

                // Voltar ao menu principal
                else if (opcaopro == 6) {
                    break;
                }
            }
        }     

        // Módulo Fornecedores
        else if (opcaomenu == 3) {
            opcaofor = 0;

            while (1) {
                printf("==================================\n");
                printf("           Fornecedores           \n");
                printf("==================================\n");

                printf("1 - Cadastrar\n");
                printf("2 - Listar\n");
                printf("3 - Buscar\n");
                printf("4 - Alterar\n");
                printf("5 - Sair\n");

                printf("Selecione uma opção: ");
                scanf("%d", &opcaofor);
                getchar();
                
                while (opcaofor > 5 || opcaofor < 1) {
                    printf("Opção inválida! Tente novamente!\n");

                    printf("Selecione uma opção: ");
                    scanf("%d", &opcaofor);
                    getchar();
                }

                // Cadastro do Novo Fornecedor
                if (opcaofor == 1) {
                    if (totalfor < MAX) {
                        printf("==================================\n");
                        printf("   Cadastrar um Novo Fornecedor   \n");
                        printf("==================================\n");

                        fornecedores[totalfor].id = totalfor + 1;

                        printf("Nome: ");
                        fgets(fornecedores[totalfor].nome, 50, stdin);
                        fornecedores[totalfor].nome[strcspn(fornecedores[totalfor].nome, "\n")] = '\0';

                        totalfor++;
                        
                        printf("Fornecedor cadastrado com sucesso!\n");
                    } else {
                        printf("Limite de fornecedores atingido!\n");
                    }
                }

                // Listar Fornecedores
                else if (opcaofor == 2) {
                    if (totalfor == 0) {
                        printf("Nenhum fornecedor cadastrado.\n");
                    } else {
                        printf("==================================\n");
                        printf("     Fornecedores Cadastrados     \n");
                        printf("==================================\n");

                        for (int i = 0; i < totalfor; i++) {
                            printf("ID: %d\n", fornecedores[i].id);
                            printf("Fornecedor: %s\n", fornecedores[i].nome);
                            printf("----------------------------------\n");
                        }
                    }
                }
                // Buscar Fornecedor
                else if (opcaofor == 3) {
                    if (totalfor == 0) {
                        printf("Nenhum Fornecedor cadastrado.\n");
                    } else {
                        printf("==================================\n");
                        printf("         Busca Fornecedor         \n");
                        printf("==================================\n");

                        int encontrado = 0;
                        char busca[50];

                        printf("Digite o nome ou ID do fornecedor para buscar: ");
                        fgets(busca, 50, stdin);
                        busca[strcspn(busca, "\n")] = '\0';

                        int idbusca = atoi(busca);

                        for (int i = 0; i < totalfor; i++) {
                            if(strcmp(fornecedores[i].nome, busca) == 0 || fornecedores[i].id == idbusca) {
                                printf("Fornecedor encontrado!\n");
                                printf("ID: %d\n", fornecedores[i].id);
                                printf("Nome: %s\n", fornecedores[i].nome);
                            
                                encontrado = 1;

                                break;
                            }
                        }
                        
                        if (!encontrado) {
                            printf("Fornecedor não encontrado!\n");
                        }
                    }
                }

                // Alterar Fornecedor
                else if (opcaofor == 4) {
                    if (totalfor == 0) {
                        printf("Nenhum Fornecedor cadastrado.\n");
                    } else {
                        int idalterar = 0;
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("       Alterar Fornecedores       \n");
                        printf("==================================\n");

                        printf("Digite o ID do fornecedor que deseja alterar: ");
                        scanf("%d", &idalterar);
                        getchar();

                        for (int i = 0; i < totalfor; i++) {
                            if (fornecedores[i].id == idalterar) {
                                printf("Novo nome: ");
                                fgets(fornecedores[i].nome, 50, stdin);
                                fornecedores[i].nome[strcspn(fornecedores[i].nome, "\n")] = '\0';

                                printf("Fornecedor alterado com sucesso!\n");

                                encontrado = 1;

                                break;
                            }
                        }
                        if (!encontrado) {
                            printf("Fornecedor não encontrado.\n");
                        }
                    }
                }

                // Voltar ao Menu Principal
                else if (opcaofor == 5) {
                    break;
                }
            }
        }

        // Módulo Vendas
        else if (opcaomenu == 4) {
            opcaoven = 0;

            while (1) {
                printf("==================================\n");
                printf("              Vendas              \n");
                printf("==================================\n");

                printf("1 - Iniciar nova venda\n");
                printf("2 - Ver venda atual\n");
                printf("3 - Finalizar venda\n");
                printf("4 - Sair\n");

                printf("Selecione uma opção: ");
                scanf("%d", &opcaoven);
                getchar();

                while (opcaoven > 4 || opcaoven < 1) {
                    printf("Opção inválida!\n");
                    printf("Selecione uma opção: ");
                    scanf("%d", &opcaoven);
                    getchar();
                }

                // Iniciar Venda
                if (opcaoven == 1) {

                    if (totalcli == 0 || totalpro == 0) {
                        printf("Precisa ter clientes e produtos cadastrados!\n");
                        continue;
                    }

                    if (vendas[totalvendas].totalprodutos >= 50) {
                        printf("Limite de produtos por venda atingido!\n");
                        break;
                    }

                    if (vendas[totalvendas].totalprodutos > 0) {
                        printf("Finalize a venda atual primeiro!\n");
                        continue;
                    }

                    int idcli;

                    printf("Digite o ID do cliente: ");
                    scanf("%d", &idcli);
                    getchar();

                    if (idcli < 1 || idcli > totalcli) {
                        printf("Cliente inválido!\n");
                        continue;
                    }

                    vendas[totalvendas].idcliente = idcli;
                    vendas[totalvendas].valor = 0;
                    vendas[totalvendas].totalprodutos = 0;

                    int opc = 1;

                    while (opc == 1) {

                        printf("====== Produtos Disponíveis ======\n");

                        for (int i = 0; i < totalpro; i++) {
                            printf("ID: %d\n", produtos[i].id);
                            printf("Produto: %s\n", produtos[i].nome);
                            printf("Preço: R$%.2f\n", produtos[i].valor);
                            printf("Quantidade em estoque: %d\n", produtos[i].estoque);
                            printf("----------------------------------\n");
                        }

                        int idpro, qt;

                        printf("Digite o ID do produto: ");
                        scanf("%d", &idpro);
                        getchar();

                        if (idpro < 1 || idpro > totalpro) {
                            printf("Produto inválido!\n");
                            continue;
                        }

                        if (produtos[idpro - 1].estoque <= 0) {
                            printf("Sem estoque!\n");
                            continue;
                        }

                        printf("Quantidade: ");
                        scanf("%d", &qt);
                        getchar();

                        if (qt <= 0 || qt > produtos[idpro - 1].estoque) {
                            printf("Quantidade inválida!\n");
                            continue;
                        }

                        int pos = vendas[totalvendas].totalprodutos;

                        vendas[totalvendas].produtos[pos] = idpro;
                        vendas[totalvendas].quantidades[pos] = qt;
                        vendas[totalvendas].totalprodutos++;

                        vendas[totalvendas].valor += produtos[idpro - 1].valor * qt;

                        produtos[idpro - 1].estoque -= qt;
                        produtos[idpro - 1].quantvendas += qt;

                        printf("Adicionar mais produtos?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        scanf("%d", &opc);
                        getchar();

                        while (opc < 1 || opc > 2) {
                            printf("Opção inválida! Tente novamente.\n");
                            printf("Adicionar mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Não\n");
                            scanf("%d", &opc);
                            getchar();
                        }
                    }
                }

                // Ver Venda Atual
                else if (opcaoven == 2) {
                    if (vendas[totalvendas].totalprodutos == 0) {
                        printf("Nenhuma venda em andamento!\n");
                        continue;
                    }

                    printf("======== Venda Atualmente ========\n");
                    printf("ID do cliente: %d\n", vendas[totalvendas].idcliente);

                    for (int i = 0; i < vendas[totalvendas].totalprodutos; i++) {
                        int idp = vendas[totalvendas].produtos[i];
                        int qt = vendas[totalvendas].quantidades[i];

                        printf("Produto: %s\n", produtos[idp - 1].nome);
                        printf("Quantidade: %d\n", qt);
                        printf("Subtotal: %.2f\n", produtos[idp - 1].valor * qt);
                        printf("----------------------------------\n");
                    }

                    printf("Total: R$ %.2f\n", vendas[totalvendas].valor);
                }

                // Finalizar Venda
                else if (opcaoven == 3) {
                    if (vendas[totalvendas].totalprodutos == 0) {
                        printf("Nenhuma venda para finalizar.\n");
                        continue;
                    }

                    faturamento += vendas[totalvendas].valor;

                    clientes[vendas[totalvendas].idcliente - 1].compras++;

                    printf("Venda finalizada!\n");
                    printf("Valor total: R$ %.2f\n", vendas[totalvendas].valor);

                    totalvendas++;

                    vendas[totalvendas].totalprodutos = 0;
                    vendas[totalvendas].valor = 0;
                }

                // Voltar ao menu principal
                else if (opcaoven == 4) {
                    break;
                }
            }
        }

        // Módulo Garantias
        else if (opcaomenu == 5) {
            opcaogar = 0;

            while (1) {
                printf("==================================\n");
                printf("             Garantia             \n");
                printf("==================================\n");

                printf("1 - Alterar garantia\n");
                printf("2 - Consultar garantia\n");
                printf("3 - Encerrar garantia\n");
                printf("4 - Sair\n");

                printf("Selecione uma opção: ");
                scanf("%d", &opcaogar);
                getchar();

                while (opcaogar > 4 || opcaogar < 1) {
                    printf("Opção inválida! Tente novamente!\n");

                    printf("Selecione uma opção: ");
                    scanf("%d", &opcaogar);
                    getchar();
                }

                // Registrar Garantia
                if (opcaogar == 1) {
                    if (totalpro > 0) {
                        char progar[50];
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("         Alterar Garantia         \n");
                        printf("==================================\n");

                        printf("Digite o nome ou ID do produto no qual deseja alterar a garantia: ");
                        fgets(progar, 50, stdin);
                        progar[strcspn(progar, "\n")] = '\0';

                        int idbuscar = atoi(progar);

                        for (int i = 0; i < totalpro; i++) {
                            if (strcmp(produtos[i].nome, progar) == 0 || produtos[i].id == idbuscar) {
                                printf("Produto encontrado!\n");
                                printf("ID: %d\n", produtos[i].id);
                                printf("Produto: %s\n", produtos[i].nome);
                                
                                encontrado = 1;
                                
                                printf("Digite a nova garantia que deseja registrar para esse produto: ");
                                fgets(produtos[i].garantia, 50, stdin);
                                produtos[i].garantia[strcspn(produtos[i].garantia, "\n")] = '\0';

                                printf("Garantia alterada com sucesso!\n");

                                break;
                            }
                        }

                        if (!encontrado) {
                            printf("Produto não encontrado!\n");
                        }
                    } else {
                        printf("Nenhum produto cadastrado.\n");
                    }
                }

                // Consultar Garantia
                else if (opcaogar == 2) {
                    if (totalpro > 0) {
                        char progar[50];
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("        Consultar Garantia        \n");
                        printf("==================================\n");

                        printf("Digite o nome ou ID do produto do qual deseja consultar a garantia: ");
                        fgets(progar, 50, stdin);
                        progar[strcspn(progar, "\n")] = '\0';
                        int idbuscar = atoi(progar);

                        for (int i = 0; i < totalpro; i++) {
                            if (strcmp(produtos[i].nome, progar) == 0 || produtos[i].id == idbuscar) {
                                printf("Produto encontrado!\n");
                                printf("ID: %d\n", produtos[i].id);
                                printf("Produto: %s\n", produtos[i].nome);
                                
                                encontrado = 1;
                                
                                if (produtos[i].garantia[0] != '\0') {
                                    printf("Garantia: %s\n", produtos[i].garantia);

                                    break;
                                } else {
                                    printf("Esse produto não possui garantia.\n");
                                }

                                break;
                            }
                        }
                        if (!encontrado) {
                            printf("Produto não encontrado!\n");
                        }            
                    } else {
                        printf("Nenhum produto cadastrado.\n");
                    }
                }

                // Encerrar Garantia
                else if (opcaogar == 3) {
                    if (totalpro > 0) {
                        char progar[50];
                        int encontrado = 0;

                        printf("==================================\n");
                        printf("         Excluir Garantia         \n");
                        printf("==================================\n");

                        printf("Digite o nome ou ID do produto do qual deseja encerrar a garantia: ");
                        fgets(progar, 50, stdin);
                        progar[strcspn(progar, "\n")] = '\0';
                        int idbuscar = atoi(progar);

                        for (int i = 0; i < totalpro; i++) {
                            if (strcmp(produtos[i].nome, progar) == 0 || produtos[i].id == idbuscar) {
                                printf("Produto encontrado!\n");
                                printf("ID: %d\n", produtos[i].id);
                                printf("Produto: %s\n", produtos[i].nome);
                                
                                encontrado = 1;
                                
                                if (produtos[i].garantia[0] != '\0') {
                                    printf("Garantia encerrada\n");
                                    produtos[i].garantia[0] = '\0';

                                    break;
                                } else {
                                    printf("Esse produto não possui garantia.\n");
                                }

                                break;
                            }
                        }
                        if (!encontrado) {
                            printf("Produto não encontrado!\n");
                        }
                    } else {
                        printf("Nenhum produto cadastrado.\n");
                    }
                }

                // Voltar ao Menu Principal
                else if (opcaogar == 4) {
                    break;
                }
            }
        }

        // Módulo Relatórios
        else if (opcaomenu == 6) {
            while (1) {   
                printf("==================================\n");
                printf("            Relatórios            \n");
                printf("==================================\n");

                printf("1 - Produtos mais vendidos\n");
                printf("2 - Produtos com baixo estoque\n");
                printf("3 - Total de vendas\n");
                printf("4 - Faturamento\n");
                printf("5 - Clientes que mais compraram\n");
                printf("6 - Produtos\n");
                printf("7 - Voltar ao menu principal\n");

                printf("Selecione uma opção: ");
                scanf("%d", &opcaorel);
                getchar();

                while (opcaorel > 7 || opcaorel < 1) {
                    printf("Opção inválida! Tente novamente!\n");

                    printf("Selecione uma opção: ");
                    scanf("%d", &opcaorel);
                    getchar();
                }

                // Produtos mais vendidos
                if (opcaorel == 1) {
                    int maisvendido = 0;

                    if (totalpro == 0) {
                        printf("Nenhum produto cadastrado!\n");
                    } else {
                        for (int i = 1; i < totalpro; i++) {
                            if (produtos[i].quantvendas >
                                produtos[maisvendido].quantvendas) {
                                
                                maisvendido = i;
                            }
                        }
                    
                        printf("====== Produto mais vendido ======\n");
                        printf("ID: %d\n", produtos[maisvendido].id);
                        printf("Nome: %s\n", produtos[maisvendido].nome);
                        printf("Quantidade vendida: %d\n", produtos[maisvendido].quantvendas);
                    }
                }

                // Produtos com baixo estoque
                else if (opcaorel == 2) {
                    int encontrou = 0;

                    printf("=== Produtos com baixo estoque ===\n");

                    for (int i = 0; i < totalpro; i++) {
                        if (produtos[i].estoque <= 5) {
                            printf("ID: %d\n", produtos[i].id);
                            printf("Nome: %s\n", produtos[i].nome);
                            printf("Estoque: %d\n\n", produtos[i].estoque);
                            printf("----------------------------------\n");
                        
                            encontrou = 1;
                        }
                    }
                
                    if (!encontrou) {
                        printf("Nenhum produto com baixo estoque.\n");
                    }
                }

                // Total de vendas
                else if (opcaorel == 3) {
                    printf("Total de vendas: %d\n", totalvendas);
                }

                // Faturamento
                else if (opcaorel == 4) {
                    printf("\nFaturamento total: R$ %.2f\n", faturamento);
                }

                // Clientes que mais compraram
                else if (opcaorel == 5) {
                    if (totalcli == 0) {
                        printf("Nenhum cliente cadastrado!\n");
                    } else {
                        int melhor = 0;

                        for (int i = 1; i < totalcli; i++) {
                            if (clientes[i].compras > clientes[melhor].compras) {
                                melhor = i;
                            }
                        }

                        printf("Cliente que mais comprou:\n");
                        printf("ID: %d\n", clientes[melhor].id);
                        printf("Nome: %s\n", clientes[melhor].nome);
                        printf("Compras: %d\n",clientes[melhor].compras);
                    }
                }

                // Produtos
                else if (opcaorel == 6) {
                    if (totalpro == 0) {
                        printf("Nenhum produto cadastrado!\n");
                    } else {
                        printf("============ Produtos ============\n");
                        for (int i = 0; i < totalpro; i++) {
                            printf("ID: %d\n", produtos[i].id);
                            printf("Produto: %s\n", produtos[i].nome);
                            printf("Preço: R$%.2f\n", produtos[i].valor);
                            printf("----------------------------------\n");
                        }
                    }
                }
                // Voltar ao Menu Principal
                else if (opcaorel == 7) {
                    break;
                }
            }
        }

        // Encerrar Programa
        else if (opcaomenu == 7) {
            printf("==================================\n");
            printf("        Programa Encerrado        \n");
            printf("==================================\n");
            break;
        }
    }
    return 0;
};
