#include "analize.h"

/* using – tik cpp faile */
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::ifstream;
using std::ofstream;
using std::map;
using std::set;
using std::pair;
using std::regex;
using std::stringstream;
using std::ostream;

/* -------------------------------------------------- */
string pakeistas_zodis(const string& zodis) {
    string naujas_zodis;

    for (unsigned char ch : zodis) {  // SVARBIAUSIA PATAISA
        ch = static_cast<unsigned char>(std::tolower(ch));
        if (!std::ispunct(ch) && !std::isdigit(ch)) {
            naujas_zodis += ch;
        }
    }
    return naujas_zodis;
}

/* -------------------------------------------------- */
void spausdinimas_zodziu_kiekis(const map<string, int>& zodziu_kiekis) {
    ofstream failas("kiekis.txt");

    if (!failas.is_open()) {
        cout << "Nepavyko sukurti kiekis.txt" << endl;
        return;
    }

    failas << left << setw(20) << "Žodis"
        << setw(10) << "Kiekis" << endl;
    failas << string(30, '-') << endl;

    for (const auto& i : zodziu_kiekis) {
        if (i.second > 1) {
            failas << left << setw(20) << i.first
                << setw(10) << i.second << endl;
        }
    }

    cout << "Rezultatai išsaugoti faile 'kiekis.txt'" << endl;
}

/* -------------------------------------------------- */
void spausdinimas_zodziu_eil(
    const map<string, pair<int, set<int>>>& zodziu_eil) {

    ofstream failas("eil.txt");

    if (!failas.is_open()) {
        cout << "Nepavyko sukurti eil.txt" << endl;
        return;
    }

    failas << left << setw(20) << "Žodis"
        << "Eilutės" << endl;
    failas << string(40, '-') << endl;

    for (const auto& i : zodziu_eil) {
        if (i.second.first > 1) {
            failas << left << setw(20) << i.first << "{";

            bool pirmas = true;
            for (int eil : i.second.second) {
                if (!pirmas) failas << ", ";
                failas << eil;
                pirmas = false;
            }
            failas << "}" << endl;
        }
    }

    cout << "Rezultatai išsaugoti faile 'eil.txt'" << endl;
}

/* -------------------------------------------------- */
string pasirinkimas_url() {
    string pasirinkimas;
    cout << "Kur rodyti URL? (T - terminalas, F - failas): ";

    while (true) {
        cin >> pasirinkimas;
        std::transform(pasirinkimas.begin(), pasirinkimas.end(),
            pasirinkimas.begin(), ::toupper);

        if (pasirinkimas == "T" || pasirinkimas == "F")
            break;

        cout << "Klaida! Įveskite T arba F: ";
    }
    return pasirinkimas;
}

/* -------------------------------------------------- */
void spausdinimas_url(ostream& out, const set<string>& url_set) {
    out << "Rasti URL adresai:" << endl;
    out << string(25, '-') << endl;

    for (const auto& url : url_set) {
        out << url << endl;
    }
}

/* -------------------------------------------------- */
void url_paskirstymas(string pasirinkimas, const set<string>& url_set) {
    if (pasirinkimas == "T") {
        spausdinimas_url(cout, url_set);
    }
    else {
        ofstream failas("url_info.txt");
        if (failas.is_open()) {
            spausdinimas_url(failas, url_set);
            cout << "Rezultatai išsaugoti faile 'url_info.txt'" << endl;
        }
    }
}

/* -------------------------------------------------- */
void failo_tvarkymas() {

    string failo_pavadinimas;
    ifstream failas;

    map<string, int> zodziu_kiekis;
    map<string, pair<int, set<int>>> zodziu_eil;
    set<string> url_set;

    int eil_nr = 0;

    regex url_regex(
        R"(((https?://(www\.)?)|(www\.))?([a-zA-Z0-9-]+\.)+([a-zA-Z]{2,})(/[^\s]*)?)"
    );

    cout << "Įveskite failo pavadinimą: ";
    getline(cin, failo_pavadinimas);

    failas.open(failo_pavadinimas);
    if (!failas.is_open()) {
        cout << "Failas nerastas!" << endl;
        return;
    }

    string eilute;
    while (getline(failas, eilute)) {
        eil_nr++;
        stringstream ss(eilute);
        string zodis;

        while (ss >> zodis) {
            if (std::regex_match(zodis, url_regex)) {
                while (!zodis.empty() &&
                    std::ispunct(static_cast<unsigned char>(zodis.back()))) {
                    zodis.pop_back();
                }
                url_set.insert(zodis);
            }
            else {
                string tvarkytas = pakeistas_zodis(zodis);
                if (!tvarkytas.empty()) {
                    zodziu_kiekis[tvarkytas]++;
                    zodziu_eil[tvarkytas].first++;
                    zodziu_eil[tvarkytas].second.insert(eil_nr);
                }
            }
        }
    }

    failas.close();

    spausdinimas_zodziu_kiekis(zodziu_kiekis);
    spausdinimas_zodziu_eil(zodziu_eil);

    if (!url_set.empty()) {
        string pasirinkimas = pasirinkimas_url();
        url_paskirstymas(pasirinkimas, url_set);
    }
    else {
        cout << "URL adresų nerasta." << endl;
    }
}
