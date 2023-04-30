#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include<stdexcept>


using namespace std;

//CLASE: FILM,BILET,CLIENT,CINEMA,ANGAJAT,BAR,REZERVARI


//INTERFATA
class IOinterface
{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};


                                                /**CLASA CLIENT*/
class Client{
    private:
        char* nume_client;
        char* prenume_client;
        char* email_client;
        char* metoda_plata;//cash sau card
        int varsta_client;//pt reducere sub 18 ani

    public:
//Constructorul este folosit pentru a inițializa obiecte din clasa Filme atunci când acestea sunt create.
//Astfel, atunci când se creează un nou obiect Client, se va apela acest constructor și variabilele membre
//ale obiectului vor fi initializate cu valorile primite ca argumente.
/**CONSTRUCTORI*/
        Client();
        Client(char* nume_client,char* prenume_client,char* email_client,char* metoda_plata,int varsta_client);
        Client(char* nume_client,char* prenume_client,char* metoda_plata);
        Client(char* nume_client,char* prenume_client,int varsta_client);
        Client(char* nume_client,char* prenume_client);
        Client(const Client &ob);//constructor copiere
//constructorul de copiere
//se pune const pentru a proteja datele din obiectul de copiat
//se pune & pentru a putea accesa direct adresa obiectului de copiat
//astfel incat sa nu folosim memorie suplimentara daca cream alt obiect

//Fiecare constructor are un set diferit de argumente și poate fi utilizat pentru a crea un obiect

/**THIS*/// folosirea operatorului THIS ajuta la evitarea ambiguitatilor si la mentinerea unei structuri coerente si clare a codului


/**SETTERS*/
        void setNume_client(char* nume_client);
        void setPrenume_client(char* prenume_client);
        void setEmail_client(char* email_client);
        void setMetoda_plata(char* metoda_plata);
        void setVarsta_client(int varsta_client);

/**GETTERS*/

        const char* getNume_client()const;
        const char* getPrenume_client()const;
        const char* getEmail_client()const;
        const char* getMetoda_plata()const;
        int getVarsta_client()const;

/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Client &ob);
        friend ostream& operator <<(ostream& out, const Client &ob);

//Destructor pt cele alocate dinamice
        ~Client(){
            if(this->nume_client!= nullptr){
                 delete[]  this->nume_client;
                 this->nume_client=nullptr;
            }

             if(this->prenume_client!= nullptr){
                 delete[]  this->prenume_client;
                 this->prenume_client=nullptr;
            }
             if(this->email_client!= nullptr){
                 delete[]  this->email_client;
                 this->email_client=nullptr;
            }
            if(this->metoda_plata!= nullptr){
                 delete[]  this->metoda_plata;
                 this->metoda_plata=nullptr;
            }
        }
//METODE

};
/**CONSTRUCTORI*/

//Constructor fara parametrii:
    Client::Client(){

        this->nume_client =nullptr;
        this->prenume_client = nullptr;
        this->email_client = nullptr;
        this->metoda_plata = nullptr;
        this->varsta_client= 0;

    }

//Constructor cu 5 parametrii:
    Client::Client(char* nume_client,char* prenume_client,char* email_client,char* metoda_plata,int varsta_client){

        this->nume_client = new char[strlen(nume_client)+1];
        strcpy(this->nume_client,nume_client);

        this->prenume_client =new char[strlen(prenume_client)+1];
        strcpy(this->prenume_client,prenume_client);


        this->email_client = new char[strlen(email_client)+1];
        strcpy(this->email_client,email_client);


        this->metoda_plata = new char[strlen(metoda_plata)+1];
        strcpy(this->metoda_plata,metoda_plata);

        this->varsta_client = varsta_client;

    }
