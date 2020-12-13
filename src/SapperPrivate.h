#ifndef SAPPERPRIVATE_H
#define SAPPERPRIVATE_H

#include <memory>

#include <QObject>
#include <QDateTime>
#include <QTimer>

#include "FlagState.h"

class SapperGameField;
class SapperPrivate : public QObject
{
    Q_OBJECT
public:
    explicit SapperPrivate(int side, int mines, QObject *parent = 0);
    ~SapperPrivate();
    int getSide()const;
    int getEstimatedFlags() const;

    void click(const QPoint &point);
    void toggleFlag(const QPoint &point);
    Flag getFlag(const QPoint &point)const;
    bool isOpended(const QPoint &point)const;
    bool isMined(const QPoint &point)const;
    bool isExploded(const QPoint &point)const;
    int getNeiMines(const QPoint &point)const;

    int getTimeSeconds()const;

signals:
    void bombed();
    void win();

private slots:
    void update();
    void bombedSlot();
    void winSlot();
private:
    const int side;
    const int mines;
    int time;
    std::unique_ptr<SapperGameField> gameField;
    QDateTime startTime;
    QTimer *timer;
    void createFieldAndTimer(const QPoint &point);
};

#endif // SAPPERPRIVATE_H
