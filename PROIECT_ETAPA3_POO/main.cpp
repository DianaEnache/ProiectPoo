#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <memory>

using namespace std;

//INTERFATA(+2 metode virtuale)
class IOinterface
{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};


                                                /**CLASA CLIENT*/

class Client{
    private:
            string nume_client;
            string prenume_client;
            string email_client;
            string metoda_plata;//cash sau card
            int varsta_client;//pt reducere sub 18 ani

    public:
//Constructorul este folosit pentru a inițializa obiecte din clasa Filme atunci când acestea sunt create.
//Astfel, atunci când se creează un nou obiect Client, se va apela acest constructor și variabilele membre
//ale obiectului vor fi initializate cu valorile primite ca argumente.
/**CONSTRUCTORI*/
        Client();
        Client(string nume_client,string prenume_client,string email_client,string metoda_plata,int varsta_client);
        Client(string nume_client,string prenume_client,string metoda_plata);
        Client(string nume_client,string prenume_client,int varsta_client);
        Client(string nume_client,string prenume_client);
        Client(const Client &ob);//constructor copiere
//constructorul de copiere
//se pune const pentru a proteja datele din obiectul de copiat
//se pune & pentru a putea accesa direct adresa obiectului de copiat
//astfel incat sa nu folosim memorie suplimentara daca cream alt obiect

//Fiecare constructor are un set diferit de argumente și poate fi utilizat pentru a crea un obiect

/**THIS*/// folosirea operatorului THIS ajuta la evitarea ambiguitatilor si la mentinerea unei structuri coerente si clare a codului


/**SETTERS*/
        void setNume_client(string nume_client);
        void setPrenume_client(string prenume_client);
        void setEmail_client(string email_client);
        void setMetoda_plata(string metoda_plata);
        void setVarsta_client(int varsta_client);

/**GETTERS*/

        string getNume_client()const;
        string getPrenume_client()const;
        string getEmail_client()const;
        string getMetoda_plata()const;
        int getVarsta_client()const;

/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Client &ob);
        friend ostream& operator <<(ostream& out, const Client &ob);


    ~Client(){}


};

/**CONSTRUCTORI*/

//Constructor fara parametrii:
    Client::Client(){

        this->nume_client = "";
        this->prenume_client = "";
        this->email_client = "";
        this->metoda_plata = "";
        this->varsta_client= 0;

    }

//Constructor cu 5 parametrii:
    Client::Client(string nume_client,string prenume_client,string email_client,string metoda_plata,int varsta_client){

        this->nume_client = nume_client;
        this->prenume_client = prenume_client;
        this->email_client = email_client;
        this->metoda_plata = metoda_plata;
        this->varsta_client = varsta_client;

    }
//Constructor 3 parametrii

    Client::Client(string nume_client,string prenume_client,string metoda_plata){

        this->nume_client = nume_client;
        this->prenume_client = prenume_client;
        this->metoda_plata = metoda_plata;

    }

    Client::Client(string nume_client,string prenume_client,int varsta_client){


        this->nume_client = nume_client;
        this->prenume_client = prenume_client;
        this->varsta_client = varsta_client;
}

//Constructor 2 parametrii

    Client::Client(string nume_client,string prenume_client){

        this->nume_client = nume_client;
        this->prenume_client = prenume_client;

    }

/**constructor copiere*/
    Client::Client(const Client &ob){

        this->nume_client = ob.nume_client;
        this->prenume_client = ob.prenume_client;
        this->email_client = ob.email_client;
        this->metoda_plata = ob.metoda_plata ;
        this->varsta_client= ob.varsta_client;
    }

void Client::setNume_client(string nume_client){

        this->nume_client = nume_client;
    };

    void Client::setPrenume_client(string prenume_client){

        this->prenume_client = prenume_client;
    };

    void Client::setEmail_client(string email_client){

        this->email_client = email_client;
    };

    void Client::setMetoda_plata(string metoda_plata){

        this->metoda_plata = metoda_plata;
    };

    void Client::setVarsta_client(int varsta_client){
        this->varsta_client = varsta_client;
    };


//GETTERS


    string Client::getNume_client()const {
        return this->nume_client;
    };

    string Client::getPrenume_client()const {
        return this->prenume_client;
    };

    string Client::getEmail_client()const {
        return this->email_client;
    };

    string Client::getMetoda_plata()const {
        return this->metoda_plata;
    };

    int Client::getVarsta_client()const{
        return this->varsta_client;
    };


/**OPERATORUL << */

    ostream& operator<<(ostream& out,const Client &ob){

        out<<"Nume:"<<ob.nume_client<<endl;
        out<<"Prenume:"<<ob.prenume_client<<endl;
        out<<"E-mail:"<<ob.email_client<<".com"<<endl;
        out<<"Metoda plata(card/cash):"<<ob.metoda_plata<<endl;
        out<<"Varsta:"<<ob.varsta_client<<" ani"<<endl;

        return out;
    }

/**OPERATORUL >> */

    istream& operator>>(istream& in,Client &ob){

        cout<<"Nume:";
        in>>ob.nume_client;

        cout<<"Prenume:";
        in>>ob.prenume_client;

        cout<<"Email:";
        in>>ob.email_client;

        cout<<"Metoda plata (card/cash):";
        in>>ob.metoda_plata;

        cout<<"Varsta:";
        in>>ob.varsta_client;

        return in;

    }


                                                      /**CLASA ANGAJAT*/
