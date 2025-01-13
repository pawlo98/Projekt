#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "curlmain.h"
#include "databasemain.h"


#include <QPixmap>
#include <QPainter>

QPixmap addTransparencyToPixmap(const QPixmap &pixmap, int alpha) {
    if (pixmap.isNull()) {
        return QPixmap();
    }

    // Create a transparent pixmap with the same size as the original
    QPixmap transparentPixmap(pixmap.size());
    transparentPixmap.fill(Qt::transparent); // Ensure it's fully transparent

    // Use QPainter to apply the transparency
    QPainter painter(&transparentPixmap);
    painter.setOpacity(alpha / 255.0); // Apply the transparency (0-255)
    painter.drawPixmap(0, 0, pixmap);
    painter.end();

    return transparentPixmap;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , background(nullptr)
{
    ui->setupUi(this);

    QString rootDirectory ="C:/Users/kamil/Desktop/PROJEKT ICE ARROW/project";

    /////////////////////////////////////////
    // SET STRETCH FACTOR ON BOTTOM WIDGET //
    /////////////////////////////////////////

    QWidget *bottomWidget = ui->bottomwidget;
    QHBoxLayout *layoutB = qobject_cast<QHBoxLayout*>(bottomWidget->layout());

    QWidget *widget_8 = ui->bottomleftwidget;
    QWidget *widget_10 = ui->bottomrightwidget;

    layoutB->setStretchFactor(widget_8, 3);
    layoutB->setStretchFactor(widget_10, 7);

    /////////////////////////////////////////
    // SET STRETCH FACTOR ON MAIN WIDGET //
    /////////////////////////////////////////

    QWidget *mainWidget = ui->mainwidget;
    QHBoxLayout *layoutM = qobject_cast<QHBoxLayout*>(mainWidget->layout());

    QWidget *widget = ui->buttonwidgetl;
    QWidget *widget_2 = ui->screenwidget;
    QWidget *widget_3 = ui->buttonwidgetr;

    layoutM->setStretchFactor(widget, 2);
    layoutM->setStretchFactor(widget_2, 6);
    layoutM->setStretchFactor(widget_3, 2);


    //////////////////////////////////////////////
    // SET BACAKGROUND IMAGE ON MAIN WIDGET //
    //////////////////////////////////////////////


    // QString MainWidgetImagePath = rootDirectory + "/images/body1.png";
    // QPixmap Mpixmap(MainWidgetImagePath);
    // imageWidget->setImage(Mpixmap);
    // imageWidget->setTransparency(200); // Semi-transparent

    //////////////////////////////////////////////
    // SET BACAKGROUND IMAGE FOR CENTRAL WIDGET //
    //////////////////////////////////////////////


    // std::string rootDirectory = ROOT_DIR;
    // std::string fullPath = std::string(rootDirectory) + "/db/creadentials.txt";
    // std::ifstream inputFile(fullPath.c_str());

    QString backgroundImagePath = rootDirectory + "/images/walp1.jpg";
    QPixmap Bpixmap(backgroundImagePath);

    if (!Bpixmap.isNull()) {
        background = new QLabel(ui->centralwidget);
        background->setPixmap(Bpixmap);
        background->setScaledContents(true);
        background->resize(ui->centralwidget->size());
        background->lower();  // Ensure it is behind other widgets
    } else {
        qDebug() << "Image not found at:" << backgroundImagePath;
    }







    ///////////////////////////////
    // SET IMAGE ON RIGHT BUTTON //
    ///////////////////////////////

    QString PushButtonRImagePath = rootDirectory + "/images/img5.png";

    ui->pushButtonR->setIcon(QIcon(PushButtonRImagePath));
    ui->pushButtonR->setIconSize(QSize(100, 100));
    ui->pushButtonR->setStyleSheet("QPushButton { border: none; background: none; }");
    ui->pushButtonR->resize(ui->centralwidget->size());



    ///////////////////////////////
    // SET IMAGE ON LEFT BUTTON  //
    ///////////////////////////////


    QString PushButtonLImagePath = rootDirectory + "/images/img6.png";

    ui->pushButtonL->setIcon(QIcon(PushButtonLImagePath));
    ui->pushButtonL->setIconSize(QSize(100, 100));
    ui->pushButtonL->setStyleSheet("QPushButton { border: none; background: none; }");

    ////////////////////////
    // CONNECTING SIGNALS //
    ////////////////////////

    connect(ui->pushButtonR, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->pushButtonL, &QPushButton::clicked, this, &MainWindow::handleButtonClick);

    connect(ui->label_5, &OptionLabel::clicked, this, &MainWindow::handleLabelClick);
    connect(ui->label_6, &OptionLabel::clicked, this, &MainWindow::handleLabelClick);
    connect(ui->label_7, &OptionLabel::clicked, this, &MainWindow::handleLabelClick);


    ///////////////////////
    // LOAD START SCREEN //
    ///////////////////////

    nlohmann::json response = getResponse();

    ui->label_2->setStyleSheet("QLabel { color: red; background:none; border: none; }");
    ui->label_3->setStyleSheet("QLabel { color: red; background:none; border: none; }");
    ui->label_4->setStyleSheet("QLabel { color: red; background:none; border: none; }");

    if (response.empty()) {
        ui->label_2->setText("API: Offline");

        ui->label_3->setText("Household connection: Offline");
    }
    else
    {
        ui->label_2->setText("API: Online");
        ui->label_3->setText("Household connection: Online");
        ui->label_2->setStyleSheet("QLabel { color: green; background:none; border: none; }");
        ui->label_3->setStyleSheet("QLabel { color: green; background:none; border: none; }");
    }

    if (connectToDatabase()) {
        ui->label_4->setText("Database connection: Online");
        ui->label_4->setStyleSheet("QLabel { color: green; background:none; border: none; }");
    }
    else
    {
        ui->label_4->setText("Database connection: Offline");
    }


}


void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);  // Call base class implementation
    if (background) {
        background->resize(ui->centralwidget->size());  // Resize the QLabel
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonR_clicked()
{
    // nlohmann::json response = getResponse();

    // if (!response.empty()) {
    //     int temp = response["main"]["temp"];
    //     std::string clouds = response["weather"][0]["description"];

    //     std::string textBlock = "";
    //     textBlock = "Temperature: " + std::to_string(temp) + " K\n" + "Clouds description: " + clouds;


    //     ui->label_2->setText(textBlock.c_str());
    // }







}


void MainWindow::on_pushButtonL_clicked()
{
    // qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    // std::string textBlock = "";
    // std::string textStart = "Data from database:\n\n";
    // int integerFetch1;
    // QString textFetch2Q = "";

    // std::string textFetch2 = "";

    // if (connectToDatabase()) {
    //     QSqlQuery query;
    //     if (!query.exec("SELECT id, name FROM person")) {
    //         qDebug() << "Query execution failed:" << query.lastError().text();
    //     } else {

    //         while (query.next()) {
    //             integerFetch1 = query.value(0).toInt();

    //             textFetch2Q = query.value(1).toString();
    //             textFetch2 = textFetch2Q.toStdString();

    //         }
    //     }
    // }

    // textBlock = textStart + "ID: " + std::to_string(integerFetch1) + "\n" + "Name: " + textFetch2;
    // ui->label_3->setText(textBlock.c_str());
}

void MainWindow::handleButtonClick() {

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString buttonName = button->objectName(); // Get the button's name
        changeContent(buttonName);
    }

}

