//
//  ZipArchive.h
//  
//
//  Created by aish on 08-9-11.
//  acsolu@gmail.com
//  Copyright 2008  Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LYCommon.h"
#import "zlib.h"
#import "zconf.h"

#import "zip.h"
#import "unzip.h"


@protocol LYZipArchiveDelegate <NSObject>
@optional
-(void) ErrorMessage:(NSString*) msg;
-(BOOL) OverWriteOperation:(NSString*) file;

@end


@interface LYZipArchive : NSObject {
@private
	zipFile		_zipFile;
	unzFile		_unzFile;
	
	NSString*   _password;
	id			_delegate;
}

@property (nonatomic, retain) id delegate;

/**
 *创建不加密的压缩文件
 *@param zipFile 压缩文件全路径
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) CreateZipFile2:(NSString*) zipFile;

/**
 *创建加密的压缩文件
 *@param zipFile 压缩文件全路径
 *@param password 压缩包加密密码
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) CreateZipFile2:(NSString*) zipFile Password:(NSString*) password;

/**
 *往压缩包追加文件
 *@param file 追加文件全路径
 *@param newname 新的文件名
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) addFileToZip:(NSString*) file newname:(NSString*) newname;

/**
 *关闭压缩包
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) CloseZipFile2;

/**
 *打开不加密压缩文件包
 *@param zipFile 压缩文件全路径
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) UnzipOpenFile:(NSString*) zipFile;

/**
 *打开加密压缩文件包
 *@param zipFile 压缩文件全路径
 *@param password 压缩包的解压密码
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) UnzipOpenFile:(NSString*) zipFile Password:(NSString*) password;

/**
 *解压处理
 *@param path 解压文件全路径
 *@param overwrite 是否写  YES：写  NO：不写
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite;

/**
 *关闭密压缩文件包
 *@return 成功标记 YES：成功  NO：不成功
 */
-(BOOL) UnzipCloseFile;
@end
