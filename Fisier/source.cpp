#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Fisier {
private:
	const int codFisier;
	static int nrFisiere; //la alegere - codFisiere depinde de el
	string numeFisier;
	int nrAccesari;
	int nrEditori; //la alegere - nr elemente din vectorul editori
	string* editori;

public:

	//constructori
	Fisier() :codFisier(nrFisiere++) {
		numeFisier = "Necunoscut";
		nrAccesari = 0;
		nrEditori = 0;
		editori = nullptr;
	}

	Fisier(string numeFisier, int nrAccesari, int nrEditori, string* editori) :codFisier(nrFisiere++) {
		this->numeFisier = numeFisier;
		this->nrAccesari = nrAccesari;
		this->nrEditori = nrEditori;
		if(editori != nullptr) {
			this->editori = new string[nrEditori];
			for (int i = 0; i < nrEditori; i++) {
				this->editori[i] = editori[i];
			}
		}
		else {
			this->editori = nullptr;
		}
	}

	Fisier(const Fisier& f) :codFisier(nrFisiere++) {
		this->numeFisier = f.numeFisier;
		this->nrAccesari = f.nrAccesari;
		this->nrEditori = f.nrEditori;
		if (f.editori != nullptr) {
			this->editori = new string[f.nrEditori];
			for (int i = 0; i < f.nrEditori; i++) {
				this->editori[i] = f.editori[i];
			}
		}
		else {
			this->editori = nullptr;
		}
	}

	//destructor
	~Fisier() {
		if (this->editori != nullptr) {
			delete[] this->editori;
		}
	}

	//getters si setters
	int getCodFisier() const {
		return codFisier;
	}

	static int getNrFisiere() {
		return nrFisiere;
	}

	int getNrEditori() {
		return this->nrEditori;
	}

	static void setNrFisiere(int nrNouFisiere) {
		if (nrNouFisiere >= 0) {
			nrFisiere = nrNouFisiere;
		}
	}

	//operatori

	void operator=(const Fisier& f) {
		this->numeFisier = f.numeFisier;
		this->nrAccesari = f.nrAccesari;
		this->nrEditori = f.nrEditori;

		if (this->editori != nullptr) {
			delete[] this->editori;
			this->editori = nullptr;
		}

		if (f.editori != nullptr) {
			this->editori = new string[f.nrEditori];
			for (int i = 0; i < f.nrEditori; i++) {
				this->editori[i] = f.editori[i];
			}
		}
		else {
			this->editori = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Fisier& f) {
		out << "Cod fisier:" << f.codFisier << endl;
		out << "Nume fisier:" << f.numeFisier << endl;
		out << "Numar accesari:" << f.nrAccesari << endl;
		out << "Numar editori:" << f.nrEditori << endl;
		if (f.editori != nullptr) {
			out << "Editori:" << endl;
			for (int i = 0; i < f.nrEditori - 1; i++) {
				out << f.editori[i] << ", ";
			}
			out << f.editori[f.nrEditori - 1] << endl;
		}
		else {
			out << "Nu exista editori" << endl;
		}
		return out;
	}

	bool operator>(const Fisier& f) {
		if (numeFisier.length() > f.numeFisier.length()) {
			return true;
		}
		else {
			return false;
		}
	}

	const string& operator[](int index) const {
		return editori[index];
	}
};

int Fisier::nrFisiere = 0;

void main() {
	Fisier f1;
	cout << f1 << endl;
	cout << "================================" << endl;

	string editori[] = { "Laura", "Mihnea", "Maria", "Andreea" };
	Fisier f2("Fisier1", 6, 4, editori);
	cout << f2 << endl;
	cout << "================================" << endl;

	Fisier f3(f2);
	cout << f3 << endl;
	cout << "================================" << endl;

	Fisier f4 = f3;
	cout << f4 << endl;
	cout << "================================" << endl;

	f1 = f4;
	cout << f1 << endl;
	cout << "================================" << endl;

	Fisier f5("kjbdjfvhjdbg", 6, 4, editori);
	cout << f5 << endl;
	cout << "================================" << endl;

	if (f1 > f5) {
		cout << "Numele fisierului " << f1.getCodFisier() << " este > decat numele fisieruli " << f5.getCodFisier() << endl;
		cout << "================================" << endl;
	}
	else {
		cout << "Numele fisierului " << f5.getCodFisier() << " este > decat numele fisieruli " << f1.getCodFisier() << endl;
		cout << "================================" << endl;
	}

	cout << f5[2] << endl;
}