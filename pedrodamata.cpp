#include <iostream>
#include <string>
#include <vector>

using namespace std;


int contarCaracteres (const string& fraseParametro);
int contarPalavras (const string& fraseParametro);
int contarLetrasA (const string& fraseParametro);
int contarPalavrasRepetidas (string fraseParametro);
string trocarPalavras (string fraseParametro);

int main(){

    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);


    cout << "Quantidade de caracteres: " << contarCaracteres(frase) << endl;
    cout << "Quantidade de palavras: " << contarPalavras(frase) << endl;
    cout << "Quantidade de letras 'A': " << contarLetrasA(frase) << endl;
    cout << "Quantidade de palavras repetidas: " << contarPalavrasRepetidas(frase) << endl;
    cout << "Palavras trocadas: " <<  "'"  << trocarPalavras(frase) << "'" << endl;


    return 0;
}

int contarCaracteres (const string& fraseParametro){

    return fraseParametro.size();
}

int contarPalavras (const string& fraseParametro){

    int qtdPalavras = 1;
    int pos = -1;
    string sub = fraseParametro;


    do{

        pos = sub.find(' ');

        if(pos != -1){

            qtdPalavras++;
            sub = sub.substr(pos + 1);
        }


    }while(pos != -1);

    return qtdPalavras;
}
int contarLetrasA (const string& fraseParametro){

    int qtdA = 0;

    for(char i : fraseParametro){

        if(i == 'a' || i == 'A'){

            qtdA ++;
        }
    }

    return qtdA;
}
int contarPalavrasRepetidas(string fraseParametro){

    int pos = -1;
    int qtdRepetidas = 0;
    vector <string> palavras;


    do{

        pos = fraseParametro.find(' ');
        palavras.push_back(fraseParametro.substr(0, pos));
        fraseParametro = fraseParametro.substr(pos + 1);

    }while(pos != -1);

    for(int i = 0; i < (int)palavras.size(); i++){
        for (int j = 0; j < (int)palavras.size(); ++j) {
            if(palavras[i] == palavras[j]){
                if(i != j){
                    qtdRepetidas++;
                }
            }
        }
    }


    return qtdRepetidas;
}
string trocarPalavras ( string fraseParametro){

    int first, last = 0,  last1;
    string fraseTrocada;

    first = fraseParametro.find(' ');

    for(int i = 0; i < (int)fraseParametro.length(); i++){
        if(isspace(fraseParametro[i])){
            last = i;
       }
    }

    string p1 = fraseParametro.substr(last+1, fraseParametro.length());
    string p3 = ' ' + fraseParametro.substr(0, first);

    fraseParametro.erase(last, fraseParametro.length());
    fraseParametro.erase(0, first);

    string p2 = fraseParametro;

    fraseTrocada = p1 + p2 + p3;

    return  fraseTrocada;

}
