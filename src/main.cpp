#include <Arduino.h>
#include <string.h> //* strlen, strcpy, strcat, strcmp, strchr
#include<stdlib.h> //* atoi


void textoChar(); //*strchr
void textoString();


void setup() {
  Serial.begin(9600);
  Serial.println();
  textoChar();
  textoString();
}

void loop() {

}

void textoChar(){
  //* Texto literal
  //* Use const char* quando o texto não será alterado
  const char cidade[] = "Sao Paulo";    //! Nas [] é passado o conteúdo desejado que foi inserido, diferento do * que passa o endereco 
  Serial.println(cidade);

  //* Descobrindo o tamanho do texto
  //* strlen conta quantos caracteres antes do '\0'(/0 é como um ponto final e sempre ocupa um espaço)
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade);

  //* Descobrindo o tamanho ocupado
  //* o sizeof() retornará um byte a mais que o comprimento por causa do '\0'
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaço utilizado: ");
  Serial.println(tamanhoVariavelCidade);

  //* O caractere \0 é colocado automaticamente quando escrevemos um texto entre " ".
  char vetorTexto[8] = {'G','u','s','t','a','v','o','\0'}; 
  Serial.println(String(vetorTexto));

  //*Comparar texto 
  //* Use const char* quando o texto não será alterado
  const char* cidade1 = "Sao Caetano";   //! O * no char é um endereco de memória(ponteiro), ele basicamente diz para imprimir a partir desse char* até encontrar o \0
  const char* cidade2 = "Sao Caetano";

  if(strcmp(cidade1, cidade2) == 0){
    Serial.println("Os textos são iguais");
  }
  else{
    Serial.println("Os textos são diferentes");
  
  //* strcmp analiza a ordem lexica(ordem alfabética) das palavras comparando a primeira letra da primei palavra
  //* com a primeira da segundo e assim até o final, se a primeira palavra vem antes que a segunda o valor
  //* retornado será menor que zero, se a primeira vem após a segundo o retorno será maior que zero.
  
  //!===========================
  //! TEXTO EDITAVEL COM char[]
  //!===========================

  char nomeAluno[20] = "Gustavp"; //* Aqui tem 7 letras mas foi usado 8 por conta do '\0'
  Serial.println(nomeAluno);

  //* Alterando caracteres individualmente
  nomeAluno[6] = 'o'; //! A contagem de caracteres comeca SEMPRE EM 0
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor
  //! Cuidado: o vetor precisa ter espaço suficiente

  strcpy(nomeAluno, "Felipe");
  Serial.println(nomeAluno);

  //* Concatetanação de texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo!");
  Serial.println(frase);

  //* Procurando caractere no texto
  //* Frase "Ola Mundo!"
  char* posicaoLetra = strchr(frase, 'M');

  if(posicaoLetra != NULL){   //* NULL é igual a '\0'
    Serial.println("Letra encontrada: ");
    Serial.println(posicaoLetra);
  }
  else{
    Serial.println("Letra não encontrada");
  }

  //* Convertendo texto numérico para inteiro
  char idadeTexto[] = "45";   // Na tabela ASC: 52(4), 53(5) e o \0
  int idade = atoi(idadeTexto); //* atoi é: a de ASC, t de até e i de inteiro, da tabela ASC até inteiro
  Serial.println(idade);

  }



}

void textoString(){
  //! ================
  //! USANDO String
  //! ================
  
  String nome = "Thiago";
  String curso = "Logica de Programação";
  String mensagem = "Ola";

  //* Concatenando String
  mensagem = mensagem + "," + nome + "! Bem-vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  //* Tamanho da String
  int tamanhoMensagem = mensagem.length();
  Serial.print("Tamanho da String em letras: ");
  Serial.println(tamanhoMensagem);

  //* Acessando umm caractere em uma posição específica
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira letra: ");
  Serial.println(primeiraLetra);

  //* Tambem é possível acessar com colchetes
  char segundaLetra = mensagem[1];
  Serial.println(segundaLetra);

  //* Procurando um texto detro da String
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.println(posicaoTextoProcurado);

  //* Extraindo um texto dentro da String
  int inicioNomeCurso = posicaoTextoProcurado + 9; //* Posicao da palavra curso + 9 caracteres
  Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1)); //* -1 tira o ponto final

  //* Substituindo um texto dentro da String
  mensagem.replace("Ola," , "Oi, tudo bom? ");
  Serial.println(mensagem);

  //* Convertendo para maiúsculas
  mensagem.toUpperCase();
  Serial.println(mensagem);

  //* Convertendo para minúsculas
  mensagem.toLowerCase();
  Serial.println(mensagem);

  //* Convertendo texto numérico para inteiros
  String textoNumero = "123";
  int numero = textoNumero.toInt();
  Serial.println(numero * 2);

  //* Verificando se a String está vazia
  String textoVazio = "";
  if(textoVazio.length() == 0){
    Serial.println("O texto está vazio");
  }

  //* Convertendo String para const char*
  //* Isso é útil quando alguma biblioteca espera texto estilo C
  const char* textoComoChar = mensagem.c_str();
  Serial.println(textoComoChar);
}