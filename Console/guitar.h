#ifndef GUITAR_H
#define GUITAR_H

#include <QList>
#include <QMap>
#include "note.h"
#include "guitarnote.h"
#include "scale.h"

class Guitar
{
private:
    int frets;
    QList<Note> tuningList;
    QList<QList<Note>> stringNoteList;
    const QStringList noteList = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    QList<Note> generateNotes(Note &startNote, int size);
    void tuning(const QList<Note> &tune);

public:
    Guitar(int frets, QList<Note> tune);
    QList<QList<Note>> getstringList() {return stringNoteList;}
    QList<QList<GuitarNote>> getAllScaleNotes(const QStringList &scale);
    QList<QList<GuitarNote>> getThreeNotes(const QStringList &scale, int startPos);
    QList<QList<QMap<Note, int>>> getBoxPattern(QStringList &scale, Note &startNote);
};

#endif // GUITAR_H
