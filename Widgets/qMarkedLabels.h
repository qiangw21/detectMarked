#ifndef _qMarkedLabels_h
#define _qMarkedLabels_h

//qt include
#include <qWidget>

class qMarkedLabelsPrivate;

class qMarkedLabels : public QWidget
{
	Q_OBJECT

public:
	typedef QWidget Superclass;
	explicit qMarkedLabels(QWidget* parent = Q_NULLPTR);
	~qMarkedLabels() override;

protected:

	QScopedPointer<qMarkedLabelsPrivate> d_ptr;

private:
	Q_DECLARE_PRIVATE(qMarkedLabels);
	Q_DISABLE_COPY(qMarkedLabels);
};

#endif // !_qMarkedLabels_h

