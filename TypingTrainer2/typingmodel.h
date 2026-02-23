#ifndef TYPINGMODEL_H
#define TYPINGMODEL_H

#include <QString>
#include <QStringList>

class TypingModel{
public:
    TypingModel();

    void loadLesson(const QString& text);

    QString getPreviousLine() const;
    QString getPassedText() const;
    QString getRemainingText() const;

    void advanceChar();
    bool isFinished() const;

private:
    QString m_fullText;
    QStringList m_lines;
    int m_lineIndex;
    int m_charIndex;
};

#endif // TYPINGMODEL_H
