#include "mediaplayerwidget.h"
#include "ui_mediaplayerwidget.h"
#include <QDebug>
MediaPlayerWidget::MediaPlayerWidget(QWidget *parent) :
    QWidget(parent),playSataFalge(false),SliderPFlage(false),
    ui(new Ui::MediaPlayerWidget)
{
    ui->setupUi(this);
    MediaPlayer = new   QMediaPlayer(this);       //实例化播放器对象
    MediaPlaylist =new  QMediaPlaylist(this);     //实例化歌单对象
    MediaPlayer->setPlaylist(MediaPlaylist);      //音乐播放器设置歌单
    MediaPlaylist->setCurrentIndex(0);            //初始状态
    MediaPlayer->setVolume(50);
    ui->VolDial->setValue(50);
    connect(MediaPlayer,SIGNAL(currentMediaChanged(const QMediaContent &)),this,SLOT(currentMediaChangedSlot(const QMediaContent &)));
    connect(MediaPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(currentdurationChangedSlot(qint64)));
    connect(MediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(horizontalSliderPositionChanged(qint64)));
}
 
MediaPlayerWidget::~MediaPlayerWidget()
{
    delete ui;
    delete MediaPlayer;
}
//添加歌单
void MediaPlayerWidget::on_AddPushButton_clicked()
{
    QStringList MP3files = QFileDialog::getOpenFileNames(this,"选择音乐文件",".","音乐文件 (*.mp3 *.mp4 *.MP3)");
    for(int i =0;i<MP3files.count();i++)
    {
        MediaPlaylist->addMedia(QUrl(MP3files.at(i)));
        ui->MediaplayListWidget->addItem(MP3files.at(i));
    }
}
 
void MediaPlayerWidget::on_PlayAndStopPushButton_clicked()
{
    if(!MediaPlaylist->isEmpty())
    {
        if(!playSataFalge)
        {
            MediaPlayer->play();
            playSataFalge = true;
            ui->PlayAndStopPushButton->setText("停止播放");
        }
        else
        {
            MediaPlayer->stop();
            playSataFalge = false;
            ui->PlayAndStopPushButton->setText("播放音乐");
        }
    }
    else
    {
        QMessageBox::warning(this,"播放器警告","歌单中未有音乐无法实现播放，请添加音乐");
    }
}
 
void MediaPlayerWidget::on_UpPushButton_clicked()
{
    MediaPlaylist->previous();
}
 
void MediaPlayerWidget::on_DownPushButton_clicked()
{
    MediaPlaylist->next();
}
 
 
void MediaPlayerWidget::on_VolDial_valueChanged(int value)
{
    MediaPlayer->setVolume(value);
}
//list窗口进行单击选择
void MediaPlayerWidget::on_MediaplayListWidget_currentRowChanged(int currentRow)
{
    if(currentRow < ui->MediaplayListWidget->count())
        MediaPlaylist->setCurrentIndex(currentRow);
}
 
void MediaPlayerWidget::currentMediaChangedSlot(const QMediaContent &item)
{
    //统计当前歌曲的时长
 
}
//持续时间改变
void MediaPlayerWidget::currentdurationChangedSlot(qint64 duration)
{
    ui->horizontalSlider->setMaximum(duration);
}
 
void MediaPlayerWidget::horizontalSliderPositionChanged(qint64 Position)
{
    if(!SliderPFlage)
    {
        ui->horizontalSlider->setValue(Position);
    }
}
 
 
 
void MediaPlayerWidget::on_horizontalSlider_sliderPressed()
{
    SliderPFlage=true;
 
}
 
void MediaPlayerWidget::on_horizontalSlider_sliderReleased()
{
    SliderPFlage=false;
    MediaPlayer->setPosition(ui->horizontalSlider->value());
}
 
void MediaPlayerWidget::on_horizontalSlider_valueChanged(int value)
{
 
}