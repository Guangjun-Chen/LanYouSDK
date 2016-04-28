//
//  LYFileTransfer.h
//  LYFileTransfer
//
//  Created by zenghaifeng on 13-10-27.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//

#import <Foundation/Foundation.h>
//Http组件
#import "ASIHTTPRequest.h"         //GET
#import "ASIFormDataRequest.h"     //POST
//数据库
#import "LYFileTransferDatabase.h" 

//该代理函数在LYTasksManager中实现
@protocol LYFileTransmissionDelegate <NSObject>
@optional
//上传回调
-(void)uploadDidFinish:(NSString*)guid; //完成上传任务时回调
-(void)uploadDidFailed:(NSString*)guid; //上传任务网络无法连接时回调
-(void)uploadDidSendBytes:(long long)bytes ofTotalByte:(long long)fileBytes withGuid:(NSString*)guid; //上传任务完成一个包时回调
//下载回调
-(void)downloadDidFinish:(NSString*)path withGuid:(NSString*)guid; //下载任务完成时回调
-(void)downloadFailed:(NSString*)guid; //下载网络无法连接时回调
-(void)downloadFileSize:(NSString*)size percentage:(float)floatvalue offset:(long long)offset withGuid:(NSString*)guid; //下载任务完成一个包时回调
@end

//该代理函数在业务端根据需求实现
@protocol LYFileTransmissionDeleteDelegate <NSObject>
-(void)deleteServiceFileDone:(NSString*)guid; //给服务器成功接收－1后回调函数
-(void)downloadLevelLimited:(NSString*)string; //下载权限限制 1-15新增需求
@end

@interface LYFileTransfer : NSObject<ASIHTTPRequestDelegate>{
    ASIFormDataRequest *_request;
}
//代理
@property (nonatomic,assign) id<LYFileTransmissionDelegate> LYFileTransmissionDelegate; //给队列管理器使用
@property (nonatomic,assign) id<LYFileTransmissionDeleteDelegate> LYFileTransmissionDeleteDelegate; //给业务端使用

//文件传输协议中规定字段（写入数据库）
@property(nonatomic,retain) NSMutableString* dynamicKey; //动态key
@property(nonatomic,retain) NSMutableString* defaultKey; //默认key:LANYOUAP
@property(nonatomic,retain) NSMutableString* postURLString; //服务器地址
//第一层
@property(nonatomic,retain) NSMutableString* protocolVersion; //版本号
@property(nonatomic,retain) NSMutableString* encryptType; //加密类型
//第二层
@property(nonatomic,retain) NSMutableString* user;  //用户
@property(nonatomic,retain) NSMutableString* isDefault; //是否是默认加密方式
@property(nonatomic,retain) NSMutableString* deviceToken; //设备号
//第三层
@property(nonatomic,retain) NSMutableString* guid;  //识别码（看作文件名）
@property(nonatomic,retain) NSMutableString* modulecode;  //型号
@property(nonatomic,retain) NSMutableString* fileType;  //文件类型
@property(nonatomic,retain) NSMutableString* compressType; //下载无
@property(nonatomic,retain) NSMutableString* dataPacketCount;  //分包总数
@property(nonatomic,retain) NSMutableString* dataPacketCurrent; //当前包
@property(nonatomic,retain) NSMutableString* fileseculevel; //1-15新增字段，上传文件级别
//数据库额外所需保存字段
@property(nonatomic,retain) NSMutableString* uploadFilePath; //上传地址全名
@property(nonatomic,retain) NSMutableString* downloadFilePath; //下载文件存放位置；带文件名，不带后缀
@property(nonatomic,retain) NSMutableString* fileSize; //total size
@property(nonatomic,assign) unsigned long long offset; //当前文件读取位置
@property(nonatomic,retain) NSMutableString* taskType; //upload/download
@property(nonatomic,retain) NSMutableString* tableName; //数据库表名
@property(nonatomic,assign) NSInteger packetLength; //上传时每次分包上传的字节数
//过程变量不记录到数据库
@property(nonatomic,retain) NSMutableData* content; //上传内容
@property(nonatomic,retain) NSMutableData* downloadFileData; //下载内容
@property(nonatomic,retain) NSMutableDictionary* dataDictionary;
@property(nonatomic,retain) NSMutableDictionary* bodyDictionary;
@property(nonatomic,retain) NSMutableString* bodyString; //AES加密后
@property(nonatomic,retain) NSMutableString* dataString; //AES加密后
@property(nonatomic,retain) NSMutableString* jsonString; //明文key json串
@property(nonatomic,retain)ASIFormDataRequest *request; //请求

