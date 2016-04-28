//
//  SecurityUtil.h
//  Smile
//
//  Created by 周 敏 on 12-11-24.
//  Copyright (c) 2012年 BOX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LYSecurityUtil : NSObject 

#pragma mark - base64
+ (NSString*)encodeBase64String:(NSString *)input;
+ (NSString*)decodeBase64String:(NSString *)input;
+ (NSString*)encodeBase64Data:(NSData *)data;
+ (NSString*)decodeBase64Data:(NSData *)data;

#pragma mark - AES加密
/**
 *AES加密  将string转成加密的string
 *@param string 需要加密的字符串
 *@param key 加密秘钥
 *@return 返回加密的字符串
 */
+ (NSString*)encryptAESData:(NSString*)string key:(NSString *)key;

/**
 *AES解密  将加密的string进行解密
 *@param string 加密的字符串
 *@param key 解密秘钥
 *@return 返回解密后的字符串
 */
+(NSString*)decryptAESData:(NSString*)string key:(NSString *)key;

#pragma mark - 移位加密
/**
 *移位加密  将NSData转成加密的NSData
 *@param data 需要加密的NSData
 *@param key 移位位数
 *@return 返回加密的NSData
 */
+(NSData *)encryptMoveBitData:(NSData *)data key:(UInt8)key;

/**
 *移位解密  将加密的NSData进行解密
 *@param data 需要解密的NSData
 *@param key 移位字符
 *@return 返回解密后的NSData
 */
+(NSData*)decryptMoveBitData:(NSData*)data key:(char)key;


/**
 *随机生成16位动态秘钥
 *@return 返回16位秘钥字符串
 */
+(NSString*)createKey;
@end
