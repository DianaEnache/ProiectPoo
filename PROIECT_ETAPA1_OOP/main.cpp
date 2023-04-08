#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

//CLASE: FILM,BILET,CLIENT,CINEMA,ANGAJAT,REZERVARI,BAR,SEDIU CINEMA

                                                /**CLASA CLIENT*/
class Client{
    private:
        char* nume_client;
        char* prenume_client;
        char* email_client;
        char* metoda_plata;//cash sau card
        int varsta_client;//pt reducere sub 18 ani

    public:
//Constructorul este folosit pentru a inițializa obiecte din clasa Client atunci când acestea sunt create.
//Astfel, atunci când se creează un nou obiect Filme, se va apela acest constructor și variabilele membre
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

 class Film{
    private:
//ATRIBUTE CLASA FILME
        char* nume_film;
        char* gen_film;
        int durata_film;//ar merge float 2.30 ore
        int rating_film;
        char* program_vizionare;//ex 22:00-23:00
        Client* client;

    public:
//Constructorul este folosit pentru a inițializa obiecte din clasa Filme atunci când acestea sunt create.
//Astfel, atunci când se creează un nou obiect Filme, se va apela acest constructor și variabilele membre
//ale obiectului vor fi initializate cu valorile primite ca argumente.

/**CONSTRUCTORI*/
        Film();
        Film(char* nume_film,char* gen_film,int durata_film,int rating_film,char* program_vizionare);//constructor cu 5 argumente
        Film(char* nume_film,char* program_vizionare,int durata_film);
        Film(char* nume_film,char* gen_film);

        Film(char* gen_film,Client* client);

        Film(char* nume_film);
        Film(const Film &ob);/**constructor copiere*/
//constructorul de copiere
//se pune const pentru a proteja datele din obiectul de copiat
//se pune & pentru a putea accesa direct adresa obiectului de copiat
//astfel incat sa nu folosim memorie suplimentara daca cream alt obiect

//Fiecare constructor are un set diferit de argumente și poate fi utilizat pentru a crea un obiect

/**THIS*/// folosirea operatorului THIS ajuta la evitarea ambiguitatilor si la mentinerea unei structuri coerente si clare a codului

/**SETTERS*///(modificare valori)

        void setNume_film(char* nume_film);
        void setGen_film(char* gen_film);
        void setDurata_film(int durata_film);
        void setRating_film(int rating_film);
        void setProgram_vizionare(char* program_vizionare);

        void setClient(Client* client);

/**GETTERS*///(accesare )

        const char* getNume_film()const; //this->membru clasa
        const char* getGen_film()const;
        int   getDurata_film();
        int   getRating_film();
        const char* getProgram_vizionare()const;

        Client& getClient();

/**SUPRAINCARCARE OPERATORI*/