class Angajat{
    private:
        string nume_angajat;
        string prenume_angajat;
        string pozitie_ocupata;//Casier,Personal de curățenie,Proiecționist,Manager de cinema,Recepționer,Agent de marketing,Tehnician de echipamente
        int luni_lucrate;
        float salariu;
//6 atribute
    public:

/**CONSTRUCTORI*/
        Angajat();
        Angajat(string nume_angajat,string prenume_angajat,string pozitie_ocupata,int luni_lucrate,float salariu);
        Angajat(string nume_angajat,string prenume_angajat,string pozitie_ocupata,int luni_lucrate);
        Angajat(string nume_angajat,string prenume_angajat,float salariu);
        Angajat(string nume_angajat,string prenume_angajat);
        Angajat(const Angajat &ob);//constructor copiere


/**SETTERS*/
        void setNume_angajat(string nume_angajat);
        void setPrenume_angajat(string prenume_angajat);
        void setPozitie_ocupata(string pozitie_ocupata);
        void setLuni_lucrate(int luni_lucrate);
        void setSalariu(float salariu);



/**GETTERS*/

        string getNume_angajat()const;
        string getPrenume_angajat()const;
        string getPozitie_ocupata()const;
        int getLuni_lucrate();
        float getSalariu();



/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Angajat &ob);
        friend ostream& operator <<(ostream& out, const Angajat &ob);


/**DESTRUCTOR*/ // pt cele alocate dinamice
        ~Angajat(){}


/**METODE*/
//METODA CALCUL SALARIU IN FUNCTIE DE LUNILE LUCRATE SI POZITIA OCUPATA
float CalculeazaSalariu(int luni_lucrate,string pozitie_ocupata)
    {
        float salariu = 0;

        if( pozitie_ocupata == "Casier" or pozitie_ocupata == "casier" ){
        salariu = luni_lucrate * 1500;

    } else if(pozitie_ocupata == "Personal de curatenie" or pozitie_ocupata == "personal de curatenie" ) {
        salariu = luni_lucrate * 1200;

    } else if( pozitie_ocupata == "Proiectionist" or pozitie_ocupata == "proiectionist" ) {
        salariu = luni_lucrate * 1800;

    } else if(pozitie_ocupata == "Manager de cinema" or pozitie_ocupata == "manager de cinema") {
        salariu = luni_lucrate * 3000;

    } else if(pozitie_ocupata == "Receptioner" or pozitie_ocupata == "receptioner") {
        salariu = luni_lucrate * 2000;

    } else if(pozitie_ocupata == "Agent de marketing" or pozitie_ocupata == "agent de marketing") {
        salariu = luni_lucrate * 2500;

    } else if(pozitie_ocupata == "Tehnician de echipamente" or pozitie_ocupata == "Tehnician de echipamente") {
        salariu = luni_lucrate * 2000;

    } else {
        cout << "Pozitie ocupata invalida!" << endl;
    }

    return salariu;
}



};






/**CONSTRUCTORI*/

//Constructor fara parametrii:
    Angajat::Angajat(){

        this->nume_angajat ="";
        this->prenume_angajat = "";
        this->pozitie_ocupata = "";
        this->luni_lucrate = 0;
        this->salariu= 0;


    }

//Constructor cu 6 parametrii

    Angajat::Angajat(string nume_angajat,string prenume_angajat,string pozitie_ocupata,int luni_lucrate,float salariu){

            this->nume_angajat = nume_angajat;
            this->prenume_angajat= prenume_angajat;
            this->pozitie_ocupata= pozitie_ocupata;
            this->luni_lucrate = luni_lucrate;
            this->salariu = salariu;


    }

//constructor cu 4 parametrii

    Angajat::Angajat(string nume_angajat,string prenume_angajat,string pozitie_ocupata,int luni_lucrate){

            this->nume_angajat = nume_angajat;
            this->prenume_angajat= prenume_angajat;
            this->pozitie_ocupata= pozitie_ocupata;
            this->luni_lucrate = luni_lucrate;
    }
//Constructor cu 3 parametrii
    Angajat::Angajat(string nume_angajat,string prenume_angajat,float salariu){

        this->nume_angajat = nume_angajat;
        this->prenume_angajat= prenume_angajat;
        this->salariu = salariu;
    }

//Constructor cu 2 parametrii

    Angajat::Angajat(string nume_angajat,string prenume_angajat){

        this->nume_angajat = nume_angajat;
        this->prenume_angajat= prenume_angajat;
    }

/**constructor copiere*/

    Angajat::Angajat(const Angajat &ob){

        this->nume_angajat = ob.nume_angajat;
        this->prenume_angajat = ob.prenume_angajat;
        this->pozitie_ocupata = ob.pozitie_ocupata ;
        this->luni_lucrate = ob.luni_lucrate;
        this->salariu = ob.salariu;


    }

//SETTERS

     void Angajat::setNume_angajat(string nume_angajat){

        this->nume_angajat =  nume_angajat;
    };

     void Angajat::setPrenume_angajat(string prenume_angajat){

        this->prenume_angajat = prenume_angajat;
    };

     void Angajat::setPozitie_ocupata(string pozitie_ocupata){

        this->pozitie_ocupata = pozitie_ocupata;
    };

    void Angajat::setLuni_lucrate(int luni_lucrate){

        this->luni_lucrate = luni_lucrate;
    };

    void Angajat::setSalariu(float salariu){

        this->salariu = salariu;
    };



//GETTERS


    string Angajat::getNume_angajat()const {
        return this->nume_angajat;
    };

    string Angajat::getPrenume_angajat()const {
        return this->prenume_angajat;
    };

    string Angajat::getPozitie_ocupata()const {
        return this->pozitie_ocupata;
    };

    float Angajat::getSalariu(){
        return this->salariu;
    };

    int Angajat::getLuni_lucrate(){
        return this->luni_lucrate;
    };


/**OPERATORUL << */
    ostream& operator<<(ostream& out,const Angajat &ob){

        out<<"Nume:"<<ob.nume_angajat<<endl;
        out<<"Prenume:"<<ob.prenume_angajat<<endl;
        out<<"Pozitie ocupata: "<<ob.pozitie_ocupata<<endl;
        out<<"Luni lucrate: "<<ob.luni_lucrate<<endl;
        out<<"Salariu: "<<ob.salariu<<endl;
        return out;
};

