#include "gui.h"
#include "ui_gui.h"
#include <QFileDialog>
#include <QMessageBox>

GUI::GUI( QWidget *parent ) :
	QMainWindow( parent ),
	ui( new Ui::GUI )
{
	ui->setupUi( this );
	setupConnections();
}

GUI::~GUI()
{
	delete ui;
}

void GUI::setupConnections()
{
	QObject::connect( ui->actionQuit, &QAction::triggered, this, &GUI::onQuitClicked );
	QObject::connect( ui->actionWizard, &QAction::triggered, this, &GUI::onSelectWizard );
	QObject::connect( ui->actionAbout_ProjectWizard, &QAction::triggered, this, &GUI::onAboutClicked );
}

void GUI::onQuitClicked()
{
	close();
}

void GUI::onSelectWizard()
{
	QFileInfo fi = QFileDialog::getOpenFileName( this, "Select project wizard" );

	if( !fi.isFile() )
		ui->statusBar->showMessage( "You not select file!" );
}

void GUI::onAboutClicked()
{
	QMessageBox msg;
	msg.setWindowTitle( "About" );
	msg.setText( "The GUI frontend for library ProjectWizard.\n\nAuthor: SR_team" );
	msg.exec();
}
