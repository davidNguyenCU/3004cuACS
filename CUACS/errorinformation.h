#ifndef ERRORINFORMATION_H
#define ERRORINFORMATION_H

#include <QDialog>

namespace Ui {
class errorInformation;
}

class errorInformation : public QDialog
{
    Q_OBJECT

public:
    explicit errorInformation(QString str, QWidget *parent = 0);
    ~errorInformation();

private:
    Ui::errorInformation *ui;
};

#endif // ERRORINFORMATION_H
