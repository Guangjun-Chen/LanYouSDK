//
//  UIImage+Modify.h
//  Category
//
//  Created by zenghaifeng on 13-10-5.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Modify)
/**
 *保存图片到相册
 *@param image 要保存的相片
 *@return 无返回
 */
+(void)saveToAlbum:(UIImage*)image;

/**
 *保存图片到指定路径
 *@param path 路径
 *@param data 要保存的图片的二进制数据
 *@return 无返回
 */
+(void)saveToPath:(NSString*)path withData:(NSData*)data;

/**
 *从原点开始裁减png图片
 *@param width 宽
 *@param height 高
 *@param path 路径
 *@return 返回裁减后的二进制数据
 */
+(NSData*)modifyImageToPNGWithWidth:(CGFloat)width height:(CGFloat)height path:(NSString*)path;

/**
 *从原点开始裁减jpg图片
 *@param width 宽
 *@param height 高
 *@param path 路径
 *@param quality 压缩质量（0~1）
 *@return 返回裁减后的二进制数据
 */
+(NSData*)modifyImageToJPGWithWidth:(CGFloat)width height:(CGFloat)height path:(NSString*)path quality:(CGFloat)quality;

/**
 *从任意坐标点开始裁减jpg或png图片
 *@param originX 起点的x坐标
 *@param originY 起点的y坐标
 *@param width 宽
 *@param height 高
 *@param path 路径
 *@param type "png"或"jpg"字符串
 *@param quality 压缩质量（0~1）
 *@return 返回裁减后的二进制数据
 */
//任意输入坐标裁减
+(NSData*)modifyImageWithOriginX:(CGFloat)originX originY:(CGFloat)originY width:(CGFloat)width height:(CGFloat)height path:(NSString*)path PNGOrJPG:(NSString*)type quality:(CGFloat)quality;

@end