//Constructor 3 parametrii

    Client::Client(char* nume_client,char* prenume_client,char* metoda_plata){

        this->nume_client = new char[strlen(nume_client)+1];
        strcpy(this->nume_client,nume_client);

        this->prenume_client =new char[strlen(prenume_client)+1];
        strcpy(this->prenume_client,prenume_client);

        this->metoda_plata = new char[strlen(metoda_plata)+1];
        strcpy(this->metoda_plata,metoda_plata);

        this->varsta_client= 0;
        this->email_client = nullptr;

    }

    Client::Client(char* nume_client,char* prenume_client,int varsta_client){

        this->nume_client = new char[strlen(nume_client)+1];
        strcpy(this->nume_client,nume_client);

        this->prenume_client =new char[strlen(prenume_client)+1];
        strcpy(this->prenume_client,prenume_client);

        this->varsta_client = varsta_client;

        this->email_client = nullptr;
        this->metoda_plata = nullptr;

    }

//Constructor 2 parametrii

    Client::Client(char* nume_client,char* prenume_client){

        this->nume_client = new char[strlen(nume_client)+1];
        strcpy(this->nume_client,nume_client);

        this->prenume_client =new char[strlen(prenume_client)+1];
        strcpy(this->prenume_client,prenume_client);

        this->email_client = nullptr;
        this->metoda_plata = nullptr;
        this->varsta_client= 0;
    }

/**constructor copiere*/
    Client::Client(const Client &ob){

        this->nume_client = new char[strlen(ob.nume_client)+1];
        strcpy(this->nume_client,ob.nume_client);

        this->prenume_client = new char[strlen(ob.prenume_client)+1];
        strcpy(this->prenume_client,ob.prenume_client);

        this->email_client = new char[strlen(ob.email_client )+1];
        strcpy(this->email_client ,ob.email_client );

        this->metoda_plata = new char[strlen(ob.metoda_plata )+1];
        strcpy(this->metoda_plata ,ob.metoda_plata );

        this->varsta_client= ob.varsta_client;
    }

//SETTERS

    void Client::setNume_client(char* nume_client){

        if(this->nume_client != nullptr)
            delete[] this->nume_client;

        this->nume_client = new char[strlen(nume_client)+1];
        strcpy(this->nume_client, nume_client);
    };

    void Client::setPrenume_client(char* prenume_client){

        if(this->prenume_client != nullptr)
            delete[] this->prenume_client;

        this->prenume_client = new char[strlen(prenume_client)+1];
        strcpy(this->prenume_client, prenume_client);
    };

    void Client::setEmail_client(char* email_client){

        if(this->email_client != nullptr)
            delete[] this->email_client;

        this->email_client = new char[strlen(email_client)+1];
        strcpy(this->email_client, email_client);

    };

    void Client::setMetoda_plata(char* metoda_plata){

        if(this->metoda_plata != nullptr)
            delete[] this->metoda_plata;

        this->metoda_plata = new char[strlen(metoda_plata)+1];
        strcpy(this->metoda_plata, metoda_plata);

    };

    void Client::setVarsta_client(int varsta_client){
        this->varsta_client = varsta_client;
    };


//GETTERS


    const char* Client::getNume_client()const {
        return this->nume_client;
    };

    const char* Client::getPrenume_client()const {
        return this->prenume_client;
    };

    const char* Client::getEmail_client()const {
        return this->email_client;
    };

    const char* Client::getMetoda_plata()const {
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
        char aux[50];
        in>>aux;
        if(ob.nume_client!=nullptr){
            delete[] ob.nume_client;
            ob.nume_client = nullptr;
        }
        ob.nume_client = new char[strlen(aux)+1];
        strcpy(ob.nume_client,aux);

        cout<<"Prenume:";
        in>>aux;
        if(ob.prenume_client!=nullptr){
            delete[] ob.prenume_client;
            ob.prenume_client = nullptr;
        }
        ob.prenume_client = new char[strlen(aux)+1];
        strcpy(ob.prenume_client,aux);

         cout<<"Email:";
        in>>aux;
        if(ob.email_client!=nullptr){
            delete[] ob.email_client;
            ob.email_client = nullptr;
        }
        ob.email_client = new char[strlen(aux)+1];
        strcpy(ob.email_client,aux);

        cout<<"Metoda plata (card/cash):";
        in>>aux;
        if(ob.metoda_plata!=nullptr){
            delete[] ob.metoda_plata;
            ob.metoda_plata = nullptr;
        }
        ob.metoda_plata = new char[strlen(aux)+1];
        strcpy(ob.metoda_plata,aux);

        cout<<"Varsta:";
        in>>ob.varsta_client;

        return in;

    }



                                                      /**CLASA ANGAJAT*/
