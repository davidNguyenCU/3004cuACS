#ifndef DETAILEDCLIENTVIEW_H
#define DETAILEDCLIENTVIEW_H

#include "client.h"
#include <QDialog>
#include <vector>
namespace Ui {
class DetailedClientView;
}

class DetailedClientView : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedClientView(QWidget *parent = 0);
    ~DetailedClientView();
    void setClients(vector<Client>);
    void setIndex(int i);
private slots:

    void on_nextBtn_clicked();

    void on_previousBtn_clicked();

private:
    Ui::DetailedClientView *ui;
    vector<Client> clients;
    int index;
    void update();
};

#endif // DETAILEDCLIENTVIEW_H
