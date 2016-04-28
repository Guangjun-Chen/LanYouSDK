//
//  PictureViewController.h
//  ShowPictures
//
//  Created by zenghaifeng on 13-9-20.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LYPictureViewController : UIViewController <UIScrollViewDelegate> {
    UIScrollView* _myScrollView; //外层视图负责左右滑动
    NSMutableArray* _imageNameArray; //相片名数组
    BOOL _isHidden; //导航栏是否已经隐藏
}
//Modified by Frank on 2015-8-3
//int 改为NSInteger
@property (nonatomic, assign) NSInteger numberOfImages;
@property (nonatomic, assign) NSInteger currentPhotoIndex;

/**
 *图片展示入口函数
 *@param array 图片名数组
 *@param startIndex 从第几张开始展示，一般设为0
 *@return 无返回
 */
- (void)getPicturesWithNameArray:(NSArray*)array withStartIndex:(NSInteger)startIndex;

@end
