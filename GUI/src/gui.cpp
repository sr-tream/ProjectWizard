#include "gui.h"
#include "ui_gui.h"
#include <QMessageBox>
#include <QScrollBar>
#include <QRegExp>
#include "../FileMan/cfileini.h"
#include "../main.h"

GUI::GUI( QWidget *parent ) :
	QMainWindow( parent ),
	ui( new Ui::GUI )
{
	ui->setupUi( this );
	setupConnections();

	set = new QSettings( "Prime-Hack", "ProjectWizard", this );

	for( int i = 0; i < set->value( "lastWizards/count" ).toInt(); ++i ) {
		ui->lastWizards->addItem( set->value( "lastWizards/" + QString::number( i ) ).toString() );
	}
	
	lay = new QGridLayout(this);
    ui->scrollAreaWidgetContents->setLayout(lay);
}

GUI::~GUI()
{
	delete ui;
}

bool GUI::event( QEvent *e )
{
	if( e->type() == QEvent::Show ) {
		updateLastWizardScrolls();
	}

	return QMainWindow::event( e );
}

void GUI::closeEvent( QCloseEvent *e )
{
	set->setValue( "lastWizards/count", ui->lastWizards->count() );

	for( int i = 0; i < ui->lastWizards->count(); ++i ) {
		set->setValue( "lastWizards/" + QString::number( i ), ui->lastWizards->item( i )->text() );
	}

	QMainWindow::closeEvent( e );
}

void GUI::setupConnections()
{
	QObject::connect( ui->actionQuit, &QAction::triggered, this, &GUI::onQuitClicked );
	QObject::connect( ui->actionWizard, &QAction::triggered, this, &GUI::onSelectWizard );
	QObject::connect( ui->actionAbout_ProjectWizard, &QAction::triggered, this, &GUI::onAboutClicked );
	QObject::connect( ui->lastWizards, &QListWidget::itemDoubleClicked, this, &GUI::onLastWizardDblClick );
    QObject::connect( ui->create, SIGNAL(clicked()), SLOT(onCreateClicked()) );
}

void GUI::updateLastWizardScrolls()
{
	ui->lastWizards->scrollToBottom();
	QScrollBar *sb = ui->lastWizards->horizontalScrollBar();
	sb->setValue( sb->maximum() );
}

bool GUI::loadWizard( QFileInfo wizard )
{
	CFileIni config(wizard.filePath().toStdString());
	
	if (!wizard.isFile()){
        ui->name->setEnabled(false);
        ui->create->setEnabled(false);
		return false;
    }
	
	// TODO: Файлы хранить в классе, или считывать при создании проекта.
    list_wizard.clear();
    ex_files.clear();
    as_is.clear();
    rename.clear();
    
	list_wizard = make_list_wizard(boost::filesystem::path(wizard.path().toStdString()));
	ex_files = config.array("/exclude");
	as_is = config.array("/AsIs");
	rename = config.array("/rename");
	std::string defName = config.value("/ProjectName");
	
	// TODO: Записать очистить лайоут и записать на него настройки
	ui->name->setText(defName.c_str());
    ui->name->setEnabled(true);
    addVariable("ProjectName", {defName}, "The project name");
    
    if (lay != nullptr){
        clearLayout(lay);
        resetVariables();
        
        // TODO: Закидать сеточку параметрами проекта
        std::deque<std::string> vars = config.array("/variable");
        int row = 0;
        for (auto &var : vars){
            std::string description = config.value(var + "/description");
            std::string defVariant = config.value(var + "/default_variant");
            int input = config.read<int>(var + "/input");
            std::deque<std::string> variants = config.array(var + "/variant");
            if (variants.empty())
                variants.push_back(defVariant);
            
            addVariable(var, variants, description);
            auto label = new QLabel(var.c_str(), this);
            label->setToolTip(description.c_str());
            lay->addWidget(label, row, 0);
            
            if (!input){
                // TODO: QComboBox
                setDefaultVariant(var, variants.size() -1);
                auto combo = new QComboBox(this);
                combo->setObjectName(QString("combo_") + var.c_str());
                for (auto &v : variants)
                    combo->addItem(v.c_str());
                combo->setCurrentText(defVariant.c_str());
                lay->addWidget(combo, row, 1);
            } else {
                // TODO: QLineEdit
                setDefaultVariant(var, 0);
            }
            
            ++row;
        }
    }
	
    ui->create->setEnabled(true);
	return true;
}

std::deque<QFileInfo> GUI::make_list_wizard(const boost::filesystem::path& path)
{
	std::deque<QFileInfo> result;
	boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
	for ( boost::filesystem::directory_iterator itr( path );
		 itr != end_itr;
	++itr )
		 {
			 if ( boost::filesystem::is_directory( *itr ) )
			 {
				 std::deque<QFileInfo> subdir = make_list_wizard( *itr );
				 for (auto file : subdir)
					 result.push_front(file);
			 }
			 result.push_front(QFileInfo((*itr).path().c_str()));
		 }
		 return result;
}

void GUI::clearLayout(QLayout* layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void GUI::onQuitClicked()
{
	close();
}

void GUI::onSelectWizard()
{
	QFileInfo fi = QFileDialog::getOpenFileName( this, "Select project wizard" );

	if( !fi.isFile() ) {
		ui->statusBar->showMessage( "You not select file!", 5000 );
		return;
	}

	// TODO: эта хуйня временная? Переделать? Как минимум не добавлять, если это не визард
	if( loadWizard( fi ) ) {
		ui->lastWizards->addItem( fi.filePath() );
		updateLastWizardScrolls();
	}
	else {
		ui->statusBar->showMessage( "This wizard is garbage", 5000 );
	}
}

void GUI::onAboutClicked()
{
	QMessageBox msg;
	msg.setWindowTitle( "About" );
	msg.setText( "The GUI frontend for library ProjectWizard.\n\nAuthor: SR_team" );
	msg.exec();
}

void GUI::onLastWizardDblClick(QListWidgetItem* item)
{
	if (!loadWizard(item->text()))
		ui->statusBar->showMessage( "This wizard is garbage", 5000 );
}

void GUI::onCreateClicked()
{ // TODO: Убрать сообщения, записать значения из QLineEdit, создать проект по шаблону
	QMessageBox msg;
	msg.setWindowTitle( "onCreateClicked" );
	msg.setText( "DUMMY" );
	msg.exec();
    
    
    for (int i = 0; i < lay->count(); ++i){
        QLayoutItem *item = lay->itemAt(i);
        if (item->widget()) {
            if (!item->widget()->objectName().isEmpty()){
                msg.setText(item->widget()->objectName());
                msg.exec();
                
                QRegExp reCombo(R"(combo_(\w+))", Qt::CaseInsensitive);
                
                if (reCombo.indexIn(item->widget()->objectName()) == 0){
                    msg.setText(((QComboBox*)item->widget())->currentText());
                    msg.exec();
                    
                    std::deque<std::string> variants = getVariants(reCombo.cap(1).toStdString());
                    for (int i = 0; i < variants.size(); ++i){
                        if (variants[i] == ((QComboBox*)item->widget())->currentText().toStdString()){
                            selectVariant(reCombo.cap(1).toStdString(), i);
                            break;
                        }
                    }
                }
            }
        }
    }
}
