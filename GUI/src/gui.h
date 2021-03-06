#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QFileDialog>
#include <QSettings>
#include <QListWidget>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>
#include <boost/filesystem.hpp>

namespace Ui
{
	class GUI;
}

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	explicit GUI( QWidget *parent = 0 );
	~GUI();

protected:
	bool event( QEvent *e ) override;
	void closeEvent( QCloseEvent *e ) override;
	void setupConnections();
	void updateLastWizardScrolls();
	bool loadWizard( QFileInfo wizard );
	void clearLayout(QLayout *layout); // TODO: cpp

private slots:
	void onQuitClicked();
	void onSelectWizard();
	void onAboutClicked();
	void onLastWizardDblClick(QListWidgetItem *item);
	void onWizardChanged(const QString &name);
    void onCreateClicked();
	void onRemoveClicked();
	void onSelectClicked();

private:
	Ui::GUI *ui;
	QSettings *set;
	QGridLayout *lay = nullptr;
};

#endif // GUI_H
