#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "s21_smart_calc.h"
#ifdef __cplusplus
}
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_reset, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_back, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_raz, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_res, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(digit_numbers()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::digit_numbers() {
    QPushButton * button = (QPushButton *)sender();
    if (button->text() == "C") {
        ui->res_show->setText("");
    } else if (button->text() == "Graph") {
        ui->widget->clearGraphs();
        double xs = ui->lineEdit_xStart->text().toDouble();
        double xe = ui->lineEdit_xEnd->text().toDouble();
        double ys = ui->lineEdit_yStart->text().toDouble();
        double ye = ui->lineEdit_yEnd->text().toDouble();
        ui->widget->xAxis->setRange(xs, xe);
        ui->widget->yAxis->setRange(ys, ye);
        ui->res_show->setText(ui->res_show->text() + "=");
        double xStart = -1000, xStop = 1000, h = 0.1;
        QVector<double> x,y;
        for (; xStart <= xStop; xStart += h) {
            QString input = ui->res_show->text();
            QByteArray res_bit = input.toLocal8Bit();
            char * res_str = res_bit.data();
            int error = 0, enter_arr_c = 0;
            queue_element_t * arr = s21_deicstra_algorithm(res_str, &error, &enter_arr_c, (int)strlen(res_str), xStart);
            double res = 0;
            if (error == 0) {
                res = OPN_alg(arr, enter_arr_c, &error);
                if (error != 0) {
                    ui->res_show->setText("Error!");
                    break;
                }
            } else {
                ui->res_show->setText("Error!");
                break;
            }
            x.push_back(xStart);
            y.push_back(res);
        }
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x,y);
        ui->widget->replot();
    } else if (button->text() == "<-") {
        QString text = ui->res_show->text();
        text.chop(1);
        if (text.isEmpty()) {
            text = "";
        }
        ui->res_show->setText(text);
    } else if (button->text() == "=") {
        double x = ui->lineEdit_x->text().toDouble();
        ui->res_show->setText(ui->res_show->text() + button->text());
        QString input = ui->res_show->text();
        QByteArray res_bit = input.toLocal8Bit();
        char * res_str = res_bit.data();
        int error = 0, enter_arr_c = 0;
        queue_element_t * arr = s21_deicstra_algorithm(res_str, &error, &enter_arr_c, (int)strlen(res_str), x);
        if (error == 0) {
            double res = OPN_alg(arr, enter_arr_c, &error);
            QString string_res = QString::number(res);
            if (error == 0) {
                ui->res_show->setText(string_res);
            } else {
                ui->res_show->setText("Error!");
            }
        } else {
            ui->res_show->setText("Error!");
        }
    } else {
        ui->res_show->setText(ui->res_show->text() + button->text());
        if (button->text() == "cos" || button->text() == "sin" || button->text() == "tan" || button->text() == "acos" || button->text() == "asin" || button->text() == "atan" || button->text() == "sqrt" || button->text() == "ln" || button->text() == "log") {
            ui->res_show->setText(ui->res_show->text() + "(");
        }
    }
}
