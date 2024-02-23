#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>



class UserInformationForm : public QWidget {
public:
    UserInformationForm(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("User Information's Form");


        //labels and labelLineEdits-ները
        QLabel *nameLabel = createLabel("Enter Name:");
        QLabel *surnameLabel= createLabel("Enter Surname:");
        QLabel *ageLabel = createLabel("Enter Age:");
        QLabel *emailLabel = createLabel("Enter Email:");
        QLabel *phoneLabel = createLabel("Enter Phone:");

        // layout-ը
        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow(nameLabel , &nameLineEdit);
        formLayout->addRow(surnameLabel, &surnameLineEdit);
        formLayout->addRow(ageLabel, &ageLineEdit);
        formLayout->addRow(emailLabel, &emailLineEdit);
        formLayout->addRow(phoneLabel, &phoneLineEdit);


        QPushButton *displayButton = new QPushButton("Click to display the info!");


        displayButton->setFont(QFont("Arial", 20));
        displayButton->setStyleSheet("color: blue");

        displayLabel.setAlignment(Qt::AlignLeft | Qt::AlignTop);

        QVBoxLayout *ButtonLayout = new QVBoxLayout;
        ButtonLayout->addWidget(displayButton);
        ButtonLayout->addWidget(&displayLabel);

        QHBoxLayout *mainLayout = new QHBoxLayout;
        mainLayout->addLayout(formLayout);
        mainLayout->addLayout(ButtonLayout);

        setLayout(mainLayout);

        connect(displayButton, &QPushButton::clicked, this, &UserInformationForm::checkAndDisplayInformation);
    }

private:
    QLabel* createLabel(const QString& text) {
        QLabel* label = new QLabel(text);
        QFont font = label->font();
        font.setPointSize(15);
        label->setFont(font);
        label->setStyleSheet("color: red");
        return label;
    }

    void displayInformation() {
        QString displayText = "Enter Name:" + nameLineEdit.text() + "\n" +
                              "Enter Surname:" + surnameLineEdit.text()  + "\n" +
                              "Enter Age:"   + ageLineEdit.text() + "\n" +
                              "Enter Email:" + emailLineEdit.text() + "\n" +
                              "Enter Phone:" + phoneLineEdit.text();
        displayLabel.setText(displayText);
    }

    void checkAndDisplayInformation() {
        if (nameLineEdit.text().isEmpty() ||
            surnameLineEdit.text().isEmpty() ||
            ageLineEdit.text().isEmpty() ||
            emailLineEdit.text().isEmpty() ||
            phoneLineEdit.text().isEmpty()) {
            QMessageBox::warning(this,"Error", "All fields are required! Please fill all the required fields.");
        } else {
            QMessageBox::information(this,"Information", "Information input was successful!");
            displayInformation();
        }
    }

    QLineEdit nameLineEdit;
    QLineEdit surnameLineEdit;
    QLineEdit ageLineEdit;
    QLineEdit emailLineEdit;
    QLineEdit phoneLineEdit;

    QLabel displayLabel;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    UserInformationForm form;
    form.show();

    return app.exec();
}

