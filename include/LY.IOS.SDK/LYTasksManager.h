//
//  LYTasksManager.h
//  TaskManager2
//
//  Created by zenghaifeng on 13-10-31.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LYFileTransfer.h"
#import "LYCommon.h"

//业务端使用
@protocol LYTasksManagerDelegate <NSObject>
@optional
//上传回调
-(void)LYTMuploadDidFinish:(NSString*)guid; //完成上传任务时回调
-(void)LYTMuploadDidFailed:(NSString*)guid; //上传任务网络无法连接时回调
-(void)LYTMuploadDidSendBytes:(long long)bytes ofTotalByte:(long long)fileBytes withGuid:(NSString*)guid; //上传任务完成一个包时回调
//下载回调
-(void)LYTMdownloadDidFinish:(NSString*)path withGuid:(NSString*)guid; //下载任务完成时回调
-(void)LYTMdownloadFailed:(NSString*)guid; //下载网络无法连接时回调
-(void)LYTMdownloadFileSize:(NSString*)size percentage:(float)floatvalue offset:(long long)offset withGuid:(NSString*)guid;//下载任务完成一个包时回调
@end

@interface LYTasksManager : NSObject<LYFileTransmissionDelegate>{
    NSMutableString* _tableName; //表名
    NSInteger _maxNumber; //数组中最大任务数
    NSMutableArray* _taskArray; //任务数组（加同步锁）
}
@property (nonatomic,assign) id<LYTasksManagerDelegate> LYTasksManagerDelegate; //给业务端使用的代理函数
@property(nonatomic,retain)NSMutableString* tableName; //任务管理器所管理的数据表
@property(nonatomic,assign) BOOL showTips;  //提测时方便测试人员使用弹出提示，默认为关闭 10-30 11:18

/**
 *入口函数
 *@param newNumber 数组中最大任务数
 *@param tableName 要管理的任务数据库表名
 *@return 无返回
 */
-(void)setMaxNumber:(NSInteger)newNumber table:(NSString*)tableName;

/**
 *插入一个要管理的任务并开始执行，如果并行任务队列已满，则变为等待状态
 *@param newTask LYFileTransfer类型的任务实例
 *@param guid 字符串GUID
 *@param table 要管理的任务数据库表名(upload/download/unity)三选一
 *@return 无返回
 */
-(void)newTask:(LYFileTransfer*)newTask guid:(NSString*)guid table:(NSString*)table;

/**
 *停止一个任务
 *@param guid 字符串GUID
 *@return 无返回
 */
-(void)stopOneTask:(NSString*)guid;

/**
 *开启一个任务
 *@param guid 字符串GUID
 *@return 无返回
 */
-(void)startOneTask:(NSString*)guid;

/**
 *开启所有任务
 *@param 无参数
 *@return 无返回
 */
-(void)startAllTasks;

/**
 *停止所有任务
 *@param 无参数
 *@return 无返回
 */
-(void)stopAllTasks;

/**
 *删除数据库中一个任务,并删除临时文件
 *@param guid 字符串GUID
 *@param table 数据库表名
 *@return 无返回
 */
-(void)deleteOneTask:(NSString*)guid table:(NSString*)tableName;

/**
 *查询队列中正在执行的个数
 *@param 无参数
 *@return 返回队列中正在执行的个数
 */
-(NSInteger)getTaskArray;


/******************* 以下是对内使用方法 **********************/
/**
 *查询当前任务状态
 *@param guid 字符串GUID
 *@return 返回当前任务状态
 */
-(NSString*)getStatus:(NSString*)guid;

/**
 *判断任务队列是否满了
 *@param 无参数
 *@return 返回YES/NO
 */
-(BOOL)tasksArrayIsFull; //比较[array count] 是否小于 _maxNumber

/**
 *将下一个等待执行的任务加入执行队列
 *@param 无参数
 *@return 无返回
 */
-(void)startNextTask;

/**
 *仅作为给测试人员显示提示使用
 *@param message 需要提示的内容
 *@return 无返回
 */
-(void)showAlertView:(NSString*)message;
@end
