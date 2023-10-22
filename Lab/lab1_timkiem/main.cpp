#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sắp xếp mảng với thuật toán Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

// Hàm đọc dữ liệu từ tệp và sắp xếp, sau đó hiển thị k phần tử đầu tiên
void SortElements(const string& filename, int k) {
    vector<int> elements;

    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Khong the mo tep." << endl;
        return;
    }

    int num;
    while (inFile >> num) {
        elements.push_back(num);
    }

    inFile.close();

    bubbleSort(elements);

    for (int i = 0; i < k && i < elements.size(); i++) {
        cout << elements[i] << endl;
    }
}

int main() {
    string fn = "Numbers01.txt";
    int k = 20;

    SortElements(fn, k);

    return 0;
}
