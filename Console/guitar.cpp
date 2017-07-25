#include "guitar.h"

Guitar::Guitar(int frets, QList<Note> tune):frets{frets + 1}, tuningList{tune}
{
    tuning(tuningList);
}

QList<Note> Guitar::generateNotes(Note &startNote, int size)
{
    /*
     * Generate as many Note objects as frets are on the guitar
     * No scale applie
     * Create a circular list from the noteList
     * Increase the octave when necessary
     */

    QList<Note> result;
    int index = noteList.indexOf(startNote.getName());
    int octave = startNote.getOctave();
    for(int i = 0; i < size; ++i)
    {
        if (index >= noteList.size() )
            index = index % noteList.size();
        if (noteList[index]=="C")
            octave++;
        result.append(Note(noteList.at(index), octave));
        index++;
    }
    return result;
}

void Guitar::tuning(const QList<Note> &tune)
{
    /*
     * Call the generateNotes function to populate the stringList
     */

    for (Note note : tune)
    {
        QList<Note> noteList = generateNotes(note, frets);
        stringNoteList.append(noteList);
    }
}

QList<QList<GuitarNote>> Guitar::getAllScaleNotes(const QStringList &scale)
{
    /*
     * Generate a list of list of GuitarNotes from the scale
     */

    QList<QList<GuitarNote>> result;

    // Interate over the guitar notes per guitar string
    for (const QList<Note> &notesOnString : stringNoteList)
    {
       QList<GuitarNote> tmp;
       // Iterate over the notes
       for (Note note : notesOnString)
       {
           // If the scale contains the guitar note determinate the index and add it to the list
            if (scale.contains(note.getName()))
            {
                int index = notesOnString.indexOf(note);
                tmp.append(GuitarNote(note, index));
                //tmp.append(map);
            }
       }
       result.append(tmp);
    }
    return result;
}

QList<QList<GuitarNote>> Guitar::getThreeNotes(const QStringList &scale, int startPos)
{
    QList<QList<GuitarNote>> result;
    QList<QList<GuitarNote>> notesOnGuitarString = getAllScaleNotes(scale);

    // c,d,e,f,g,a,b + startPos (0-6)
    // Find the index of the startPos on the first guitar string
    QString name = scale.at(startPos);
    int index = 0;
    for (GuitarNote &note : notesOnGuitarString[0])
    {
        if (note.getName() == name)
        {
            index = notesOnGuitarString[0].indexOf(note);
            break;
        }
    }
    qDebug() << "index:" << index << endl;

    for (const QList<GuitarNote> &guitarString : notesOnGuitarString)
    {
        QList<GuitarNote> tmp;
        for (int i = 0; i < 3; ++i)
        {
            index += i;
            qDebug() << "index:" << index << endl;
            tmp.append(guitarString.at(index));
        }
        result.append(tmp);
    }
    return result;
}

QList<QList<QMap<Note, int> > > Guitar::getBoxPattern(QStringList &scale, Note &startNote)
{
    /*
     * Return a list of notes box pattern per string from the scale
     * Notes are not farther than 4 frets on a string
     */

    QList<QList<QMap<Note, int>>> result;

     return result;

}
