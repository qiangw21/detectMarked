#ifndef _qDetectMarked_h
#define _qDetectMarked_h

//qt include
#include <QMainWindow>

class qDetectMarkedPrivate;

class qDetectMarked : public QMainWindow
{
	Q_OBJECT

public:
	typedef QMainWindow Superclass;
	explicit qDetectMarked(QWidget* parent = Q_NULLPTR);
	~qDetectMarked() override;


protected slots:

signals:

protected:
	QScopedPointer<qDetectMarkedPrivate> d_ptr;


private:
	Q_DECLARE_PRIVATE(qDetectMarked);
	Q_DISABLE_COPY(qDetectMarked);
};


#endif // !_qDetectMarked_h