/**
 *文件上传任务入口函数
 *@param fileDPath 上传的文件路径
 *@param packetSize 分包上传每个包的大小
 *@param urlString 上传的url路径
 *@param tableName 加入该任务的表名
 *@return 无返回
 */
-(void)uploadFile:(NSString*)fileDPath withEachPacketSize:(NSInteger)packetSize withPostUrl:(NSString*)urlString withTableName:(NSString*)tableName;

/**
 *文件下载任务入口函数
 *@param localPath 文件下载保存的路径（不含文件名和后缀） 
 *@param urlString 上传的url路径
 *@param tableName 加入该任务的表名
 *@return 无返回
 */
-(void)downloadFileToPath:(NSString*)localPath withPostUrl:(NSString*)urlString withTableName:(NSString*)tableName;

/**
 *通知服务器删除上传文件接口函数（给服务器发送－1指令）
 *@param 无参数
 *@return 无返回（可使用LYFileTransmissionDeleteDelegate的代理回调函数）
 */
-(void)deleteUploadFile; //使用该方法前需先停止该任务（用队列管理器中的停止方法）


/***************** 注意：以上函数给业务端使用，以下函数给任务队列管理器“LYTasksManager”使用 *********************/

/**
 *继续执行任务（LYTasksManager中使用）
 *@param taskType 固定任务字符串类型（upload/download二选一）
 *@return 无返回
 */
-(void)taskContinue:(NSString*)taskType; //合并uploadContinue和downloadContinue

/**
 *停止任务（LYTasksManager中使用）
 *@param taskType 固定任务字符串类型（upload/download二选一）
 *@return 无返回
 */
-(void)taskStop:(NSString*)taskType; //合并uploadStop和downloadStop

/**
 *查询该guid任务是否已存在数据库任务列表中 （LYTasksManager中使用）
 *@param guid 字符串GUID
 *@param table 数据库表名
 *@return 返回 YES/NO
 */
-(BOOL)guidIsExist:(NSString*)guid table:(NSString*) table;

/**
 *查询该guid任务是否已完成 （LYTasksManager中使用）
 *@param guid 字符串GUID
 *@param table 数据库表名
 *@return 返回 YES/NO
 */
-(BOOL)taskFinished:(NSString*)guid table:(NSString*)tableName;

/**
 *查询该guid任务是否正在执行 （LYTasksManager中使用）
 *@param guid 字符串GUID
 *@param table 数据库表名
 *@return 返回 YES/NO
 */
-(BOOL)taskIsExecuting:(NSString*)guid table:(NSString*)tableName;

/**
 *查询该guid任务是否已停止 （LYTasksManager中使用）
 *@param guid 字符串GUID
 *@param table 数据库表名
 *@return 返回 YES/NO
 */
-(BOOL)taskIsStop:(NSString*)guid table:(NSString*)tableName;

/**
 *从数据库中更新上传任务断点续传数据 （LYTasksManager中newTask使用）
 *@param guid 字符串GUID
 *@return 无返回
 */
-(void)updateDataFromUploadTable:(NSString*)guid;

/**
 *从数据库中更新下载任务断点续传数据 （LYTasksManager中newTask使用）
 *@param guid 字符串GUID
 *@return 无返回
 */
-(void)updateDataFromDownloadTable:(NSString*)guid;

@end
