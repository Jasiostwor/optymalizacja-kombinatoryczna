#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    // Otwieranie pliku z danymi
    ifstream plik("m30.txt");
    if (!plik.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku dane.txt!" << endl;
        return 1;
    }

    int liczba_procesorow, liczba_zadan;
    
    // Wczytanie liczby procesorów i zadań
    plik >> liczba_procesorow >> liczba_zadan;

    vector<int> zadania(liczba_zadan);
    
    // Wczytanie czasów trwania poszczególnych zadań
    for (int i = 0; i < liczba_zadan; i++) {
        plik >> zadania[i];
    }
    plik.close();

    // 1. Krok algorytmu LPT: Sortowanie zadań malejąco
    // Dzięki temu najdłuższe zadania są przydzielane jako pierwsze.
    sort(zadania.rbegin(), zadania.rend());

    // Wektor przechowujący aktualny czas pracy (obciążenie) każdego procesora
    vector<int> procesory(liczba_procesorow, 0);

    // 2. Krok algorytmu zachłannego: Przydzielanie zadań
    for (int i = 0; i < liczba_zadan; i++) {
        int index_najluźniejszego = 0;
        
        // Szukanie procesora z najmniejszym aktualnym obciążeniem
        for (int j = 1; j < liczba_procesorow; j++) {
            if (procesory[j] < procesory[index_najluźniejszego]) {
                index_najluźniejszego = j;
            }
        }
        
        // Przypisanie zadania do znalezionego procesora
        procesory[index_najluźniejszego] += zadania[i];
    }

    // Znalezienie procesora z największym obciążeniem (to nasz czas zakończenia, tzw. makespan)
    int czas_zakonczenia = 0;
    for (int j = 0; j < liczba_procesorow; j++) {
        if (procesory[j] > czas_zakonczenia) {
            czas_zakonczenia = procesory[j];
        }
    }

    cout << "Zakonczono szeregowanie zadan." << endl;
    cout << "Maksymalny czas pracy procesora (makespan): " << czas_zakonczenia << endl;
    
    // Wypisanie obciążenia każdego z procesorów
    cout << "\nSzczegolowe obciazenie poszczegolnych procesorow:" << endl;
    for (int j = 0; j < liczba_procesorow; j++) {
        cout << "Procesor " << j + 1 << ": " << procesory[j] << " jednostek czasu" << endl;
    }

    return 0;
}