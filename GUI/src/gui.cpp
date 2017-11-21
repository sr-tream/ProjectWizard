#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
	setupConnections();
}

GUI::~GUI()
{
    delete ui;
}

void GUI::setupConnections()
{
	QObject::connect(ui->actionQuit, &QAction::triggered, this, &GUI::onQuitClicked);
}

void GUI::onQuitClicked()
{
	close();
}
