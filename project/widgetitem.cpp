#include "widgetitem.h"
#include "ui_widgetitem.h"
#include <QString>
#include <QPixmap>
#include <QFileInfo>
#include <QDateTime>
#include <QWidget>
#include <QSize>
#include <QBitmap>
WidgetItem::WidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetItem)
{
    ui->setupUi(this);

}
void WidgetItem::setfile_name(QString name){
    ui->label_3->setText(name);
}

void WidgetItem::setfile_date(QString date){
    ui->label_4->setText(date);
}
void WidgetItem::setfile_image(QString path){

    QPixmap pixmap(path);
    ui->label_2->setPixmap(pixmap);
    //ui->label_2->setMask(pixmap.mask());
    //ui->label_2->setMaximumWidth(60);
   // ui->label_2->setMaximumHeight(60);

}
QString WidgetItem::get_file_name(){
    return ui->label_3->text();
}
WidgetItem::~WidgetItem()
{
    delete ui;
}