class Angajat{
    private:
        char* nume_angajat;
        char* prenume_angajat;
        char* pozitie_ocupata;//Casier,Personal de curățenie,Proiecționist,Manager de cinema,Recepționer,Agent de marketing,Tehnician de echipamente
        int luni_lucrate;
        float salariu;
        long long CNP;
//6 atribute
    public:

/**CONSTRUCTORI*/
        Angajat();
        Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate,float salariu);
        Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate);
        Angajat(char* nume_angajat,char* prenume_angajat,float salariu);
        Angajat(char* nume_angajat,char* prenume_angajat);
        Angajat(const Angajat &ob);//constructor copiere


/**SETTERS*/
        void setNume_angajat(char* nume_angajat);
        void setPrenume_angajat(char* prenume_angajat);
        void setPozitie_ocupata(char* pozitie_ocupata);
        void setLuni_lucrate(int luni_lucrate);
        void setSalariu(float salariu);



/**GETTERS*/

        const char* getNume_angajat()const;
        const char* getPrenume_angajat()const;
        const char* getPozitie_ocupata()const;
        int getLuni_lucrate();
        float getSalariu();



/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Angajat &ob);
        friend ostream& operator <<(ostream& out, const Angajat &ob);


/**DESTRUCTOR*/ // pt cele alocate dinamice
        ~Angajat(){
            if(this->nume_angajat!= nullptr){
                 delete[]  this->nume_angajat;
                 this->nume_angajat=nullptr;
            }

             if(this->prenume_angajat!= nullptr){
                 delete[]  this->prenume_angajat;
                 this->prenume_angajat=nullptr;
            }
             if(this->pozitie_ocupata!= nullptr){
                 delete[]  this->pozitie_ocupata;
                 this->pozitie_ocupata=nullptr;
            }

        }


/**METODE*/
//METODA CALCUL SALARIU IN FUNCTIE DE LUNILE LUCRATE SI POZITIA OCUPATA

   float CalculeazaSalariu(int luni_lucrate,char* pozitie_ocupata)
    {
        float salariu = 0;

        if(strcasecmp(pozitie_ocupata, "Casier") == 0){
        salariu = luni_lucrate * 1500;

    } else if(strcasecmp(pozitie_ocupata, "Personal de curatenie") == 0) {
        salariu = luni_lucrate * 1200;

    } else if(strcasecmp(pozitie_ocupata, "Proiectionist") == 0) {
        salariu = luni_lucrate * 1800;

    } else if(strcasecmp(pozitie_ocupata, "Manager de cinema") == 0) {
        salariu = luni_lucrate * 3000;

    } else if(strcasecmp(pozitie_ocupata, "Receptioner") == 0) {
        salariu = luni_lucrate * 2000;

    } else if(strcasecmp(pozitie_ocupata, "Agent de marketing") == 0) {
        salariu = luni_lucrate * 2500;

    } else if(strcasecmp(pozitie_ocupata, "Tehnician de echipamente") == 0) {
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

        this->nume_angajat =nullptr;
        this->prenume_angajat = nullptr;
        this->pozitie_ocupata = nullptr;
        this->luni_lucrate = 0;
        this->salariu= 0;


    }

//Constructor cu 6 parametrii

    Angajat::Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate,float salariu){

        this->nume_angajat= new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat,nume_angajat);

        this->prenume_angajat= new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat,prenume_angajat);

        this->pozitie_ocupata= new char[strlen(pozitie_ocupata)+1];
        strcpy(this->pozitie_ocupata,pozitie_ocupata);

        this->luni_lucrate = luni_lucrate;
        this->salariu = salariu;


    }

