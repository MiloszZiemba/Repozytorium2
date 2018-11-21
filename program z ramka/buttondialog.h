#ifndef BUTTONDIALOG_H
#define BUTTONDIALOG_H

#include <QDialog>

namespace Ui {
class ButtonDialog;
}

class ButtonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ButtonDialog(QWidget *parent = nullptr);
    ~ButtonDialog();

private:
    Ui::ButtonDialog *ui;
};

#endif // BUTTONDIALOG_H
