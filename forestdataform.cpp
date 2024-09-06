#include "forestdataform.h"

ForestDataForm::ForestDataForm(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *layout1 = new QVBoxLayout(this);
    QLabel *label1 = new QLabel("This is View 1", this);
    layout1->addWidget(label1);
    setLayout(layout1);

}
