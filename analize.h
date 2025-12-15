#ifndef ANALIZE_H_INCLUDED
#define ANALIZE_H_INCLUDED

#include "Mylib.h"

std::string pakeistas_zodis(const std::string& zodis);

void spausdinimas_zodziu_kiekis(
    const std::map<std::string, int>& zodziu_kiekis
);

void spausdinimas_zodziu_eil(
    const std::map<std::string,
    std::pair<int, std::set<int>>>& zodziu_eil
);

std::string pasirinkimas_url();

void spausdinimas_url(
    std::ostream& out,
    const std::set<std::string>& url_set
);

void url_paskirstymas(
    std::string pasirinkimas,
    const std::set<std::string>& url_set
);

void failo_tvarkymas();

#endif
