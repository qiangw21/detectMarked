#include "qMarkedViewer.h"

//Qt includes
#include <QWheelEvent>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>

//temp
#include <iostream>

class qMarkedViewerPrivate
{
	Q_DECLARE_PUBLIC(qMarkedViewer);

protected:
	qMarkedViewer* const q_ptr;
public:
	qMarkedViewerPrivate(qMarkedViewer& object);
	~qMarkedViewerPrivate();

	void modify();

	bool IsEditor{ false };
	QPoint CurrentPos;
	QImage DisplayImage;
	QPainter Painter;
};
//-----------------------------------------------------------------------------
// qMarkedViewerPrivate methods
//-----------------------------------------------------------------------------
qMarkedViewerPrivate::qMarkedViewerPrivate(qMarkedViewer& object)
	: q_ptr(&object)
{

}

qMarkedViewerPrivate::~qMarkedViewerPrivate()
{
}

void qMarkedViewerPrivate::modify()
{
	Q_Q(qMarkedViewer);
	if (IsEditor)
		q->update();

}

//-----------------------------------------------------------------------------
// qMarkedViewer methods
//-----------------------------------------------------------------------------
qMarkedViewer::qMarkedViewer(QWidget* parent) :Superclass(parent)
, d_ptr(new qMarkedViewerPrivate(*this))
{
	Q_D(qMarkedViewer);
}

qMarkedViewer::~qMarkedViewer()
{

}

void qMarkedViewer::set_image(QImage& image)
{
	Q_D(qMarkedViewer);
	d->DisplayImage = image;
}

int qMarkedViewer::get_image_width()
{
	Q_D(qMarkedViewer);
	return d->DisplayImage.width();
}

int qMarkedViewer::get_image_height()
{
	Q_D(qMarkedViewer);
	return d->DisplayImage.height();
}

bool qMarkedViewer::is_null()
{
	Q_D(qMarkedViewer);
	return d->DisplayImage.isNull();
}

bool qMarkedViewer::is_editor()
{
	Q_D(qMarkedViewer);
	return d->IsEditor;
}

void qMarkedViewer::set_is_editor(bool on)
{
	Q_D(qMarkedViewer);
	d->IsEditor = on;
}

void qMarkedViewer::set_current_pos(const QPoint& pos)
{
	Q_D(qMarkedViewer);
	d->CurrentPos = pos - this->pos();
	d->modify();
}

void qMarkedViewer::paintEvent(QPaintEvent* event)
{
	Superclass::paintEvent(event);

	Q_D(qMarkedViewer);
	if (d->DisplayImage.isNull())
		return;

	d->Painter.begin(this);
	d->Painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap::fromImage(d->DisplayImage));

	if (d->IsEditor)
	{
		d->Painter.setPen(QPen(Qt::green, 1, Qt::SolidLine));
		d->Painter.drawLine(d->CurrentPos.x(), 0, d->CurrentPos.x(), this->height());
		d->Painter.drawLine(0, d->CurrentPos.y(), this->width(), d->CurrentPos.y());
	}
	d->Painter.end();
}