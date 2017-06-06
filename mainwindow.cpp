#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

#include <QDebug>

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

void MainWindow::setAverage()
{
	if(ui->checkBox->isChecked()){ //8 HWs
		if (ui->checkBox_2->isChecked()) //schema B
			emit averageChanged((((ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()+ui->spinBox_4->value()+ui->spinBox_5->value()+ui->spinBox_6->value()+ui->spinBox_7->value()+ui->spinBox_8->value())*(0.25/8))+(std::max(ui->spinBox_9->value(), ui->spinBox_10->value())*0.3)+(ui->spinBox_11->value()*0.44)));
	else //schema A
			emit averageChanged((((ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()+ui->spinBox_4->value()+ui->spinBox_5->value()+ui->spinBox_6->value()+ui->spinBox_7->value()+ui->spinBox_8->value())*(0.25/8))+((ui->spinBox_9->value()+ui->spinBox_10->value())*0.2)+(ui->spinBox_11->value()*0.35)));
	}
	else{ //7 HWs
		if (ui->checkBox_2->isChecked()) //schema B
			emit averageChanged((((ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()+ui->spinBox_4->value()+ui->spinBox_5->value()+ui->spinBox_6->value()+ui->spinBox_7->value())*(0.25/7))+(std::max(ui->spinBox_9->value(), ui->spinBox_10->value())*0.3)+(ui->spinBox_11->value()*0.44)));
		else //schema A
			emit averageChanged((((ui->spinBox->value()+ui->spinBox_2->value()+ui->spinBox_3->value()+ui->spinBox_4->value()+ui->spinBox_5->value()+ui->spinBox_6->value()+ui->spinBox_7->value())*(0.25/7))+((ui->spinBox_9->value()+ui->spinBox_10->value())*0.2)+(ui->spinBox_11->value()*0.35)));
	}
}
