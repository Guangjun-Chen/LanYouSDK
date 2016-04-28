//
//  LYCheckNetwork.h
//  test1
//
//  Created by zenghaifeng on 13-10-29.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//
// 加静态库 "SystemConfiguration.framework"

#import <Foundation/Foundation.h>
#import "Reachability.h"

@protocol LYCheckNetworkDelegate <NSObject>
-(void)isReachable;
-(void)isUnReachable;
-(void)isReachableViaWiFi;
-(void)isReachableViaWWAN;
@end

@interface LYCheckNetwork : NSObject{
    Reachability * _reach;
}
@property (nonatomic,assign) id<LYCheckNetworkDelegate> LYCheckNetworkDelegate;
/**
 *开启网络检测功能
 *@param 无参数
 *@return 无返回
 */
-(void)startcheckingNetworkEnvironment;

/**
 *关闭网络检测功能
 *@param 无参数
 *@return 无返回
 */
-(void)stopCheckingNetworkEnvironment;
@end
