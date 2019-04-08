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
    ui->clientName->setText(currentPair.first.getFirstName());
}
