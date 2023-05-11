/*
 Classe main da cui viene avviato il gioco
*/

#include <iostream>
using namespace std;
#include "Gioco.hpp"
#include "Negozio.hpp"
#include "../elementi/personaggi/Protagonista.hpp"

int main() {
  GestoreFile gf = GestoreFile();
  Protagonista p = Protagonista(gf);
  Gioco g = Gioco();
  if (p.getVita() == 0) {
    p.rigenera();
    g = Gioco(gf, true, p.getDifficolta());
  } else {
    g = Gioco(gf, false);
  }
  Negozio negozio = Negozio();

  bool ciclo = true, cicloNeg;
  int scelta, sceltaNeg;
  Arma acquisto = Arma(Stringa((char*) "tmp"));

  do {
    cout<<endl<<"Inserisci il numero corrispondente alla scelta:"<<endl;
    cout<<"0) Termina esecuzione 1) Stampa resoconto 2) Vai al negozio 3) Attacca nemico"<<endl;
    cout<<"4) Prendi danno dal nemico 5) Muovi avanti di livello 6) Muovi indietro di livello"<<endl;
    cin>>scelta;
    cout<<endl;
    switch (scelta) {
      case 0:
        ciclo = false;
        break;
      case 1:
        cout<<p.toString().s;
        cout<<p.getArma().toString().s;
        g.debug();
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
        if (g.attaccaNemico(p.infliggiDanno())) {
          cout<<"Nemico colpito!"<<endl;
        } else {
          cout<<"Nemico ucciso!"<<endl;
          p.guadagna(g.getPrimoNemico().getRicompensa());
          p.aggiungiPunti(g.getPrimoNemico().getRicompensa());
          g.rimuoviNemici();
        }
        break;
      case 4:
        p.prendiDanno(g.getPrimoNemico().getDanno());
        cout<<"Ahia! Questo ha fatto male..."<<endl;
        break;
      case 5:
        if (g.muoviAvanti()) {
          cout<<p.getNome().s<<" avanza di livello"<<endl;
        } else {
          cout<<"Non puoi ancora avanzare"<<endl;
        }
        break;
      case 6:
        if (g.muoviIndietro()) {
          cout<<p.getNome().s<<" indietreggia di livello"<<endl;
        } else {
          cout<<"Non puoi andare indietro ancora"<<endl;
        }
        break;
      default:
        cout<<"Scelta inesistente"<<endl;
        break;
    }
  } while (ciclo && p.getVita() > 0);

  cout<<"Gioco terminato"<<endl;

  p.salva(gf);
  g.salva(gf);
  
  return 0;
}