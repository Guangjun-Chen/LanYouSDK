//
//  MyRecorder.h
//  HFRecorder
//
//  Created by zenghaifeng on 13-9-25.
//  Copyright (c) 2013年 LanYou. All rights reserved.
//  Modified by Frank on 2015-8-3
//  修改lame.h引入路径
//

#import <Foundation/Foundation.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AVFoundation/AVFoundation.h>
#import "lame.h"

@protocol LYAudioDelegate <NSObject>
//录音结束后回调
- (void)LYAudioRecorderFinished;
//音频全部播放完成后回调
- (void)LYAudioPlayerFinished;
@end

@interface LYAudio : NSObject <AVAudioPlayerDelegate, AVAudioRecorderDelegate> {
    //@interface LYAudio : NSObject{
    float _recordTime;
}

@property (nonatomic, assign) id<LYAudioDelegate> LYAudioDelegate;
@property (retain, nonatomic) AVAudioRecorder* audioRecorder;
@property (retain, nonatomic) AVAudioPlayer* audioPlayer;

/**
 *设置录音时间
 *@param time 录音时间（秒）
 *@return 无返回
 */
- (void)setRecordTime:(float)time;

/**
 *录音入口函数设置并开始
 *@param url 录音存放路径
 *@param recordSetting 录音的字典设置
 *@return 无返回
 */
- (void)callRecorder:(NSURL*)url recordSetting:(NSDictionary*)recordSetting;

/**
 *录音停止
 *@param 无参数
 *@return 无返回
 */
- (void)stopRecorder;

/**
 *音频播放入口函数设置并开始
 *@param url 文件路径
 *@return 无返回
 */
- (void)callPlaySound:(NSURL*)url;

/**
 *音频播放停止
 *@param 无参数
 *@return 无返回
 */
- (void)stopPlayer;

/**
 *pcm格式转mp3格式
 *@param pcmPath 要转换的pcm文件路径
 *@param mp3Path 转换后的mp3文件存放路径
 *@return 无返回
 */
- (void)PCMtoMP3:(NSString*)pcmPath mp3Path:(NSString*)mp3Path;

//备注：pcm转amr格式查阅amr库文件说明，调用EncodeWAVEToAMR(pcmData,1,16) 和 DecodeAMRToWAVE(amrData2) c语言函数;
@end
