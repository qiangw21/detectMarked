#include "qMarkedLabels.h"

//qt include
#include <QTableWidget>
#include <QGridLayout>
#include <QHeaderView>

class qMarkedLabelsPrivate
{
	Q_DECLARE_PUBLIC(qMarkedLabels);

protected:
	qMarkedLabels* const q_ptr;
public:
	qMarkedLabelsPrivate(qMarkedLabels& object);
	~qMarkedLabelsPrivate();

	QTableWidget* MarkedLabels{ nullptr };
};

//-----------------------------------------------------------------------------
// qMarkedLabelsPrivate methods
//-----------------------------------------------------------------------------
qMarkedLabelsPrivate::qMarkedLabelsPrivate(qMarkedLabels& object)
	: q_ptr(&object)
{
	this->MarkedLabels = new QTableWidget(&object);
	this->MarkedLabels->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->MarkedLabels->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->MarkedLabels->setSelectionMode(QAbstractItemView::SingleSelection);
	this->MarkedLabels->setColumnCount(1);
	QTableWidgetItem* __qtablewidgetitem = new QTableWidgetItem();
	this->MarkedLabels->setHorizontalHeaderItem(0, __qtablewidgetitem);
	QStringList header;
	header << QStringLiteral("±êÇ©");
	this->MarkedLabels->setHorizontalHeaderLabels(header);
	this->MarkedLabels->setColumnWidth(0, 500);
	this->MarkedLabels->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);

	QGridLayout* gridLayout = new QGridLayout(&object);
	gridLayout->setSpacing(0);
	gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
	gridLayout->setContentsMargins(0, 0, 0, 0);
	gridLayout->addWidget(this->MarkedLabels);
}

qMarkedLabelsPrivate::~qMarkedLabelsPrivate()
{
}

//-----------------------------------------------------------------------------
// qMarkedLabels methods
//-----------------------------------------------------------------------------
qMarkedLabels::qMarkedLabels(QWidget* parent) :Superclass(parent)
, d_ptr(new qMarkedLabelsPrivate(*this))
{

}

qMarkedLabels::~qMarkedLabels()
{

}