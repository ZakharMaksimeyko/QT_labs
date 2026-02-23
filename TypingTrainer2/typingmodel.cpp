#include "typingmodel.h"

TypingModel::TypingModel()
    : m_lineIndex(0), m_charIndex(0)
{
}

void TypingModel::loadLesson(const QString &text)
{
    m_fullText = text;
    m_lines = m_fullText.split('\n', Qt::SkipEmptyParts);

    m_lineIndex = 0;
    m_charIndex = 0;
}

QString TypingModel::getPreviousLine() const
{
    if (m_lineIndex <= 0 || m_lines.isEmpty()) {
        return "";
    }
    return m_lines[m_lineIndex - 1];
}

QString TypingModel::getPassedText() const
{
    if (m_lineIndex >= m_lines.size()) {
        return "";
    }
    return m_lines[m_lineIndex].left(m_charIndex);
}

QString TypingModel::getRemainingText() const
{
    if (m_lineIndex >= m_lines.size()) {
        return "";
    }
    return m_lines[m_lineIndex].mid(m_charIndex);
}

bool TypingModel::isFinished() const
{
    return m_lineIndex >= m_lines.size();
}

void TypingModel::advanceChar()
{
    if (isFinished()) {
        return;
    }

    QString currentLine = m_lines[m_lineIndex];
    if (m_charIndex < currentLine.length()) {
        m_charIndex++;
    } else {
        m_lineIndex++;
        m_charIndex = 0;
    }
}
