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

void DetailedMatchesView::setIndex(int i){index = i;}

void DetailedMatchesView::setMatches(vector<std::pair<Client, Animal>> m, vector<Client> nm){
    matches = m;
    nonMatches = nm;

    if(matches.size() != 0 && nonMatches.size() != 0){
        if(index < matches.size()){ //check if match or non-match is being displayed
            update(true);
        }else{
            update(false);
        }
    }
}

void DetailedMatchesView::on_nextBtn_clicked(){
    if(index == (matches.size() + nonMatches.size() - 1)){
         index = 0;
    }else{
        index += 1;
    }

    if(index < matches.size()){ //check if match or non-match is being displayed
        update(true);
    }else{
        update(false);
    }
}

void DetailedMatchesView::on_previousBtn_clicked()
{
    if(index == 0){
        index = matches.size() + nonMatches.size() - 1;
    }else{
        index -= 1;
    }

    if(index < matches.size()){ //check if match or non-match is being displayed
        update(true);
    }else{
        update(false);
    }
}

void DetailedMatchesView::update(bool isMatch){
    if(isMatch){
        ui->matchFrame->setVisible(true);  //set nonMatch frame invisible and match visible
        ui->nonMatchFrame->setVisible(false);
        std::pair<Client, Animal> currentPair = matches.at(index);
        ui->clientName->setText(currentPair.first.getFirstName() + " " + currentPair.first.getLastName());
        ui->clientBehavePref->setText(QString::number(currentPair.first.getBehaviour()));
        ui->clientControlPref->setText(QString::number(currentPair.first.getOwnerControl()));
        ui->clientSocialPref->setText(QString::number(currentPair.first.getSociability()));
        ui->clientChildPref->setText(QString::number(currentPair.first.getChildFriendly()));
        ui->clientStrangePref->setText(QString::number(currentPair.first.getStrangerFriendly()));

        ui->behaveRank->setText(QString::number(currentPair.first.getBehaveRank()));
        ui->controlRank->setText(QString::number(currentPair.first.getOwnerRank()));
        ui->socialRank->setText(QString::number(currentPair.first.getSocialRank()));

        ui->animalName->setText(currentPair.second.getName());
        ui->animalStrangePref->setText(QString::number(currentPair.second.getStrangerFriendly()));
        ui->animalChildPref->setText(QString::number(currentPair.second.getChildFriendly()));

        ui->trainability->setText(QString::number(currentPair.second.getTrainability()));
        ui->intelligence->setText(QString::number(currentPair.second.getIntelligence()));
        ui->obedience->setText(QString::number(currentPair.second.getObedience()));

        QString gargantuan ='('+
        QString::number(currentPair.second.getTrainability()) + "+" +
        QString::number(currentPair.second.getIntelligence()) + "+" +
        QString::number(currentPair.second.getObedience()) + ")/30 =~" +
        QString::number((int)(((currentPair.second.getTrainability()+currentPair.second.getIntelligence()+currentPair.second.getObedience())/30.0)*100.0f))
        +'%';
        ui->controlScore->setText(gargantuan);
        ui->controlCI->setText("100%-|"+
        QString::number((int)((currentPair.first.getOwnerControl())*10.0f)) +"%-"+
        QString::number((int)(((currentPair.second.getTrainability()+currentPair.second.getIntelligence()+currentPair.second.getObedience())/30.0)*100.0f))
        +"%|=~"+
        QString::number(100-abs(((int)((currentPair.first.getOwnerControl())*10.0f))-((int)(((currentPair.second.getTrainability()+currentPair.second.getIntelligence()+currentPair.second.getObedience())/30.0)*100.0f))))
        +'%');

      ui->sociability->setText(QString::number(currentPair.second.getSocialAttitutde()));
      ui->playfulness->setText(QString::number(currentPair.second.getPlayfulness()));
      ui->energy->setText(QString::number(currentPair.second.getEnergy()));
      ui->independence->setText(QString::number(currentPair.second.getIndependence()));
      QString gargantuan2 ='('+
      QString::number(currentPair.second.getSocialAttitutde()) + "+" +
      QString::number(currentPair.second.getPlayfulness()) + "+" +
      QString::number(currentPair.second.getEnergy()) + "+" +
      QString::number(currentPair.second.getIndependence()) + ")/40 =~" +
      QString::number((int)(((currentPair.second.getSocialAttitutde()+currentPair.second.getPlayfulness()+currentPair.second.getEnergy()+currentPair.second.getIndependence())/40.0)*100.0f))
      +'%';
      ui->socialScore->setText(gargantuan2);
      ui->socialCI->setText("100%-|"+
      QString::number((int)((currentPair.first.getSociability())*10.0f)) +"%-"+
      QString::number((int)(((currentPair.second.getSocialAttitutde()+currentPair.second.getPlayfulness()+currentPair.second.getEnergy()+currentPair.second.getIndependence())/40.0)*100.0f))
      +"%|=~"+
      QString::number(100-abs(((int)((currentPair.first.getSociability())*10.0f))-((int)(((currentPair.second.getSocialAttitutde()+currentPair.second.getPlayfulness()+currentPair.second.getEnergy()+currentPair.second.getIndependence())/40.0)*100.0f))))
      +'%');

      ui->tolerance->setText(QString::number(currentPair.second.getPatience()));
      ui->temperament->setText(QString::number(currentPair.second.getTemperament()));
      ui->mischeviousness->setText(QString::number(currentPair.second.getMischievousness()));

      QString gargantuan3 ='('+
      QString::number(currentPair.second.getPatience()) + "+" +
      QString::number(currentPair.second.getTemperament()) + "+" +
      QString::number(currentPair.second.getMischievousness()) + ")/30=~" +
      QString::number((int)(((currentPair.second.getPatience()+currentPair.second.getTemperament()+currentPair.second.getMischievousness())/30.0)*100.0f))
      +'%';
      ui->behaviorScore->setText(gargantuan3);
      ui->behaviorCI->setText("100%-|"+
      QString::number((int)((currentPair.first.getBehaviour())*10.0f)) +'%'+" - "+
      QString::number((int)(((currentPair.second.getPatience()+currentPair.second.getTemperament()+currentPair.second.getMischievousness())/30.0)*100.0f))
      +"%|=~"+
      QString::number(100-abs(((int)((currentPair.first.getBehaviour())*10.0f))-((int)(((currentPair.second.getPatience()+currentPair.second.getTemperament()+currentPair.second.getMischievousness())/30.0)*100.0f))))
      +'%'
    );

      ui->finalCIX->setText(
        "("+QString::number(100-abs(((int)((currentPair.first.getOwnerControl())*10.0f))-((int)(((currentPair.second.getTrainability()+currentPair.second.getIntelligence()+currentPair.second.getObedience())/30.0)*100.0f))))
        +"%)*ControlRank+("+
        QString::number(100-abs(((int)((currentPair.first.getSociability())*10.0f))-((int)(((currentPair.second.getSocialAttitutde()+currentPair.second.getPlayfulness()+currentPair.second.getEnergy()+currentPair.second.getIndependence())/40.0)*100.0f))))
        +"%)*SocialRank+("+
        QString::number(100-abs(((int)((currentPair.first.getBehaviour())*10.0f))-((int)(((currentPair.second.getPatience()+currentPair.second.getTemperament()+currentPair.second.getMischievousness())/30.0)*100.0f))))
        +"%)*BehaviorRank="+
        QString::number((int)((ACM::getCompatibilityIndex(currentPair.second, currentPair.first))*100.0f))+'%'
      );
    }else{
        Client currentClient = nonMatches.at(index - matches.size());
        ui->matchFrame->setVisible(false);  //set nonMatch frame visible and make other frames invisible
        ui->nonMatchFrame->setVisible(true);

        ui->lblClient2->setText("Client: " + currentClient.getFirstName() + " " + currentClient.getLastName());
    }


}
