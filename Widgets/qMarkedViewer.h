#ifndef _qMarkedViewer_h
#define _qMarkedViewer_h

//Qt include
#include <QLabel>

class qMarkedViewerPrivate;

class qMarkedViewer : public QLabel
{
	Q_OBJECT

public:
	typedef QLabel Superclass;
	explicit qMarkedViewer(QWidget* parent = Q_NULLPTR);
	~qMarkedViewer() override;

	void set_image(QImage& image);

	int get_image_width();
	int get_image_height();
	bool is_null();

	void set_is_editor(bool on);
	bool is_editor();

public slots:
	void set_current_pos(const QPoint& pos);

protected:
	QScopedPointer<qMarkedViewerPrivate> d_ptr;

	void paintEvent(QPaintEvent* event) override;

private:
	Q_DECLARE_PRIVATE(qMarkedViewer);
	Q_DISABLE_COPY(qMarkedViewer);
};

#endif // !_qMarkedViewer_h