//constructor cu 4 parametrii

    Angajat::Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate){

        this->nume_angajat= new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat,nume_angajat);

        this->prenume_angajat= new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat,prenume_angajat);

        this->pozitie_ocupata= new char[strlen(pozitie_ocupata)+1];
        strcpy(this->pozitie_ocupata,pozitie_ocupata);

        this->luni_lucrate = luni_lucrate;


        this->salariu= 0;
    }
//Constructor cu 3 parametrii
    Angajat::Angajat(char* nume_angajat,char* prenume_angajat,float salariu){

        this->nume_angajat= new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat,nume_angajat);

        this->prenume_angajat= new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat,prenume_angajat);

        this->salariu = salariu;

        this->luni_lucrate = 0;

    }


//Constructor cu 2 parametrii

    Angajat::Angajat(char* nume_angajat,char* prenume_angajat){

        this->nume_angajat= new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat,nume_angajat);

        this->prenume_angajat= new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat,prenume_angajat);

        this->pozitie_ocupata = nullptr;
        this->luni_lucrate = 0;
        this->salariu= 0;


    }

/**constructor copiere*/

    Angajat::Angajat(const Angajat &ob){


        this->nume_angajat = new char[strlen(ob.nume_angajat)+1];
        strcpy(this->nume_angajat,ob.nume_angajat);

        this->prenume_angajat = new char[strlen(ob.prenume_angajat)+1];
        strcpy(this->prenume_angajat,ob.prenume_angajat);

        this->pozitie_ocupata = new char[strlen(ob.pozitie_ocupata )+1];
        strcpy(this->pozitie_ocupata ,ob.pozitie_ocupata );

        this->luni_lucrate = ob.luni_lucrate;

        this->salariu = ob.salariu;


    }

//SETTERS

     void Angajat::setNume_angajat(char* nume_angajat){

        if(this->nume_angajat != nullptr)
            delete[] this->nume_angajat;

        this->nume_angajat = new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat, nume_angajat);
    };

     void Angajat::setPrenume_angajat(char* prenume_angajat){

        if(this->prenume_angajat != nullptr)
            delete[] this->prenume_angajat;

        this->prenume_angajat = new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat, prenume_angajat);
    };

     void Angajat::setPozitie_ocupata(char* pozitie_ocupata){

        if(this->pozitie_ocupata != nullptr)
            delete[] this->pozitie_ocupata;

        this->pozitie_ocupata = new char[strlen(pozitie_ocupata)+1];
        strcpy(this->pozitie_ocupata, pozitie_ocupata);
    };

    void Angajat::setLuni_lucrate(int luni_lucrate){
        this->luni_lucrate = luni_lucrate;
    };

    void Angajat::setSalariu(float salariu){
        this->salariu = salariu;
    };



