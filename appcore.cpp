#include <QFile>
#include <QQmlContext>
#include <QGuiApplication>
#include <QDebug>

#include "appcore.h"
#include "filetablemodel.h"

AppCore::AppCore(QQmlContext *rootContext, QObject *parent)
    : QObject(parent)
    , model(new FileTableModel())
{
    QVector<QVector<QString> > *dataModel = new QVector<QVector<QString> >;


    QFile file("in.txt");

    Q_ASSERT(file.open(QIODevice::ReadOnly));

    QString in(file.readAll());

    QStringList inLines(in.split(QRegExp("[\r\n]"), QString::SkipEmptyParts));


    for(int i = 0; i < inLines.count(); i++)
    {
        QStringList inLine = inLines.at(i).split(";", QString::SkipEmptyParts);

        dataModel->append(inLine.replaceInStrings(QRegExp("^[ \t]+"), "").toVector());

        qDebug() << inLine;
    }

    file.close();


    model->setModelData(dataModel);

    rootContext->setContextProperty("tableModel", model);
}