/**OPERATORUL >> */
    istream& operator >>(istream& in, Angajat & ob){
        cout<<"Nume:";
        in>>ob.nume_angajat;

        cout<<"Prenume:";
        in>>ob.prenume_angajat;

        cout<<"Pozitie ocupata:";
        in>>ob.pozitie_ocupata;

        cout<<"Luni lucrate:";
        in>>ob.luni_lucrate;

        cout<<"Salariu:";
        in>>ob.salariu;

        return in;

        };




                                                    /**CLASA CINEMA */

class Cinema{
    private:
        string nume_cinema;
        string site_web;
        string nr_telefon;

    public:

/**CONSTRUCTORI*/

    Cinema();//constructor fara parametrii
    Cinema(string nume_cinema,string site_web,string nr_telefon);
    Cinema(string nume_cinema,string site_web);
    Cinema(string nume_cinema);
    Cinema(const Cinema &ob);//constructor copiere

/**SETTERS*/

    void setNume_cinema(string nume_cinema);
    void setSite_web(string site_web);
    void setNr_telefon(string nr_telefon);

/**GETTERS*/

    string getNume_cinema()const;
    string getSite_web()const;
    string getNr_telefon()const;

/**SUPRAINCARCARE OPERATORI*/

    friend istream& operator >>(istream& in, Cinema &ob);
    friend ostream& operator <<(ostream& out, const Cinema &ob);

//Destructor pt cele alocate dinamice
        ~Cinema(){}

};

//CONSTRUCTORI

//Constructor fara parametrii:
    Cinema::Cinema(){
        this->nume_cinema = "";
        this->nr_telefon = "";
        this->site_web = "";
    }

//Constructor cu 3 parametrii:
    Cinema::Cinema(string nume_cinema,string site_web,string nr_telefon){

        this->nume_cinema = nume_cinema;
        this->site_web = site_web;
        this->nr_telefon = nr_telefon;

    }

//Constructor cu 2 parametrii:
    Cinema::Cinema(string nume_cinema,string site_web){

        this->nume_cinema = nume_cinema;
        this->site_web = site_web;
    }

//Constructor cu 1 parametru:
    Cinema::Cinema(string nume_cinema){

        this->nume_cinema = nume_cinema;
    }

//Constructor copiere:

     Cinema::Cinema(const Cinema &ob){

        this->nume_cinema = ob.nume_cinema;
        this->site_web = ob.site_web;
        this->nr_telefon = ob.nr_telefon;
    }

//SETTERS

    void Cinema::setNume_cinema(string nume_cinema){

        this->nume_cinema = nume_cinema;
    };

    void Cinema::setSite_web(string site_web){

        this->site_web = site_web;
    };

    void Cinema::setNr_telefon(string nr_telefon){

        this->nr_telefon = nr_telefon;
    };

//GETTERS

    string Cinema::getNume_cinema()const {
        return this->nume_cinema;
    };

    string Cinema::getSite_web()const {
        return this->site_web;
    };

    string Cinema::getNr_telefon()const {
        return this->nr_telefon;
    };

/**OPERATORUL << */

    ostream& operator<<(ostream& out,const Cinema &ob){

        out<<"Nume cinema:"<<ob.nume_cinema<<endl;
        out<<"Web site:"<<ob.site_web<<".com"<<endl;
        out<<"Numar telefon:"<<ob.nr_telefon<<endl;
        out<<endl;
        return out;
    }

/**OPERATORUL >> */

    istream& operator>>(istream& in,Cinema &ob){

        cout<<"Nume cinema: ";
        in>>ob.nume_cinema;

        cout<<"Web site: ";
        in>>ob.site_web;

        cout<<"Numar telefon: ";
        in>>ob.nr_telefon;

        return in;

    }


                                                        /**CLASA BAR CINEMA*/



//IERRARHIE DE MOSTENIRI

class Bar{//Parinte ->>//Bar Bautura,Bar Mancare(copii)
    protected://protected
        string nume_produs;
        int stoc_produse;
        float pret_produse;

    public:
//Constructori
        Bar(){
            this->stoc_produse = 0;
            this->pret_produse = 0;
            this->nume_produs = "";

            };

        Bar(int stoc_produse,string nume_produs){

                    this->stoc_produse=stoc_produse;
                    this->nume_produs = nume_produs;
            };

        Bar(string nume_produs,int stoc_produse,float pret_produse){

            this->stoc_produse=stoc_produse;
            this->nume_produs = nume_produs;
            this->pret_produse = pret_produse;

        };

//Setters
    void setStoc_produse(int stoc_produse){
        this->stoc_produse=stoc_produse;
    };

    void setPret_produse(float pret_produse){
        this->pret_produse=pret_produse;
    };

    void setNume_produs(string nume_produs){
        this->nume_produs = nume_produs;
    };

//Getters
    int getStoc_produse(){
        return this->stoc_produse;
    };

     float getPret_produse(){
        return this->pret_produse;
    };

     string getNume_produs(){
        return this->nume_produs;
    };

    //destructor
    virtual ~Bar(){}



};

class BarBautura:public Bar{
    private:
        bool gheata_bautura;//cu sau fara gheata

    public:

        BarBautura();
        BarBautura(bool gheata_bautura,string nume_produs,int stoc_produse,float pret_produse):Bar(nume_produs,stoc_produse,pret_produse){ this->gheata_bautura = gheata_bautura;}
        BarBautura(const BarBautura &ob);


//Getter
         bool getGheata_bautura() {return gheata_bautura;};
//Setter
        void setGheata_bautura(bool gheata_bautura) {
            this->gheata_bautura = gheata_bautura;
            }

        void afisare(){
            cout<<gheata_bautura<<endl;
        }

    virtual ~BarBautura(){}
};

class BarMancare:public Bar{
    private:
        bool combo_meniu;

    public:
        BarMancare();
        BarMancare(bool combo_meniu,string nume_produs,int stoc_produse,float pret_produse):Bar(nume_produs,stoc_produse,pret_produse){this->combo_meniu=combo_meniu;}
//Getter
        bool getCombo_meniu(){return this->combo_meniu=combo_meniu;};