//GETTERS


    const char* Angajat::getNume_angajat()const {
        return this->nume_angajat;
    };

    const char* Angajat::getPrenume_angajat()const {
        return this->prenume_angajat;
    };

    const char* Angajat::getPozitie_ocupata()const {
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
        out<<" "<<endl;
        out<<"Afisare informatii angajat:"<<endl;
        out<<" "<<endl;
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
        char* nume_cinema;
        char* site_web;
        char* nr_telefon;
        //Sediu_cinema sediu

   public:

/**CONSTRUCTORI*/

    Cinema();//constructor fara parametrii
    Cinema(char* nume_cinema,char* site_web,char* nr_telefon);
    Cinema(char* nume_cinema,char* site_web);
    Cinema(char* nume_cinema);
    Cinema(const Cinema &ob);//constructor copiere

/**SETTERS*/

    void setNume_cinema(char* nume_cinema);
    void setSite_web(char* site_web);
    void setNr_telefon(char* nr_telefon);


/**GETTERS*/

    const char* getNume_cinema()const;
    const char* getSite_web()const;
    const char* getNr_telefon()const;
    //Film* getFilme();

/**SUPRAINCARCARE OPERATORI*/

    friend istream& operator >>(istream& in, Cinema &ob);
    friend ostream& operator <<(ostream& out, const Cinema &ob);

//Destructor pt cele alocate dinamice
        ~Cinema(){
            if(this->nume_cinema!= nullptr){
                 delete[]  this->nume_cinema;
                 this->nume_cinema=nullptr;
            }

            if(this->site_web!= nullptr){
                 delete[]  this->site_web;
                 this->site_web=nullptr;
            }

            if(this->nr_telefon!= nullptr){
                 delete[]  this->nr_telefon;
                 this->nr_telefon=nullptr;
            }

        }
};

//CONSTRUCTORI

//Constructor fara parametrii:
    Cinema::Cinema(){
        this->nume_cinema = nullptr;
        this->nr_telefon = nullptr;
        this->site_web = nullptr;

    }

//Constructor cu 3 parametrii:
    Cinema::Cinema(char* nume_cinema,char* site_web,char* nr_telefon){

        this->nume_cinema = new char[strlen(nume_cinema)+1];
        strcpy(this->nume_cinema,nume_cinema);

         this->site_web = new char[strlen(site_web)+1];
        strcpy(this->site_web,site_web);

         this->nr_telefon = new char[strlen(nr_telefon)+1];
        strcpy(this->nr_telefon,nr_telefon);
    }

//Constructor cu 2 parametrii:
    Cinema::Cinema(char* nume_cinema,char* site_web){

        this->nume_cinema = new char[strlen(nume_cinema)+1];
        strcpy(this->nume_cinema,nume_cinema);

         this->site_web = new char[strlen(site_web)+1];
        strcpy(this->site_web,site_web);

        site_web = nullptr;
    }

//Constructor cu 1 parametru:
    Cinema::Cinema(char* nume_cinema){

        this->nume_cinema = new char[strlen(nume_cinema)+1];
        strcpy(this->nume_cinema,nume_cinema);

        site_web = nullptr;
        nr_telefon = nullptr;

    }

//Constructor copiere:

     Cinema::Cinema(const Cinema &ob){

         this->nume_cinema = new char[strlen(ob.nume_cinema)+1];
        strcpy(this->nume_cinema,ob.nume_cinema);

        this->site_web = new char[strlen(ob.site_web)+1];
        strcpy(this->site_web,ob.site_web);

        this->nr_telefon = new char[strlen(ob.nr_telefon)+1];
        strcpy(this->nr_telefon,ob.nr_telefon);
     }

//SETTERS

    void Cinema::setNume_cinema(char* nume_cinema){
        if(this->nume_cinema != nullptr)
            delete[] this->nume_cinema;

        this->nume_cinema = new char[strlen(nume_cinema)+1];
        strcpy(this->nume_cinema, nume_cinema);
    };

    void Cinema::setSite_web(char* site_web){
       if(this->site_web != nullptr)
            delete[] this->site_web;

        this->site_web = new char[strlen(site_web)+1];
        strcpy(this->site_web, site_web);

    };

    void Cinema::setNr_telefon(char* nr_telefon){
       if(this->nr_telefon != nullptr)
            delete[] this->nr_telefon;

        this->nr_telefon = new char[strlen(nr_telefon)+1];
        strcpy(this->nr_telefon, nr_telefon);
    };

