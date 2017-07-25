#include <QCoreApplication>
#include <QDebug>
#include <QList>

#include "note.h"
#include "guitarnote.h"
#include "scale.h"
#include "guitar.h"

using namespace std;


int main(int argc, char *argv[])
{
    //QCoreApplication app(argc, argv);

    Note A_Note("A", 2);
    qDebug() << "A_Note:" << A_Note << endl;

    GuitarNote a_note(A_Note, 2);
    qDebug() << "a_note:" << a_note << endl;

    QList<int> major = {2, 2, 1, 2, 2, 2};
    Scale Major("Major", major, "three_notes");
    QStringList c_major = Major.getScaleNote("C");
    qDebug() << "C major scale:" << c_major << endl;

    QList<int> minor = {2, 1, 2, 2, 1, 2};
    Scale Minor("Minor", minor, "three_notes");
    QStringList a_minor = Minor.getScaleNote("A");
    qDebug() << "A minor scale:" << a_minor << endl;

    QList<Note> tuning = {Note("E", 2), Note("A", 2), Note("D", 3), Note("G", 3), Note("B", 3), Note("E", 4)};
    Guitar Gibson(22, tuning);
    QList<QList<Note>> notes = Gibson.getstringList();
    //qDebug() << "String notes: " << notes;

    //QList<QList<QMap<Note, int>>> allNotes = Gibson.getAllScaleNotes(c_major);
    QList<QList<GuitarNote>> allNotes = Gibson.getAllScaleNotes(c_major);
    //qDebug() << "All notes from c major: " << allNotes;
    qDebug() << "All notes from c major on the first string: " << allNotes[0] << endl;

    QList<QList<GuitarNote>> threeNotes = Gibson.getThreeNotes(c_major, 1);
    qDebug() << "Three notes per string view: " << threeNotes << endl;

    //return app.exec();
    return 0;
}
