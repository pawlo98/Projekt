#ifndef OPTIONLABEL_H
#define OPTIONLABEL_H

#include <QLabel>
#include <QMouseEvent>

class OptionLabel : public QLabel {
    Q_OBJECT

public:
    explicit OptionLabel(QWidget *parent = nullptr);

signals:
        void clicked(const QString &text);

protected:
        void mousePressEvent(QMouseEvent *event) override;

private:
        bool isActive = false;
};


#endif // OPTIONLABEL_H