        friend istream& operator >>(istream& in, Film &ob);
        friend ostream& operator <<(ostream& out, const Film &ob);
        Film& operator = (const Film &ob);

//Destructor pt cele alocate dinamice
        ~Film(){
            if(this->nume_film!= nullptr){
                 delete[]  this->nume_film;
                 this->nume_film=nullptr;
            }

             if(this->gen_film!= nullptr){
                 delete[]  this->gen_film;
                 this->gen_film=nullptr;
            }
             if(this->program_vizionare!= nullptr){
                 delete[]  this->program_vizionare;
                 this->program_vizionare=nullptr;
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
    Film::Film(char* nume_film,char* gen_film,int durata_film,int rating_film,char* program_vizionare){

        this->nume_film = new char[strlen(nume_film)+1];
        strcpy(this->nume_film,nume_film);

        this->gen_film =new char[strlen(gen_film)+1];
        strcpy(this->gen_film,gen_film);


        this->program_vizionare = new char[strlen(program_vizionare)+1];
        strcpy(this->program_vizionare,program_vizionare);

        this->durata_film = durata_film;

        this->rating_film = rating_film;

    }

//Constructor cu 3 parametrii:
    Film::Film(char* nume_film,char* program_vizionare,int durata_film){

        this->nume_film = new char[strlen(nume_film)+1];
        strcpy(this->nume_film,nume_film);

        this->program_vizionare = new char[strlen(program_vizionare)+1];
        strcpy(this->program_vizionare,program_vizionare);

        this->durata_film = durata_film;

        gen_film = nullptr;
        rating_film = 0;
    }
//Constructor cu 2 parametrii:
    Film::Film(char* nume_film,char* gen_film){

        this->nume_film = new char[strlen(nume_film)+1];
        strcpy(this->nume_film,nume_film);

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
    Film::Film(char* nume_film){

        this->nume_film = new char[strlen(nume_film)+1];
        strcpy(this->nume_film,nume_film);

        gen_film = nullptr;
        durata_film = 0;
        rating_film = 0;
        program_vizionare = nullptr;
    }
//Constructor copiere:
    Film::Film(const Film &ob){

        this->nume_film = new char[strlen(ob.nume_film)+1];
        strcpy(this->nume_film,ob.nume_film);

        this->gen_film = new char[strlen(ob.gen_film)+1];
        strcpy(this->gen_film,ob.gen_film);

        this->program_vizionare = new char[strlen(ob.program_vizionare )+1];
        strcpy(this->program_vizionare ,ob.program_vizionare );

        this->durata_film = ob.durata_film;

        this->rating_film = ob.rating_film;

        this->client = ob.client;


    }

//SETTERS

    void Film::setNume_film(char* nume_film){
        if(this->nume_film != nullptr)
            delete[] this->nume_film;

        this->nume_film = new char[strlen(nume_film)+1];
        strcpy(this->nume_film, nume_film);
    };

    void Film::setGen_film(char* gen_film){
        if(this->gen_film != nullptr)
            delete[] this->gen_film;

        this->gen_film = new char[strlen(gen_film)+1];
        strcpy(this->gen_film, gen_film);
    };

    void Film::setProgram_vizionare(char* program_vizionare){
         if(this->program_vizionare != nullptr)
            delete[] this->program_vizionare;

        this->program_vizionare = new char[strlen(program_vizionare)+1];
        strcpy(this->program_vizionare,program_vizionare);
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

    const char* Film::getNume_film()const {
        return this->nume_film;
    };

    const char* Film::getGen_film()const{
        return this->gen_film;
    };

    const char* Film::getProgram_vizionare()const{
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
        in>>aux;
        if(ob.nume_film!=nullptr){
            delete[] ob.nume_film;
            ob.nume_film = nullptr;
        }
        ob.nume_film = new char[strlen(aux)+1];
        strcpy(ob.nume_film,aux);

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
        in>>aux;
        if(ob.program_vizionare!=nullptr){
            delete[] ob.program_vizionare;
            ob.program_vizionare = nullptr;
        }
        ob.program_vizionare= new char[strlen(aux)+1];
        strcpy(ob.program_vizionare,aux);

         return in;

    }

/**OPERATOR = */

    Film& Film::operator = (const Film &ob){
        if(this != &ob)
        {
            this->durata_film = ob.durata_film;
            this->rating_film = ob.rating_film;

            this->nume_film = new char[strlen(ob.nume_film)+1];
            strcpy(this->nume_film,ob.nume_film);

            this->gen_film = new char[strlen(ob.gen_film)+1];
            strcpy(this->gen_film,ob.gen_film);

            this->program_vizionare = new char[strlen(ob.program_vizionare)+1];
            strcpy(this->program_vizionare,ob.program_vizionare);
        }
        return *this;

    }







                                        /**CLASA BILET*/

class Bilet{
    private:
        int loc;
        int rand;
        int sala;
        bool VIP;
        double pret_bilet;//ar merge o metoda reducere elev/student
        Client* client; //clase corelate prin compunere

    public:
    /**CONSTRUCTORI*/
        Bilet();
        Bilet(int loc,int rand,int sala,bool VIP,double pret_bilet);
        Bilet(int loc,int rand,int sala);
        Bilet(bool VIP,double pret_bilet);
        Bilet(double pret_bilet,Client* client);
        Bilet(const Bilet &ob);//constructor copiere



    /**SETTERS*/
        void setLoc(int loc);
        void setRand(int rand);
        void setSala(int sala);
        void setVIP(bool VIP);
        void setpret_bilet(double pret_bilet);
        void setClient(Client* client);


    /**GETTERS*/
        int getLoc();
        int getRand();
        int getSala();
        bool getVIP();
        double getpret_bilet();
        Client& getClient();


    /**SUPRAINCARCARE DE OPERATORI*/
        friend istream& operator >>(istream& in, Bilet &ob);
        friend ostream& operator <<(ostream& out, const Bilet &ob);

    //METODA REDUCERE IN FUNCTIE DE varsta
    double CalculeazaPretBilet(const Client& client){
         if (client.getVarsta_client() < 16) {
                return pret_bilet * 0.5; // reducere 50% pentru clienti sub 16 ani
            } else {
                return pret_bilet;
            }
        }

};
//CONSTRUCTORI
    //Constructor fara parametri
    Bilet::Bilet(){
        int loc = 0;
        int rand = 0;
        int sala = 0;
        bool VIP = false;
        double pret_bilet = 0;
        Client* client = nullptr;

    }

//Constructor cu 5 parametrii
    Bilet::Bilet(int loc,int rand,int sala,bool VIP,double pret_bilet){
        this->loc = loc;
        this->rand = rand;
        this->sala = rand;
        this->VIP = VIP;
        this->pret_bilet = pret_bilet;
    }

//Constructorul cu 3 parametrii
    Bilet::Bilet(int loc,int rand,int sala){
        this->loc = loc;
        this->rand = rand;
        this->sala = sala;
        bool VIP = false;
        double pret_bilet = 0;
    }

//Constructorul cu 2 parametrii
    Bilet::Bilet(bool VIP,double pret_bilet){
        int loc = 0;
        int rand = 0;
        int sala = 0;
        this->VIP=VIP;
        this->pret_bilet=pret_bilet;
    }


    Bilet::Bilet(double pret_bilet,Client* client){
        int loc = 0;
        int rand = 0;
        int sala = 0;
        bool VIP = false;
        this->client = client;
        this->pret_bilet = pret_bilet;

    }

/**constructor copiere*/
    Bilet::Bilet(const Bilet &ob){
        this->loc = ob.loc;
        this->rand = ob.rand;
        this->sala = ob.sala;
        this->VIP = ob.VIP;
        this->pret_bilet = ob.pret_bilet;
        this->client = ob.client;

    }

//SETTERS
    void Bilet::setLoc(int loc){
        this->loc=loc;
    }

    void Bilet::setRand(int rand){
        this->rand=rand;
    }

    void Bilet::setSala(int sala){
        this->sala = sala;
    }

    void Bilet::setVIP(bool VIP){
        this->VIP = VIP;
    }

    void Bilet::setpret_bilet(double pret_bilet){
        this->pret_bilet = pret_bilet;
    }

    void Bilet::setClient(Client* client){
        this->client = client;
    }


//GETTERS

    int Bilet::getLoc(){
        return this->loc;
    }

    int Bilet::getRand(){
        return this->rand;
    }

    int Bilet::getSala(){
        return this->sala;
    }

    bool Bilet::getVIP(){
        return this->VIP;
    }

    double Bilet::getpret_bilet(){
        return this->pret_bilet;
    }

    Client& Bilet::getClient(){
        return *client;
    }


/**OPERATORUL << */
    ostream& operator<<(ostream& out,const Bilet &ob){

        out<<"Loc:"<<ob.loc<<endl;
        out<<"Rand:"<<ob.rand<<endl;
        out<<"Sala:"<<ob.sala<<endl;
        out << "VIP(1.Da/0.Nu): " << (ob.VIP ? "Da" : "Nu") << endl;
        //out<<"pret_bilet:"<<ob.pret_bilet<<endl;
        return out;
    }

/**OPERATORUL >> */

    istream& operator>>(istream& in,Bilet &ob){

        cout<<"Loc:";
        in>>ob.loc;

        cout<<"Rand:";
        in>>ob.rand;

        cout<<"Sala:";
        in>>ob.sala;

        cout<<"VIP:";
        in>>ob.VIP;

        //cout<<"pret_bilet:";
       // in>>ob.pret_bilet;

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
        Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate,float salariu,long long CNP);
        Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate);
        Angajat(char* nume_angajat,char* prenume_angajat,float salariu);
        Angajat(char* nume_angajat,char* prenume_angajat,long long CNP);
        Angajat(char* nume_angajat,char* prenume_angajat);
        Angajat(const Angajat &ob);//constructor copiere


/**SETTERS*/
        void setNume_angajat(char* nume_angajat);
        void setPrenume_angajat(char* prenume_angajat);
        void setPozitie_ocupata(char* pozitie_ocupata);
        void setLuni_lucrate(int luni_lucrate);
        void setSalariu(float salariu);
        void setCNP(long long CNP);


/**GETTERS*/

        const char* getNume_angajat()const;
        const char* getPrenume_angajat()const;
        const char* getPozitie_ocupata()const;
        int getLuni_lucrate();
        float getSalariu();
        long long getCNP();


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
        this->CNP = 0;

    }

//Constructor cu 6 parametrii

    Angajat::Angajat(char* nume_angajat,char* prenume_angajat,char* pozitie_ocupata,int luni_lucrate,float salariu,long long CNP){

        this->nume_angajat= new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat,nume_angajat);

        this->prenume_angajat= new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat,prenume_angajat);

        this->pozitie_ocupata= new char[strlen(pozitie_ocupata)+1];
        strcpy(this->pozitie_ocupata,pozitie_ocupata);

        this->luni_lucrate = luni_lucrate;
        this->salariu = salariu;
        this->CNP = CNP;

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

        this->CNP= 0;
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
        this->CNP = 0;
    }

