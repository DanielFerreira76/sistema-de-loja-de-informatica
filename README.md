# sistema-de-loja-de-informatica

Projeto acadêmico em C para gerenciamento de uma loja de informática, incluindo cadastro de clientes, fornecedores e produtos, registro de vendas e relatórios de desempenho.

## 🚀 Tecnologias utilizadas
- C
- GCC (compilador)
- VS Code

## ⚙️ Funcionalidades

- Cadastro de clientes
- Fornecedores e produtos
- Registro de vendas
- Relatórios de desempenho

##🖼️ Interface do sistema

O sistema funciona através de menus interativos no terminal.

##🏠 Menu Principal

Ao iniciar o programa, o usuário encontra as seguintes opções:

==================================
  SISTEMA DE LOJA DE INFORMÁTICA
==================================

1 - Clientes
2 - Produtos
3 - Fornecedores
4 - Vendas
5 - Garantias
6 - Relatórios
7 - Encerrar Programa

##👤 Módulo Clientes

Permite gerenciar os clientes cadastrados.

Funcionalidades:
==================================
             Clientes
==================================

1 - Cadastrar
2 - Buscar
3 - Alterar
4 - Excluir
5 - Sair


O usuário pode:

- Cadastrar novos clientes;
- Buscar clientes por nome ou ID;
- Alterar informações;
- Excluir clientes.

##📦 Módulo Produtos

Permite controlar os produtos da loja.

==================================
             Produtos
==================================

1 - Cadastrar
2 - Ver Estoque
3 - Buscar
4 - Alterar Preço
5 - Excluir Produto
6 - Sair

O usuário pode:

- Cadastrar produtos;
- Consultar o estoque;
- Buscar produtos;
- Alterar preços;
- Excluir produtos.

Cada produto possui:

ID;
Nome;
Preço;
Quantidade em estoque;
Fornecedor;
Garantia.

##🏭 Módulo Fornecedores

Gerencia os fornecedores cadastrados.

==================================
           Fornecedores
==================================

1 - Cadastrar
2 - Listar
3 - Buscar
4 - Alterar
5 - Sair

Funcionalidades:

- Cadastrar fornecedores;
- Listar fornecedores;
- Buscar por nome ou ID;
- Alterar informações.

🛒 Módulo Vendas

Responsável pelo processo de venda.

==================================
              Vendas
==================================

1 - Iniciar nova venda
2 - Ver venda atual
3 - Finalizar venda
4 - Sair

O sistema permite:

- Selecionar um cliente;
- Adicionar produtos à venda;
- Controlar o estoque automaticamente;
- Calcular o valor total da compra;
- Finalizar a venda.

##🛡️ Módulo Garantias

Gerencia as garantias dos produtos.

==================================
             Garantia
==================================

1 - Alterar garantia
2 - Consultar garantia
3 - Encerrar garantia
4 - Sair

Funcionalidades:

- Alterar a garantia de um produto;
- Consultar a garantia;
- Encerrar a garantia.


##📊 Módulo Relatórios

Exibe informações importantes sobre a loja.

==================================
            Relatórios
==================================

1 - Produtos mais vendidos
2 - Produtos com baixo estoque
3 - Total de vendas
4 - Faturamento
5 - Clientes que mais compraram
6 - Produtos
7 - Voltar ao menu principal



O usuário pode visualizar:

- Produto mais vendido;
- Produtos com estoque baixo;
- Total de vendas realizadas;
- Faturamento total;
- Cliente que mais comprou;
- Lista de produtos cadastrados.


## 📦 Como executar

1. Clone o repositório:

```bash
git clone https://github.com/DanielFerreira76/lojainfor.c.git
```

### 2. Entre na pasta

```bash
cd sistema-de-loja-de-informatica
```

### 3. Compile o programa

```bash
gcc lojainfor.c -o lojainfor
```

### 4. Execute

No Windows:

```bash
lojainfor.exe
```

No Linux ou macOS:

```bash
./lojainfor
```

### Estrutura do Projeto

📦 sistema-de-loja-de-informatica
 ├── .gitattributes
 ├── LICENSE
 ├── README.md
 └── lojainfor.c

## 📝 Aprendizados

Durante o desenvolvimento deste projeto, foram aplicados e aprimorados os seguintes conceitos:

- Estruturas (`struct`) para organizar clientes, produtos, fornecedores e vendas.
- Estruturas de repetição (`while` e `for`) para criação dos menus e percorrer os dados cadastrados.
- Estruturas condicionais (`if` e `else`) para validação das opções e controle do fluxo do programa.
- Manipulação de strings utilizando funções da biblioteca `string.h`.
- Utilização de vetores para armazenar os registros do sistema.
- Implementação das operações CRUD (Cadastrar, Buscar, Alterar e Excluir).
- Controle de estoque, vendas e faturamento.
- Validação de entradas do usuário para evitar erros de utilização.
- Organização e desenvolvimento de um sistema completo em linguagem C.
- Boas práticas de programação e lógica computacional.

## 👨‍🏫 Orientador
Hudson Neves - https://github.com/HudsonNeves

## 👨‍💻 Autores

Daniel Ferreira Vieira - https://github.com/DanielFerreira76

Denzel Luiz Sousa e Silva - https://github.com/Poluxzz

Felipe Oliveira Veras - 

Ítalo Rodrigues dos Santos -

Carlos Aparecido Pires dos Anjos -

Cleber Junio da Silva Souza -

Alexandre Brito Vasco de Oliveira -

Gabriel Barbosa Luiz -



GitHub: https://github.com/DanielFerreira76