        virtual ~BarMancare(){}

};

class Bautura:public IOinterface {
private:
    string nume;
public:
    Bautura(string nume) {
        this->nume = nume;
    }
    string getNume() {
        return nume;
    }


    istream& citire(istream& in)
    {

        cout<<"Introduceti numele bauturii:";
        in>>nume;
        return in;
    }
    ostream& afisare(ostream& out) const
    {
        cout<<"Bautura:";
        out<<nume;
        return out;
    }




};

                                                    /**CLASA FILM**/

class Film{
    protected:
//ATRIBUTE CLASA FILME
        string nume_film;
        string gen_film;
        int durata_film;//ar merge float 2.30 ore
        int rating_film;
        string program_vizionare;//ex 22:00-23:00
        Client* client;

    public:

/**CONSTRUCTORI*/
        Film();
        Film(string nume_film,string gen_film,int durata_film,int rating_film, string program_vizionare);//constructor cu 5 argumente
        Film(string nume_film, string program_vizionare,int durata_film);
        Film(string nume_film,string gen_film);

        Film(string gen_film,Client* client);

        Film(string nume_film);
        Film(const Film &ob);/**constructor copiere*/

/**SETTERS*///(modificare valori)

        void setNume_film(string nume_film);
        void setGen_film(string gen_film);
        void setDurata_film(int durata_film);
        void setRating_film(int rating_film);
        void setProgram_vizionare(string program_vizionare);

        void setClient(Client* client);

/**GETTERS*///(accesare )

        const string getNume_film()const; //this->membru clasa
        const string getGen_film()const;
        int   getDurata_film();
        int   getRating_film();
        const string getProgram_vizionare()const;

        Client& getClient();

/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Film &ob);
        friend ostream& operator <<(ostream& out, const Film &ob);
        Film& operator = (const Film &ob);

//Destructor pt cele alocate dinamice
         ~Film(){}

//Metode
  bool poateFiVizionat(const Client& client,string gen_film) {

     if (gen_film =="horror" && client.getVarsta_client() < 18) {
         return false;
     }
     return true;
}


};

//CONSTRUCTORI

//Constructor fara parametrii:
    Film::Film(){

        this->nume_film ="";
        this->gen_film = "";
        this->durata_film = 0;
        this->rating_film  = 0;
        this->program_vizionare = "";
        Client* client = nullptr;
    }
//Constructor cu 5 parametrii:
    Film::Film(string nume_film,string gen_film,int durata_film,int rating_film, string program_vizionare){

        this->nume_film = nume_film;
        this->gen_film =gen_film;
        this->program_vizionare = program_vizionare;
        this->durata_film = durata_film;
        this->rating_film = rating_film;

    }

//Constructor cu 3 parametrii:
    Film::Film(string nume_film, string program_vizionare,int durata_film){

        this->nume_film = nume_film;
        this->program_vizionare = program_vizionare;
        this->durata_film = durata_film;
    }

//Constructor cu 2 parametrii:
    Film::Film(string nume_film,string gen_film){

        this->nume_film = nume_film;
        this->gen_film =gen_film;
    }

    Film::Film(string gen_film,Client* client){

        this->gen_film =gen_film;
        this->client = client;

    }
//Constructor cu 1 parametru:
    Film::Film(string nume_film){

       this->nume_film = nume_film;

    }
//Constructor copiere:
    Film::Film(const Film &ob){

        this->nume_film = ob.nume_film;
        this->gen_film = ob.gen_film;
        this->program_vizionare = ob.program_vizionare;
        this->durata_film = ob.durata_film;
        this->rating_film = ob.rating_film;
        this->client = ob.client;
}

//SETTERS

    void Film::setNume_film(string nume_film){

        this->nume_film = nume_film;
    };

    void Film::setGen_film(string gen_film){

        this->gen_film = gen_film;
    };

    void Film::setProgram_vizionare( string program_vizionare){

        this->program_vizionare = program_vizionare;
    };

    void Film::setDurata_film(int durata_film){
        this->durata_film = durata_film;
    };

    void Film::setRating_film(int rating_film){
        this->rating_film = rating_film;
    };

     void Film::setClient(Client* client){
        this->client = client;
    }

//GETTERS

    const string Film::getNume_film()const {
        return this->nume_film;
    };

    const string Film::getGen_film()const{
        return this->gen_film;
    };

    const string Film::getProgram_vizionare()const{
        return this->program_vizionare;
    };

    int Film::getDurata_film(){
        return this->durata_film;
    };

    int Film::getRating_film(){
        return this->rating_film;
    };

     Client& Film::getClient(){
        return *client;
    }

/**OPERATORUL << */

    ostream& operator<<(ostream& out,const Film &ob){

        out<<"Nume film:"<<ob.nume_film<<endl;
        out<<"Gen film:"<<ob.gen_film<<endl;
        out<<"Durata film:"<<ob.durata_film<<" ore"<<endl;
        out<<"Rating:"<<ob.rating_film<<endl;
        out<<"Program vizionare:"<<ob.program_vizionare<<endl;
        out<<endl;
        return out;
    }

/**OPERATORUL >> */

    istream& operator>>(istream& in,Film &ob){
        cout<<"Nume film:";
        in>>ob.nume_film;

        cout<<"Gen film:";
        in>>ob.gen_film;

        cout<<"Durata film:";
        in>>ob.durata_film;

        cout<<"Rating:";
        in>>ob.rating_film;

        cout<<"Program vizionare: ";
        in>>ob.program_vizionare;

        return in;

    }



                                                            /**CLASA REZERVARI*/
//STATIC VARIABILA
class Rezervari{
    protected:
        static int nr_locuri_rezervate;
        float pret_bilet;
        vector<int> locuri_rezervate;  // lista cu locurile rezervate



    public:
/**CONSTRUCTOR*/

        Rezervari(vector<int> newVector) {
                locuri_rezervate = newVector;
        }

