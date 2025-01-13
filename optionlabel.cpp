#include "optionlabel.h"

OptionLabel::OptionLabel(QWidget *parent) : QLabel(parent) {}


void OptionLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isActive = !isActive;
        emit clicked(isActive ? "You clicked the image!" : "");

    }
}
