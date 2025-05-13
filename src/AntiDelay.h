/**
 * @file AntiDelay.h
 * @author Martin Vichnál
 * @page https://github.com/martinvichnal/AntiDelay
 * @brief AntiDelay is a library that aims to provide non-blocking delay functionality.
 * @version v1.1.2
 * @date 2023-12-31
 *
 * @copyright Copyright (c) 2024
 */

#ifndef AntiDelay_h
#define AntiDelay_h

#include <Arduino.h>

class AntiDelay
{
public:
  AntiDelay(unsigned long interval);
  operator bool();
  void reset();
  void setInterval(unsigned long interval);
  void pause();
  void resume();
  bool isRunning();

  /** temps écoulé depuis le dernier reset (ms) */
  uint32_t elapsed() const;

  /** temps restant avant l’expiration du timer (ms) */
  uint32_t remaining() const;

private:
  unsigned long timeInterval;   // durée programmée
  unsigned long previousMillis; // instant du dernier reset
  bool isPaused;
  unsigned long pauseOffset;
};
#endif