        Rezervari(float pret_bilet){
            this->pret_bilet = pret_bilet;
            this->locuri_rezervate = vector<int>();
        }

        void setPretBilet(float pret_bilet) {
            this->pret_bilet = pret_bilet;
        }

        //STATIC
        static int getNrlocuri(){
            return nr_locuri_rezervate;
        }


        void adaugaLocRezervat(int loc) {

            locuri_rezervate.push_back(loc);
            nr_locuri_rezervate++;
        }


        void stergeLocRezervat(int loc) {
                for (int i = 0; i < locuri_rezervate.size(); i++) {
                    if (locuri_rezervate[i] == loc) {
                        if (i < locuri_rezervate.size()) {

                            locuri_rezervate.erase(locuri_rezervate.begin() + i);
                        }
                    break;
                }
            }
        }

        //UTILIZARE SORT
        void sortLocuriRezervate() {
            sort(locuri_rezervate.begin(), locuri_rezervate.end());
        }


        void afiseazaInformatiiRezervare() {
            if(locuri_rezervate.size()>0)
            {
                cout<<  "================================================================="<< endl;
                cout<<  "=====================REZERVARE==================================="<< endl;
                cout<<  "================================================================="<< endl;
                cout << "Numar locuri rezervate: " <<locuri_rezervate.size()<< endl;
                cout << "Locuri rezervate: ";
                for (int i = 0; i < this->locuri_rezervate.size(); i++) {
                    cout << this->locuri_rezervate[i] << " ";
                }
                cout << endl;
                cout << "Pret total: " << this->calculeazaPretTotal() << endl;
            }
            else
                cout<<"Nu";
        }

        float calculeazaPretTotal() {
            float pret_total = locuri_rezervate.size() * pret_bilet;
                    return pret_total;
        }


        virtual ~Rezervari()
        {
            locuri_rezervate.clear();
        }


};
int Rezervari::nr_locuri_rezervate = 0;

//MOSTENIRE MULTIPLA(+ierarhie de mosteniri)

class Bilet: public Rezervari{

    private:
        int sala;
        int rand;
        string ora;// ex 22:00
        string data_bilet;

     public:
        Bilet(int s, int r, string o, string data_b, float pret_b): sala(s), rand(r), ora(o), data_bilet(data_b), Rezervari(pret_b){}



        void afiseazaInformatiiBilet() {
            //cout << "Nume film: " << << endl;
            cout << "===========BILET================="<<endl;
            cout << "Sala: " << this->sala << "           Ora: " << this->ora << endl;
            cout << "Rand: " << this->rand << "           Data: " << this->data_bilet << endl;

        }



//Getters
        int getSala(){return sala;};
        int getRand(){return rand;};
        string getOra(){return ora;}
        string getData_bilet() {return data_bilet;};

//Setters
        void setSala(int sala){this->sala=sala;};
        void setRand(int rand){this->rand=rand;};
        void setOra(string ora){this->ora=ora;};
        void setData_bilet(string data_bilet){this->data_bilet=data_bilet;};


        ~Bilet(){}

};


//POLIMORFISM (clasa abstracta + 2 metode virtuale)
class Plata{
    protected:
        float valoare;

    public:
        Plata(float v) : valoare(v){}
        virtual float calculeazaTotal() = 0;
        virtual void afiseazaDetalii() = 0;
        virtual ~Plata(){}
};

class PlataOnline:public Plata{
    protected:
       float taxaDeProcesare;

    public:
        PlataOnline(float valoare,float Tx):Plata(valoare),taxaDeProcesare(Tx){}
        float calculeazaTotal()override{return valoare + taxaDeProcesare;}
        void afiseazaDetalii()override{cout<<"PLATA ONLINE : "<<calculeazaTotal()<<" RON.    Reprezentand valoarea initiala de "<<valoare<<" RON + "<<taxaDeProcesare<<" RON TAXA de Procesare a platii ONLINE"<<endl;}
        ~PlataOnline(){}
};

class PlataFizica: public Plata{
    protected:
        float comision;
    public:
        PlataFizica(float valoare,float comision):Plata(valoare),comision(comision){}
        float calculeazaTotal()override{return valoare*( comision / 100 );}
        void afiseazaDetalii()override{cout<<"PLATA FIZICA : "<<calculeazaTotal()<<" RON.        Reprezentand valoarea initiala de "<<valoare<<" RON cu un  comision "<<comision<<"% "<<endl;}
        ~PlataFizica(){}
};


//SABLON
template <typename T>
class Gestiune {
private:
    vector<T> listaObiecte;

public:
    //constructor
    Gestiune() {}

    //adauga un obiect in lista
    void adaugaObiect(const T& obiect) {
        listaObiecte.push_back(obiect);
    }

    //returneaza numarul de obiecte din lista
    int numarObiecte() const {
        return listaObiecte.size();
    }

    //returneaza obiectul de la indexul specificat
    T& getObiect(int index) {
        return listaObiecte[index];
    }

    // Destructor
    ~Gestiune() {}
};



//DESIGN PATTERNS

class AngajatiDatabase {// Singleton
private:
    static AngajatiDatabase* instance;
    vector<string> lista_angajati;
    AngajatiDatabase();

public:
    static AngajatiDatabase* getInstance();
    void addAngajat(const string& Angajat);
    void deleteAngajat(const string& Angajat);
    void displayAngajati();
};

    AngajatiDatabase* AngajatiDatabase::instance = nullptr;

    AngajatiDatabase::AngajatiDatabase() {}

    AngajatiDatabase* AngajatiDatabase::getInstance(){

        if (instance == nullptr) {
            instance = new AngajatiDatabase();
        }
        return instance;
    }


    void AngajatiDatabase::addAngajat(const string& Angajat) {

        cout << "Angajat adaugat in baza de date: " << Angajat << endl;
        lista_angajati.push_back(Angajat);
        cout << " " << endl;
    }

    void AngajatiDatabase::deleteAngajat(const string& Angajat) {

        cout << "Angajat sters din baza de date: " << Angajat << endl;
        for (auto i = lista_angajati.begin(); i != lista_angajati.end(); ++i) {
            if (*i == Angajat) {
                lista_angajati.erase(i);
                break;
            }
             cout << " " << endl;
        }
    }

        void AngajatiDatabase::displayAngajati() {
            cout << "Lista cu angajatii promovati:" << endl;
            cout << " " << endl;
            for (const auto& employee : lista_angajati) {
                cout << employee <<endl;
            }
            cout << " " << endl;
        }


