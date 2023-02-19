#include "qDetectMarked.h"
#include "ui_qDetectMarked.h"


class qDetectMarkedPrivate : public Ui_qDetectMarked
{
	Q_DECLARE_PUBLIC(qDetectMarked);

protected:
	qDetectMarked* const q_ptr;
public:
	qDetectMarkedPrivate(qDetectMarked& object);
	~qDetectMarkedPrivate();

	void init();
};
//-----------------------------------------------------------------------------
// qDetectMarkedPrivate methods
//-----------------------------------------------------------------------------
qDetectMarkedPrivate::qDetectMarkedPrivate(qDetectMarked& object)
	:q_ptr(&object)
{

}

qDetectMarkedPrivate::~qDetectMarkedPrivate()
{
}

void qDetectMarkedPrivate::init()
{
	Q_Q(qDetectMarked);
	this->setupUi(q);
	this->markedWidget->installEventFilter(q);
	
}

//-----------------------------------------------------------------------------
// qDetectMarked methods
//-----------------------------------------------------------------------------
qDetectMarked::qDetectMarked(QWidget* parent) :Superclass(parent)
,d_ptr(new qDetectMarkedPrivate(*this))
{
	Q_D(qDetectMarked);
	d->init();
}

qDetectMarked::~qDetectMarked()
{

}