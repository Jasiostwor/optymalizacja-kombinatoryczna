#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

void generuj(const string& nazwaPliku, int m, int n, int minCzas, int maxCzas) {
    ofstream plik(nazwaPliku);
    if (!plik.is_open()) return;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minCzas, maxCzas);

    plik << m << "\n" << n << "\n";
    for (int i = 0; i < n; ++i) {
        plik << dist(gen) << "\n";
    }
    plik.close();
    cout << "Utworzono: " << nazwaPliku << endl;
}

int main() {
    generuj("maly_test.txt", 5, 20, 1, 50);      
    generuj("sredni_test.txt", 20, 100, 30, 60); 
    
    return 0;
}