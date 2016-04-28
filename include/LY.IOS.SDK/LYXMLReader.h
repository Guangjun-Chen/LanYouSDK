//
//  XMLReader.h
//  LY.IOS.SDK
//
//  Created by xiejiyong on 13-9-21.
//  Copyright (c) 2013年 xiejiyong. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface LYXMLReader : NSObject<NSXMLParserDelegate>
{
    NSMutableArray *dictionaryStack;
    NSMutableString *textInProgress;
    NSError **errorPointer;
}
/**
 *XML二进制数据解析
 *@param data XML文件的二进制数据
 *@param errorPointer 错误编码
 *@return 解析返回的字典数据
 */
+ (NSDictionary *)dictionaryForXMLData:(NSData *)data error:(NSError **)errorPointer;

/**
 *XML 字符串数据解析
 *@param string XML文件的字符串数据
 *@param errorPointer 错误编码
 *@return 解析返回的字典数据
 */
+ (NSDictionary *)dictionaryForXMLString:(NSString *)string error:(NSError **)errorPointer;

@end

