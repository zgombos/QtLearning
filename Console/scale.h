#ifndef SCALE_H
#define SCALE_H

#include <QString>
#include <QStringList>
#include <QList>


class Scale
{
private:
    QString name;
    QList<int> interval;
    QString hint;
    const QStringList noteList = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    QStringList notes;

public:
    Scale(QString name,  QList<int> &interval,  QString hint);
    QStringList getScaleNote(const QString &root);

};

#endif // SCALE_H