void MainWindow::changeContent(const QString &buttonName) {

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->screenwidget);
    ui->screenwidget->setGraphicsEffect(opacityEffect);

    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(500); // 500 ms duration
    animation->setStartValue(1.0); // Fully visible
    animation->setEndValue(0.0); // Fully transparent
    connect(animation, &QPropertyAnimation::finished, [this, buttonName]() {
        // Change content after fade-out animation
        if (ui->screenwidget->layout()) {
            clearLayout(ui->screenwidget->layout());
        }

        QVBoxLayout *newLayout = new QVBoxLayout();



        if (buttonName == "pushButtonR") {
            slideNumber ++;
            if (slideNumber > slideMax)
            {
                slideNumber = 0;
            }
            // Content for pushButtonR
            // newLayout->addWidget(new QLabel("Right Widget 1"));
            // newLayout->addWidget(new QLabel("Right Widget 2"));
        } else if (buttonName == "pushButtonL") {
            slideNumber --;
            if (slideNumber < 0)
            {
                slideNumber = slideMax;
            }
            // Content for pushButtonL
            // newLayout->addWidget(new QLabel("Left Widget 1"));
            // newLayout->addWidget(new QLabel("Left Widget 2"));
        }

        qDebug() << slideNumber;

        switch (slideNumber) {
        case 0:
        {
            homeScreenLoad(newLayout);
        } break;
        case 1:
        {
            testScreenLoad(newLayout);
        } break;

        default:
            break;
        }

        ui->screenwidget->setLayout(newLayout);


        // Apply fade-in animation to widget_3
        QGraphicsOpacityEffect *opacityEffect = qobject_cast<QGraphicsOpacityEffect *>(ui->screenwidget->graphicsEffect());
        if (!opacityEffect) {
            opacityEffect = new QGraphicsOpacityEffect(ui->screenwidget);
            ui->screenwidget->setGraphicsEffect(opacityEffect);
        }
        QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0); // Fully transparent
        animation->setEndValue(1.0); // Fully visible
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void MainWindow::clearLayout(QLayout *layout) {
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
        delete layout;
    }
}


void MainWindow::handleLabelClick()
{
    QLabel *label = qobject_cast<QLabel *>(sender());
    if (label) {
        QString labelName = label->objectName();
        changeContentForBRW(labelName);
    }
}

