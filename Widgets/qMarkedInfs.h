#ifndef _qMarkedInfs_h
#define _qMarkedInfs_h

//qt include
#include <qWidget>

class qMarkedInfsPrivate;

class qMarkedInfs : public QWidget
{
	Q_OBJECT

public:
	typedef QWidget Superclass;
	explicit qMarkedInfs(QWidget* parent = Q_NULLPTR);
	~qMarkedInfs() override;

protected:

	QScopedPointer<qMarkedInfsPrivate> d_ptr;

private:
	Q_DECLARE_PRIVATE(qMarkedInfs);
	Q_DISABLE_COPY(qMarkedInfs);
};

#endif // !_qMarkedInfs_h