//GETTERS

    const char* Cinema::getNume_cinema()const {
        return this->nume_cinema;
    };

    const char* Cinema::getSite_web()const {
        return this->site_web;
    };

    const char* Cinema::getNr_telefon()const {
        return this->nr_telefon;
    };

/**OPERATORUL << */

    ostream& operator<<(ostream& out,const Cinema &ob){

        out<<"Nume cinema:"<<ob.nume_cinema<<endl;
        out<<"Web site:"<<ob.site_web<<endl;
        out<<"Numar telefon:"<<ob.nr_telefon<<endl;
        out<<endl;
        return out;
    }

/**OPERATORUL >> */

    istream& operator>>(istream& in,Cinema &ob){
        cout<<"Nume cinema:";
        char aux[50];
        in>>aux;
        if(ob.nume_cinema!=nullptr){
            delete[] ob.nume_cinema;
            ob.nume_cinema = nullptr;
        }
        ob.nume_cinema = new char[strlen(aux)+1];
        strcpy(ob.nume_cinema,aux);

        cout<<"Web site:";
        in>>aux;
        if(ob.site_web!=nullptr){
            delete[] ob.site_web;
            ob.site_web = nullptr;
        }
        ob.site_web = new char[strlen(aux)+1];
        strcpy(ob.site_web,aux);

        cout<<"Numar telefon";
        in>>aux;
        if(ob.nr_telefon!=nullptr){
            delete[] ob.nr_telefon;
            ob.nr_telefon = nullptr;
        }
        ob.nr_telefon= new char[strlen(aux)+1];
        strcpy(ob.nr_telefon,aux);

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
            this->nume_produs = nullptr;

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
        BarMancare(bool combo_meniu,char* nume_produs,int stoc_produse,float pret_produse):Bar(nume_produs,stoc_produse,pret_produse){this->combo_meniu=combo_meniu;}
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


class Film{
    protected:
//ATRIBUTE CLASA FILME
        string nume_film;
        char* gen_film;
        int durata_film;
        int rating_film;
        string program_vizionare;//ex 22:00-23:00
        Client* client;

    public:

/**CONSTRUCTORI*/
        Film();
        Film(string nume_film,char* gen_film,int durata_film,int rating_film, string program_vizionare);//constructor cu 5 argumente
        Film(string nume_film, string program_vizionare,int durata_film);
        Film(string nume_film,char* gen_film);

        Film(char* gen_film,Client* client);

        Film(string nume_film);
        Film(const Film &ob);/**constructor copiere*/

/**SETTERS*///(modificare valori)

        void setNume_film(string nume_film);
        void setGen_film(char* gen_film);
        void setDurata_film(int durata_film);
        void setRating_film(int rating_film);
        void setProgram_vizionare(string program_vizionare);

        void setClient(Client* client);

/**GETTERS*///(accesare )

        const string getNume_film()const; //this->membru clasa
        const char* getGen_film()const;
        int   getDurata_film();
        int   getRating_film();
        const string getProgram_vizionare()const;

        Client& getClient();

/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Film &ob);
        friend ostream& operator <<(ostream& out, const Film &ob);
        Film& operator = (const Film &ob);

//Destructor pt cele alocate dinamice
         ~Film(){


             if(this->gen_film!= nullptr){
                 delete[]  this->gen_film;
                 this->gen_film=nullptr;
            }

        }
       // Film:~Film(){}
//Metode
  bool poateFiVizionat(const Client& client,char* gen_film) {

     if (strcasecmp(gen_film,"horror") == 0 && client.getVarsta_client() < 18) {
         return false;
     }
     return true;
}


};
//CONSTRUCTORI

//Constructor fara parametrii:
    Film::Film(){

        this->nume_film =nullptr;
        this->gen_film = nullptr;
        this->durata_film = 0;
        this->rating_film  = 0;
        this->program_vizionare = nullptr;
        Client* client = nullptr;
    }
