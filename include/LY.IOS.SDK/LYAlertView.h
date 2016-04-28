//
//  LYAlertView.h
//  LY.IOS.SDK
//
//  Created by xiejiyong on 13-9-21.
//  Copyright (c) 2013年 xiejiyong. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LYCommon.h"
#define kMax_ConstrainedSize        CGSizeMake(200, 100)
@interface LYAlertView : UIView
{
    NSString* _text;
    CGSize  _fontSize;
}

/**
 *简单提示 默认显示1.5秒后自动消息
 *@param text 提示的内容
 *@param view 在哪个View上显示
 *@return 无返回
 */
+(void)showText:(NSString*)text inView:(UIView*)view;
@end