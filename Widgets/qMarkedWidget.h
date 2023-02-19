#ifndef _qMarkedWidget_h
#define _qMarkedWidget_h

//qt include
#include <qWidget.h>

//std include
#include <string>

class qMarkedWidgetPrivate;

class qMarkedWidget : public QWidget
{
	Q_OBJECT

public:
	typedef QWidget Superclass;
	explicit qMarkedWidget(QWidget* parent = Q_NULLPTR);
	~qMarkedWidget() override;

	enum State
	{
		Viewer_Moving = 0,
		Viewer_Zoom,
		Viewer_None
	};

protected slots:
	void zoom(int factor, double ratio = 0.01);
	void zoom_to_fit();

	void span(const QPoint& offset);

signals:

protected:
	
	void set_state(State state);
	void clear_state();

	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;

	QScopedPointer<qMarkedWidgetPrivate> d_ptr;

private:
	Q_DECLARE_PRIVATE(qMarkedWidget);
	Q_DISABLE_COPY(qMarkedWidget);
};


#endif // !_qMarkedWidget_h
