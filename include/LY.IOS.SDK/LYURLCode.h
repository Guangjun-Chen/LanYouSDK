//
//  LYURLCode.h
//  URLCode
//
//  Created by zenghaifeng on 13-10-9.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LYURLCode : NSObject
/**
 *url加密
 *@param inputString 要加密的字符串
 *@return 返回加密后的字符串
 */
+(NSString *)encodeToPercentEscapeString: (NSString *)inputString;

/**
 *url解密
 *@param inputString 要解密的字符串
 *@return 返回解密后的字符串
 */
+(NSString *)decodeFromPercentEscapeString: (NSString *)inputString;

@end