//Constructor cu 5 parametrii:
    Film::Film(string nume_film,char* gen_film,int durata_film,int rating_film, string program_vizionare){

        this->nume_film = nume_film;


        this->gen_film =new char[strlen(gen_film)+1];
        strcpy(this->gen_film,gen_film);


        this->program_vizionare = program_vizionare;


        this->durata_film = durata_film;

        this->rating_film = rating_film;

    }

//Constructor cu 3 parametrii:
    Film::Film(string nume_film, string program_vizionare,int durata_film){

       this->nume_film = nume_film;

        this->program_vizionare = program_vizionare;


        this->durata_film = durata_film;

        gen_film = nullptr;
        rating_film = 0;
    }
//Constructor cu 2 parametrii:
    Film::Film(string nume_film,char* gen_film){

        this->nume_film = nume_film;

        this->gen_film =new char[strlen(gen_film)+1];
        strcpy(this->gen_film,gen_film);

        durata_film = 0;
        rating_film = 0;
        program_vizionare = nullptr;
    }

    Film::Film(char* gen_film,Client* client){

        this->gen_film =new char[strlen(gen_film)+1];
        strcpy(this->gen_film,gen_film);

        this->client = client;

        nume_film = nullptr;
        durata_film = 0;
        rating_film = 0;
        program_vizionare = nullptr;

    }
//Constructor cu 1 parametru:
    Film::Film(string nume_film){

       this->nume_film = nume_film;

        gen_film = nullptr;
        durata_film = 0;
        rating_film = 0;
        program_vizionare = nullptr;
    }
//Constructor copiere:
    Film::Film(const Film &ob){

        this->nume_film = ob.nume_film;

        this->gen_film = new char[strlen(ob.gen_film)+1];
        strcpy(this->gen_film,ob.gen_film);

        this->program_vizionare = ob.program_vizionare;


        this->durata_film = ob.durata_film;

        this->rating_film = ob.rating_film;

        this->client = ob.client;


    }

