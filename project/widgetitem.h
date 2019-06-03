#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QProgressBar>
#include <QLabel>
#include <QWidget>
#include <QLabel>
#include <QString>
namespace Ui {
class WidgetItem;
}

class WidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetItem(QWidget *parent = nullptr);
    ~WidgetItem();


//private:
    Ui::WidgetItem *ui;
    void setfile_name(QString name);
    void setfile_date(QString date);
  void  setfile_image(QString path);
    QString get_file_name();
};

#endif // WIDGETITEM_H
