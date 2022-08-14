#pragma once

#include <QMediaPlayer>

class Track;

class Player : public QMediaPlayer
{
  Q_OBJECT

public:
  explicit Player(Track* parent);
  bool isReady() const;
  void setNextPlayer(Player* mediaPlayer);
  bool playActive(bool force = false);
  void pauseActive();

signals:
  void playerLoaded();

private slots:
  void mediaPlayerStatusChanged(QMediaPlayer::MediaStatus status);
  void mediaPlayerPositionChanged(qint64 position);
  void setupNextPlayer();

private:
  void startNextPlayer();

  const Track* m_track;
  bool m_ready;
  bool m_active;
  Player* m_next_media_player;

  friend class TestPlayer;
  friend class TestTrack;
  friend class TestTrackControls;
};
