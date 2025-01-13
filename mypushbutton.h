#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton {
    Q_OBJECT

public:
    explicit MyPushButton(QWidget *parent = nullptr);

signals:
   // void toggleStateChanged(bool isTextVisible);

protected:
   // void mousePressEvent(QMouseEvent *event) override;

private:
    //bool isTextVisible = false;
};

#endif // MYPUSHBUTTON_H
