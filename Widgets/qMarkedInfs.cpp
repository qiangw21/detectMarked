#include "qMarkedInfs.h"

//qt include
#include <QTableWidget>
#include <QGridLayout>
#include <QHeaderView>

class qMarkedInfsPrivate
{
	Q_DECLARE_PUBLIC(qMarkedInfs);

protected:
	qMarkedInfs* const q_ptr;
public:
	qMarkedInfsPrivate(qMarkedInfs& object);
	~qMarkedInfsPrivate();

	QTableWidget* MarkedInfs{ nullptr };
};

//-----------------------------------------------------------------------------
// qMarkedInfsPrivate methods
//-----------------------------------------------------------------------------
qMarkedInfsPrivate::qMarkedInfsPrivate(qMarkedInfs& object)
	: q_ptr(&object)
{
	this->MarkedInfs = new QTableWidget(&object);
	this->MarkedInfs->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->MarkedInfs->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->MarkedInfs->setSelectionMode(QAbstractItemView::SingleSelection);
	this->MarkedInfs->setColumnCount(5);
	QTableWidgetItem* __qtablewidgetitem = new QTableWidgetItem();
	this->MarkedInfs->setHorizontalHeaderItem(0, __qtablewidgetitem);
	QTableWidgetItem* __qtablewidgetitem1 = new QTableWidgetItem();
	this->MarkedInfs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
	QTableWidgetItem* __qtablewidgetitem2 = new QTableWidgetItem();
	this->MarkedInfs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
	QTableWidgetItem* __qtablewidgetitem3 = new QTableWidgetItem();
	this->MarkedInfs->setHorizontalHeaderItem(3, __qtablewidgetitem3);
	QTableWidgetItem* __qtablewidgetitem4 = new QTableWidgetItem();
	this->MarkedInfs->setHorizontalHeaderItem(4, __qtablewidgetitem4);
	QStringList header;
	header << QStringLiteral("±êÇ©") << QStringLiteral("start_x") << QStringLiteral("statr_y") <<
		QStringLiteral("end_x") << QStringLiteral("end_y");
	this->MarkedInfs->setHorizontalHeaderLabels(header);
	this->MarkedInfs->setColumnWidth(0, 100);
	this->MarkedInfs->setColumnWidth(1, 100);
	this->MarkedInfs->setColumnWidth(2, 100);
	this->MarkedInfs->setColumnWidth(3, 100);
	this->MarkedInfs->setColumnWidth(4, 100);
	
	QGridLayout* gridLayout = new QGridLayout(&object);
	gridLayout->setSpacing(0);
	gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
	gridLayout->setContentsMargins(0, 0, 0, 0);
	gridLayout->addWidget(this->MarkedInfs);
}

qMarkedInfsPrivate::~qMarkedInfsPrivate()
{
}

//-----------------------------------------------------------------------------
// qMarkedInfs methods
//-----------------------------------------------------------------------------
qMarkedInfs::qMarkedInfs(QWidget* parent) 
	: Superclass(parent) 
	, d_ptr(new qMarkedInfsPrivate(*this))
{

}

qMarkedInfs::~qMarkedInfs()
{

}