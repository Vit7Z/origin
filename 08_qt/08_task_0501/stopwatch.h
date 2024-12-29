#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>

class StopWatch : public QObject
{
  Q_OBJECT

  public:
    explicit StopWatch(QObject *parent = nullptr);
    ~StopWatch();
  signals:
    void SignalTimer(uint, float);
    void SignalGetLap(uint, float, uint);
  public slots:
    void StartTimer();
    void StopTimer();
    void ResetTime();
    void GetLap();
  private:
    QTimer* timer;
    uint16_t minutes, mnt_tmp, mil_seconds, minutes_lap, counter_lap;
    float seconds, seconds_lap, scd_temp;
};

#endif // STOPWATCH_H