/**PENTRU MENIU*/
//system(cls) este utilizată pentru a curăța ecranul consolei (eliminarea textului și a altor informații afișate pe ecran

void meniu(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU PRINCIPAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"  Bine ati venit in meniul principal ! "<<endl;
    cout<<"  Va multumim pentru ca ati ales sa ne utilizati serviciile."<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"- Alegeti tipul de utilizator:-"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1. Client\n2. Angajat\n3. Admin\n0. Exit\n\n";
    cout<<"Introduceti numarul dorit:";


}


void meniuClient(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU CLIENT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 1.Crearea unui profil de utilizator."<<endl;
    cout<<" 2.Lista Cinema-uri"<<endl;
    cout<<" 3.Info Filme"<<endl;
    cout<<" 4.Adugare rezervare"<<endl;
    cout<<" 5.Stergere rezervare"<<endl;
    cout<<" 6.Detalii despre bilet"<<endl;
    cout<<" 7.Bar Cinema "<<endl;
    cout<<" 0.Exit."<<endl;
    cout<<" "<<endl;
    cout<<"Introduceti numarul dorit: ";
}


void meniuAngajati(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU ANGAJATI~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 1.Lista Angajati"<<endl;
    cout<<" 2.Calculator de salariu in functie de lunile lucrate  si pozitia ocupata"<<endl;
    cout<<" 0.Exit."<<endl;
    cout<<" "<<endl;
    cout<<"Introduceti numarul dorit:";

}

