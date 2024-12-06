#include <iostream>
#include <string>
#include "Dizionario.cpp"

int main() {
    Dizionario<std::string> dict;

    //inserimento valori nel dizionari
    dict.inserisci("dog", "animal");
    dict.inserisci("computer", "machine");
    dict.inserisci("pen", "writing tool");

    std::cout<<"Inserimento di una chiave con collisione..."<<std::endl;
    dict.inserisci("god", "collision_example");

    std::cout<<"Recupero di valori esistenti:"<<std::endl;
    std::cout<<"Value for 'dog': "<<dict.recupera("dog")<<std::endl;
    std::cout<<"Value for 'computer': "<<dict.recupera("computer")<<std::endl;
    std::cout<<"Value for 'pen': "<<dict.recupera("pen")<<std::endl;

    std::cout<<"Verifica appartenenza delle chiavi:"<<std::endl;
    std::cout<<"La chiave 'dog' appartiene al dizionario? "<<(dict.appartiene("dog") ? "Sì" : "No")<<std::endl;
    std::cout<<"La chiave 'book' appartiene al dizionario? "<<(dict.appartiene("book") ? "Sì" : "No")<<std::endl;

    std::cout<<"Cancellazione di una chiave ('computer'):"<<std::endl;
    dict.cancella("computer");

    std::cout << "Dopo la cancellazione, la chiave 'computer' appartiene? "<<(dict.appartiene("computer") ? "Sì" : "No")<<std::endl;

    std::cout<<"Stato attuale del dizionario:"<<std::endl;
    dict.stampa();

    return 0;
}
