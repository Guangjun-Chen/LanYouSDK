//
//  Common.h
//  LY.IOS.SDK
//
//  Created by xiejiyong on 13-9-16.
//  Copyright (c) 2013年 xiejiyong. All rights reserved.
//  Modified by Frank on 2015-8-3
//  NSObject的协议去掉了NSCopying
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define DEVICE_TYPE_iPad 3 //iPad端登录
#define DEVICE_TYPE_IPHONE 2 //iPhone端登录

#define timeOutSecond 30 //超时时间 秒

#ifdef __cplusplus
#define MYLIB_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define MYLIB_EXTERN extern __attribute__((visibility("default")))
#endif

#ifdef DEBUG
#define DebugLog(format, ...) NSLog(format, ##__VA_ARGS__)
#else
#define DebugLog(format, ...)
#endif
#define LOGIN_USERID @"loginUserID"
#define LOGIN_STATUS @"loginStatus" //登录状态
#define SOUND_STATE @"SoundState" //声音
#define SHAKE_STATE @"ShakeState" //震动
//文件传输切块大小（目前按每块512K来分割）
#define FILEBLOCKSIZE 512 * 1024

//默认服务器IP
//#define SERVER_IP  @"172.25.6.31"
extern NSString* SERVER_IP;
//默认服务器端口
//#define SERVER_PORT  80
extern NSString* SERVER_PORT;

//客户端AES密钥默认
#define AES_DEFAULT_KEY @"LANYOUAPLANYOUAP"

//每次登录后服务端返回的
extern NSString* AESDOAKEY;

extern NSString* ISLOGIN; //是否登陆
extern NSString* USERNAME; //用户名
extern NSString* PASSWORD; //密码
extern NSString* USERID; //用户ID
extern NSString* EMPNAME; //用户姓名
extern NSString* USERTYPE; //用户类型
extern NSString* ORGANIZATION; //组织ID
extern NSString* DownloadURL; //文件下载地址
extern NSString* UploadURL; //文件上传地址

@interface LYCommon : NSObject

+ (void)SetServerIP:(NSString*)ip;
+ (void)SetServerPort:(NSString*)port;

/**
 *从GUID字符串 转换为 GUID bytes
 *@param GUID 字符串GUID
 *@return 返回CFUUIDBytes的GUID
 */
+ (CFUUIDBytes)stringWithUUID:(NSString*)GUID;

/**
 *从GUID bytes转换为GUID字符串
 *@param uuidBytes CFUUIDBytes的GUID
 *@return 返回字符串的GUID
 */
+ (NSString*)GetUUIDStringFromBytes:(CFUUIDBytes)uuidBytes;

/**
 *产生GUID字符串方法
 *@return 返回字符串的GUID
 */
+ (NSString*)stringWithUUID;

/**
 *产生CFUUIDBytes GUID 方法
 *@return 返回CFUUIDBytes的GUID
 */
+ (CFUUIDBytes)getUUIDBytes;

/**
 *获取时间戳
 *@return 返回时间戳
 */
+ (NSInteger)getTimeStamp;

/**
 *按指定格式获取本机当前时间
 *@param formatter 时间格式
 *@return 返回指定格式的时间
 */
+ (NSString*)getLocalCurrentTime:(NSDateFormatter*)formatter;

/**
 *NSDate to NSString
 *@param date 时间
 *@return 返回字符串  格式yyyy-MM-dd HH:mm:ss
 */
+ (NSString*)dateToString:(NSDate*)date;

/**
 *按照格式NSDate to NSString
 *@param date 时间
 *@param format 时间格式
 *@return 返回字符串
 */
+ (NSString*)stringFromData:(NSDate*)date format:(NSString*)format;

/**
 *NSString to NSDate
 *@param str 字符串
 *@return 返回时间 格式yyyy-MM-dd HH:mm:ss
 */
+ (NSDate*)stringToDate:(NSString*)str;

/**
 *设置图片背景灰色
 *@param sourceImage 需要设置的图片
 *@return 返回设置好的图片
 */
+ (UIImage*)getGrayImage:(UIImage*)sourceImage;

/**
 *获取当前设备类型
 *@return 返回设备类型 2：iPad端登录；3：iPhone端登录
 */
+ (NSInteger)currentDeviceType;

/**
 *保存自定义设置
 *@return 无返回
 */
+ (void)saveSystemSetting:(NSMutableDictionary*)dict;

/**
 *获取自定义设置
 *@return 返回自定义设备字典
 */
+ (NSMutableDictionary*)getSystemSetting;

/**
 *URL编码
 *@param str 需要编码的字符串
 *@return 返回编码后的字符串
 */
+ (NSString*)URLCode:(NSString*)str;

/**
 *URL反编码
 *@param str 需要反编码的字符串
 *@return 返回反编码后的字符串
 */
+ (NSString*)URLUnCode:(NSString*)str;

/**
 *获取App设置信息
 *@return 返回设备信息
 */
+ (NSUserDefaults*)getAppSetting;

/**
 *播放铃声
 *@param index 播放铃声的ID
 *@return 无返回
 */
+ (void)playSound:(UInt32)index;

/**
 *震动
 *@return 无返回
 */
+ (void)shake;

/**
 *URL转义处理
 *@return  字符串
 */
+ (NSString*)stringEscapeChar:(NSString*)character;
@end
