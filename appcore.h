#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>

class QQmlContext;
class FileTableModel;

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QQmlContext *rootContext, QObject *parent = nullptr);

private:
    FileTableModel *model;
};

#endif // APPCORE_H
