#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    nameLabel("Enter Name:"),
    surnameLabel("Enter Surname:"),
    ageLabel("Enter Age:"),
    emailLabel("Enter Email:"),
    phoneLabel("Enter Phone:"),
    displayButton("Click to display the info!"),
    displayLabel()
{
    setWindowTitle("User Information's Form");

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(&nameLabel, &nameLineEdit);
    formLayout->addRow(&surnameLabel, &surnameLineEdit);
    formLayout->addRow(&ageLabel, &ageLineEdit);
    formLayout->addRow(&emailLabel, &emailLineEdit);
    formLayout->addRow(&phoneLabel, &phoneLineEdit);

    connect(&displayButton, &QPushButton::clicked, this, &MainWindow::displayInformation);

    QVBoxLayout *ButtonLayout = new QVBoxLayout;
    ButtonLayout->addWidget(&displayButton);
    ButtonLayout->addWidget(&displayLabel);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(ButtonLayout);

    setLayout(mainLayout);
}

void MainWindow::displayInformation() {
    QString displayText =  "Enter Name: " + nameLineEdit.text() + "\n" +
                          "Enter Surname: " + surnameLineEdit.text() + "\n" +
                          "Enter Age: " + ageLineEdit.text() + "\n" +
                          "Enter Email: " + emailLineEdit.text() + "\n" +
                          "Enter Phone: " + phoneLineEdit.text();
    displayLabel.setText(displayText);
}








