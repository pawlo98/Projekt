#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButtonL_clicked();
    void on_pushButtonR_clicked();

    void handleButtonClick();
    void changeContent(const QString &buttonName);

    void handleLabelClick();
    void changeContentForBRW(const QString &labelName);

private:
    Ui::MainWindow *ui;
    QLabel *background;
    QWidget *screenWidget;

    int slideNumber = 0;
    int slideMax = 5;

    void clearLayout(QLayout *layout);

    void homeScreenLoad(QVBoxLayout *newLayout); //slider 2 funkcje
    void testScreenLoad(QVBoxLayout *newLayout);

    int optionNumber = 0;

    void chartsLoad(QVBoxLayout *newLayout); //te 3 dolne to są dolny widget
    void testBRWLoad(QVBoxLayout *newLayout);
    void testBRW2Load(QVBoxLayout *newLayout); //tutaj nowe funkcje

protected:
    void resizeEvent(QResizeEvent *event) override;
};


#endif // MAINWINDOW_H
