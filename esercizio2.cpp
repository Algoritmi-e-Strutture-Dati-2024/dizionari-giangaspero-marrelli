#include <iostream>
#include <string>

template <typename T>
class Dizionario {
private:
    static const int TABLE_SIZE = 100; // Dimensione fissa della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

    // Funzione hash di base
    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % TABLE_SIZE;
    }

    // Funzione per trovare uno slot libero o la posizione corretta per una chiave
    int findSlot(int startIndex, const std::string& key) const {
        int index = startIndex;
        while (true) {
            if (!table[index].isOccupied || table[index].key == key) {
                return index;
            }
            index = (index + 1) % TABLE_SIZE; // Probing lineare
            if (index == startIndex) {
                cout<<"No available slots or key not found!"<<endl;
            }
        }
    }

public:
    //----------FUNZIONE INSERISCI CON DOUBLE HASHING-------
    void inserisci(const std::string& key, const T value)
    {
        int index = hashFunction(key);

        if (table[index].isOccupied && table[index].key != key)
        {
            index = findSlot(index, key);
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    //------------FUNZIONE RECUPERA CON DOUBLE HASHING-----
    T recupera(const std::string& key) const {
        int index = hashFunction(key);

        if (!table[index].isOccupied || table[index].key != key) {
            index = findSlot(index, key);
        }

        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }

        cout<<"Key not found!"<<endl;
    }

    //----------APPARTIENE CON DOUBLE HASHING---------
    bool appartiene(const std::string& key) const
    {
        int index = hashFunction(key);
        int step = 1 + (index % (TABLE_SIZE - 1));
        int startIndex = index;

        while (table[index].isOccupied)
        {
            if (table[index].key == key)
            {
                return true;
            }
        
            index = (index + step) % TABLE_SIZE;

            if (index == startIndex)
            {
                break;
            }

        }

        return false;
    }

    //---------CANCELLA CON DOUBLE HASHING--------
    void cancella(const std::string& key) {
        int index = hashFunction(key);

        if (!table[index].isOccupied || table[index].key != key)
        {
            index = findSlot(index, key); 
        }

        if (table[index].isOccupied && table[index].key == key)
        {
            table[index].isOccupied = false;
            table[index].key = "";
            table[index].value = T();

            std::cout<<"Key "<<key<<" deleted."<<std::endl;

            return 1;
        }
        else
        std::cout <<"Key "<<key<<" not found."<<std::endl;
        
    }

    // Metodo per stampare il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};