//SETTERS

    void Film::setNume_film(string nume_film){
        this->nume_film = nume_film;
    };

    void Film::setGen_film(char* gen_film){
        if(this->gen_film != nullptr)
            delete[] this->gen_film;

        this->gen_film = new char[strlen(gen_film)+1];
        strcpy(this->gen_film, gen_film);
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

    const char* Film::getGen_film()const{
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
        out<<"Durata film:"<<ob.durata_film<<"ore"<<endl;
        out<<"Rating:"<<ob.rating_film<<endl;
        out<<"Program vizionare:"<<ob.program_vizionare<<endl;
        out<<endl;
        return out;
    }

/**OPERATORUL >> */

    istream& operator>>(istream& in,Film &ob){
        cout<<"Nume film:";
        char aux[50];
        in>>ob.nume_film;

        cout<<"Gen film:";
        in>>aux;
        if(ob.gen_film!=nullptr){
            delete[] ob.gen_film;
            ob.gen_film = nullptr;
        }
        ob.gen_film = new char[strlen(aux)+1];
        strcpy(ob.gen_film,aux);

        cout<<"Durata film:";
        in>>ob.durata_film;

        cout<<"Rating:";
        in>>ob.rating_film;

        cout<<"Program vizionare";
        in>>ob.program_vizionare;


         return in;

    }

/**OPERATOR = */




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

class Bilet: public Rezervari, public Film{

    private:
        int sala;
        int rand;
        string ora;// ex 22:00
        string data_bilet;

     public:
        Bilet(int s, int r, string o, string data_b, float pret_b, string nume_f): sala(s), rand(r), ora(o), data_bilet(data_b), Rezervari(pret_b), Film(nume_f){}



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


//EXCEPTION CUSTOM
class LocDejaRezervatException : public exception {
public:
    const char* what() const noexcept override {
        return "Acest loc a fost deja rezervat!";
    }
};


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
    //in viitor admin

}


void meniuClient(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU CLIENT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 1.Crearea unui profil de utilizator."<<endl;
    cout<<" 2.Lista Cinema-uri"<<endl;
    cout<<" 3.Lista Filme"<<endl;
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


int main(){


//Filme //nume_film; gen_film;durata_film;rating_film; program_vizionare;



Film F1("El Camino","thriller",2,9,"11:00-13:00");
Film F2("Jurassic Park(1993)","aventura",2,8,"15:00-17:00");
Film F3("About Time","dragoste",2,7,"18:00-20:00");
Film F4("Fight Club","thriller",2,8,"13:00-15:00");

int contorFilme = 4;

vector<Film> listaFilme = {F1,F2,F3,F4};

//Cinema nume_cinema site_web; nr_telefon

Cinema C1("Cinema City","www.cinemacity.com","0723454312");
Cinema C2("Happy Cinema","www.Happycinema.com","0722335689");
Cinema C3("Cinema Union","www.cinemaUnionn.com","0744337689");
Cinema C4("Cinema Magia","www.cinemamaggiaa.com","0766598712");

int contorCinema = 4;
vector<Cinema> listaCinema = {C1,C2,C3,C4};



//Angajat  nume_angajat  prenume_angajat pozitie_ocupata luni_lucrate

Angajat A1("Popescu","Ion","Tehnician de echipamente",10,20000);
Angajat A2("Grigorescu","Liviu","Manager de cinema",3,9000);
Angajat A3("Ilie","Alexandru Marian","Proiectionist",7,12600);
Angajat A4("Vasile","Dorin","Personal de curatenie",10,12000);

int contorAngajati=4;
vector<Angajat> listaAngajati = {A1,A2,A3,A4};



vector<int> locuri_rezervate ;
int optiune;


//MENIU
do{

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
                        case 3://3.Lista Filme
                            {
                                system("cls");
                                cout<<" "<<endl;
                                cout<<"Aceasta este lista de filme difuzate astazi:"<<endl;
                                cout<<" "<<endl;
                                for( int i = 0;i<contorFilme;i++)
                                    cout<<listaFilme[i]<<endl;
                                    cout<<" "<<endl;

                                system("pause");
                                break;

                            }
                        case 4://4.Adugare rezervare
                            {
                                Rezervari r(20);
                                int rezervare;
                                char continua_adaugare;
                                cout << "Introduceti locurile de rezervat (introduceti 'q' pentru a opri): ";

                               do{
                                cin>>rezervare;



                                r.adaugaLocRezervat(rezervare);
                                cout << "Loc adaugat cu succes! Continuati adaugarea? (y/n): ";
                                cin >> continua_adaugare;
                               }while (continua_adaugare == 'y');

                            system("cls");
                            r.afiseazaInformatiiRezervare();


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
                                    try {
                                    if (!(cin >> sala)) {
                                        throw "Tip de date introdus gresit!";
                                    }
                                }  catch (const char* msg) {
                                        cerr << msg << endl;
                                        exit(0);
                                    }


                                    int rand;
                                    cout<<"Introduceti randul:";
                                    try {
                                    if (!(cin >> rand)) {
                                        throw "Tip de date introdus gresit!";
                                    }
                                }  catch (const char* msg) {
                                        cerr << msg << endl;
                                        exit(0);
                                    }

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
                do{
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
                                       break;
                                }

                                case 0:
                                {
                                    optiune = 0;
                                    system("pause");
                                    break;
                                }


                                default:
                                    {
                                        cout<<"Invalid!"<<endl;
                                        system("pause");
                                    }





                        }



                }while(alegere4);
                 break;

            }
            case 3:{
                    cout<<"Ne pare rau ,este in curs de dezvoltare"<<endl;
                    system("pause");
            }
            case 0:{
                system("pause");
                break;
                }

 }
 exit(0);

}while(optiune==0);

 return 0;

}
