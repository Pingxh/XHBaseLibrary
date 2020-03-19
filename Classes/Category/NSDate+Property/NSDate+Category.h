//
//  NSDate+Category.h
//  BaseFramework
//
//  Created by PingXuhui on 2019/1/24.
//  Copyright © 2019 Pxh. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (Category)

/**
 时间转换为时间戳

 @param datetime 要转换的时间
 @return 返回转换后的时间戳 long long 类型
 */
+ (long long)getDateTimeTOMilliSeconds:(NSDate *)datetime;

/**
 时间戳转时间
 
 @param format 格式化样式
 @param stamp 时间戳
 @return 返回格式化后的时间
 */
+ (NSString *)formatterTime:(NSString *)format stampString:(NSString *)stamp;

@end

NS_ASSUME_NONNULL_END
