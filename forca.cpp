#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false; 
}

bool nao_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void set_cabecalho(){
    cout << "*********************\n";
    cout << "*** Jogo da Forca ***\n";
    cout << "*********************\n";
    cout << "\n\n";
}

void set_erros(){
    cout<<"Chutes errados: ";
    for(char letra: chutes_errados){
        cout<<letra<<" ";
        }
        cout<<"\n";
}

void set_palavra(){
     for(char letra : palavra_secreta){
            if(chutou[letra]){
                cout<<letra<<" ";
            }
            else{
                cout<<"_ ";
            }
        }
        cout<<"\n\n";
}

void chuta(){
     cout<<"Seu chute: ";

        char chute;
        cin >> chute;

        chutou[chute] = true;

        if(letra_existe(chute)){
            cout<<"Você acertou! Seu chute está na palavra.\n";
        }
        else{
            cout<<"Você errou! Seu chute não está na palavra.\n";
            chutes_errados.push_back(chute);

        }
        cout<<"\n";
}
vector<string> ler(){
    ifstream arquivo;
    arquivo.open("lista.txt");

    if(arquivo.is_open()){
        int quantidade;
        arquivo >> quantidade;

        vector<string> lista;

        for(int i=0; i<quantidade;i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            lista.push_back(palavra_lida);
        }

        arquivo.close();
        return lista;
    }
    else{
        cout << "\nNão foi possível acessar o banco de palavras.\n";
        exit(0);
    }
}

void sorteio(){
    vector<string> palavras = ler();

    srand(time(NULL));
    int sorteado = rand() % palavras.size();

    palavra_secreta = palavras[sorteado];

}

void salvar(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("lista.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista.size() << "\n";

        for(string palavra : nova_lista){
            arquivo << palavra << "\n";
        }
        arquivo.close();
    }
    else{
        cout << "\nNão foi possível acessar o banco de palavras.\n";
        exit(0);
    }
}

void adicionar(){
    cout<<"\nDigite a nova palavra (usando letras maiúsculas): ";
    string nova;
    cin >> nova;

    vector<string> palavras = ler();
    palavras.push_back(nova);

    salvar(palavras);
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    set_cabecalho();
    ler();
    sorteio();

    while(nao_acertou() && nao_enforcou()){
        set_erros();
        set_palavra();
        chuta();
    }

    cout<<"Fim de jogo!\n";
    cout<<"A palavra secreta era: "<<palavra_secreta<<"\n";
    if(nao_acertou()){
        cout<<"Você perdeu! Tente novamente\n";
    }
    else{
        cout<<"Parabéns! Você acertou a palavra secreta!\n"; 

        cout <<"\nVocê deseja adicionar uma nova palavra ao banco? (S/N)\n";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adicionar();
        }
    }

}