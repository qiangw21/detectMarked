#include "qMarkedWidget.h"
#include "ui_qMarkedWidget.h"

//Qt includes
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QImage>

//std includes
#include <iostream>

class qMarkedWidgetPrivate : public Ui_qMarkedWidget
{
	Q_DECLARE_PUBLIC(qMarkedWidget);

protected:
	qMarkedWidget* const q_ptr;
public:
	qMarkedWidgetPrivate(qMarkedWidget& object);
	~qMarkedWidgetPrivate();

	void init();
	void load_image(const QString& file_path);

	QPoint ViewerCenterPoint;
	QPoint LastMousePos;
	QSize ZoomKeepSize;
	double ZoomRatio{ 1.0 };
	qMarkedWidget::State ViewerSate{ qMarkedWidget::Viewer_None };
};
//-----------------------------------------------------------------------------
// qMarkedWidgetPrivate methods
//-----------------------------------------------------------------------------
qMarkedWidgetPrivate::qMarkedWidgetPrivate(qMarkedWidget& object)
	: q_ptr(&object)
{

}

qMarkedWidgetPrivate::~qMarkedWidgetPrivate()
{
}

void qMarkedWidgetPrivate::init()
{
	Q_Q(qMarkedWidget);
	this->setupUi(q);
	this->markedViewer->hide();

}

void qMarkedWidgetPrivate::load_image(const QString& file_path)
{
	Q_Q(qMarkedWidget);
	if (file_path.endsWith(".jpg") || file_path.endsWith(".png") || file_path.endsWith(".jpeg"))
	{
		QImage image;
		if (!image.load(file_path))
			return;

		if (this->markedViewer->isHidden())
			this->markedViewer->show();
		this->markedViewer->set_image(image);
		q->zoom_to_fit();
	}
}

//-----------------------------------------------------------------------------
// qMarkedWidget methods
//-----------------------------------------------------------------------------
qMarkedWidget::qMarkedWidget(QWidget* parent) :Superclass(parent)
,d_ptr(new qMarkedWidgetPrivate(*this))
{
	Q_D(qMarkedWidget);
	d->init();
}

qMarkedWidget::~qMarkedWidget()
{

}

void qMarkedWidget::zoom_to_fit()
{
	Q_D(qMarkedWidget);
	if (d->markedViewer->is_null())
		return;

	int parent_w = this->width();
	int parent_h = this->height();

	int img_w = d->markedViewer->get_image_width();
	int img_h = d->markedViewer->get_image_height();
	double scale = static_cast<double>(parent_h) / img_h;
	if (scale * img_w > parent_w)
		scale = static_cast<double>(parent_w) / img_w;

	int scale_w = static_cast<int>(std::round(scale * img_w));
	int scale_h = static_cast<int>(std::round(scale * img_h));

	d->markedViewer->resize(scale_w, scale_h);

	int delta_w = (parent_w - scale_w) / 2;
	int delta_h = (parent_h - scale_h) / 2;
	d->markedViewer->move(QPoint(delta_w, delta_h));

	d->ViewerCenterPoint = QPoint(static_cast<int>(parent_w / 2), static_cast<int>(parent_h / 2));
	d->ZoomKeepSize = QSize(scale_w, scale_h);
	d->ZoomRatio = 1.0;
}

void qMarkedWidget::zoom(int factor, double ratio /*= 0.01*/)
{
	Q_D(qMarkedWidget);
	if ((d->ZoomRatio < 0.1 && factor < 0) || factor == 0)
		return;

	factor /= std::abs(factor);
	
	d->ZoomRatio += factor * ratio;
	int current_w = static_cast<int>(d->ZoomRatio * d->ZoomKeepSize.width());
	int current_h = static_cast<int>(d->ZoomRatio * d->ZoomKeepSize.height());

	d->markedViewer->resize(current_w, current_h);

	QPoint move_pos = d->ViewerCenterPoint - QPoint(static_cast<int>(current_w / 2), static_cast<int>(current_h / 2));

	d->markedViewer->move(move_pos);
}

void qMarkedWidget::span(const QPoint& offset)
{
	Q_D(qMarkedWidget);

	QPoint move_pos = d->markedViewer->pos() + offset;
	d->markedViewer->move(move_pos);
	d->ViewerCenterPoint += offset;
}

void qMarkedWidget::dragEnterEvent(QDragEnterEvent* event)
{
	Q_D(qMarkedWidget);

	if (event->mimeData()->hasUrls())
		event->acceptProposedAction();
	else
		event->ignore();
}

void qMarkedWidget::dropEvent(QDropEvent* event)
{
	Q_D(qMarkedWidget);

	const QMimeData* mimeData = event->mimeData();
	if (mimeData->hasUrls())
	{
		QList<QUrl> urls = mimeData->urls();
		QString file_path = urls.at(0).toLocalFile();
		d->load_image(file_path);
	}
}

void qMarkedWidget::set_state(State state)
{
	Q_D(qMarkedWidget);
	if (d->ViewerSate != Viewer_None)
		return;

	if (d->markedViewer->is_null())
	{
		d->ViewerSate = Viewer_None;
		return;
	}
	d->ViewerSate = state;
}

void qMarkedWidget::clear_state()
{
	Q_D(qMarkedWidget);
	d->ViewerSate = Viewer_None;
}

void qMarkedWidget::resizeEvent(QResizeEvent* event)
{
	Superclass::resizeEvent(event);
	this->zoom_to_fit();
}

void qMarkedWidget::wheelEvent(QWheelEvent* event)
{
	
	/*QPoint num_degrees = event->angleDelta();
	int step = -1;
	if (!num_degrees.isNull())
		step = num_degrees.y();

	event->accept();
	
	
	this->zoom(step);*/
}

void qMarkedWidget::mousePressEvent(QMouseEvent* event)
{
	Q_D(qMarkedWidget);

	if (event->buttons() & Qt::RightButton)
		this->set_state(Viewer_Zoom);
	if (event->buttons() & Qt::MiddleButton)
		this->set_state(Viewer_Moving);

	d->LastMousePos = event->pos();
	d->markedViewer->set_current_pos(d->LastMousePos);
}

void qMarkedWidget::mouseReleaseEvent(QMouseEvent* event)
{
	Q_D(qMarkedWidget);
	this->clear_state();

	d->LastMousePos = event->pos();
	d->markedViewer->set_current_pos(d->LastMousePos);
}

void qMarkedWidget::mouseMoveEvent(QMouseEvent* event)
{
	Q_D(qMarkedWidget);
	
	QPoint offset = event->pos() - d->LastMousePos;

	switch (d->ViewerSate)
	{
	case Viewer_Moving:
		this->span(offset);
		break;
	case Viewer_Zoom:
		this->zoom(-offset.y());
		break;
	default:
		break;
	}

	d->LastMousePos = event->pos();
	d->markedViewer->set_current_pos(d->LastMousePos);
}