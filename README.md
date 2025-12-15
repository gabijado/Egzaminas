# Egzaminas
Egzamino_uzd

Šio projekto tikslas – praktiškai pademonstruoti std::string ir asociatyvių konteinerių (std::map, std::set) naudojimą 
analizuojant tekstą. Programa apdoroja tekstinį failą, skaičiuoja žodžių pasikartojimus, kuria cross-reference tipo lentelę ir 
suranda tekste esančius URL adresus.

##Programa realizuoja šiuos užduotyje nurodytus funkcionalumus:
1. Skaičiuoja, kiek kartų pasikartoja kiekvienas skirtingas žodis tekste
2. Ignoruoja skyrybos ženklus ir skaičius (jie nelaikomi žodžio dalimi)
3. Žodžius apdoroja neatsižvelgiant į raidžių dydį
4. Išveda tik tuos žodžius, kurie pasikartojo daugiau nei vieną kartą
5. Sukuria cross-reference lentelę, kurioje nurodoma, kuriose teksto eilutėse kiekvienas žodis buvo paminėtas
6. Suranda tekste esančius URL adresus, pateiktus tiek pilnu, tiek sutrumpintu pavidalu
7. Leidžia vartotojui pasirinkti, ar URL adresai bus išvedami į terminalą, ar į failą

##Naudojami konteineriai
1. std::map<std::string, int> – žodžių pasikartojimų skaičiavimui
2. std::map<std::string, std::pair<int, std::set<int>>> – cross-reference lentelės sudarymui
3. std::set<std::string> – unikalių URL adresų saugojimui
4. std::set<int> – eilučių numeriams be pasikartojimų kaupti
5. std::string teksto apdorojimui.

##Struktūra
1. main.cpp — pagrindinis programos failas
2. analize.cpp / analize.h — teksto analizės, žodžių skaičiavimo ir URL apdorojimo logika
3. Mylib.h — standartinių bibliotekų antraštė
4. README.md — projekto dokumentacija

##Naudojimosi instrukcija
1. Paleiskite programą.
2. Įveskite teksto failo pavadinimą, kurį norite analizuoti.
3. Programa:
    1. nuskaitys failą eilutė po eilutės;
    2. suskaičiuos žodžių pasikartojimus;
    3. nustatys, kuriose eilutėse kiekvienas žodis pasikartojo;
    4. suras visus URL adresus.
4. Žodžių pasikartojimų rezultatai bus išsaugoti faile:
    a. kiekis.txt – žodis ir jo pasikartojimų skaičius
5. Cross-reference lentelė bus išsaugota faile:
    a. eil.txt – žodis ir eilučių numeriai, kuriose jis buvo paminėtas
6. Jei tekste randami URL adresai, vartotojas gali pasirinkti:
    a. T – rodyti URL terminale
    b. F – išsaugoti URL faile url_info.txt

##URL paieškos realizacija
URL adresų paieškai naudojama std::regex. Aptinkami:
    a. adresai su http:// ir https://
    b. adresai su www
    c. domenai be protokolo (pvz. vu.lt, saitas.xyz)
Rasti URL adresai saugomi std::set, todėl išvedami be pasikartojimų.

##Išvesties failai
Programa sugeneruoja šiuos failus:
    a. kiekis.txt – žodžiai, pasikartojantys daugiau nei 1 kartą, ir jų kiekiai
    b. eil.txt – cross-reference lentelė (žodis → eilučių numeriai)
    c. url_info.txt – rasti URL adresai (jei pasirinkta išvestis į failą)

##Išvados
Šio darbo metu buvo pademonstruotas efektyvus std::string ir asociatyvių konteinerių panaudojimas sprendžiant realią teksto 
analizės užduotį. Programa korektiškai apdoroja tekstą, kuria cross-reference lentelę ir suranda URL adresus, atitinkančius 
užduotyje pateiktus reikalavimus.
