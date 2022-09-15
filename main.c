#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nomePersonagem[20];
    char tipoDePersonagem[20]; //da para modificar e colocar descrição do personagem
}Personagem;

typedef struct{
    char titulo[25];
    int anoDePublicacao;
    char ISBN[20];
    Personagem personagem[20];
    int numPersonagens;
}Livro;


typedef struct{
    char nome[20];
    int anoDeNacimento;
    char paisDeNacimento[15];
    int numLivros;
    Livro livro[20];
}Autor;

void telaInicial(){
    printf("1 - Exibir autores\n");
    printf("2 - Adicionar autor\n");
    printf("3 - Exibir livros\n");
    printf("4 - adicionar livros\n");
    printf("5 - Exibir personagens\n");
    printf("6 - adicionar personagens\n");
    printf("7 - Sair\n");
}

Autor addAutor(){
    Autor autor;
    printf("Digite o nome do autor: ");
    scanf(" %[^\n]s", autor.nome);
    printf("Ano de nacimento: ");
    scanf("%d", &autor.anoDeNacimento);
    printf("pais de Nacimento: ");
    scanf(" %[^\n]s", autor.paisDeNacimento);
    autor.numLivros = 0;
    printf("\nAutor adicionado com sucesso\n");
    return autor;
}

void listarautores(Autor autores[], int numAutores){
    printf("id     nome         nacimento         pais\n");
    for (int i = 0; i < numAutores; i++){
        printf("%d  -   %s          %d         %s\n", i, autores[i].nome, autores[i].anoDeNacimento, autores[i].paisDeNacimento);
    }
    printf("\n\n");
}

void listarLivros(Autor autores[], int numAutores){
    printf("id(livro)  id(autor)  autor        titulo       ano de publicação     ISBN\n");
    for (int i = 0; i < numAutores; i++){
         for(int j = 0; j < autores[i].numLivros; j++){
            printf("  %d          %d       %s      %s             %d     %s\n",j, i, autores[i].nome, autores[i].livro[j].titulo, autores[i].livro[j].anoDePublicacao, autores[i].livro[j].ISBN); 
         }
    }
    printf("\n\n");
}

void listarPersonagens(Autor autores[], int numAutores){
    printf("id(livro)  id(autor)  id(personagem)  autor  titulo do livro   nome do personagem  tipo do personagem\n");
    for (int i = 0; i < numAutores; i++){
         for(int j = 0; j < autores[i].numLivros; j++){
            for (int q = 0; q < autores[i].livro[j].numPersonagens; q++){
                printf("  %d          %d            %d          %s         %s                  %s                   %s\n",j, i, q, autores[i].nome, autores[i].livro[j].titulo, autores[i].livro[j].personagem[q].nomePersonagem, autores[i].livro[j].personagem[q].tipoDePersonagem); 
            }
         }
    }
    printf("\n\n");
}



Livro addLivro(){
    Livro livro;
    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]s", livro.titulo);
    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.anoDePublicacao);
    printf("digite o ISBN do livro: ");
    scanf(" %[^\n]s", livro.ISBN);
    livro.numPersonagens = 0;
    printf("\nLivro adicionado com sucesso\n");
    return livro;
}

Personagem addPersonagem(){
    Personagem personagem;
    printf("Digite o nome do personagem: ");
    scanf(" %[^\n]s", personagem.nomePersonagem);
    printf("Digite o tipo de personagem(humano, cachorro, gato...): ");
    scanf(" %[^\n]s", personagem.tipoDePersonagem);
    printf("\n personagem adicionado com sucesso\n");
    return personagem;
}


int main()
{
    int c = 0, op = 0, numAutores = 0, numLivros = 0, numPersonagens = 0;
    Autor autor[20];
    while(c!=7){
        telaInicial();
        scanf("%d", &op);
        switch(op){
        case 1:
            if(numAutores == 0){
                printf("Nenhum autor foi adicionado\n");
            }
            else{
                listarautores(autor, numAutores);
            }
        break;
        case 2:
            autor[numAutores] = addAutor();
            numAutores ++;
        break;
        case 3:
            if(numLivros == 0){
                    printf("Nenhum livro foi adicionado\n");
                }
                else{
                    listarLivros(autor, numAutores);
                }
                
        break;
        case 4:
            if(numAutores == 0){
                printf("Não ha autores adicionados\n");
            }
            else{
                int cont;
                while (op != 0){
                    listarautores(autor, numAutores);
                    printf("Digite o ID do autor que vc deseja adicionar um livro: ");
                    scanf("%d", &cont);
                    if(cont <= numAutores && cont >= 0){
                        op = 0;
                    }
                }
                autor[cont].livro[autor[cont].numLivros] = addLivro();
                autor[cont].numLivros++;
                numLivros++;
            }
        break;
        case 5:
            if(numPersonagens == 0){
                printf("Nenhum personagem foi adicionado\n");
            }
            else{
               listarPersonagens(autor, numAutores);
            }
                    
        break;
        case 6:
            if(numAutores == 0){
                printf("Não ha autores adicionados\n");
            }
            if(numLivros == 0){
                printf("Nenhum livro foi adicionado\n");
            }
            else{
                int cont1, cont2;
                while (op != 0){
                    listarLivros(autor, numAutores);
                    printf("Digite o ID que é autor do livro: ");
                    scanf("%d", &cont1);
                    if(cont1 <= numAutores && cont1 >= 0){
                        op = 0;
                    }
                }
                op = 1;
                while (op != 0){
                    printf("Digite o ID do livro: ");
                    scanf("%d", &cont2);
                    if(cont2 <= autor[cont1].numLivros && cont2 >= 0){
                        op = 0;
                    }
                }
                autor[cont1].livro[cont2].personagem[autor[cont1].livro[cont2].numPersonagens] = addPersonagem();
                autor[cont1].livro[cont2].numPersonagens++;
                numPersonagens++;
            }
        break;
        case 7:
        c = 7;
        break;


        }


    }
    return 0;
}