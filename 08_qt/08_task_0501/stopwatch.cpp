#include "stopwatch.h"

StopWatch::StopWatch(QObject* parent): QObject{parent} {
  timer = new QTimer(this);
  minutes = 0;
  minutes_lap = 0;
  counter_lap = 0;
  mnt_tmp = 0;

  seconds = 0;
  seconds_lap = 0;
  scd_temp = 0;
  mil_seconds = 0;
  connect(timer, &QTimer::timeout, this, &StopWatch::StartTimer);
}

StopWatch::~StopWatch() {}

void StopWatch::StartTimer() {
  timer->start(100);
  mil_seconds++;

  if (mil_seconds >= 1) {
    seconds = seconds + 0.1;
    mil_seconds = 0;
  }

  if (seconds >= 60) {
    minutes++;
    seconds = 0;
  }

  emit SignalTimer(minutes, seconds);
}

void StopWatch::StopTimer() {
  timer->stop();
  emit SignalTimer(minutes, seconds);
}

void StopWatch::ResetTime() {
  minutes = seconds = counter_lap = 0;
  minutes_lap = seconds_lap = 0;
  emit SignalTimer(minutes, seconds);
}

 void StopWatch::GetLap() {
  mnt_tmp = minutes - minutes_lap;
  scd_temp = seconds - seconds_lap;
  counter_lap++;
  emit SignalGetLap(mnt_tmp, scd_temp, counter_lap);
  minutes_lap = minutes;
  seconds_lap = seconds;
}
