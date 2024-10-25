#ifndef MEDIAPLAYERWIDGET_H
#define MEDIAPLAYERWIDGET_H
 
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class MediaPlayerWidget;
}
 
class MediaPlayerWidget : public QWidget
{
    Q_OBJECT
 
public:
    explicit MediaPlayerWidget(QWidget *parent = 0);
    ~MediaPlayerWidget();
 
private slots:
    void on_AddPushButton_clicked();
 
    void on_PlayAndStopPushButton_clicked();
 
    void on_UpPushButton_clicked();
 
    void on_DownPushButton_clicked();
 
 
    void on_VolDial_valueChanged(int value);
 
    void on_MediaplayListWidget_currentRowChanged(int currentRow);
 
   void  currentMediaChangedSlot(const QMediaContent &item);
   void  currentdurationChangedSlot(qint64 duration);
   void horizontalSliderPositionChanged(qint64 Position);
   void on_horizontalSlider_sliderPressed();
 
   void on_horizontalSlider_sliderReleased();
 
   void on_horizontalSlider_valueChanged(int value);
 
private:
    Ui::MediaPlayerWidget *ui;
    //播放器对象指针
    QMediaPlayer   * MediaPlayer;
    QMediaPlaylist  * MediaPlaylist;
    bool    playSataFalge;
    bool    SliderPFlage;
};
 
#endif // MEDIAPLAYERWIDGET_H