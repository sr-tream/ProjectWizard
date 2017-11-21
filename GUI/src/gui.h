#ifndef GUI_H
#define GUI_H

#include <QMainWindow>

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
	void setupConnections();

private slots:
	void onQuitClicked();
	void onSelectWizard();
	void onAboutClicked();

private:
	Ui::GUI *ui;
};

#endif // GUI_H
