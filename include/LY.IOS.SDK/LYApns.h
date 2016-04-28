//
//  LYApns.h
//  LY.IOS.SDK
//
//  Created by xiejiyong on 13-9-25.
//  Copyright (c) 2013年 xiejiyong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LYCommon.h"
@interface LYApns : NSObject


/**
 *获取本机设备串，用于APNS 消息推送
 *@return 返回设备令牌字符串
 */
+(NSString*)getDeviceToken;
@end
