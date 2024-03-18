#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama, nim;
    int loginAttempt = 0;
    int menu;
    double inputValue, outputValue;
    
    // Login
    while (loginAttempt < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        // Simulasi login (contoh: nama = "bila", nim = "104")
        if (nama == "bila" && nim == "104") {
            cout << "Login berhasil! Welcome!, " << nama << "!" << endl;
            break;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            loginAttempt++;
        }
    }

    if (loginAttempt >= 3) {
        cout << "Anda telah gagal login sebanyak 3 kali. Mianhaeyo Program berhenti." << endl;
        return 0;
    }

    while (true) {
        cout << "=====================================================================" << endl;
        cout << "|         		 PROGRAM KONVERSI SUHU SEDERHANA 				     |" << endl;
        cout << "=====================================================================" << endl;
        cout << "|1. Konversi Celcius ke (Reamur, Farenheit, Kelvin)				 |" << endl;
        cout << "|2. Konversi Reamur ke (Celcius, Farenheit, Kelvin)				 |" << endl;
        cout << "|3. Konversi Farenheit ke (Celcius, Reamur, Kelvin)				 |" << endl;
        cout << "|4. Konversi Kelvin ke (Celcius, Reamur, Farenheit)				 |" << endl;
        cout << "|5. Logout 														 |" << endl;
        cout << "=====================================================================" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nilai dalam Celcius: ";
            cin >> inputValue;
            outputValue = (inputValue * 4) / 5; // Reamur
            cout << inputValue << " Celcius ke Reamur: " << outputValue << " Reamur\n";
            outputValue = (inputValue * 9) / 5 + 32; // Farenheit
            cout << inputValue << " Celcius ke Farenheit: " << outputValue << " Farenheit\n";
            outputValue = inputValue + 273.15; // Kelvin
            cout << inputValue << " Celcius ke Kelvin: " << outputValue << " Kelvin\n";
        } else if (menu == 2) {
            cout << "Masukkan nilai dalam Reamur: ";
            cin >> inputValue;
            outputValue = inputValue * 1.25; // Celcius
            cout << inputValue << " Reamur ke Celcius: " << outputValue << " Celcius\n";
            outputValue = (inputValue * 2.25) + 32; // Farenheit
            cout << inputValue << " Reamur ke Farenheit: " << outputValue << " Farenheit\n";
            outputValue = inputValue * 1.25 + 273.15; // Kelvin
            cout << inputValue << " Reamur ke Kelvin: " << outputValue << " Kelvin\n";
        } else if (menu == 3) {
            cout << "Masukkan nilai dalam Farenheit: ";
            cin >> inputValue;
            outputValue = (inputValue - 32) * 5 / 9; // Celcius
           	cout << inputValue << " Farenheit ke Celcius: " << outputValue << " Celcius\n";
           	outputValue = (inputValue - 32) * 4 / 9; // Reamur
            cout << inputValue << " Farenheit ke Reamur: " << outputValue << " Reamur\n";
            outputValue = (inputValue - 32) * 5 / 9 + 273.15; // Kelvin
            cout << inputValue << " Farenheit ke Kelvin: " << outputValue << " Kelvin\n";
    	} else if (menu == 4) {
	    	cout << "Masukkan nilai dalam Kelvin: ";	
	    	cin >> inputValue;
	        outputValue = inputValue - 273.15; // Celcius
	        cout << inputValue << " Kelvin ke Celcius: " << outputValue << " Celcius\n";
	        outputValue = (inputValue - 273.15) * 0.8; // Reamur
	        cout << inputValue << " Kelvin ke Reamur: " << outputValue << " Reamur\n";
	        outputValue = (inputValue - 273.15) * 9 / 5 + 32; // Farenheit
	        cout << inputValue << " Kelvin ke Farenheit: " << outputValue << " Farenheit\n";
    	
		} else if (menu== 5) {
			cout << "Terima kasih telah menggunakan program ini. See you!" << endl;
            exit(0);
	
    }   else { cout << "Menu tidak valid. Silakan coba lagi." << endl; } } 
    
    
	return 0;
    }
	
			