#include "gui.h"
#include "ui_gui.h"
#include <QMessageBox>
#include <QScrollBar>
#include <QRegExp>
#include <QFileDialog>
#include "../FileMan/cfileini.h"
#include "../main.h"

GUI::GUI ( QWidget *parent ) :
    QMainWindow ( parent ),
    ui ( new Ui::GUI )
{
    ui->setupUi ( this );
    setupConnections();

    set = new QSettings ( "Prime-Hack", "ProjectWizard", this );

    for ( int i = 0; i < set->value ( "lastWizards/count" ).toInt(); ++i ) {
        ui->lastWizards->addItem ( set->value ( "lastWizards/" + QString::number ( i ) ).toString() );
    }

    lay = new QGridLayout ( this );
    ui->scrollAreaWidgetContents->setLayout ( lay );
}

GUI::~GUI()
{
    delete ui;
}

bool GUI::event ( QEvent *e )
{
    if ( e->type() == QEvent::Show ) {
        updateLastWizardScrolls();
    }

    return QMainWindow::event ( e );
}

void GUI::closeEvent ( QCloseEvent *e )
{
    set->setValue ( "lastWizards/count", ui->lastWizards->count() );

    for ( int i = 0; i < ui->lastWizards->count(); ++i ) {
        set->setValue ( "lastWizards/" + QString::number ( i ), ui->lastWizards->item ( i )->text() );
    }

    QMainWindow::closeEvent ( e );
}

void GUI::setupConnections()
{
    QObject::connect ( ui->actionQuit, &QAction::triggered, this, &GUI::onQuitClicked );
    QObject::connect ( ui->actionWizard, &QAction::triggered, this, &GUI::onSelectWizard );
    QObject::connect ( ui->actionAbout_ProjectWizard, &QAction::triggered, this, &GUI::onAboutClicked );
    QObject::connect ( ui->lastWizards, &QListWidget::itemDoubleClicked, this, &GUI::onLastWizardDblClick );
    QObject::connect ( ui->create, SIGNAL ( clicked() ), SLOT ( onCreateClicked() ) );
}

void GUI::updateLastWizardScrolls()
{
    ui->lastWizards->scrollToBottom();
    QScrollBar *sb = ui->lastWizards->horizontalScrollBar();
    sb->setValue ( sb->maximum() );
}

bool GUI::loadWizard ( QFileInfo wizard )
{
    CFileIni config ( wizard.filePath().toStdString() );
	setWizard(wizard.filePath().toStdString());

    if ( !wizard.isFile() ) {
        ui->name->setEnabled ( false );
        ui->create->setEnabled ( false );
        return false;
    }

    setProject(make_list_wizard ( boost::filesystem::path ( wizard.path().toStdString() ) ));
	setExclude(config.array ( "/exclude" ));
	setAsIs(config.array ( "/AsIs" ));
	setRename(config.array ( "/rename" ));
	
    std::string defName = config.value ( "/ProjectName" );

    ui->name->setText ( defName.c_str() );
    ui->name->setEnabled ( true );
    addVariable ( "ProjectName", {defName}, "The project name" );

    if ( lay != nullptr ) {
        clearLayout ( lay );
        resetVariables();

        std::deque<std::string> vars = config.array ( "/variable" );
        int row = 0;
        for ( auto &var : vars ) {
            std::string description = config.value ( var + "/description" );
            std::string defVariant = config.value ( var + "/default_variant" );
            int input = config.read<int> ( var + "/input" );
            std::deque<std::string> variants = config.array ( var + "/variant" );
            if ( variants.empty() )
                variants.push_back ( defVariant );

            addVariable ( var, variants, description );
            auto label = new QLabel ( var.c_str(), this );
            label->setToolTip ( description.c_str() );
            lay->addWidget ( label, row, 0 );

            if ( !input ) {
                // QComboBox
                setDefaultVariant ( var, variants.size() -1 );
                auto combo = new QComboBox ( this );
                combo->setObjectName ( QString ( "combo_" ) + var.c_str() );
                for ( auto &v : variants )
                    combo->addItem ( v.c_str() );
                combo->setCurrentText ( defVariant.c_str() );
                lay->addWidget ( combo, row, 1 );
            } else {
                // QLineEdit
                setDefaultVariant ( var, 0 );
                auto line = new QLineEdit ( this );
                line->setObjectName ( QString ( "line_" ) + var.c_str() );
                line->setText ( defVariant.c_str() );
                lay->addWidget ( line, row, 1 );
            }

            ++row;
        }
    }

    ui->create->setEnabled ( true );
    return true;
}

void GUI::clearLayout ( QLayout* layout )
{
    QLayoutItem *item;
    while ( ( item = layout->takeAt ( 0 ) ) ) {
        if ( item->layout() ) {
            clearLayout ( item->layout() );
            delete item->layout();
        }
        if ( item->widget() ) {
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
    QFileInfo fi = QFileDialog::getOpenFileName ( this, "Select project wizard" );

    if ( !fi.isFile() ) {
        ui->statusBar->showMessage ( "You not select file!", 5000 );
        return;
    }

    if ( loadWizard ( fi ) ) {
        ui->lastWizards->addItem ( fi.filePath() );
        updateLastWizardScrolls();
    } else {
        ui->statusBar->showMessage ( "This wizard is garbage", 5000 );
    }
}

void GUI::onAboutClicked()
{
    QMessageBox msg;
    msg.setWindowTitle ( "About" );
    msg.setText ( "The GUI frontend for library ProjectWizard.\n\nAuthor: SR_team" );
    msg.exec();
}

void GUI::onLastWizardDblClick ( QListWidgetItem* item )
{
    if ( !loadWizard ( item->text() ) )
        ui->statusBar->showMessage ( "This wizard is garbage", 5000 );
}

void GUI::onCreateClicked()
{
	setVariants("ProjectName", {ui->name->text().toStdString()});
	QString projectPath = QFileDialog::getExistingDirectory ( this, "Select projects directory" ) + "/";

    for ( int i = 0; i < lay->count(); ++i ) {
        QLayoutItem *item = lay->itemAt ( i );
        if ( item->widget() ) {
            if ( !item->widget()->objectName().isEmpty() ) {

                QRegExp reCombo ( R"(combo_(\w+))", Qt::CaseInsensitive );
                QRegExp reLine ( R"(line_(\w+))", Qt::CaseInsensitive );

                if ( reCombo.indexIn ( item->widget()->objectName() ) == 0 ) {
                    std::deque<std::string> variants = getVariants ( reCombo.cap ( 1 ).toStdString() );
                    for ( int j = 0; j < variants.size(); ++j ) {
                        if ( variants[j] == ( ( QComboBox* ) item->widget() )->currentText().toStdString() ) {
                            selectVariant ( reCombo.cap ( 1 ).toStdString(), j );
                            break;
                        }
                    }
                } else if ( reLine.indexIn ( item->widget()->objectName() ) == 0 ) {
                    addVariant ( reLine.cap ( 1 ).toStdString(), ( ( QLineEdit* ) item->widget() )->text().toStdString() );
                    selectVariant ( reLine.cap ( 1 ).toStdString(), 1 );
                }
            }
        }
    }
    
    createProject(projectPath.toStdString());
	QMessageBox msg;
	msg.setText("Project \"" + ui->name->text() + "\" has created!");
	msg.exec();
}