void MainWindow::changeContentForBRW(const QString &labelName) {

    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(ui->screenwidget);
    ui->bottomrightwidget->setGraphicsEffect(opacityEffect);

    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(500); // 500 ms duration
    animation->setStartValue(1.0); // Fully visible
    animation->setEndValue(0.0); // Fully transparent
    connect(animation, &QPropertyAnimation::finished, [this, labelName]() {
        // Change content after fade-out animation
        if (ui->bottomrightwidget->layout()) {
            clearLayout(ui->bottomrightwidget->layout());
        }

        QVBoxLayout *newLayout = new QVBoxLayout();



        if (labelName == "label_5") {
            optionNumber = 0;
           // Content for pushButtonR
        } else if (labelName == "label_6") {
            optionNumber = 1;
           // Content for pushButtonL
        } else if (labelName == "label_7") {
            optionNumber = 2;
        }


        qDebug() << optionNumber;

        switch (optionNumber) {
        case 0:
        {
            testBRWLoad(newLayout);
        } break;
        case 1:
        {
            testBRW2Load(newLayout);
        } break;
        case 2:
        {
            chartsLoad(newLayout);
        } break;

        default:
            break;
        }

        ui->bottomrightwidget->setLayout(newLayout);


        // Apply fade-in animation to widget_3
        QGraphicsOpacityEffect *opacityEffect = qobject_cast<QGraphicsOpacityEffect *>(ui->bottomrightwidget->graphicsEffect());
        if (!opacityEffect) {
            opacityEffect = new QGraphicsOpacityEffect(ui->screenwidget);
            ui->bottomrightwidget->setGraphicsEffect(opacityEffect);
        }
        QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0); // Fully transparent
        animation->setEndValue(1.0); // Fully visible
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    });
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}


void MainWindow::homeScreenLoad(QVBoxLayout *newLayout)
{
    nlohmann::json response = getResponse();

    QLabel *label_1 = new QLabel();
    label_1->setObjectName("label_1");
    newLayout->addWidget(label_1);

    QLabel *label_2 = new QLabel();
    label_2->setObjectName("label_2");
    newLayout->addWidget(label_2);

    QLabel *label_3 = new QLabel();
    label_3->setObjectName("label_3");
    newLayout->addWidget(label_3);

    QLabel *label_4 = new QLabel();
    label_4->setObjectName("label_4");
    newLayout->addWidget(label_4);

    label_1->setStyleSheet("QLabel { color: white; background:none; border: none; }");
    label_1->setAlignment(Qt::AlignCenter);
    label_1->setText("Home Screen");

    label_2->setStyleSheet("QLabel { color: red; background:none; border: none; }");
    label_3->setStyleSheet("QLabel { color: red; background:none; border: none; }");
    label_4->setStyleSheet("QLabel { color: red; background:none; border: none; }");

    if (response.empty()) {
        label_2->setText("API: Offline");

        label_3->setText("Household connection: Offline");
    }
    else
    {
        label_2->setText("API: Online");
        label_3->setText("Household connection: Online");
        label_2->setStyleSheet("QLabel { color: green; background:none; border: none; }");
        label_3->setStyleSheet("QLabel { color: green; background:none; border: none; }");
    }

    if (connectToDatabase()) {
        label_4->setText("Database connection: Online");
        label_4->setStyleSheet("QLabel { color: green; background:none; border: none; }");
    }
    else
    {
        label_4->setText("Database connection: Offline");
    }
}

void MainWindow::testScreenLoad(QVBoxLayout *newLayout)
{
    QLabel *label_T = new QLabel("asd");
    label_T->setObjectName("label_T");
    newLayout->addWidget(label_T);
}


void MainWindow::testBRWLoad(QVBoxLayout *newLayout)
{
    QLabel *label_T = new QLabel("asd");
    label_T->setObjectName("label_T");
    newLayout->addWidget(label_T);
}

void MainWindow::testBRW2Load(QVBoxLayout *newLayout)
{
    QLabel *label_T = new QLabel("asd");
    label_T->setObjectName("label_T");
    newLayout->addWidget(label_T);
}

void MainWindow::chartsLoad(QVBoxLayout *newLayout)
{
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    int integerFetch1;

    std::string selectQuery = "SELECT produced_energy FROM energy_production LIMIT 24";

    QLineSeries *series = new QLineSeries();
    if (connectToDatabase()) {
        QSqlQuery query;
        if (!query.exec(selectQuery.c_str())) {
            qDebug() << "Query execution failed:" << query.lastError().text();
        } else {

            int i = 0;
            while (query.next()) {
                integerFetch1 = query.value(0).toInt();
                series->append(i, integerFetch1);
                i ++;

                // textFetch2Q = query.value(1).toString();
                // textFetch2 = textFetch2Q.toStdString();

            }
        }
    }

    // textBlock = textStart + "ID: " + std::to_string(integerFetch1) + "\n" + "Name: " + textFetch2;
    // ui->label_3->setText(textBlock.c_str());




    // Create a chart and chart view
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

  //  chartView->setAlignment(Qt::AlignCenter);
    // Add chart view to the layout

    newLayout->addWidget(chartView);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    chartView->resize(400, 300); // Default size

  //  parent->setLayout(layout);
}
