#include "station.h"
#include <QDebug>

#include "params.h"

int Station::nombreStations=0;

Station::Station(QString nom,Station::Type t, Ligne * pligne):PointSynchronisation()
{
    this->typeStation = t;
    this->nom=nom;
    this->maligne = pligne;
    Station::nombreStations++;
    this->numPS = Station::nombreStations;
}

void Station::run()
{
    qDebug() << "Station run";
    for(;;){
        sleep(1);
    }
}

void Station::createSignal()
{
    while(this->listSignals.size())
    {
        Signals *s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Demande:
            {
                if(!this->estVert())
                {
                    qDebug() << "Station "<< this->numPS<< " \t signal Signals::Demande recu";
                    s->emetteur()->addSignal(new Signals(this,Signals::Arret));

                    Rame * rame = dynamic_cast<Rame *>(s->emetteur());

                    //Fait descendre Passager
                    QList <Passager *> listedescend = rame->descend(this);
                    qDebug() << "--------------------------" << listedescend.size() << " passager descend de la rame";

                    //Fait monter Passager
                    QList <Passager *> listePassagerMonte;
                    int nbMontant;
                    if(CAPACITERAME-rame->getNbPassager() > this->listePassager.size()){
                        nbMontant = this->listePassager.size();
                    }else{
                        nbMontant = CAPACITERAME-rame->getNbPassager();
                    }
                    for(int i = 0; i < nbMontant; i++){
                        listePassagerMonte.push_back(this->listePassager.at(i));
                    }
                    for(int i = 0; i < nbMontant; i++){
                        this->listePassager.removeFirst();
                    }
                    rame->monte(listePassagerMonte);
                    qDebug() << "--------------------------" << listePassagerMonte.size() << " passager monte dans la rame";

                    sleep(5);
                    this->passerVert();                    
                    s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                }
            }
            break;
            case Signals::EstPasse:
            {
                qDebug()<< "Message estPasse recu par Station";
                this->passerRouge();
                if(this->getPrecedent() != NULL)
                    this->getPrecedent()->passerVert();
                this->derniereRame = s->emetteur();
                sleep(3);
                this->setPassagers();
            }
            break;
        }
    }
}

void Station::afficher(QPainter * painter, int x, int y, int wElement, int hElement, bool affNom){

    if(affNom){
    //    x-=wElement;
    }

    if(this->estVert())
        painter->setPen(QColor(0,255,0));
    else
        painter->setPen(QColor(255,0,0));
    if(affNom)
        painter->drawLine(x-wElement-1, y-hElement, x-1-wElement, y);
    else
        painter->drawLine(x, y, x, y-hElement);
    painter->setPen(QColor(0,0,0));

    painter->fillRect(x-wElement,y-hElement,wElement, hElement, QBrush(QColor(0,0,255)));
    if(affNom==true){
        painter->translate(x, y-(2*hElement));
        painter->rotate(-45);
        QFont font(QString("Helvetica"));
        font.setBold(true);
        font.setPixelSize(20);
        painter->setFont(font);
        painter->drawText(0, 0, this->nom);

        font.setPixelSize(10);

        painter->setFont(font);
        painter->drawText(0, 10,QString::number(this->listePassager.size()));
        painter->rotate(+45);
        painter->translate(-x, -(y-(2*hElement)));
    }else{

    QFont font2(QString("Helvetica"));
    font2.setBold(true);
    font2.setPixelSize(10);
    QString nb();

    painter->setFont(font2);
    painter->drawText(x-wElement+1, y+hElement-2,QString::number(this->listePassager.size()));
}

}

QString Station::getNom(){
    return this->nom;
}

Ligne * Station::getLigne(){
    return this->maligne;
}

void Station::setPassagers(){
    int nbPassager = rand()%(NBMAXPASSAGERSTATION + 1);
    if((nbPassager + this->listePassager.size()) > NBMAXPASSAGERSTATION){
        nbPassager = NBMAXPASSAGERSTATION;
    }
    for(int i=0; i < nbPassager; i++){
        //Indice aleatoire de la station destination
        int indice = rand()%(this->maligne->getStations()->size());
        //Verifie si station destion != station en cours
        while(this->maligne->getStations()->at(indice)->getNom() == this->nom){
            indice = rand()%(this->maligne->getStations()->size());
        }
        //Ajout du passager à la station
        this->listePassager.push_back(new Passager (this->maligne->getStations()->at(indice)));
    }
}
