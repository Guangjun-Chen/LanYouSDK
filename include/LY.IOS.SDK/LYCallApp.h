//
//  CallApp.h
//  CallApp
//
//  Created by zenghaifeng on 13-9-25.
//  Copyright (c) 2013年 LanYou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MFMessageComposeViewController.h> //sms
#import <MessageUI/MFMailComposeViewController.h> //email

@protocol CallAppDelegate <NSObject>
// 处理发送完的sms响应结果
- (void)CallAppViewControllerSMS:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result;
//处理发送完的email响应结果
-(void)CallAppViewControllerEmail:(MFMailComposeViewController *)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError *)error;
//处理照片选择器
- (void)CallAppImagePickerController:(UIImagePickerController *)picker
didFinishPickingMediaWithInfo:(NSDictionary *)info;
- (void)CallAppImagePickerControllerDidCancel:(UIImagePickerController *)picker;
@end

@interface LYCallApp : UIViewController<MFMessageComposeViewControllerDelegate,MFMailComposeViewControllerDelegate,UIImagePickerControllerDelegate,UINavigationControllerDelegate>

@property (nonatomic,assign) id<CallAppDelegate> CallAppDelegate;

/**
 *调用电话
 *@param phoneNumber 电话号码字符串
 *@return 无返回
 */
-(void)callPhone:(NSString*)phoneNumber;

/**
 *调用短信界面
 *@param bodyOfMessage 短信内容字符串
 *@param recipients 收件人数组
 *@return 无返回
 */
-(void)callSMS:(NSString *)bodyOfMessage recipientList:(NSArray *)recipients;

/**
 *调用邮件界面
 *@param recipients 收件人数组
 *@param ccRecipients 抄送人数组
 *@param bccRecipients 暗抄人数组
 *@param subject 主题字符串
 *@param content 内容
 *@return 无返回
 */
-(void)callMail:(NSArray*)recipients toccRecipients:(NSArray*)ccRecipients tobccRecipients:(NSArray*)bccRecipients withSubject:(NSString *)subject content:(NSString *)content;

/**
 *调用获取图片选择器
 *@param cameraType 获取图片方式（拍照或从相册中获取）
 *@return 无返回
 */
-(void)callPhoto:(UIImagePickerControllerSourceType)cameraType;

@end
