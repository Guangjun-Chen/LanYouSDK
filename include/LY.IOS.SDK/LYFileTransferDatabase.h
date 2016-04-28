//
//  LYFileTransferDatabase.h
//  LYFileTransfer
//
//  Created by zenghaifeng on 13-10-15.
//  Copyright (c) 2013年 Lanyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDatabase.h"

@interface LYFileTransferDatabase : NSObject{
    FMDatabase* database;
}
//数据库单例
+(LYFileTransferDatabase*)sharedDatabase;
-(id)init;
@property (nonatomic,retain) FMDatabase *database;
@end
