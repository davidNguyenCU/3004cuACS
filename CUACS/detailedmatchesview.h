#ifndef DETAILEDMATCHESVIEW_H
#define DETAILEDMATCHESVIEW_H

#include <QDialog>
#include <vector>
#include "animal.h"
#include "client.h"
#include "ACM.h"
#include <QTableWidget>

namespace Ui {
class DetailedMatchesView;
}

class DetailedMatchesView : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedMatchesView(QWidget *parent = 0);
    ~DetailedMatchesView();
    void setMatches(vector<std::pair<Client, Animal>>, vector<Client> nonMatches);
    void setIndex(int);
private slots:
    void on_previousBtn_clicked();

    void on_nextBtn_clicked();

private:
    void update();
    Ui::DetailedMatchesView *ui;
    vector<std::pair<Client, Animal>> matches;
    vector<Client> nonMatches;
    QTableWidget *table;
    int index;
};

#endif // DETAILEDMATCHESVIEW_H
