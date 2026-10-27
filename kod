#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cout << "Podaj liczbe maszyn: ";
    cin >> m;
    cout << "Podaj liczbe zadan: ";
    cin >> n;
    vector<int> zadania(n);
    cout << "Podaj czasy zadan: ";
    for (int i = 0; i < n; i++) {
        cin >> zadania[i];
    }
    sort(zadania.begin(), zadania.end(), greater<int>());
    vector<int> maszyny(m, 0);
    for (int i = 0; i < n; i++) {
        int min = 0;
        for (int j = 1; j < m; j++) {
            if (maszyny[j] < maszyny[min]) {
                min = j;
            }
        }
        maszyny[min] = maszyny[min] + zadania[i];
        cout << "Zadanie " << zadania[i] << " trafia na maszyne " << min + 1 << endl;
    }
    int pcmax = maszyny[0];
    for (int i = 1; i < m; i++) {
        if (maszyny[i] > pcmax) {
            pcmax = maszyny[i];
        }
    }
    cout << endl << "Obciazenie maszyn:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Maszyna " << i + 1 << ": " << maszyny[i] << endl;
    }
    cout << "PCmax = " << pcmax << endl;
    return 0;
}
