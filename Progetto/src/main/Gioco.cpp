/*
 Classe main da cui viene avviato il gioco
*/

#include <iostream>
using namespace std;
#include "Negozio.hpp"
#include "Livello.hpp"
#include "../elementi/personaggi/Protagonista.hpp"
/* #include "../elementi/personaggi/Goblin.cpp" */

int main() {
  Negozio negozio = Negozio();
  Protagonista p = Protagonista();

  bool ciclo = true, cicloNeg;
  int scelta, sceltaNeg;
  Arma acquisto = Arma(Stringa((char*) "tmp"));

  /* Livello l1 = Livello();
  l1.protagonistaArriva();
  l1.inserisciNemico(Goblin());
  l1.protagonistaAddios();
  l1.salva(); */

  do {
    cout<<endl<<"Inserisci il numero corrispondente alla scelta:"<<endl;
    cout<<"0) Termina esecuzione. 1) Stampa resoconto. 2) Vai al negozio. 3) Guadagna 500 denari."<<endl;
    cout<<"4) Ricevi 30 punti ma anche 2 di danno."<<endl;
    cin>>scelta;
    cout<<endl;
    switch (scelta) {
      case 0:
        cout<<"Partita terminata"<<endl;
        ciclo = false;
        break;
      case 1:
        cout<<p.toString().s;
        cout<<p.getArma().toString().s;
        break;
      case 2:
        cicloNeg = true;
        do {
          cout<<"Inserire il numero corrispondente alla scelta:"<<endl;
          cout<<"0) Esci dal negozio. 1) Compra un arma."<<endl;
          cin>>sceltaNeg;
          cout<<endl;
          switch (sceltaNeg) {
            case 0:
              cout<<"Grazie di essere passato"<<endl;
              cicloNeg = false;
              break;
            case 1:
              cout<<"Articoli disponibili"<<endl;
              cout<<negozio.mostraArticoli().s;
              cout<<"Inserisci il numero dell'arma da comprare: ";
              cin>>sceltaNeg;
              acquisto = negozio.vendiArma(sceltaNeg);
              if(p.spendi(acquisto.getCosto())) {
                p.cambiaArma(acquisto);
                cout<<"Acquisto effettuato. Saldo residuo: "<<p.getDenaro()<<endl;
              } else {
                cout<<"Denaro insufficiente"<<endl;
              }
              break;
            default:
              cout<<"Scelta inesistente"<<endl;
              break;
          }
        } while (cicloNeg);
        break;
      case 3:
        p.guadagna(500);
        cout<<p.getNome().s<<" ha guadagnato 500 denari. Saldo attuale: "<<p.getDenaro()<<endl;
        break;
      case 4:
        p.aggiungiPunti(30);
        p.prendiDanno(2);
        cout<<p.getNome().s<<" ha ricevuto 30 punti. Punti attuali: "<<p.getPunti()<<endl;
        cout<<p.getNome().s<<" ha subito 2 di danno. Vita attuale: "<<p.getVita()<<endl;
        break;
      default:
        cout<<"Scelta inesistente"<<endl;
        break;
    }
  } while (ciclo && p.getVita() > 0);

  p.salva();

  return 0;
}