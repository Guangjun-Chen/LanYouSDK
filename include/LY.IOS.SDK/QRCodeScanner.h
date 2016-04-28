//
//  QRCodeScanner.h
//  LY_App_iPhone
//
//  Created by Frank on 5/18/15.
//
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@protocol QRCodeScannerDelegate <NSObject>
/**
 * 撤销扫描的委托函数
 */
- (void)cancelScanning;

@optional
/**
 * 获取二维码扫描值的委托函数
 * @param aVMetadataMachineReadableCodeObj 二维码返回值的机器码对象, 一般使用stringValue解析有用字符
 */
- (void)getQRCode:(AVMetadataMachineReadableCodeObject *)aVMetadataMachineReadableCodeObj;

@end

@interface QRCodeScanner : UIViewController<AVCaptureMetadataOutputObjectsDelegate>{
    AVCaptureMetadataOutput *captureMetadataOutput;
}

@property (nonatomic) BOOL isReading;

@property (nonatomic, strong) AVCaptureSession *captureSession;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *videoPreviewLayer;
@property (nonatomic, assign) id <QRCodeScannerDelegate> delegate;

/**
 * 开始创建二维码扫描读取界面
 */
- (BOOL)startReading;

@end
