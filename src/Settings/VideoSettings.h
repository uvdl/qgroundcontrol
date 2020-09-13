/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#ifndef VideoSettings_H
#define VideoSettings_H

#include "SettingsGroup.h"

class VideoSettings : public SettingsGroup
{
    Q_OBJECT

public:
    VideoSettings(QObject* parent = nullptr);
    DEFINE_SETTING_NAME_GROUP()

    DEFINE_SETTINGFACT(videoSource)
    DEFINE_SETTINGFACT(udpPort)
    DEFINE_SETTINGFACT(tcpUrl)
    DEFINE_SETTINGFACT(rtspUrl)
    DEFINE_SETTINGFACT(aspectRatio)
    DEFINE_SETTINGFACT(videoFit)
    DEFINE_SETTINGFACT(gridLines)
    DEFINE_SETTINGFACT(showRecControl)
    DEFINE_SETTINGFACT(recordingFormat)
    DEFINE_SETTINGFACT(maxVideoSize)
    DEFINE_SETTINGFACT(enableStorageLimit)
    DEFINE_SETTINGFACT(rtspTimeout)
    DEFINE_SETTINGFACT(streamEnabled)
    DEFINE_SETTINGFACT(disableWhenDisarmed)
    DEFINE_SETTINGFACT(lowLatencyMode)
    DEFINE_SETTINGFACT(audio)
    DEFINE_SETTINGFACT(audioUdpPort)

    Q_PROPERTY(bool     streamConfigured        READ streamConfigured       NOTIFY streamConfiguredChanged)
    Q_PROPERTY(bool     audioEnabled            READ audioEnabled           NOTIFY audioEnabledChanged)
    Q_PROPERTY(QString  rtspVideoSource         READ rtspVideoSource        CONSTANT)
    Q_PROPERTY(QString  udp264VideoSource       READ udp264VideoSource      CONSTANT)
    Q_PROPERTY(QString  multicastUdp264VideoSource       READ multicastUdp264VideoSource      CONSTANT)
    Q_PROPERTY(QString  multicastUdp265VideoSource       READ multicastUdp265VideoSource      CONSTANT)
    Q_PROPERTY(QString  udp265VideoSource       READ udp265VideoSource      CONSTANT)
    Q_PROPERTY(QString  udp265VideoSourceStreamControl      READ udp265VideoSourceStreamControl      CONSTANT)
    Q_PROPERTY(QString  udp264VideoSourceStreamControl      READ udp264VideoSourceStreamControl      CONSTANT)
    Q_PROPERTY(QString  tcpVideoSource          READ tcpVideoSource         CONSTANT)
    Q_PROPERTY(QString  mpegtsVideoSource       READ mpegtsVideoSource      CONSTANT)
    Q_PROPERTY(QString  disabledVideoSource     READ disabledVideoSource      CONSTANT)

    bool     audioEnabled            ();
    bool     streamConfigured       ();
    QString  rtspVideoSource        () { return videoSourceRTSP; }
    QString  udp264VideoSource      () { return videoSourceUDPH264; }
    QString  multicastUdp264VideoSource     () { return videoSourceMulticastUDPH264; }
    QString  multicastUdp265VideoSource     () { return videoSourceMulticastUDPH265; }
    QString  udp265VideoSource      () { return videoSourceUDPH265; }
    QString  udp265VideoSourceStreamControl () { return videoSourceUDPH265StreamControl; }
    QString  udp264VideoSourceStreamControl () { return videoSourceUDPH264StreamControl; }
    QString  tcpVideoSource         () { return videoSourceTCP; }
    QString  mpegtsVideoSource      () { return videoSourceMPEGTS; }
    QString  disabledVideoSource    () { return videoDisabled; }

    static const char* videoSourceNoVideo;
    static const char* videoDisabled;
    static const char* videoSourceUDPH264;
    static const char* videoSourceMulticastUDPH264;
    static const char* videoSourceMulticastUDPH265;
    static const char* videoSourceUDPH265;
    static const char* videoSourceUDPH265StreamControl;
    static const char* videoSourceUDPH264StreamControl;
    static const char* videoSourceRTSP;
    static const char* videoSourceTCP;
    static const char* videoSourceMPEGTS;

signals:
    void streamConfiguredChanged    ();
    void audioEnabledChanged    ();

private slots:
    void _configChanged             (QVariant value);

private:
    void _setDefaults               ();

private:
    bool _noVideo = false;

};

#endif
