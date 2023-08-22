#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::Clear_value_ui() {
    ui->move_x_value->setValue(0);
    ui->move_y_value->setValue(0);
    ui->move_z_value->setValue(0);

    ui->rotate_x_value->setValue(0);
    ui->rotate_y_value->setValue(0);
    ui->rotate_z_value->setValue(0);

    ui->scale_value->setValue(1);


    ui->move_x_slider->setValue(0);
    ui->move_y_slider->setValue(0);
    ui->move_z_slider->setValue(0);

    ui->rotate_x_slider->setValue(0);
    ui->rotate_y_slider->setValue(0);
    ui->rotate_z_slider->setValue(0);

    ui->scale_slider->setValue(1);

    ui->openGLWidget->geometries->tmp_scale = 1;
    ui->openGLWidget->geometries->tmp_rotate_x = 0;
    ui->openGLWidget->geometries->tmp_rotate_y = 0;
    ui->openGLWidget->geometries->tmp_rotate_z = 0;

    ui->openGLWidget->geometries->tmp_move_x = 0;
    ui->openGLWidget->geometries->tmp_move_y = 0;
    ui->openGLWidget->geometries->tmp_move_z = 0;

    ui->file_name->setText("");
    ui->vertices_name->setText("");
    ui->edges_name->setText("");


}


void MainWindow::on_OPEN_FILE_clicked()
{
    Clear_value_ui();
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "*.obj");

        if (str.length()) {



            ui->openGLWidget->geometries->flag_draw = 1;

            QByteArray barr = str.toLatin1();
            QString alala = (char *) barr.data();


           ui->openGLWidget->geometries->filepath = alala;


           ui->openGLWidget->geometries->parsing();
           ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);

           int vertices_cnt = ui->openGLWidget->geometries->figure.col / 3;
           int edges_cnt = ui->openGLWidget->geometries->figure.col_connect / 4;




           QStringList file_name_split = str.split("/");
           QString file_name = file_name_split.value(file_name_split.length() - 1);


           ui->vertices_name->setText(QString::number(vertices_cnt));
           ui->edges_name->setText(QString::number(edges_cnt));
           ui->file_name->setText(file_name);

        }
}





void MainWindow::on_scale_slider_valueChanged(int value)
{
    double new_value = (double) value / 1000;

    ui->scale_value->setValue(new_value);

    ui->openGLWidget->geometries->scaling(new_value);

    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);



}


void MainWindow::on_rotate_z_slider_valueChanged(int value)
{
    double new_value = (double) value;

    ui->rotate_z_value->setValue(new_value);

    ui->openGLWidget->geometries->rotate(new_value, 'z');
    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);

}


void MainWindow::on_rotate_y_slider_valueChanged(int value)
{
    double new_value = (double) value;

    ui->rotate_y_value->setValue(new_value);


    ui->openGLWidget->geometries->rotate(new_value, 'y');
    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);
}


void MainWindow::on_rotate_x_slider_valueChanged(int value)
{
    double new_value = (double) value;

    ui->rotate_x_value->setValue(new_value);

    ui->openGLWidget->geometries->rotate(new_value, 'x');
    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);
}


void MainWindow::on_move_x_slider_valueChanged(int value)
{
    double new_value = (double) value / 10;

    ui->move_x_value->setValue(new_value);

    ui->openGLWidget->geometries->move(new_value, 'x');


    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);
}


void MainWindow::on_move_y_slider_valueChanged(int value)
{
    float new_value = (float) value / 10;

    ui->move_y_value->setValue(new_value);

    ui->openGLWidget->geometries->move(new_value, 'y');
    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);

}


void MainWindow::on_move_z_slider_valueChanged(int value)
{
    float new_value = (float) value / 10;

    ui->move_z_value->setValue(new_value);

    ui->openGLWidget->geometries->move(new_value, 'z');
    ui->openGLWidget->geometries->drawcube(&ui->openGLWidget->program);

}
