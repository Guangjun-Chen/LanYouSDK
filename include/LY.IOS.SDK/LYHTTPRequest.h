//
//  LYHTTPRequest.h
//  LY.IOS.SDK
//
//  Created by xiejiyong on 13-9-27.
//  Copyright (c) 2013年 xiejiyong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASIFormDataRequest.h"
#import "Reachability.h"
#import "LYCommon.h"
#import "LYAlertView.h"
#import "JSONKit.h"
#import "LYApns.h"
#import "LYSecurityUtil.h"

#include <sys/socket.h> // Per msqr
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>

@interface LYHTTPRequest : NSObject

+(NSDictionary *)PostGetJSON:(NSString *)params;


+(NSDictionary *)PostGetFileServiceUrl:(NSString *)servercode functionCode:(NSString *)functioncode;

/**
 *Post方式请求服务
 *@param servercode 服务编号
 *@param functionCode 方法编号
 *@param Parameters 参数
 *@return 服务端返回的数据
 */
+(NSDictionary *)PostServiceData:(NSString *)servercode functionCode:(NSString *)functioncode Parameters:(NSMutableDictionary *)parameters;

/**
 *Get方式请求服务
 *@param servercode 服务编号
 *@param functionCode 方法编号
 *@param Parameters 参数
 *@return 服务端返回的数据
 */
+(NSDictionary *)GetServiceData:(NSString *)servercode functionCode:(NSString *)functioncode Parameters:(NSMutableDictionary *)parameters;

@end