void meniuBar(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU BAR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"INAINTE DE A INTRA LA FILMUL PE CARE ABIA ASTEPTI SA IL VEZI, "<<endl;
    cout<<"TE INVITAM LA BARUL CINEMATOGRAFULUI NOSTRU PENTRU A-TI CUMPARA MENIUL PREFERAT SI PERFECT PENTRU VIZIONARE!"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void meniuFilme(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~FILME~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 0.El Camino"<<endl;
    cout<<" 1.Jurassic Park(1993)"<<endl;
    cout<<" 2.About Time"<<endl;
    cout<<" 3.Fight Club"<<endl;
    cout<<" "<<endl;
}

int main()
{

//Filme //nume_film; gen_film;durata_film;rating_film; program_vizionare;

Film F1("El Camino","thriller",2,9,"11:00-13:00");
Film F2("Jurassic Park(1993)","aventura",2,8,"15:00-17:00");
Film F3("About Time","dragoste",2,7,"18:00-20:00");
Film F4("Fight Club","thriller",2,8,"13:00-15:00");

int contorFilme = 4;

vector<Film> listaFilme = {F1,F2,F3,F4};

//Angajat  nume_angajat  prenume_angajat pozitie_ocupata luni_lucrate salariu CNP

Angajat A1("Popescu","Ion","Tehnician de echipamente",10,20000);
Angajat A2("Grigorescu","Liviu","Manager de cinema",3,9000);
Angajat A3("Ilie","Alexandru Marian","Proiectionist",7,12600);
Angajat A4("Vasile","Dorin","Personal de curatenie",10,12000);

int contorAngajati=4;
vector<Angajat> listaAngajati = {A1,A2,A3,A4};


//Cinema nume_cinema site_web; nr_telefon
Cinema C1("Cinema City","www.cinemacity.com","0723454312");
Cinema C2("Happy Cinema","www.Happycinema.com","0722335689");
Cinema C3("Cinema Union","www.cinemaUnionn.com","0744337689");
Cinema C4("Cinema Magia","www.cinemamaggiaa.com","0766598712");

int contorCinema = 4;
vector<Cinema> listaCinema = {C1,C2,C3,C4};


vector<int> locuri_rezervate ;
int optiune;


//MENIU
bool verif = false;
while(verif == false){

meniu();
cin>>optiune;
switch(optiune){
        case 1://Client
        {   int alegere;
            do{
                meniuClient();
                cin>>alegere;

                    switch(alegere)
                    {
                        case 1://1.Crearea unui profil de utilizator.
                            {
                                system("cls");
                                Client adaugare;
                                cin>>adaugare;
                                system("cls");
                                cout<<" "<<endl;
                                cout<<"Profilul dumneavoastra:"<<endl;
                                cout<<" "<<endl;
                                cout<<adaugare;
                                cout<<endl;
                                system("pause");
                                break;

                            }
                        case 2://2.Lista Cinema-uri
                            {
                                system("cls");
                                cout<<" "<<endl;
                                cout<<"Aceasta este lista de cinema-uri din orasul tau:"<<endl;
                                cout<<" "<<endl;
                                for( int i = 0;i<listaCinema.size();i++)
                                    cout<<listaCinema[i]<<endl;
                                    cout<<" "<<endl;

                                system("pause");
                                break;

                            }
                        case 3://3.Info Filme
                            {
                                system("cls");
                                meniuFilme();
                                Gestiune<Film> gestiuneFilme;
                                gestiuneFilme.adaugaObiect(F1);
                                gestiuneFilme.adaugaObiect(F2);
                                gestiuneFilme.adaugaObiect(F3);
                                gestiuneFilme.adaugaObiect(F4);
                                // Afișare număr de filme din gestiune
                                cout << "Numarul de filme din gestiune: " << gestiuneFilme.numarObiecte() << endl;
                                cout <<""<<endl;

                                // Accesare și afișare informații despre un film din gestiune
                                int k;//alegere film
                                cout<<"Ce film doriti sa accesati? :";
                                cin>>k;
                                Film& filmAccesat = gestiuneFilme.getObiect(k);
                                cout <<""<<endl;

                                cout << "Informatii despre filmul accesat:" << endl;
                                cout <<""<<endl;
                                cout << filmAccesat << endl;

                                system("pause");


                                break;

                            }
                        case 4://4.Adugare rezervare
                            {
                                Rezervari r(20);
                                //SMART POINTER
                                unique_ptr<Rezervari> rezervariPtr(new Rezervari(r));
                                int rezervare;
                                char continua_adaugare;
                                cout << "Introduceti locurile de rezervat (introduceti 'q' pentru a opri): ";

                               do{
                                cin>>rezervare;

                                rezervariPtr->adaugaLocRezervat(rezervare);
                                cout << "Loc adaugat cu succes! Continuati adaugarea? (y/n): ";
                                cin >> continua_adaugare;
                               }while (continua_adaugare == 'y');

                            system("cls");
                            rezervariPtr->sortLocuriRezervate();
                            rezervariPtr->afiseazaInformatiiRezervare();


                            system("pause");
                            break;
                            }
                        case 5://5.Stergere rezervare
                            {
                              cout<<"Ne pare rau este in curs de dezvoltare";
                              system("pause");
                              break;

                            }
                        case 6://6.Detalii despre bilet
                            {
                                    int sala;
                                    cout<<"Introdueti sala:";
                                    cin>>sala;

                                    int rand;
                                    cout<<"Introduceti randul:";
                                    cin>>rand;

                                    string cinema;
                                    cout<<"Introduceri cinema-ul dorit:";
                                    cin>>cinema;

                                    string ora;
                                    cout<<"Introduceti ora dorita :";
                                    cin>>ora;

                                    string data;
                                    cout<<"Introduceti data : ";
                                    cin>>data;

                                    string numefilm;
                                    cout<<"Introduceti numele filmului : ";
                                    cin>>numefilm;

                                    string plata;
                                    cout<<"Introduceti cum doriti sa achitati(online sau fizic) : ";
                                    cin>>plata;

                                    if(plata == "online"){

                                        int nr;
                                        cout<<"Cate locuri ati rezervat ? : ";
                                        cin>>nr;
                                        float pret = nr*20;
                                        PlataOnline P1(pret,5.50);
                                        P1.calculeazaTotal();

                                        system("cls");
                                        cout << "===========BILET================="<<endl;
                                        cout << "Sala: " << sala << "           Ora: " << ora << endl;
                                        cout << "Rand: " << rand << "           Data: " << data << endl;
                                        cout << "Film: " << numefilm<< "         Cinema: " << cinema << endl;
                                        cout<<"  "<<endl;
                                        P1.afiseazaDetalii();
                                        cout<<"  "<<endl;
                                        system("pause");
                                        break;

                                    }else if(plata == "fizic"){
                                        int nr1;
                                        cout<<"Cate locuri ati rezervat ? : ";
                                        cin>>nr1;
                                        float pret1 = nr1*20;
                                        PlataFizica P2(pret1,30.50);
                                        P2.calculeazaTotal();

                                        system("cls");
                                        cout << "===========BILET================="<<endl;
                                        cout << "Sala: " << sala << "           Ora: " << ora << endl;
                                        cout << "Rand: " << rand << "           Data: " << data << endl;
                                        cout << "Film: " << numefilm<< "         Cinema: " << cinema << endl;
                                        cout<<"  "<<endl;
                                        P2.afiseazaDetalii();
                                        cout<<"  "<<endl;
                                        system("pause");
                                        break;

                                    }else{
                                        cout<<"Invalid! Introducere incorecta";
                                        system("pause");
                                        break;
                                        }




                                system("pause");
                                break;
                            }
                        case 7://7.Bar Cinema
                            {
                                system("cls");
                                meniuBar();
                                int alegere2;
                                cout<<"Ce doriti sa consumati(1.Mancare 2.Bautura):";
                                cin>>alegere2;


                                switch(alegere2){

                                    case 1:{

                                        string produs;
                                        cout<<"Ce produs doriti? : ";
                                        cin>>produs;

                                        if(produs.compare("nachos") == 0){

                                                int numar_produse;
                                                cout<<"Cate produse?";
                                                cin>>numar_produse;

                                                int alegere2;
                                                cout<<"Doriti combo?(1.Da 0.Nu) : ";
                                                cin>>alegere2;

                                                    if (alegere2 == 1){
                                                        system("cls");
                                                        cout<<" Comanda este gata !"<<endl;
                                                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                                        cout<<" Nachos Combo  "<<numar_produse<<" BUC X 23.59"<<endl;
                                                        cout<<" Pret: "<<numar_produse * 23.59 <<" RON"<<endl;

                                                        system("pause");
                                                    }else if(alegere2 == 0){
                                                        system("cls");
                                                        cout<<" Comanda este gata !"<<endl;
                                                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                                        cout<<" Nachos "<<numar_produse<<" BUC X 13.59"<<endl;
                                                        cout<<" Pret: "<<numar_produse * 13.59 <<" RON"<<endl;
                                                        system("pause");
                                                        break;
                                                    }else{
                                                        cout<<"Alegere invalida!"<<endl;
                                                        system("pause");
                                                        break;

                                                    }



                                        }else if(produs.compare("popcorn") == 0){

                                                int numar_produse;
                                                cout<<"Cate produse?";
                                                cin>>numar_produse;


                                                int alegere3;
                                                cout<<"Doriti combo?(1.Da 0.Nu) : ";
                                                cin>>alegere3;

                                                if (alegere3 == 1){
                                                        system("cls");
                                                        cout<<" Comanda este gata !"<<endl;
                                                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                                        cout<<" Popcorn Combo  "<<numar_produse<<" BUC X 23.59"<<endl;
                                                        cout<<" Pret: "<<numar_produse * 23.59 <<" RON"<<endl;

                                                        system("pause");
                                                        break;
                                                    }else if(alegere3 == 0){
                                                        system("cls");
                                                        cout<<" Comanda este gata !"<<endl;
                                                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                                        cout<<" Popcorn "<<numar_produse<<" BUC X 13.59"<<endl;
                                                        cout<<" Pret: "<<numar_produse * 13.59 <<" RON"<<endl;
                                                        system("pause");
                                                        break;
                                                    }else{
                                                        cout<<"Alegere invalida!"<<endl;
                                                        system("pause");
                                                        break;

                                                    }

                                        }else{
                                            cout<<"Nu avem acest produs!"<<endl;
                                            system("pause");
                                            break;
                                        }

                                        verif = true;
                                        break;
                                    }

                                    case 2:{//BAUTURA


                                    vector<Bautura> bauturi = {
                                        Bautura("apa"),
                                        Bautura("cocacola"),
                                        Bautura("fanta"),
                                        Bautura("pepsi")
                                    };

                                    string bauturaCautata;
                                    cout << "Introduceti bautura: ";
                                    cin >> bauturaCautata;

                                    bool gasit = false;
                                    for (int i = 0; i < bauturi.size(); i++) {
                                        if (bauturi[i].getNume() == bauturaCautata) {
                                            gasit = true;
                                            break;
                                        }
                                    }

                                    if (gasit) {
                                        int numar_produse;
                                        cout<<"Cate produse?";
                                        cin>>numar_produse;

                                                int alegere2;
                                                cout<<"Doriti gheata?(1.Da 0.Nu) : ";
                                                cin>>alegere2;

                                                    if (alegere2 == 1){
                                                        system("cls");
                                                        cout<<" Comanda este gata !"<<endl;
                                                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                                        cout<<bauturaCautata<<" cu gehata  "<<numar_produse<<" BUC X 23.59"<<endl;
                                                        cout<<" Pret: "<<numar_produse * 23.59 <<" RON"<<endl;

                                                        system("pause");
                                                        break;
                                                    }else if(alegere2 == 0){
                                                        system("cls");
                                                        cout<<" Comanda este gata !"<<endl;
                                                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                                        cout<<bauturaCautata<<" fara gheata "<<numar_produse<<" BUC X 13.59"<<endl;
                                                        cout<<" Pret: "<<numar_produse * 13.59 <<" RON"<<endl;
                                                        system("pause");
                                                        break;
                                                    }else{
                                                        cout<<"Alegere invalida!"<<endl;
                                                        system("pause");
                                                        break;

                                                    }

                                    } else {
                                        cout << "Bautura cautata nu exista in lista." << endl;
                                        system("pause");
                                        break;
                                    }

                                        break;
                                    }

                                    default:
                                        {
                                            cout<<"Alegere invalida!"<<endl;
                                            break;
                                        }

                                }

                                break;
                            }
                        case 0:
                            {
                                optiune = 0;
                                system("pause");
                                break;
                            }

                    }
                }while(alegere);
                break;

            }
            case 2:{//Angajat

                int alegere4;
                bool verif2 = false;
                while(verif2 == false){
                        meniuAngajati();
                        cin>>alegere4;
                        switch(alegere4){

                                case 1:
                                {
                                    cout<<" ";
                                   for(int i= 0;i<contorAngajati;i++)
                                        cout<<listaAngajati[i]<<endl;
                                    cout<<" "<<endl;
                                        system("pause");
                                        verif2 = true;
                                        break;

                                }

                                case 2:
                                {
                                        char nume[100];
                                        cout << "Introduceti numele angajatului: ";
                                        cin >> nume;

                                        char prenume[100];
                                        cout << "Introduceti prenumele angajatului: ";
                                        cin >> prenume;

                                        char pozitie[100];
                                        cout << "Introduceti pozitia ocupata angajatului: ";
                                        cin >> pozitie;

                                        int luniLucrate;
                                        cout << "Introduceti cate luni a lucrat angajatul: ";
                                        cin >> luniLucrate;

                                        Angajat angajat(nume,prenume,pozitie, luniLucrate);
                                        float salariu = angajat.CalculeazaSalariu(luniLucrate,pozitie);
                                        cout << "Salariul angajatului "<<angajat.getNume_angajat()<<" "<<angajat.getPrenume_angajat()<<" "<<"este de :" << salariu <<" lei"<<endl;


                                       system("pause");
                                       verif2 = true;
                                       break;
                                }

                                case 0:
                                {
                                    verif2 = true;
                                    system("pause");
                                    break;
                                }

                                default:
                                    {
                                        cout<<"Invalid!"<<endl;
                                        system("pause");
                                    }
                        }



                }
                 break;

            }
            case 3:{//Admin
                    system("cls");
                     AngajatiDatabase* database = AngajatiDatabase::getInstance();

                    int choice;
                    string angajat;
                    do {
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU ANGAJATI PROMOVATI~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout << "1. Adauga angajat" << endl;
                            cout << "2. Sterge angajat" << endl;
                            cout << "3. Afiseaza lista de angajati promovati" << endl;
                            cout << "0. EXIT" << endl;
                            cout << "Introduceti optiunea: ";
                            cin >> choice;
                               system("cls");
                            switch (choice) {
                                case 1:
                                    cout << "Introduceti numele angajatului: ";
                                    cin >> angajat;
                                    database->addAngajat(angajat);
                                    break;
                                case 2:
                                    cout << "Introduceti numele angajatului de sters: ";
                                    cin >> angajat;
                                    database->deleteAngajat(angajat);
                                    break;
                                case 3:
                                    database->displayAngajati();
                                    break;
                                case 0:

                                    cout << "La revedere!" << endl;
                                    break;
                                default:
                                    cout << "Optiune invalida!" << endl;
                                    break;
                            }
                                cout << endl;

                        } while (choice != 0);

                    system("pause");
                    break;
            }
            case 0:{
                system("pause");
                verif = true;
                break;
                }

 }

}

    return 0;
}

