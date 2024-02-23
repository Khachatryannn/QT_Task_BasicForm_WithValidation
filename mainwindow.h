#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFont>


class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void displayInformation();

private:
    QLabel nameLabel;
    QLineEdit nameLineEdit;
    QLabel surnameLabel;
    QLineEdit surnameLineEdit;
    QLabel ageLabel;
    QLineEdit ageLineEdit;
    QLabel emailLabel;
    QLineEdit emailLineEdit;
    QLabel phoneLabel;
    QLineEdit phoneLineEdit;
    QFont Font;

    QPushButton displayButton;
    QLabel displayLabel;
};



#endif // MAINWINDOW_H