    Angajat::Angajat(char* nume_angajat,char* prenume_angajat,long long CNP){

        this->nume_angajat= new char[strlen(nume_angajat)+1];
        strcpy(this->nume_angajat,nume_angajat);

        this->prenume_angajat= new char[strlen(prenume_angajat)+1];
        strcpy(this->prenume_angajat,prenume_angajat);

        this->CNP = CNP;

        this->salariu = 0;
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
        this->CNP = 0;

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

        this->CNP = CNP;
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

    void Angajat::setCNP(long long CNP){
        this->CNP = CNP;
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

    long long Angajat::getCNP(){
        return this->CNP;
    };

/**OPERATORUL << */
    ostream& operator<<(ostream& out,const Angajat &ob){
        out<<" "<<endl;
        out<<"Afisare informatii angajat:"<<endl;
        out<<" "<<endl;
        out<<"Nume:"<<ob.nume_angajat<<endl;
        out<<"Prenume:"<<ob.prenume_angajat<<endl;
        //out<<"CNP: "<<ob.CNP<<endl;
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

        //cout<<"CNP:";
        //in>>ob.CNP;

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
        //Film* filme;//  vector  corelare prin compunere
        //Sediu_cinema sediu

   public:

/**CONSTRUCTORI*/

    Cinema();//constructor fara parametrii
    Cinema(char* nume_cinema,char* site_web,char* nr_telefon);
    //Cinema(char* nume_cinema,char* site_web,Film* filme);
    //Cinema(char* nume_cinema,Film* filme);
    Cinema(char* nume_cinema,char* site_web);
    Cinema(char* nume_cinema);
    Cinema(const Cinema &ob);//constructor copiere

/**SETTERS*/

    void setNume_cinema(char* nume_cinema);
    void setSite_web(char* site_web);
    void setNr_telefon(char* nr_telefon);
    //void SetFilme(Film* filme);

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
          /**
            if(this->filme!= NULL){
                delete[] this->filme;
                this->filme = NULL;
            }*/
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

                                                            /**CLASA REZERVARI*/


class Rezervari{
    private:
        int nr_locuri_rezervate;
        int* locuri_rezervate;
        Film* film;
        Client* client;
        Bilet* bilet;

    public:
/**CONSTRUCTOR*/
        Rezervari(Film* film, Client* client,Bilet* bilet) {
            this->film = film;
            this->client = client;
            this->bilet = bilet;
            this->locuri_rezervate = new int[100];
            this->nr_locuri_rezervate = 0;
        }

        void adaugaLocRezervat(int loc) {
            this->locuri_rezervate[this->nr_locuri_rezervate++] = loc;
        }
        void stergeLocRezervat(int loc) {
            for (int i = 0; i < this->nr_locuri_rezervate; i++) {
                if (this->locuri_rezervate[i] == loc) {
                    for (int j = i; j < this->nr_locuri_rezervate - 1; j++) {
                        this->locuri_rezervate[j] = this->locuri_rezervate[j + 1];
                    }
                    this->nr_locuri_rezervate--;
                    return;
                }
            }
        }

        void afiseazaLocuriRezervate() {
                    cout << "Locurile rezervate sunt: ";
                        for (int i = 0; i < nr_locuri_rezervate; i++) {
                                cout << locuri_rezervate[i] << " ";
                        }
                    cout << endl;
            }


        int calculeazaPretTotal() {
            return this->nr_locuri_rezervate * this->bilet->getpret_bilet();
        }
        void afiseazaInformatiiRezervare() {
            cout << "Rezervare pentru filmul " << this->film->getNume_film() << ", facuta de " << this->client->getNume_client() << endl;
            cout << "Numar locuri rezervate: " << this->nr_locuri_rezervate << endl;
            cout << "Pret total: " << this->calculeazaPretTotal() << endl;
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
    cout<<" 0.Exit."<<endl;
    cout<<" "<<endl;
    cout<<"Introduceti numarul dorit: ";


}

void meniuFilm(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU FILM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 1.Lista filme."<<endl;
    cout<<" 2.Selectare film dorit."<<endl;
    cout<<" 0.Exit."<<endl;
}

void meniuBilet(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU BILET~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 1.Pretul biletului (reducere pentru persoanele sub 16)"<<endl;
    cout<<" 2.Date bilet"<<endl;
    cout<<" 0.Exit."<<endl;
    cout<<" "<<endl;
    cout<<"Introduceti numarul dorit: ";


}

void meniuCinema(){
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~MENIU CIINEMA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" 1.Lista Cinema-uri"<<endl;
    cout<<" 0.Exit."<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
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



int main(){

//Filme //nume_film; gen_film;durata_film;rating_film; program_vizionare;

Film F1("El Camino","thriller",2,9,"11:00-13:00");
Film F2("Jurassic Park(1993)","aventura",2,8,"15:00-17:00");
Film F3("About Time","dragoste",2,7,"18:00-20:00");
Film F4("Fight Club","thriller",2,8,"13:00-15:00");

int contorFilme = 4;
Film listaFilme[100]={F1,F2,F3,F4};


//Cinema nume_cinema site_web; nr_telefon

Cinema C1("Cinema City","www.cinemacity.com","0723454312");
Cinema C2("Happy Cinema","www.Happycinema.com","0722335689");
Cinema C3("Cinema Union","www.cinemaUnionn.com","0744337689");
Cinema C4("Cinema Magia","www.cinemamaggiaa.com","0766598712");

int contorCinema = 4;
Cinema listaCinema[100]={C1,C2,C3,C4};


//Angajat  nume_angajat  prenume_angajat pozitie_ocupata luni_lucrate salariu CNP

Angajat A1("Popescu","Ion","Tehnician de echipamente",10,20000,12345678912);
Angajat A2("Grigorescu","Liviu","Manager de cinema",3,9000,189040640585);
Angajat A3("Ilie","Alexandru Marian","Proiectionist",7,12600,197081210783);
Angajat A4("Vasile","Dorin","Personal de curatenie",10,12000,197101208627);

int contorAngajati=4;
Angajat listaAngajati[100]={A1,A2,A3,A4};

//rezervari
int locuri_rezervate[50] = {-1};
int nr_locuri_rezervate = 0;

char* nume,prenume,pozitie;
    int optiune;//alegere
    do
    {
            meniu();
            cin >> optiune;
            int optiune1;
        switch(optiune)
            {
                case 0: //0.Exit
                    break;
                case 1://1.Client
                    do
                    {
                        meniuClient();
                        cin>>optiune1;
                        int optiune2;

                        if(optiune1==0){break;}//0.Exit

                        else if(optiune1 == 1)//1.Crearea unui profil de utilizator.
                            {
                                Client adaugare;
                                cin>>adaugare;
                                system("cls");
                                cout<<" "<<endl;
                                cout<<"Profilul dumneavoastra:"<<endl;
                                cout<<" "<<endl;
                                cout<<adaugare;
                                cout<<endl;

                            }
                        else if(optiune1 == 4 )//4.Rezervarea unui loc la cinema."
                            {
                                char numefilm[100];
                                cout << "Introduceti numele filmului: ";
                                cin >> numefilm;
                                Film film(numefilm);

                                char numeclient[100];
                                cout << "Introduceti numele clientului: ";
                                cin >> numeclient;

                                char prenumeclient[100];
                                cout << "Introduceti prenumele clientului: ";
                                cin >> prenumeclient;

                                Client client(numeclient,prenumeclient);


                                Bilet bilet(true,20);
                                Rezervari rezervari(&film, &client,&bilet);
                                cout << "Introduceti locul dorit: ";
                                int nr_rez;
                                cin>>nr_rez;

                                bool loc_rezervat = false;
                                for (int i = 0; i < nr_locuri_rezervate; i++) {
                                        if (locuri_rezervate[i] == nr_rez) {
                                        loc_rezervat = true;
                                cout << "Locul a fost deja rezervat!" << endl;
                                break;
                                }
                            }

                            // adăugăm locul în vector dacă nu a fost deja rezervat
                            if (!loc_rezervat) {
                            locuri_rezervate[nr_locuri_rezervate++] = nr_rez;
                            rezervari.adaugaLocRezervat(nr_rez);
                            }

                            rezervari.afiseazaLocuriRezervate();



                            cout<<"Doriti sa mai rezervati un loc?"<<endl;
                            cout<<"Introduceti optiunea dorita(1.da/ 0.nu)):";
                            cin>>optiune2;
                            if(optiune2 == 1)
                                {

                                    cin>>nr_rez;

                                bool loc_rezervat = false;
                                for (int i = 0; i < nr_locuri_rezervate; i++) {
                                        if (locuri_rezervate[i] == nr_rez) {
                                        loc_rezervat = true;
                                cout << "Locul a fost deja rezervat!" << endl;
                                break;
                                }
                            }

                            // adăugăm locul în vector dacă nu a fost deja rezervat
                            if (!loc_rezervat) {
                            locuri_rezervate[nr_locuri_rezervate++] = nr_rez;
                            rezervari.adaugaLocRezervat(nr_rez);
                            }

                                rezervari.afiseazaLocuriRezervate();
                                cout<<" "<<endl;
                                cout<<"Informatii rezervare:"<<endl;
                                cout<<" "<<endl;
                                rezervari.afiseazaInformatiiRezervare();



                                }else if(optiune2 == 0){break;}

                                system("pause");





                            }
                        else if(optiune1 == 5) //3.Stergerea locului rezervat.
                        {

                            cout<<"Ne pare rau ,este in curs de dezvoltare"<<endl;
                            system("pause");
                        }

                        else if(optiune1 == 2)//4.Lista Cinema-uri
                        {
                            cout<<" "<<endl;
                            cout<<"Aceasta este lista de cinema-uri din orasul tau:"<<endl;
                            cout<<" "<<endl;
                            for( int i = 0;i<contorCinema;i++)
                                cout<<listaCinema[i]<<endl;
                                cout<<" "<<endl;

                            system("pause");
                        }

                        else if(optiune1 == 3)//5.Lista Filme
                        {
                            cout<<" "<<endl;
                            cout<<"Aceasta este lista de filme difuzate astazi:"<<endl;
                            cout<<" "<<endl;
                            for( int i = 0;i<contorFilme;i++)
                                cout<<listaFilme[i]<<endl;
                                cout<<" "<<endl;

                            system("pause");
                        }

                        else if(optiune1 == 6)//6.Detalii despre bilet
                        {

                            meniuBilet();
                            cin>>optiune2;
                            if(optiune2 == 1)//1.Pretul biletului (reducere pentru persoanele sub 16)
                            {
                                char numeclient[100];
                                cout << "Introduceti numele clientului: ";
                                cin >> numeclient;

                                char prenumeclient[100];
                                cout << "Introduceti prenumele clientului: ";
                                cin >> prenumeclient;

                                int varsta;
                                cout<<"Introduceti varsta: ";
                                cin>>varsta;

                                char genfilm[100];
                                cout<<"Introduceti genul filmului pe care doriti sa-l vizionati:";
                                cin>>genfilm;

                                Client client(numeclient,prenumeclient,varsta);
                                Film film1(genfilm,&client);
                                bool vizionare = film1.poateFiVizionat(client,genfilm);
                                if(vizionare == true){

                                }else {
                                        cout<<"Nu este permisa vizionarea,clientul are sub 18 ani"<<endl;
                                        system("pause");
                                        break;
                                }




                                Bilet bilet(20,&client);/**DE RETINUT */
                                double pret = bilet.CalculeazaPretBilet(client);


                                int locuriRez;
                                cout<<"Cate locuri ati rezervat?:";
                                cin>>locuriRez;

                                int pret_tot = pret * locuriRez;

                                cout << "Pretul biletului este: " << pret_tot << endl;


                                system("pause");

                            }

                            else if(optiune2 == 2)//2.Date bilet
                            {
                                Bilet aux;
                                cin>>aux;
                                system("cls");
                                cout<<" "<<endl;
                                cout<<"Biletul dumneavoastra:"<<endl;
                                cout<<" "<<endl;
                                cout<<aux;
                                cout<<endl;
                                system("pause");

                            }

                            else if(optiune2 == 0){break;}//exit


                        }

                    }while(optiune1);
                        break;

                case 2://Angajati
                    { int optiune3;
                    do{
                        meniuAngajati();
                        cin>>optiune3;
                        int optiune4;

                        if(optiune3==0){break;}//0.Exit

                        else if(optiune3 == 1)//Lista Angajati
                        {

                           cout<<" ";
                           for(int i= 0;i<contorAngajati;i++)
                            cout<<listaAngajati[i]<<endl;
                            cout<<" "<<endl;
                            system("pause");
                        }

                        else if(optiune3 == 2)//2.Calculator de salariu in functie de lunile lucrate  si pozitia ocupata
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
                        }

                    }while(optiune3);}


                case 3:
                    { int optiune4;



                            cout<<"Ne pare rau ,este in curs de dezvoltare"<<endl;
                            system("pause");





                            }

            }
        }
        while(optiune);


        return 0;
/*
    //Cinema
    Cinema cinema("CinemaCity","www.cinemacity.com","0723456767");
    cout<<"-------------------------------------"<<endl;
    cout<<cinema.getNume_cinema()<<endl;
    cout<<"Numar telefon:"<<cinema.getNr_telefon()<<endl;
    cout<<"Site web:"<<cinema.getSite_web()<<endl;
    cout<<"-------------------------------------"<<endl;
    //Film myobj;

    Film film("Inception");
    Client client("John Doe","Mihaela");
    Bilet bilet(true,20);
    Rezervari rezervari(&film, &client,&bilet);
    rezervari.adaugaLocRezervat(5);
    rezervari.adaugaLocRezervat(8);
    rezervari.adaugaLocRezervat(7);
    rezervari.stergeLocRezervat(5);
    rezervari.afiseazaInformatiiRezervare();

    Filme
    cout<<"-------------------------------------"<<endl;
    Film film("Titanic","Drama",2,9,"22:00-23:00");
    cout<<"In seara aceast se difuzeaza:"<<endl;
    cout<<film.getNume_film()<<" "<<"Gen:"<<film.getGen_film()<<endl;
    cout<<"Rating:"<<film.getRating_film()<<endl;
    cout<<"Durata:"<<film.getDurata_film()<<" "<<"h"<<endl;
    cout<<"Program:"<<film.getProgram_vizionare()<<endl;
    cout<<"-------------------------------------"<<endl;

    //Metoda vizionare in functie de varsta
    Client client("Maria","Ioana",10);
    Film film1("Horror",&client);
    bool vizionare = film1.poateFiVizionat(client,"Horror");
    if(vizionare == true){
        cout<<"Este permisa vizionarea,clientul are peste 18 ani."<<endl;
    }else {
        cout<<"Nu este permisa vizionarea,clientul are sub 18 ani"<<endl;
    }

    Angajat angajat("Popescu", "Ion", "Casier", 10);

    // Apelăm metoda CalculeazaSalariu și afișăm rezultatul
    float salariu = angajat.CalculeazaSalariu(1,"Proiecționist");
    cout << "Salariul angajatului "<<angajat.getNume_angajat()<<" "<<angajat.getPrenume_angajat()<<" "<<"este de :" << salariu <<" lei"<<endl;

    //CLIENT
    Client client1("Popescu","Maria","mariapopescu@gmail.com","card",14);
    cout<<"-------------------------------------"<<endl;
    cout<<"Profil Client:"<<endl;
    cout<<"Nume:"<<" "<<client1.getNume_client()<<endl;
    cout<<"Prenume:"<<" "<<client1.getPrenume_client()<<endl;
    cout<<"E-mail:"<<" "<<client1.getEmail_client()<<endl;
    cout<<"Metoda plata:"<<client1.getMetoda_plata()<<endl;
    cout<<"Varsta:"<<client1.getVarsta_client()<<endl;
    cout<<"-------------------------------------"<<endl;



    cout<<"-------------------------------------"<<endl;



   // Client client;
    //client.setVarsta_client(14);
    //Bilet bilet(20,&client);/**DE RETINUT */

    //double pret = bilet.CalculeazaPretBilet(client);
    //cout << "Pretul biletului este: " << pret << endl;


    //myobj.setProgram_vizionare("21:00-23:00");
    //myobj.setGen_film("horror");
    //cout<<myobj.getGen_film()<<" "<<myobj.getProgram_vizionare();



}
