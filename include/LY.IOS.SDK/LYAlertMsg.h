//
//  Alert.h
//  LY.IOS.SDK
//
//  Created by xiejiyong on 13-9-20.
//  Copyright (c) 2013年 xiejiyong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "MBProgressHUD.h"
#import "LYCommon.h"
@protocol LYAlertMsgDelegate <NSObject>

-(void)LYAlertMsgView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
-(void)LYhudWasHidden;

@end

@interface LYAlertMsg :UIViewController<MBProgressHUDDelegate> {
	MBProgressHUD *HUD;
}
@property (nonatomic,assign) id<LYAlertMsgDelegate> LYAlertMsgdelegate;

/**
 *提示对话框
 *@param msg 提示的内容
 *@param tag tag标记
 *@return 无返回
 */
-(void)showMsg:(NSString *)msg withTag:(long)tag;

/**
 *确认对话框
 *@param msg 提示的内容
 *@param tag tag标记
 *@return 无返回
 */
-(void)alertMsg:(NSString *)msg withTag:(long)tag;

/**
 *显示等待提示
 *@param msg 提示的内容
 *@param selName 关联的方法
 *@param view 在哪个View上显示
 *@return 无返回
 */
-(void)shouHudMsg:(NSString*) msg selectorName:(SEL)selName DisplyView:(UIView*)view;

/**
 *隐藏等待提示
 *@return 无返回
 */
-(void)hideHudMsg;
@end
