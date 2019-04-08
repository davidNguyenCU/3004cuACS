#include "detailedmatchesview.h"
#include "ui_detailedmatchesview.h"
#include "ACM.h"
#include <QDialog>
#include <vector>

DetailedMatchesView::DetailedMatchesView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailedMatchesView)
{
    ui->setupUi(this);
    index = 0;
}

DetailedMatchesView::~DetailedMatchesView(){
    delete ui;
}

void DetailedMatchesView::setIndex(int i){index = 1;}

void DetailedMatchesView::setMatches(vector<std::pair<Client, Animal>> m){
    matches = m;
    if(matches.size()!=0){update();}
}

void DetailedMatchesView::on_nextBtn_clicked(){
    if(index == (matches.size()-1)){
            index = 0;
        }else{
            index+=1;
        }
        update();
}

void DetailedMatchesView::on_previousBtn_clicked()
{
    if(index == 0){
        index = matches.size()-1;
    }else{
        index-=1;
    }
    update();
}

void DetailedMatchesView::update(){
    std::pair<Client, Animal> currentPair = matches.at(index);
    ui->clientName->setText(currentPair.first.getFirstName() + " " + currentPair.first.getLastName());
    ui->clientBehavePref->setText(QString::number(currentPair.first.getBehaviour()));
    /*ui->clientControlPref->setText(currentPair.first.getOwnerControl());
    ui->clientSocialPref->setText(currentPair.first.getSociability());

    ui->clientChildPref->setText(currentPair.first.getChildFriendly());
    ui->clientStrangePref->setText(currentPair.first.getStrangerFriendly());

    ui->behaveRank->setText(currentPair.first.getBehaveRank());
    ui->controlRank->setText(currentPair.first.getOwnerRank());
    ui->socialRank->setText(currentPair.first.getSocialRank());

    ui->animalName->setText(currentPair.second.getName());
    ui->animalStrangePref->setText(currentPair.second.getStrangerFriendly());
    ui->animalChildPref->setText(currentPair.second.getChildFriendly());

    ui->trainability->setText(currentPair.second.getTrainability());
    ui->intelligence->setText(currentPair.second.getIntelligence());
    ui->obedience->setText(currentPair.second.getObedience());
    QString gargantuan = currentPair.second.getTrainability() + ' ' + currentPair.second.getIntelligence() + ' ' + currentPair.second.getObedience() + ") /30 = ";
    //(currentPair.second.getTrainability()+currentPair.second.getIntelligence()+currentPair.second.getObedience())/30.0
    ui->controlScore->setText(gargantuan);*/

}
